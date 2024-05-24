#include <IRremote.hpp>
enum relayPins {
  relay_1 = 12,
  relay_2 = 11,
  relay_3 = 10,
  relay_4 = 9
};
enum switchPins
{
  pushButtonSwitch1 = 8,
  pushButtonSwitch2 = 7,
  pushButtonSwitch3 = 6,
  pushButtonSwitch4 = 5
};


int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);

int pushButtonState1 = 0; 
int pushButtonState2 = 0; 
int pushButtonState3 = 0; 
int pushButtonState4 = 0;

void setup() 
{
  configurePins();
}

void relayOnOff(int relay){

    switch(relay){
      case 1: 
             if(pushButtonState1 == 0){
              digitalWrite(relay_1, HIGH); 
              pushButtonState1 = 1;
              }
             else{
              digitalWrite(relay_1, LOW); 
              pushButtonState1 = 0;
              }
             delay(100);
      break;
      case 2: 
             if(pushButtonState2 == 0){
              digitalWrite(relay_2, HIGH); 
              pushButtonState2 = 1;
              }
             else{
              digitalWrite(relay_2, LOW); 
              pushButtonState2 = 0;
              }
             delay(100);
      break;
      case 3: 
             if(pushButtonState3 == 0){
              digitalWrite(relay_3, HIGH);
              pushButtonState3 = 1;
              }else{
              digitalWrite(relay_3, LOW); 
              pushButtonState3 = 0;
              }
             delay(100);
      break;
      case 4: 
             if(pushButtonState4 == 0){
              digitalWrite(relay_4, HIGH); 
              pushButtonState4 = 1;
              }
             else{
              digitalWrite(relay_4, LOW); 
              pushButtonState4 = 0;
              }
             delay(100);
      break;
           
      default : break;      
      }
  
}


void loop() {     
     
    if (digitalRead(pushButtonSwitch1) == LOW){
      delay(200);
      relayOnOff(1);      
    }
    else if (digitalRead(pushButtonSwitch2) == LOW){
      delay(200);
      relayOnOff(2);
    }
    else if (digitalRead(pushButtonSwitch3) == LOW){
      delay(200);
      relayOnOff(3);
    }
    else if (digitalRead(pushButtonSwitch4) == LOW){
      delay(200);
      relayOnOff(4);
    }

      if (IrReceiver.decode()) {
        auto value= IrReceiver.decodedIRData.decodedRawData; 
      Serial.print("Decoded IR Signal: ");
      Serial.println(value, HEX);
         switch(value){
          case 0xEF10BF00: 
                    relayOnOff(1);
          break;
          case 0xEE11BF00: 
                    relayOnOff(2);
          break;
          case 0xED12BF00: 
                    relayOnOff(3);
          break;
          case 0xEB14BF00: 
                    relayOnOff(4);
          break;
          default : break;      
          }    
    irrecv.resume(); 
    }
  }
void configurePins() 
{
   Serial.begin(9600);
  irrecv.enableIRIn();  
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);

  pinMode(pushButtonSwitch1, INPUT_PULLUP);
  pinMode(pushButtonSwitch2, INPUT_PULLUP);
  pinMode(pushButtonSwitch3, INPUT_PULLUP);
  pinMode(pushButtonSwitch4, INPUT_PULLUP);
}