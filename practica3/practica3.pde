import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

void setup(){
size(512,512);
arduino= new Arduino(this,Arduino.list()[1],57600);
}

void draw(){
background(constrain(mouseX/2,0,255));
arduino.analogWrite(11,constrain(mouseX/2,0,255));
arduino.analogWrite(9,constrain(mouseY/2,0,255));
}