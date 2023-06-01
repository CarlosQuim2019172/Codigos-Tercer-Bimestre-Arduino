/*
 * Fundación Kinal
 * Centro Educativo Técnico Labral Kinal 
 * Electrónica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de Electrónica Digital y Reparación de Computadoras I
 * Nombre: Carlos Alexander Quim Chapaz
 * Carné: 2019172 
 * Proyecto: Uso de Interrupciones externas - Bimeste III
*/

//Directivas de Propocesador
#define btn_rising  2 //pin 2 utilizado para una interrupción externa para rising
#define btn_falling 3 //pin 3 utilizado para una interrupción externa para falling 

//Funciones ISR 
/*ISR = interrupt services routine 
 * Estas son las funciones que van a ser llamadas al dispararse una interrupción externa 
 * 
 * NOTA: Las funciones deben de ser sin retorno y sin parametrods
*/

void funcion_ISR_falling(void);
void funcion_ISR_rising(void);

void setup() {
  Serial.begin(19200); //Inicion de comunicación serial
  pinMode(btn_rising, INPUT);
  pinMode(btn_falling, INPUT);
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING); //Anclar la interrupcion del pin 2 a una funcion de ISR, disparado por el flanco 
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupcion del pin 2 a una funcion de ISR, disparado por el flanco
}

void loop() {
  // put your main code here, to run repeatedly:
}


//Funciones ISR
void funcion_ISR_rising(void){
  //Cuando se dispara la interrupcion por RISING 
  Serial.println("Hemos presionado el boton de rising");
  
}

void funcion_ISR_falling(void){
  //Cuando se dispara la interrupcion por FALLING 
  Serial.println("Hemos presionado el boton de falling");
}
