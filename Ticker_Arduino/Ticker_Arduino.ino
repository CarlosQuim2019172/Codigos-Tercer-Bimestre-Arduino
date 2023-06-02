/*
 * Fundación Kinal
 * Centro Educativo Técnico Labral Kinal 
 * Electrónica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de Electrónica Digital y Reparación de Computadoras I
 * Nombre: Carlos Alexander Quim Chapaz
 * Carné: 2019172 
 * Proyecto: Uso de interrupciones de temporizador por medio de Ticker - Bimeste III
*/

//librerias 
#include <Ticker.h> //Esta libreria me permite hacer uso del timer

//Directivas de Propocesador
#define led_arduino 13 //pin 2 utilizado para una interrupción externa para rising

//Funciones ISR 
/*ISR = interrupt services routine 
 * Estas son las funciones que van a ser llamadas al dispararse una interrupción externa 
 * 
 * NOTA: Las funciones deben de ser sin retorno y sin parametrods
*/
void led_ISR(void);

//Constructores 
Ticker accion_led_ISR(led_ISR,3000); //Cada 3 segundos se encendera/apagara el led del pin 13

//Variables axiliares
volatile static bool state_led;

void setup() {
  Serial.begin(19200); //Inicion de comunicación serial
  pinMode(led_arduino, OUTPUT);
  digitalWrite(led_arduino, LOW);
  accion_led_ISR.start(); //Inicio la interrupcion ue esperaria que se repita cada 3 segundos
  state_led = LOW;
}

void loop() {
  accion_led_ISR.update();
}

//Funciones ISR
void led_ISR(void){
  state_led = digitalRead(led_arduino); //Leo del estado digital del pin que estoy usando como salida
  digitalWrite(led_arduino, !state_led);
  Serial.println("Ha acurrido la interrupcion");
}
