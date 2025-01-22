
#include <IRremote.h>

int RECV_PIN = 3;
int role=4;
int LEDPin=6,LEDPin2=9;
int hareketpin=5;
int buton=10;
int hareketenerji=12;


unsigned long timer1Start = 0;  // start time for timer 1
unsigned long timer2Start = 0;  // start time for timer 2
const long timer1Interval = 500;  // interval at which to trigger timer 1 (in milliseconds)




#define BUTON1 0xFFA25D
#define BUTON2 0xFF629D
#define BUTON3 0xFFE21D
#define BUTON4 0xFF22DD
#define BUTON5 0xFF02FD
#define BUTON6 0xFFC23D
#define BUTON7 0xFFE01F
#define BUTON8 0xFFA857
#define BUTON9 0xFF906F
#define BUTON0 0xFF9867
#define BUTONx 0xFF6897
#define BUTONk 0XFFB04F
#define BUTONu 0xFF18E7
#define BUTONd 0xFF4AB5
#define BUTONr 0xFF5AA5
#define BUTONl 0xFF10EF



IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(hareketenerji,OUTPUT);
  pinMode(buton,INPUT);
  pinMode(LEDPin2,OUTPUT);
  pinMode(hareketpin,INPUT);
  pinMode(role,OUTPUT);
  pinMode(role,OUTPUT);
  pinMode(LEDPin,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  digitalWrite(12,HIGH);
}

void loop() {
  
  unsigned long currentMillis = millis();  // get the current time
  
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(740); // Receive the next value
    
  if (currentMillis - timer1Start >= timer1Interval) {  // if the time interval has elapsed
     timer1Start = currentMillis;   // update the previous time
    Serial.println("Timer has been triggered!");  // print a message to the serial monitor
  
///////////////////
 if(results.value == BUTON1)
   digitalWrite(6,!digitalRead(6));
 
///////////////////
 if(results.value == BUTON2)
   digitalWrite(4,!digitalRead(4));

  if(results.value == BUTON3){
   digitalWrite(12,!digitalRead(12));
   digitalWrite(9,LOW);
  }
  
 if(results.value == BUTON4){
   
   
   if(digitalRead(12)==1){
     digitalWrite(12,LOW);
     digitalWrite(9,!digitalRead(9));
   }
   else{
     digitalWrite(9,!digitalRead(9));
   }
  }


  

}
 
}

if(digitalRead(5)==HIGH){
   digitalWrite(9,!digitalRead(9));
   
}

delay(10);
}





