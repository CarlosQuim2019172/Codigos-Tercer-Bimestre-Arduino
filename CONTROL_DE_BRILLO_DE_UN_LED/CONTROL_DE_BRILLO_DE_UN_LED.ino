/*
 * Fundación Kinal
 * Centro Educativo Técnico Labral Kinal 
 * Electrónica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de Electrónica Digital y Reparación de Computadoras I
 * Nombre: Carlos Alexander Quim Chapaz
 * Carné: 2019172 
 * Proyecto: Intesidad de LED
*/

//Directivas de Procesador
#define pot A5
#define led 3

//variables 
int intensidad, brillo;

void setup() {
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  intensidad = analogRead(pot);

  //Mapeo de los valores del potenciometro
  brillo = map(intensidad, 0, 1023, 0, 255);

  analogWrite(led, brillo);
}
