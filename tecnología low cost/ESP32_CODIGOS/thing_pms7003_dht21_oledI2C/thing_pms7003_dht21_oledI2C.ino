/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */
 
/* Al TRABAJAR CON LA PLACA ESP32 SE REQUIERE ADICIONAR EN PREFERENCIAS : https://dl.espressif.com/dl/package_esp32_index.json 
 *  INSTALAR EN GESTOR DE TARJETAS : ESP32
 REQUIERE INSTALAR LA LIBRERIA THINGSPEAK Y WIFI(si no tuviese)
 INSTALAR LIBRERIA PMSLIBRARY
 INSTALAR LIBRERIA SSD1306 by ADAFRUIT Y ADAFRUIT GFX KIBRARY by Adafruit 
 INSTALAR LIBRERIA DHT SENSOR LIBRARY by Adafruit y Adafruit Unified sensor  
*/
//// INCLUYENDO SENSORES POR BLOQUES 

//// Se debe contar con una cuenta en ThingSpeak

///////////////////////////////////////////////////////////
//// 1RO IOT THINGSPEAK 
//// esp32
#include "ThingSpeak.h"
#include "WiFi.h"
WiFiClient cliente;

//// DEFINIR LOS PÁRAMETROS DE CONEXIÓN PLACA-NUBE 
const char* ssid = "--";               //// SSID ROUTER.
const char* password = "--";       //// Contraseña de router.

unsigned long channelID = --;   //// Cambiar con el ID del canal 
const char* WriteAPIKey = "--";  //// Cambiar con el Write API Key del canal.

///////////////////////////////////////////////////////////
//// Oled
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaración para el SSD1306 display - conexion por I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

///////////////////////////////////////////////////////////
/// 2DO. PLANTOWER PMS7003
#include "PMS.h"
#include "Wire.h"
PMS pms(Serial1);
PMS::DATA data;
#define RXD2 26
#define TXD2 25

///////////////////////////////////////////////////////////
////// 3RO. DHT22
#include "Arduino.h"
#include "DHT.h"
#define DHTPIN 13     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
#define DHTTYPE DHT22   // DHT 21, DHT 23
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  
///////////////////////////////////////////////////////////
 ///// THINGSPEAK
  Serial.println("CONFIGURACIÓN NUBE:");

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi conectado!");

  ThingSpeak.begin(cliente);

///////////////////////////////////////////////////////////  
  //// PMS7003
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  pms.passiveMode();

///////////////////////////////////////////////////////////
 //// DHT22
   dht.begin();

///////////////////////////////////////////////////////////  
 //// oled 
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306  failo"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  
}

void loop()
{
  delay(2000);
  
///////////////////////////////////////////////////////////
  //// Lecturas de sensores
  sensores();

///////////////////////////////////////////////////////////
  ThingSpeak.writeFields(channelID,WriteAPIKey);
  Serial.println("Datos enviados a ThingSpeak!");
  //// delay(10000);
  delay(10000);
  
}

void sensores() {

///////////////////////////////////////////////////////////
//// PMS 7003

  //ACTIVACIÓN DEL VENTILADOR, Y TIEMPO DE ESTABILIZACIÓN DE 30 SEGUNDOS;
  Serial.println("Ventilador activado");
  pms.wakeUp();
  delay(10000);

  //ESTABLECIENDO SOLICITUD DE LAS LECTURAS;
  pms.requestRead();
  //LECTURA DE LOS DATOS, ADEMÁS TIEMPO EN OBTENCIÓN DE LECTURAS;
  if (pms.readUntil(data))
  {
    
    //// RECORDAR LAS ESPECIFICACIONES DEL SENSOR
    //// https://download.kamami.com/p564008-p564008-PMS7003%20series%20data%20manua_English_V2.5.pdf
    
    float PM_1   =   (data.PM_AE_UG_1_0);    //// PM 1 
    float PM_2_5 =   (data.PM_AE_UG_2_5);    //// PM 2.5
    float PM_10  =   (data.PM_AE_UG_10_0);   //// PM 10

    Serial.print("PM 1.0 (ug/m3): ");  Serial.println(PM_1);
    Serial.print("PM 2.5 (ug/m3): ");  Serial.println(PM_2_5);
    Serial.print("PM 10.0 (ug/m3): "); Serial.println(PM_10);

///////////////////////////////////////////////////////////
    ///// DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();   
    Serial.print("TEMPERATURA: ");
    Serial.println(t);
    Serial.print("HUMEDAD: ");
    Serial.println(h);

    Serial.println("-----------------------");

///////////////////////////////////////////////////////////
//// oled

  // clear display
  display.clearDisplay();
  
  // display temperatura
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print(t,1);
  display.print("");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display Humedad 
  
  display.setTextSize(2);
  display.setCursor(85,0);
  display.print(h,0);
  display.print("%"); 

  // display PM 2.5
  display.setTextSize(1);
  display.setCursor(0,18);
  display.print("PM 2.5 ");
  display.setTextSize(3);
  display.setCursor(0,28);
  display.print(PM_2_5,0);

  // display PM 10
  display.setTextSize(1);
  display.setCursor(64,18);
  display.print("PM 10");
  display.setTextSize(3);
  display.setCursor(64,28);
  display.print(PM_10,0);

  
  // INCA
  int INCA = PM_2_5*100/50;
  
  if(INCA<=50){
    display.setTextSize(2);
    display.setCursor(0,51);
    display.print("BUENA");
  } else if(INCA>50 && INCA<=100){
    display.setTextSize(2);
    display.setCursor(0,51);
    display.print("MODERADO");
  } else if(INCA>100 && INCA <= 500){
    display.setTextSize(2);
    display.setCursor(0,51);
    display.print("MALO");
  } else{
    display.setTextSize(2);
    display.setCursor(0,51);
    display.print("VUEC");
  }
  
  

  display.display(); 
  
  ///////////////////////////////////////////////////////////
    //// Envio a thingspeak
    //// formato (FIELD, VARIABLE)
    ThingSpeak.setField (1,PM_1);
    ThingSpeak.setField (2,PM_2_5);
    ThingSpeak.setField (3,PM_10);
    ThingSpeak.setField (4,t);
    ThingSpeak.setField (5,h);  

    delay(5000);

  }
  else
  {
    Serial.println("LECTURA FALLIDA.");
  }
  
  //// APAGAR EL VENTILADOR;
    pms.sleep();

}
