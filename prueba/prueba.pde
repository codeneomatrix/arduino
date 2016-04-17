import cc.arduino.*;
import processing.serial.*;

Arduino arduino;

int ledpin=13;
boolean led=false;

void setup(){
  size(200,200);
  arduino=new Arduino(this,Arduino.list()[1],57600);
  arduino.pinMode(ledpin,Arduino.OUTPUT);
  arduino.digitalWrite(ledpin,Arduino.HIGH);
}
void draw(){}
  void mousePressed(){
  if(led){
    arduino.digitalWrite(ledpin,Arduino.HIGH);
  }else{
    arduino.digitalWrite(ledpin,Arduino.LOW);
  }
  led=!led;
  }