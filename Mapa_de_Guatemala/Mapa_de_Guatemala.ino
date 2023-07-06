//Librerias
#include <Wire.h>
#include <PCF8574.h>

//Directivas de Preprocesador 
#define ZumbadorPin 6
#define PCF8574_HIGH LOW  //Negacion utilizada para encender un puerto del expansor PCF8574
#define PCF8574_LOW HIGH  //Negacion utilizada para apagar un puerto del expansor PCF8574

//Constructor
PCF8574 expansor_PCF(0x27);  //Expansor con direccion I2C 0x27

//Variables
int num_de_pregunta;
int tencendido = 3000; //tiempo de encendido de las leds
String respuesta;
int a=440;
int f=349;
int cH=523;

//Funciones
int num_random();
void preguntas();
void tiempo_de_respuesta();
void incorrecta();

void setup() {
  Serial.begin(38400);
  expansor_PCF.begin();
  for (int i = 2; i < 17; i++) {
    pinMode(i, OUTPUT);
  }  
}

void loop() {
  num_de_pregunta = num_random();
  preguntas();
  delay(1500);
}

int num_random() {
  int num = random(0, 21);
  return num;
}

void preguntas() {
  switch (num_de_pregunta) {
    case 0:
      Serial.println("Cabecera de Petén?");
      tiempo_de_respuesta();
      if (respuesta == String("Flores")) {
        digitalWrite(2, HIGH);
        delay(tencendido);
        digitalWrite(2, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Flores");
        incorrecta();
      }
      break;
    case 1:
      Serial.println("Cabecera de Izabal?");
      tiempo_de_respuesta();
      if (respuesta == String("Puerto Barrios")) {
        digitalWrite(3, HIGH);
        delay(tencendido);
        digitalWrite(3, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Puerto Barrios");
        incorrecta();
      }
      break;
    case 2:
      Serial.println("Cabecera de Alta Verapaz?");
      tiempo_de_respuesta();
      if (respuesta == String("Cobán")) {
        digitalWrite(4, HIGH);
        delay(tencendido);
        digitalWrite(4, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Cobán");
        incorrecta();
      }
      break;
    case 3:
      Serial.println("Cabecera de Qiché?");
      tiempo_de_respuesta();
      if (respuesta == String("Santa Cruz del Quiché")) {
        digitalWrite(5, HIGH);
        delay(tencendido);
        digitalWrite(5, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Santa Cruz del Quiché");
        incorrecta();
      }
      break;
    case 4:
      Serial.println("Cabecera de Huehuetenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Huehuetenango")) {
        expansor_PCF.write(0, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(0, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Huehuetenango");
        incorrecta();
      }
      break;
    case 5:
      Serial.println("Cabecera de Escuintla?");
      tiempo_de_respuesta();
      if (respuesta == String("Escuintla")) {
        expansor_PCF.write(1, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(1, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Escuintla");
        incorrecta();
      }
      break;
    case 6:
      Serial.println("Cabecera de San Marcos?");
      tiempo_de_respuesta();
      if (respuesta == String("San Marcos")) {
        digitalWrite(8, HIGH);
        delay(tencendido);
        digitalWrite(8, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: San Marcos");
        incorrecta();
      }
      break;
    case 7:
      Serial.println("Cabecera de Jutiapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Jutiapa")) {
        digitalWrite(9, HIGH);
        delay(tencendido);
        digitalWrite(9, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Jutiapa");
        incorrecta();
      }
      break;
    case 8:
      Serial.println("Cabecera de Baja Verapaz?");
      tiempo_de_respuesta();
      if (respuesta == String("Salamá")) {
        digitalWrite(10, HIGH);
        delay(tencendido);
        digitalWrite(10, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Salamá");
        incorrecta();
      }
      break;
    case 9:
      Serial.println("Cabecera de Santa Rosa?");
      tiempo_de_respuesta();
      if (respuesta == String("Cuilapa")) {
        digitalWrite(11, HIGH);
        delay(tencendido);
        digitalWrite(11, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Cuilapa");
        incorrecta();
      }
      break;
    case 10:
      Serial.println("Cabecera de Zacapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Zacapa")) {
        digitalWrite(12, HIGH);
        delay(tencendido);
        digitalWrite(12, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Zacapa");
        incorrecta();
      }
      break;
    case 11:
      Serial.println("Cabecera de Suchitepéquez?");
      tiempo_de_respuesta();
      if (respuesta == String("Mazatenango")) {
        digitalWrite(13, HIGH);
        delay(tencendido);
        digitalWrite(13, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Mazatenango");
        incorrecta();
      }
      break;
    case 12:
      Serial.println("Cabecera de Chiquimula?");
      tiempo_de_respuesta();
      if (respuesta == String("Chiquimula")) {
        digitalWrite(14, HIGH);
        delay(tencendido);
        digitalWrite(14, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Chiquimula");
        incorrecta();
      }
      break;
    case 13:
      Serial.println("Cabecera de Guatemala?");
      tiempo_de_respuesta();
      if (respuesta == String("Ciudad de Guatemala")) {
        digitalWrite(15, HIGH);
        delay(tencendido);
        digitalWrite(15, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Ciudad de Guatemala");
        incorrecta();
      }
      break;
    case 14:
      Serial.println("Cabecera de Jalapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Jalapa")) {
        digitalWrite(16, HIGH);
        delay(tencendido);
        digitalWrite(16, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Jalapa");
        incorrecta();
      }
      break;
    case 15:
      Serial.println("Cabecera de Chimaltenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Chimaltenango")) {
        digitalWrite(17, HIGH);
        delay(tencendido);
        digitalWrite(17, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Chimaltenango");
        incorrecta();
      }
      break;
    case 16:
      Serial.println("Cabecera de Quetzaltenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Quetzaltenango")) {
        expansor_PCF.write(2, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(2, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Quetzaltenango");
        incorrecta();
      }
      break;
    case 17:
      Serial.println("Cabecera de El Progreso?");
      tiempo_de_respuesta();
      if (respuesta == String("Guastatoya")) {
        digitalWrite(7, HIGH);
        delay(tencendido);
        digitalWrite(7, LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Guastatoya");
        incorrecta();
      }
      break;
    case 18:
      Serial.println("Cabecera de Retalhuleu?");
      tiempo_de_respuesta();
      if (respuesta == String("Retalhuleu")) {
        expansor_PCF.write(7, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(7, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Retalhuleu");
        incorrecta();
         
      }
      break;
    case 19:
      Serial.println("Cabecera de Sololá?");
      tiempo_de_respuesta();
      if (respuesta == String("Sololá")) {
        expansor_PCF.write(4, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(4, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Sololá");
        incorrecta();
      }
      break;
    case 20:
      Serial.println("Cabecera de Totonicapán?");
      tiempo_de_respuesta();
      if (respuesta == String("Totonicapán")) {
        expansor_PCF.write(5, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(5, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: Totonicapán");
        incorrecta();
      }
      break;
    case 21:
      Serial.println("Cabecera de Sacatepéquez?");
      tiempo_de_respuesta();
      if (respuesta == String("La Antigua Guatemala")) {
        expansor_PCF.write(6, PCF8574_HIGH);
        delay(tencendido);
        expansor_PCF.write(6, PCF8574_LOW);
      } else {
        Serial.print("Incorrecta - ");
        Serial.println("Respuesta Correcta: La Antigua Guatemala");
        incorrecta();
      }
      break;
  }
}

void tiempo_de_respuesta() {
  bool tiempo = false;
  int a = 10;

  while ((!Serial.available() > 0) && tiempo == false) {
    Serial.print(a);
    Serial.print(", ");
    delay(1000);
    a--;
    if (a < 0) {
      tiempo = true;
      Serial.println();
      Serial.println("Sin Tiempo");
    }
  }

  Serial.println();
  respuesta = Serial.readStringUntil('\n');

  if (tiempo == false) {
    Serial.println();
    Serial.print("Usted Respondio: ");
    Serial.println(respuesta);
  }
}

void incorrecta() {
  tone(ZumbadorPin, a, 500);
    delay(500+50);
    tone(ZumbadorPin, a, 500);
    delay(500+50);     
    tone(ZumbadorPin, a, 500); 
    delay(500+50);
    tone(ZumbadorPin, f, 350);  
    delay(350+50);
    tone(ZumbadorPin, cH, 150);
    delay(150+50); 
    
    tone(ZumbadorPin, a, 500);
    delay(500+50);
    tone(ZumbadorPin, f, 350);
    delay(350+50);
    tone(ZumbadorPin, cH, 150);
    delay(150+50);
    tone(ZumbadorPin, a, 1000);   
    delay(1000+50);
}
