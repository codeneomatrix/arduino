import cc.arduino.*;
import processing.serial.*;

Arduino arduino;

int ledpin=13;
boolean blink=false;

void setup(){
  size(200,200);
  arduino=new Arduino(this,Arduino.list()[1],57600);
  arduino.pinMode(ledpin,Arduino.OUTPUT);
  arduino.digitalWrite(ledpin,Arduino.LOW);
}
void draw(){
if(blink){
  arduino.digitalWrite(ledpin,Arduino.HIGH);
  delay(100);
  arduino.digitalWrite(ledpin,Arduino.LOW);
  delay(100);
}else{
  arduino.digitalWrite(ledpin,Arduino.LOW);
}
}

void mousePressed(){
  blink=!blink;
}