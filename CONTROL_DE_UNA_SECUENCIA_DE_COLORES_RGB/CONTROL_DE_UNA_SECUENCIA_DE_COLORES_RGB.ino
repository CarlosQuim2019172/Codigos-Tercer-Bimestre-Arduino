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

#define pot A5
#define LEDR 3
#define LEDG 5
#define LEDB 6

//variables 
int variacion, tiempo;

void setup() {
  pinMode(pot, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
  variacion = analogRead(pot);

  //Mapeo de los valores del potenciometro
  tiempo = map(variacion, 0, 1023, 100, 1000);

  analogWrite(LEDR, 174);
  analogWrite(LEDG, 92);
  analogWrite(LEDB, 230);
  delay(tiempo);
  analogWrite(LEDR, 255);
  analogWrite(LEDG, 255);
  analogWrite(LEDB, 255);
  delay(tiempo);
  analogWrite(LEDR, 0);
  analogWrite(LEDG, 255);
  analogWrite(LEDB, 255);
  delay(tiempo);
  analogWrite(LEDR, 189);
  analogWrite(LEDG, 174);
  analogWrite(LEDB, 20);
  delay(tiempo);
  analogWrite(LEDR, 255);
  analogWrite(LEDG, 87);
  analogWrite(LEDB, 35);
  delay(tiempo);
}
