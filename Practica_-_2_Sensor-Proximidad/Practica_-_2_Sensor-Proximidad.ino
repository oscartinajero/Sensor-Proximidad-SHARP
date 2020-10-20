#include <LiquidCrystal_I2C.h>  // Librería para Display

LiquidCrystal_I2C lcd(0x27,16,2);

//Variables globales
int gatillo_sensor = A0;
float lectura = 1;
int cm;
int brillo;


void setup() {
  //Comunicasión Serial a 9600 baudios
  Serial.begin(9600);
  //LEDs a Encender segun a distancia que se nos ha dado
  pinMode(2,OUTPUT); // 62cm
  pinMode(3,OUTPUT); // 80cm
  pinMode(4,OUTPUT); // 90cm

  //LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
 
void loop() {
  lectura = distancia(20);
  //cm = pow(3027.4 / sensor, 1.2134);

  //LCD
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
  lcd.setCursor(0,1);
  lcd.print(lectura);
  lcd.print("cm");

  //LED1
  if(lectura <59){
    digitalWrite(2,HIGH);
    delay(300);
    digitalWrite(2,LOW);
    delay(300);
  }
  else if(lectura >= 59 && lectura <= 65){
    if(lectura >=61 && lectura <= 63){
      digitalWrite(2,HIGH);
    }else{
      digitalWrite(2,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      delay(100);
    }
  }
  //LED2
  else if(lectura >65 && lectura <= 83){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    delay(300);
    digitalWrite(3,LOW);
    delay(300);
  }
  else if(lectura >= 77 && lectura <= 83){
    if(lectura >=79 && lectura <= 81){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
    }else{
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      delay(100);
      digitalWrite(3,LOW);
      delay(100);
    }
  }
  //LED3
  else if(lectura >83 && lectura <= 93){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    delay(300);
    digitalWrite(4,LOW);
    delay(300);
  }
  else if(lectura >= 87 && lectura <= 93){
    if(lectura >=89 && lectura <= 91){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
    }else{
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(4,LOW);
      delay(100);
    }
  }
  else if(lectura>93){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(90);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(90);
  }
  
  delay(1000);
}

int distancia(int n){
  long suma = 0;
  for (int i = 0; i < n; i++){
    suma+=analogRead(A0);
  }
  float adc = suma/n;
  float distancia_cm = 28940.1 * pow(adc, -1.16);
  return(distancia_cm);
}
