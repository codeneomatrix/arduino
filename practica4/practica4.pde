import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

color off = color(0,0,0);
color on=color(49,229,71);

int[] values= {arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW,arduino.LOW};

void setup(){
size(470,200);
arduino= new Arduino(this,Arduino.list()[1],57600);
for(int i=0; i<=13;i++){
arduino.pinMode(i,Arduino.OUTPUT);
}
}

void draw(){
background(off);
stroke(on);
for(int i=0; i<=13;i++){
if(values[i]==Arduino.HIGH){
  fill(on);
  rect(i*30+31,75,20,20);
}else{
  fill(off);
  rect(i*30+31,75,20,20);
}
}

}

void mousePressed(){
int pin=(((mouseX-470)/30)+13);
if(values[pin]==Arduino.LOW){
  arduino.digitalWrite(pin,Arduino.HIGH);
  values[pin]=Arduino.HIGH;
}
else{
arduino.digitalWrite(pin,Arduino.LOW);
  values[pin]=Arduino.LOW;
}
}