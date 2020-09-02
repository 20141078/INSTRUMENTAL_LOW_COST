/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

//// Instalar librerias DS18B20 del IDE ARDUINO
//// Incluir libreria
#include <OneWire.h>
#include <DallasTemperature.h>

//// Pin de conexión
const int oneWireBus = 4;     

//// Configuración de comunicación de sensor
OneWire oneWire(oneWireBus);

//// Referencia oneWire del sensor de temperatura 
DallasTemperature sensors(&oneWire);

void setup() {
  //// Inicie el monitor en serie
  Serial.begin(115200);
  ////// Inicie el sensor DS18B20
  sensors.begin();
}

void loop() {
  
  sensors.requestTemperatures(); 
  //// Lecturas de temperatura
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(1000);
}
