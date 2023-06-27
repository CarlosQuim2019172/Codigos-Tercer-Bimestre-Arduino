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

//Libreria
#include <Servo.h>

//Directivas del preprocesador
//Usaremos una LDR en configuracion PULLDOWN
#define ch_LDR    A0  //pin A0 del arduino, a este conectaremos el punto medio del divisor de tension entre LDR y una resistencia de 33K
#define sensor 2
#define led_Azul  3   //led azul conectado al pin 3
#define led_Verde 4   //led verde conectado al pin 4
#define led_Rojo  5   //led rojo conectado al pin 5
#define invalido 9
#define valido 8

//Variables
int IN1 = A1;
int IN2 = A2;
int IN3 = A3;
int IN4 = A4;
int t = 10;

//Valores analogicos de la intensidad de cada color
int resultado_azul, resultado_rojo, resultado_verde;

//Valores analogicos leidos por la LDR
int resultado;
int x, a;

//Valor de umbral para los colores
int tol = 8; //este valor lo podremos cambiar segun los valores leidos por nuestra LDR

//Funciones
int deteccion_objeto();
void Antihorario(void);

//Paso
//Antihorario
int antihorario [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

//Constructor
Servo empuje;

void setup() {
  //Comunicacion Serial
  Serial.begin(9600);
  //Configuracion de I/O
  pinMode(ch_LDR, INPUT); //pin A0 como entrada
  pinMode(sensor, INPUT);
  pinMode(led_Azul, OUTPUT); //pin 3 como salida
  pinMode(led_Verde, OUTPUT); //pin 4 como salida
  pinMode(led_Rojo, OUTPUT);  //pin 5 como salida
  pinMode(valido, OUTPUT);
  pinMode(invalido, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Los leds inician en un estado de bajo
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);

  //Servo
  empuje.attach(6);
  empuje.write(180);
}

void loop() {
  if (digitalRead(sensor) == false) {
    detector_objeto();
    if (resultado_azul > 76 && resultado_azul < 178) {
      digitalWrite(valido, HIGH); //Encendemos una Led verde si el objeto es valido
      //Movemos la banda hasta la posicion del servo
      posicion_s();
      delay(500);
      //Accionamos el servo para poder mover el objeto de la banda
      empuje.write(0); //Movemos el servo hasta 0 grados
      delay(500);
      empuje.write(180); //Regresamos el servo a 180 grados
      digitalWrite(valido, LOW); //Apagamos la Led verde
      delay(1500);
    }
    else {
      for (int a = 0; a < 4; a++) {
        //Encendemos una Led Roja 4 veces si el color no coincide
        digitalWrite(invalido, HIGH);
        delay(200);
        digitalWrite(invalido, LOW);
        delay(200);
      }
      posicion_s(); //Si el sensor de colores detecta que no hay coincidencia del color, retira el objeto fuera de la banda
    }
  } else {
    //Si el sensor no detencta objetos sigue avanzando la banda
    Antihorario();
  }
}

int detector_objeto () {
  //Enviendo el led rojo
  digitalWrite(led_Rojo, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("R = ");
  Serial.println(resultado_rojo);
  digitalWrite(led_Rojo, LOW);
  delay(150);

  //Enviendo el led verde
  digitalWrite(led_Verde, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("G = ");
  Serial.println(resultado_verde);
  digitalWrite(led_Verde, LOW);
  delay(150);

  //Enviendo el led azul
  digitalWrite(led_Azul, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("B = ");
  Serial.println(resultado_azul);
  digitalWrite(led_Azul, LOW);
  delay(150);
}

void Antihorario(void) {
  // bucle recorre la matriz de una fila por vez
  for (int i = 0; i < 4; i++) {
    digitalWrite(IN1, antihorario[i][0]);
    digitalWrite(IN2, antihorario[i][1]);
    digitalWrite(IN3, antihorario[i][2]);
    digitalWrite(IN4, antihorario[i][3]);
    delay(t);
  }

}

void posicion_s (void) {
  // bucle del recorrido de matriz 275 veces hasta la posicion del servo
  for (int i = 0; i < 275; i++) {
    Antihorario();
  }
}
