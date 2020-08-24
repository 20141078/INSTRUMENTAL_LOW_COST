/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

//// INSTALAR LIBRERIAS "ADAFRUIT_SENSOR" Y "ADAFRUIT_BME280"
//// ABRIR LIBRERIAS
//// UTILIZAREMOS LA CONEXIÓN I2C
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//// TAMBIÉN PUEDE UTILIZARSE LA CONEXIÓN SPI
/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5
Adafruit_BME280 bme(BME_CS); // hardware SPI
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
*/

///// DEFINIENDO EL NIVEL DE PRESIÓN A NIVEL DEL MAR
#define SEALEVELPRESSURE_HPA (1013.25)

//// DEFINIENDO 
Adafruit_BME280 bme; // I2C

void setup() {
  Serial.begin(115200);
  Serial.println("BME280 ");
  bool status;

  // configuración 
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Lectura fallida, desconecte el sensor");
    while (1);
  }

  Serial.println("-- Prueba de incio --");
  Serial.println();
}

void loop() { 
  
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
    
  Serial.print("Presión Atmosférica = ");
  Serial.print(bme.readPressure() / 100.0);
  Serial.println(" hPa");

  Serial.print("Altitud = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humedad Relativa = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println("----------------------");
    delay(2000);

}
