#include <IRremote.h>

const byte IR_RECEIVE_PIN = 2;

#define led1 8
#define led2 9
#define led3 10
#define led4 11

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

}

void loop() {
  if(IrReceiver.decode()){
    String ir_code = String(IrReceiver.decodedIRData.command, HEX);
    Serial.println(ir_code);

    // If delete here you can check your controller key value
    if(ir_code == "1"){
      digitalWrite(led1,HIGH);
    } else if(ir_code == "2"){
      digitalWrite(led2,HIGH);
    } else if(ir_code == "3"){
      digitalWrite(led3,HIGH);
    } else if(ir_code == "4"){
      digitalWrite(led4,HIGH);
    } else if(ir_code == "0"){
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
    }
    //
    IrReceiver.resume();
  }
}
