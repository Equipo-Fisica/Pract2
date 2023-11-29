//# Pr-ctica-2
//Práctica número 2

#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int inputPin = 7;

int value = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String matriculas[6] = {"2022", "2022", "2022", "2022", "2022"," 2022"};

//ìndice de la matricula actual
int currentIndex=0;

//Estado del botòn en el ùltimo ciclo
int lastButtonState = LOW;

void setup(){
  //configura el nùmero de columnas y filas del LCD:
lcd.begin(16, 2);

  //configura el pin digital 7 como entrada
pinMode(inputPin, INPUT);

  // imprime la primera matrìcula en el LCD
lcd.print(" a ");
}

void loop()
{
  //lee el valor del pin de entrada
value = digitalRead(inputPin);

  //si el botòn acaba de ser presionado 
if(value)
{
    // Si el valor obtenido es alto, se procede a limpiar la pantalla y mostrar un texto el cual es "Limpiando..."
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Limpiando...");
    delay(2000);
    
    
    // Con esto se borra todo en el lcd
    lcd.clear();
    
    // Con esto el valor que tiene actualmente la matricula incrementa
    currentIndex = (currentIndex + 1) % 6;
    
    // Se procede a mostrar la matricula siguiente de algun compañero en el lcd con el fin de continuar con el siguiente paso
    lcd.print(matriculas[currentIndex]);
    delay(1000);
}
  
// Asi como esta el boton, se guarda para poder usarse en el proximo ciclo
  lastButtonState = value;
}
