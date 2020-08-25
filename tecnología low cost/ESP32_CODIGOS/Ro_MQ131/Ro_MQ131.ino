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
#define mq131 35

void setup() {
    Serial.begin(115200);
}

void loop() {
    float sensor_volt; 
    float RS_air;           //// valor de RS vía en un aire limpio
    float Ro;               //// valor de R0 
    float sensorValue = 0;
    int RL = 1; // RL = 1K
    sensorValue = analogRead(mq131);
    sensor_volt = (sensorValue/4095)*5.0;
    RS_air = RL*(5.0-sensor_volt)/sensor_volt; 

    //// Obteniendo valor de Ro, Necesario para el MQ131
    Ro = RS_air/16.3862 ; // La relación de RS / R0 es 16.3862 según https://www.sensorsportal.com/DOWNLOADS/MQ131.pdf 

    Serial.print("sensor_volt = ");
    Serial.print(sensor_volt);
    Serial.print("V");

    Serial.print("  R0 = ");
    Serial.println(Ro);
    delay(1000);

}
