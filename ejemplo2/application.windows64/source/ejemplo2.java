import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import cc.arduino.*; 
import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class ejemplo2 extends PApplet {




Arduino arduino;

int ledpin=13;
boolean blink=false;

public void setup(){
  
  arduino=new Arduino(this,Arduino.list()[1],57600);
  arduino.pinMode(ledpin,Arduino.OUTPUT);
  arduino.digitalWrite(ledpin,Arduino.LOW);
}
public void draw(){
if(blink){
  arduino.digitalWrite(ledpin,Arduino.HIGH);
  delay(100);
  arduino.digitalWrite(ledpin,Arduino.LOW);
  delay(100);
}else{
  arduino.digitalWrite(ledpin,Arduino.LOW);
}
}

public void mousePressed(){
  blink=!blink;
}
  public void settings() {  size(200,200); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "ejemplo2" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
