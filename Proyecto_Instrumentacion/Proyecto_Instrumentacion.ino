/***Definiciones Macros***/
#define PIN_LMIzq   A0
#define PIN_LMDer   A1
#define PIN_MPX     A2
/***Lecturas para Mapeo***/
#define MPX_Read0     0
#define MPX_Read1     0
#define MPX_Read2     0
#define MPX_Read3     0
#define MPX_Read4     0
#define MPX_Read5     0
#define MPX_Read6     0
#define MPX_Read7     0
#define MPX_Read8     0  
#define MPX_Read9     0
#define MPX_Read10    0
/*******Variables********/
float MPX;    
float LMIzq; 
float LMDer;
float V_MPX, V_LMIzq, V_LMDer; 
/***************Prototipo de Funciones****************/
void ReadTemperature(float LMIzq, float LMDer);
void ReadPressure(float MPX);
void Get_Voltage(float V_MPX, float V_LMIzq, float V_LMDer);

void setup(){
  Serial.begin(9600);    
}

void loop(){
  /*Toma el valor de Presion e imprime en Serial*/
  ReadPressure(MPX);
  /*Toma los valores Temperatura e imprime en Serial*/
  ReadTemperature(LMIzq, LMDer);
  /*Toma los voltajes de salida de sensores e imprime en Serial*/
  Get_Voltage(V_MPX,V_LMIzq,V_LMDer);
  delay(1000); //Luego de 1 segundo se toma la siguiente lectura
}
/*Obtiene lectura de Presion*/
void ReadPressure(float MPX){
  MPX = analogRead(PIN_MPX);
  MPX = map(MPX, MPX_Read0, MPX_Read1, 0, 10);
  
  Serial.print("MPX10DP:          "); 
  Serial.println(MPX);

  delay(5);
}

/**********Lectrua de sensores Temperatura***********************/
void ReadTemperature(float LMIzq, float LMDer){
  LMIzq = analogRead(PIN_LMIzq) * 0.004882812 * 100;  
  LMIzq = LMIzq - 273.15;                    //Convierte de Kelvin a Centigrado 
  LMDer = analogRead(A1) * 0.004882812 * 100;    //Se lee la temperatura en Kelvin
  LMDer = LMDer - 273.15;                    //Convierte de Kelvin a Centigrado 

  Serial.print("LM355 Izq:         "); 
  Serial.println(LMIzq);
  Serial.print("LM355 Der:         "); 
  Serial.println(LMDer);
  delay(5);
}
/**********Calcula voltajes de salida***********************/
void Get_Voltage(float V_MPX, float V_LMIzq, float V_LMDer){
  Serial.print("Voltage MPX10DP:   "); 
  V_MPX   = analogRead(PIN_MPX) * (5.0/1023.0);
  Serial.println(V_MPX);
  
  Serial.print("Voltage LM355 Izq: "); 
  V_LMIzq = analogRead(PIN_LMIzq) * (5.0/1023.0);
  Serial.println(V_LMIzq);
  
  Serial.print("Voltage LM355 Der: ");
  V_LMDer = analogRead(PIN_LMDer) * (5.0/1023.0);
  Serial.println(V_LMDer);
  delay(5);
}

