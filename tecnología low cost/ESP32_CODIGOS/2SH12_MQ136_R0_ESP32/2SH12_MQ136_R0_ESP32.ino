/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

 //// ANALÒGICO
#include "Arduino.h"
#define SO2_2SH12 32
//// ASUMO QUE EL SENSOR 2SH12 INCORPORA AL MQ136

void setup() {
    Serial.begin(115200);
}

void loop() {
    float sensor_volt; 
    float RS_air;           //// valor de RS vía en un aire limpio
    float Ro;               //// valor de R0 
    float sensorValue = 0;
    int RL = 1; // RL = 1K
    sensorValue = analogRead(SO2_2SH12);
    sensor_volt = (sensorValue/4095)*5.0;
    RS_air = RL*(5.0-sensor_volt)/sensor_volt; 
    //// Obteniendo valor de Ro, Necesario para el MQ131
    Ro = RS_air/18.0572 ; // La relación de RS_AIRE / R0 es 18.0572  
    Serial.print("ADC = ");
    Serial.print(sensorValue);
    Serial.print(" ");
    
    Serial.print(" sensor_volt = ");
    Serial.print(sensor_volt);
    Serial.print("V");

    Serial.print("  R0 = ");
    Serial.println(Ro);
    delay(1000);
    


    //// tener presente que la tensión de aire limpio según hoja de datos es de <= 1.5
    //// donde RS = (5-1.5)/1.5
    ////  Ro = 2.3333 / 18.0572
    //// R0  = 0.1292   //// esto sería el R0 teórico según hoja de datos
    


}
