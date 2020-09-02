

int LED_VERDE     = 33;
int LED_NARANJA   = 14;   
int LED_AMARILLO  = 12; 
int LED_ROJO      = 13;

void setup() {                           
                                        
                                       
  pinMode(LED_VERDE, OUTPUT);     
  pinMode(LED_NARANJA, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);     
  pinMode(LED_ROJO, OUTPUT);
  
}

void loop() {                           
  digitalWrite(LED_VERDE, HIGH);   // Enciende el LED.
  delay(1000);                          // Espera un segundo.
  digitalWrite(LED_VERDE, LOW);    // Apaga el LED.
  delay(2000);                          // Espera dos segundos.

  digitalWrite(LED_NARANJA, HIGH);   // Enciende el LED.
  delay(1000);                          // Espera un segundo.
  digitalWrite(LED_NARANJA, LOW);    // Apaga el LED
  delay(2000);    

  digitalWrite(LED_AMARILLO, HIGH);   // Enciende el LED.
  delay(1000);                          // Espera un segundo.
  digitalWrite(LED_AMARILLO, LOW);    // Apaga el LED
  delay(2000);   

  digitalWrite(LED_ROJO, HIGH);   // Enciende el LED.
  delay(1000);                          // Espera un segundo.
  digitalWrite(LED_ROJO, LOW);    // Apaga el LED
  delay(2000);   


  
}
