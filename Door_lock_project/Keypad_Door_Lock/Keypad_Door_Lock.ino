#include <Password.h> 
#include <Keypad.h>
#include<Servo.h>
Servo servo;
Password password = Password( "3333" );

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 9,8,7,6 };
byte colPins[COLS] = { 5,4,3,2, };


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  Serial.begin(9600);
  servo.attach(11);
  keypad.addEventListener(keypadEvent); 
  }

void loop(){
  keypad.getKey();
}

void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
  Serial.print("Pressed: ");
  Serial.println(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    case '#': password.reset(); break;
    default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    servo.write(0);

   Serial.println("CORRECT OPENED");
  }else{
    servo.write(90);
    Serial.println("WRONG CLOSED");
    
  }
}                                                                                                            //  created by ( science is science 2005 )
