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
//Librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Directivas de Preprocesado
#define button 2

//Funcion ISR
void sensortemp();
void funcion_boton();

//Constructores
Ticker accion_temperatura(sensortemp, 3000);
Ticker state_button(funcion_boton,6000);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  accion_temperatura.start();
  state_button.start();
  sensor.begin();
}

void loop() {
  accion_temperatura.update();
  state_button.update();
}

void sensortemp(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.println("---SENSOR DE TEMPERATURA---");
  Serial.print("La Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}

void funcion_boton(){
  int estado = digitalRead(button);
  
  if(estado == HIGH){
    Serial.println("---ACCION DEL BOTON---");
    Serial.println("Boton Presionado");
  }

  if(estado == LOW){
    Serial.println("---ACCION DEL BOTON---");
    Serial.println("Boton No Presionado");
  }
}
