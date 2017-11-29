#define LED         13
#define PIN_Serial  11
#define PIN_S1      10
#define PIN_S2       9
#define PIN_S3       8
#define PIN_S4       7

int cycles = 0;

void setup(){
  pinMode(PIN_Serial, OUTPUT);
  pinMode(PIN_S1, OUTPUT);
  pinMode(PIN_S2, OUTPUT);
  pinMode(PIN_S3, OUTPUT);
  pinMode(PIN_S4, OUTPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  Serial.println(digitalRead(PIN_S4));

  // Señal de Break
  digitalWrite(PIN_Serial, LOW);
  delay(3000);
  // Señal de Sync
  digitalWrite(PIN_Serial, HIGH);
  delay(200);
  // Bits de Nombre
  int nameBits[] = {0,0, 0, 1, 1, 0, 0, 0, 0,1};
  // Generacion de Nombre
  for(int i=0; i<10; i++){
    if(nameBits[i] == 1){
      digitalWrite(PIN_Serial, HIGH);
    }
    else{
      digitalWrite(PIN_Serial, LOW);
    }
    delay(50);
  }

  
  // Bits de Apellido
  int LnameBits[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1};
  // Generacion de Apellido
  for(int i=0; i<10; i++){
    if(LnameBits[i] == 1){
      digitalWrite(PIN_Serial, HIGH);
    }
    else{
      digitalWrite(PIN_Serial, LOW);
    }
    delay(50);
  }

  int slots[] = {0,1,1,0,0,1,0,0,1};
  // Slots
  int i; 
  for(i=0; i<8; i++){
  
      if(slots[i] == 1){
        if(i == 0 ||i == 1)
           digitalWrite(PIN_S1, HIGH);
        else if(i == 2 ||i == 3)
           digitalWrite(PIN_S2, HIGH);
        else if(i == 4 ||i == 5)
           digitalWrite(PIN_S3, HIGH);
        else if(i == 6 || i == 7)
           digitalWrite(PIN_S4, HIGH);
      }
      else if(slots[i] == 0){
        if(i == 0 ||i == 1)
           digitalWrite(PIN_S1, LOW);
        else if(i == 2 ||i == 3)
           digitalWrite(PIN_S2, LOW);
        else if(i == 4 ||i == 5)
           digitalWrite(PIN_S3, LOW);
        else if (i == 6 || i == 7)
           digitalWrite(PIN_S4, LOW);
      }
      delay(70);
    
  }
    
  digitalWrite(LED,HIGH);
  
  
}
