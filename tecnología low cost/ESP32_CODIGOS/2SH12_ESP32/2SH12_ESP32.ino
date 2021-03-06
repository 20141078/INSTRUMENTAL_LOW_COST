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
 //// EL SENSOR 2SH12 NO TIENE UN DATASHEET
 //// RECOMIENDO USAR CUDIADOSAMENTE EL SENSOR, EN ESPECIAL SUS LECTURAS
 //// AL NO CONTAR CON UN DATASHEET, ES NECESARIO COMPARARLO CON UNA ESTACÓN DE CALIDAD DE AIRE
 //// ASÍ TAMBIÉN, PUEDE USARSE UN REESCALADO EN SU MEDICIÓN (NO ES TAN RECOMEDABLE)
 //// EL REECALADO PERMITE CONVERTIR DE ;
 //// ANALÓGICO (0-4095) -- > CONCENTRACIÓN (0-500 PPM)
 
 //// ANALÒGICO
#include "Arduino.h"
#define SO2_2SH12 32     //// DEFINIENDO PIN ANLOGICO CON CAPACIDAD 
                     //// DE TRANSMISIÒN EN LA NUBE

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  //// LECTURA DEL SENSOR SEMICONDUCTOR
  //// RECORDAR EL FUNCIONAMIENTO DE ESTOS TIPOS DE SENSORES
  float so2 = analogRead(SO2_2SH12);
  
  //// "SERIAL.print" PERMITE INTERACTUAR Y VISUALIZAR EL REGISTRO
  //// EN LA COMPUTADORA
  Serial.print("SO2: ");
  Serial.print(so2);
  Serial.println(" ");

  //// EL TIEMPO SE ESTABLECE EN MILISEGUNDOS
  //// 1000 MILISEGUNDOS = 1 SEGUNDO
  delay(1000);

}
