/*SICHA HUAMAN RUDY GABRIEL 
 * METEORÓLOGO DE LA UNALM
 * PROTOTIPO 2 DE CALIDAD DE AIRE Y VARIABLES METEOROLÓGICAS
 * CUENTA DE GITHUB https://github.com/20141078/INSTRUMENTAL_LOW_COST
 * CUENTA EN THINGSPEAK https://thingspeak.com/channels/1047170 
 * PROYECTO REFERENTE A LOS CURSOS 
 * MONITOREO Y CONTROL DE LA CONTAMINACIÓN ATMOSFÉRICA
 * TEORÍA INSTRUMENTAL DE VARIABLES METEOROLÓGICAS
 */

//// EL ANEMÓMETRO ES DIGITAL
uint8_t Wind_Pin = 15;         //// Definir el PIN del anemómetro
const int m_time = 5;          //// Definir el tiempo de medición para viento (s)
const float pi = 3.14159265;   //// Numero pi
int radio = 73;                //// Radio del anemometro(mm)
float windspeed;               //// Viento m/s
float RPM;                     //// Revoluciones por munuto
//float wind;                  //// 
int wind_ct;                   //// CONTEO

void setup() {
    Serial.begin(115200);
}

void loop() {
  getSensorData();
  delay(500);
}

void getSensorData() {
  meassure_wind();
  Serial.print("  Conteo: ");
  Serial.print(wind_ct);
  Serial.print("    Wind: ");
  Serial.print(windspeed);
  Serial.println(" m/s");
}

void meassure_wind() {
  wind_ct = 0;
  attachInterrupt(digitalPinToInterrupt(Wind_Pin), IntCallback, RISING);
  //// TIEMPO DE CONTEO
  delay(1000 * m_time);
  
  //// Cálculo de revoluciones por minuto (RPM)
  RPM = ((float)wind_ct*60) / (float)m_time * 2.4; 
  
  //// Cálculo de velocidad del viento m/s
  windspeed = ((4 * pi * radio * RPM)/60) / 1000;  
}

void IntCallback() {
  //// adición de conteo
  wind_ct++;
}
