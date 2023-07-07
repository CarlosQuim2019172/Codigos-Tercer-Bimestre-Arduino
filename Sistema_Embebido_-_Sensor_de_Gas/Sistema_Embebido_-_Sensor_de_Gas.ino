/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Carlos Quim
   Carnet: 2019172
   Proyecto: Sistema Embebido
*/

//Librerias
#include <Ticker.h>
#include <LedControl.h>

//Directivas de Preprocesado
#define pGas A0

//Funciones
void sensor_gas();
void RepresentarMatriz(byte *Datos, int espera);

//Variables
int time = 150;
int gas, conversion, promedio;


//Constructores
Ticker mediciones(sensor_gas, 5000);
LedControl matriz = LedControl(11, 13, 10, 1); // Los numeros se refieren a que pin de arduino tienes en cada uno de los terminales
/* 11 para el DIN, 13 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/

//Animaciones
byte Fuego1[] = {
  0b00001000,
  0b00001100,
  0b00011100,
  0b00111110,
  0b01110110,
  0b01100110,
  0b01001100,
  0b00101000
};

byte Fuego2[] = {
  0b00101000,
  0b01001101,
  0b00011100,
  0b00111110,
  0b01110110,
  0b01100110,
  0b01001100,
  0b00101000
};

byte Fuego3[] = {
  0b00010000,
  0b00110000,
  0b00111000,
  0b01111100,
  0b01101110,
  0b01100110,
  0b00110010,
  0b00010100
};

byte Fuego4[] = {
  0b00010100,
  0b10110010,
  0b00111000,
  0b01111100,
  0b01101110,
  0b01100110,
  0b00110010,
  0b00010100
};

byte Copo1[] = {
  0b00000000,
  0b00000000,
  0b00001000,
  0b00011100,
  0b00111110,
  0b00011100,
  0b00001000,
  0b00000000
};

byte Copo2[] = {
  0b00000000,
  0b00001000,
  0b00101010,
  0b00011100,
  0b00111110,
  0b00011100,
  0b00101010,
  0b00001000
};

byte Copo3[] = {
  0b00000000,
  0b01001001,
  0b00101010,
  0b00011100,
  0b01111111,
  0b00011100,
  0b00101010,
  0b01001001
};

void setup() {
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  Serial.begin(9600);
  pinMode(pGas, INPUT);
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8); // La valores estan entre 1 y 15
  matriz.clearDisplay(0);
  mediciones.start();
}

void loop() {
  mediciones.update();

  if (promedio < 50)
  {
    Serial.println("Su Habitación se Encuentra Libre de GAS");
    RepresentarMatriz(Copo1, time);
    delay(150);
    RepresentarMatriz(Copo2, time);
    delay(150);
    RepresentarMatriz(Copo3, time);
    delay(150);
    matriz.clearDisplay(0);
  }
  else
  {
    Serial.println("SE DETECTO GAS!!!");
    RepresentarMatriz(Fuego1, time);
    delay(250);
    RepresentarMatriz(Fuego2, time);
    delay(250);
    RepresentarMatriz(Fuego3, time);
    delay(250);
    RepresentarMatriz(Fuego4, time);
    delay(250);
    matriz.clearDisplay(0);
  }

}

void sensor_gas() {
  int a, b = 0;

  gas = analogRead(pGas);
  conversion = map(gas, 0, 1024, 0, 100);

  for (int i = 0; i < 5; i++) {
    a = conversion;
    b = a + b;
    delay(100);
  }
  promedio = b / 5;

  Serial.print("Gas al: ");
  Serial.print(promedio);
  Serial.println("%");

}

// Definimos una funcion para representar las figuras
void RepresentarMatriz(byte *Datos, int espera) { //Representa los bytes de datos para una matriz de 8x8
  //Llamar animación :  RepresentarMatriz(Mensaje_n,time);
  for (int i = 0; i < 8; i++) {
    matriz.setColumn(0, i, Datos[7 - i]);
  }
  delay(espera);
}
