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
#define voltaje A3

//Variables
int Vcc = 5;
int R2 = 10000;
float R1 = 0;
float Vout = 0;
float lectura = 0;
float valor = 0;
float conver = 0;

//Constructor
LiquidCrystal_I2C lcd_quim(0x27,16,2);

//Funciones
void convesion();

void setup() {
  lcd_quim.init();
  lcd_quim.backlight();
}

void loop() {
  convesion();
}

void convesion(){
  //Leemos el valor del divisor de voltaje
  lectura = analogRead(voltaje);
  
  //Realizamos la conversion de esa lectura
  conver = lectura * Vcc;
  Vout = conver / 1023;

  //Realizamos la operación necesaria para obtener el valor de R1
  valor = (Vcc / Vout) - 1;
  R1 = R2 * valor; 
  
  //Imprimimos el valor de resistencia R1
  if(lectura){
    lcd_quim.setCursor(0,0);
    lcd_quim.print(" Valor de R1 :D ");
    lcd_quim.setCursor(9,1);
    lcd_quim.print(" ohms");
    lcd_quim.setCursor(2,1);
    lcd_quim.print(R1);
  }
  
  if(!lectura){
    lcd_quim.setCursor(0,0);
    lcd_quim.print("Sin Resistencia");
    lcd_quim.setCursor(0,1);
    lcd_quim.print("      :(       ");
  }
  

}
