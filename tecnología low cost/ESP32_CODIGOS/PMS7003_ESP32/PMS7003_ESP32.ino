/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

//// INCLUYENDO LIBRERIAS DEL SENSOR PLANTOWER PMS7003
#include "PMS.h"   /// INSTALAR LA LIBRERIA " PMS Libreria "
PMS pms(Serial1);
PMS::DATA data;

//// DEFINIENDO PINES DE TRANSMISIÓN
#define RXD2 26     //// CONECTAR AL PIN 25 DE LA PLACA ESP32
#define TXD2 25     //// CONECTAR AL PIN 26 DE LA PLACA ESP32 

//// SI DESEA CONECTAR VARIOS PLANTOWER PMS7003
//// REVISAR https://circuits4you.com/2018/12/31/esp32-hardware-serial2-example/ 


void setup()
{
  //// VELOCIDAD DE CONEXIÓN PLACA-MONITOR
  Serial.begin(115200);
  //// VELOCIDAD DE CONEXIÓN PLACA-SENSOR
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);

  //// PMS7003, MODO PASIVO(EVITA EL DESGASTE DEL LÁSER) 
  pms.passiveMode();

}

void loop()
{
//ACTIVACIÓN DEL VENTILADOR, Y TIEMPO DE ESTABILIZACIÓN DE 30 SEGUNDOS;
 Serial.println("Ventilador activado");
  pms.wakeUp();
  delay(30000);

  //ESTABLECIENDO SOLICITUD DE LAS LECTURAS;
  pms.requestRead();
  
  //LECTURA DE LOS DATOS, ADEMÁS TIEMPO EN OBTENCIÓN DE LECTURAS;
  Serial.println("COMIENZO DE LECTURAS");
  
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
    Serial.println("-----------------------");
    
    delay(5000);
  }
  else
  {
    Serial.println("LECTURA FALLIDA");
  }
  
  //  APAGAR EL VENTILADOR;
  pms.sleep(); 
  delay(5000);

}
