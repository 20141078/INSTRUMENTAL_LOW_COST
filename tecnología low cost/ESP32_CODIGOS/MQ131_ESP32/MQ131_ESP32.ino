/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

 //// EL CÒDIGO ESPECIFICA EL FUNCIONAMIENTO DEL SENSOR
 //// PARA EL USO ADECUADO, DEBEN SEGUIR LA HOJA DE DATOS 
 //// https://www.sensorsportal.com/DOWNLOADS/MQ131.pdf
 //// Y OBTENER LAS VARIABLES INTERMEDIAS
 
 //// ANALÒGICO
#include "Arduino.h"
#define mq131 35     //// DEFINIENDO PIN ANLOGICO CON CAPACIDAD 
                     //// DE TRANSMISIÒN EN LA NUBE

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  //// LECTURA DEL SENSOR SEMICONDUCTOR
  //// RECORDAR EL FUNCIONAMIENTO DE ESTOS TIPOS DE SENSORES
  float ozono = analogRead(mq131);
  
  //// "SERIAL.print" PERMITE INTERACTUAR Y VISUALIZAR EL REGISTRO
  //// EN LA COMPUTADORA
  Serial.print("ozono: ");
  Serial.print(ozono);
  Serial.println(" ");

  //// EL TIEMPO SE ESTABLECE EN MILISEGUNDOS
  //// 1000 MILISEGUNDOS = 1 SEGUNDO
  delay(1000);

}
