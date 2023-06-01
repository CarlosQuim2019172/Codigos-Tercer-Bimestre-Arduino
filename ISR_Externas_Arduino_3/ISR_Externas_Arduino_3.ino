/*
 * Fundación Kinal
 * Centro Educativo Técnico Labral Kinal 
 * Electrónica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de Electrónica Digital y Reparación de Computadoras I
 * Nombre: Carlos Alexander Quim Chapaz
 * Carné: 2019172 
 * Proyecto: Uso de Interrupciones externas ejemplo 3 - Bimeste III
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

//Variables 
volatile static bool f_print = false; //Variable booleana que me permite imprimir un texto en el Loop
volatile static unsigned char i = 0; ///variable que va de 0 - 255

void setup() {
  Serial.begin(19200); //Inicion de comunicación serial
  pinMode(btn_rising, INPUT);
  pinMode(btn_falling, INPUT);
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING); //Anclar la interrupcion del pin 2 a una funcion de ISR, disparado por el flanco 
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupcion del pin 2 a una funcion de ISR, disparado por el flanco
}

void loop() {
  if(f_print){
    f_print = false; //Limpio la variable
    Serial.println(i);    
  }
}

//Funciones ISR
void funcion_ISR_rising(void){
  i++; //aunmento el valor de la variable
  f_print = true; 
}

void funcion_ISR_falling(void){
  i--; //disminuyo el valor de la variable
  f_print = true;
}
