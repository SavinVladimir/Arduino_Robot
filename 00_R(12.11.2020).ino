#include "IRremote.h"

#define UP1 2
#define DOWN1 7
#define UP2 3
#define DOWN2 6

IRrecv irrecv(11); // указываем вывод, к которому подключен приемник

decode_results results;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(UP1,OUTPUT);
  pinMode(DOWN1,OUTPUT);
  pinMode(UP2,OUTPUT);
  pinMode(DOWN2,OUTPUT);
  irrecv.enableIRIn(); // запускаем прием
}

void loop() {
  int go = 1;
  int d = -1;
  while (go == 1){
    if ( irrecv.decode( &results )) { // если данные пришли
      switch ( results.value ) {
      case 0xFF18E7: /*вперёд*/
          d = 0;
          
          break;
      case 0xFF4AB5: /*назад*/
          d = 1;
          
          break;
      case 0xFF10EF: /*влево*/
          d = 2;
          
          break;
      case 0xFF5AA5: /*вправо*/
          d = 3;
          
          break;
      case 0xFF38C7: /*cтоп*/
          d = 4;
          
          break;
      }
      if (d == 0){
        digitalWrite(UP1, HIGH);
        digitalWrite(UP2, HIGH);
        delay(250);
      }
      else if (d == 1){
        digitalWrite(DOWN1, HIGH);
        digitalWrite(DOWN2, HIGH);
        delay(250);
      }
      else if (d == 2){
        digitalWrite(UP1, HIGH);
        digitalWrite(DOWN2, HIGH);
        delay(250);
      }
      else if (d == 3){
        digitalWrite(UP2, HIGH);
        digitalWrite(DOWN1, HIGH);
        delay(250);
      }
      else if (d == 4){
        digitalWrite(UP1, LOW);
        digitalWrite(UP2, LOW);
        digitalWrite(DOWN1, LOW);
        digitalWrite(DOWN2, LOW);
        delay(250);
      }

          
      irrecv.resume(); // принимаем следующую команду
    } 
  }
}
