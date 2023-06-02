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
#define btn_incremento 2 //pin 2 utilizado para una interrupción externa para rising
#define btn_decremento 3 //pin 3 utilizado para una interrupción externa para falling 

//Funciones 
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
void display_unidades();
void display_decenas();

//Variables 
volatile static bool f_print = false; //Variable booleana que me permite imprimir un texto en el Loop
int unidades = 0; ///variable que va de 0 - 9
int decenas = 0; ///variable que va de 0 - 5

void setup() {
  pinMode(btn_incremento, INPUT);
  pinMode(btn_decremento, INPUT);
  for(int i = 4; i < 11; i++){
    pinMode(i, OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(btn_incremento),funcion_ISR_rising,RISING); //Anclar la interrupcion del pin 9 a una funcion de ISR, disparado por el flanco 
  attachInterrupt(digitalPinToInterrupt(btn_decremento),funcion_ISR_falling,FALLING); //Anclar la interrupcion del pin 10 a una funcion de ISR, disparado por el flanco
}

void loop() {
  if(f_print){
    f_print = false; //Limpio la variable 

    if(unidades > 9){
      decenas++;
      unidades = 0;
    }

    if(unidades == -1){
      unidades = 9;
      decenas--;
    }

    if(decenas < 0){
      unidades = 0;
      decenas = 5;
    }

    if(unidades > 0 && decenas == 5){
      unidades = 0;
      decenas = 0;
    }
  } 

  display_unidades();
  display_decenas();
}

//Funciones ISR
void funcion_ISR_rising(void){
  unidades ++; //aunmento el valor de la variable 
  f_print = true; 
}

void funcion_ISR_falling(void){
  unidades --; //disminuyo el valor de la variable  
  f_print = true;
}

//Funciones Numeros
void display_unidades(){
  if(unidades == 0){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  if(unidades == 1){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH); 
  }
  if(unidades == 2){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  if(unidades == 3){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
  if(unidades == 4){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  if(unidades == 5){ 
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH); 
  }
  if(unidades == 6){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  if(unidades == 7){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
  if(unidades == 8){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  if(unidades == 9){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
}

void display_decenas(){
  if(decenas == 0){
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  if(decenas == 1){
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH); 
  }
  if(decenas == 2){
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }
  if(decenas == 3){
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
  }
  if(decenas == 4){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  if(decenas == 5){ 
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH); 
  }
}
