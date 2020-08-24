/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

//// INCLUYENDO LIBRERIAS DEL SENSOR DHT22
#include "Arduino.h"
#include "DHT.h"
#define DHTPIN 13         //// DEFINIENDO PIN
#define DHTTYPE DHT22     //// OTROS MODELOS COLOCAR DHT 21, DHT 23
DHT dht(DHTPIN, DHTTYPE); //// DEFINIR PIN Y TIPO DE DHT

void setup() {
  
   //// VELOCIDAD DE CONEXIÓN PLACA-MONITOR
  Serial.begin(115200);
  
  Serial.println("DHT 22, Comienzo");
  dht.begin();
}

void loop() {

  //// Lecturas de la humedad y temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // LECTURA FALLIDA, REINTENTO.
  if (isnan(h) || isnan(t) ){
    Serial.println("FLECTURA FALLIDA");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%      Temperatura: ");
  Serial.print(t);
  Serial.println("°C ");
  delay(2000);


}
