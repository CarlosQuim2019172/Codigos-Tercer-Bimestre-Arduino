/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Carlos Quim
   Carnet: 2019172
   Proyecto: Sensor de Color con LDR
*/
//Librerias 
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

//Directivas del preprocesador
#define LEDV 2  

//Funciones
void sensortemp();

//Constructores
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);
SoftwareSerial miBT(10,11); //RX= 10 y TX= 11
Ticker accion_temperatura(sensortemp, 10000);

//Variables 
float tempC;
char dato;

void setup() {
  miBT.begin(38400);
  Serial.begin(9600);
  pinMode(LEDV,OUTPUT);
  sensor.begin();
  accion_temperatura.start();
}

void loop() {
  if(miBT.available()){ //Recibimos datos de la app 
    dato = miBT.read();  
    if(dato == '1'){ //Encendemos la LED
      digitalWrite(LEDV, HIGH);
    }

    if(dato == '0'){ //Encendemos la LED
      digitalWrite(LEDV, LOW);
    }   
  }

  accion_temperatura.update();
}

void sensortemp(){ //Funcion del Sensor de temperatura
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  miBT.print(temp);
}
