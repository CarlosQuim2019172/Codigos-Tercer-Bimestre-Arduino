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
#include <LiquidCrystal_I2C.h>
#define v A3

//Variables
unsigned int r1;
int vcc = 5;
int r2 = -10000; //Resistencia de 10K

//Constructor
LiquidCrystal_I2C lcd_quim(0x27,16,2);

//Funciones
unsigned int convesion();

void setup() {
  lcd_quim.init();
  lcd_quim.backlight();
}

void loop() {
  convesion();
}

unsigned int convesion(){
  float conver = analogRead(v);
  float vout = (5 * conver)/1023;
  float multi = r2 * vout;
  float res = vout - vcc;
  r1 = multi/res;

  lcd_quim.setCursor(0,0);
  lcd_quim.print("-Valor de R1 :D-");
  lcd_quim.setCursor(0,5);
  lcd_quim.println(r1);
}
