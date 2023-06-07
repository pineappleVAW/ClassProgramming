/*  This code was written for the Stitch the Loop e-textiles curriculum by the
Exploring Computer Science e-textiles team. ECS 2018 GPL V3 for non commercial use.  
ECS 2018 CC- BY NC SA.  */

/*
◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
This program is an EXAMPLE of the many possible solutions.  This code will compile as is.
◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇

*/
/*  STUDENT META HERE
STUDENT NAME(S) Vincent Whitney
 Date Written
Brief description of what program does here.
*/


/*
 This is an example of code that ECS leaders used to make 
 lights blink in four different ways with a pizza cart 
 (four lights on the umbrella). 
 Lights were attached to pins 2, 3, 10, and 9.
 We used the two button switches on the Circuit Playground 
 (connected to 4 & 19).
 */

 // The first section is where to declare global objects and call up additional files the program needs to use.  
 
int led1 = 10; //We named each led to make it easier to code
int led2 = 9;
int led3 = 12;
int switch1 = 4;
int switch2 = 19; //We named our switches 
int delaytime1 = 50; //We also created a fun variable that makes it easier to
//change the speed of one blinking pattern


void setup() {
  // The second section is for things that only need to be done once at the beginning of the program.  
  
  Serial.begin(9600);   //start serial connection
  pinMode(switch1, INPUT); //Set switches to inputs
  pinMode(switch2, INPUT);
  pinMode(led1, OUTPUT); //Set lights to outputs
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);
}

void loop() {
 /* The third section is for things that happen repeatedly in the program loop
while the program is running. The code is executed in the order coded. */
 
  int switch1storage = digitalRead(switch1);
  int switch2storage = digitalRead(switch2);
  Serial.println(switch1storage, switch2storage);
  /*The three lines above make the computer 1) look at 
    whether the switches are open (i.e., "read" them)
    and print 1 or 0 to the serial monitor so we can look at them 
 */
  delay (100); //delay for 1/10 of a second every time it reads the switches
  if (switch1storage == HIGH && switch2storage == HIGH) { //if both switches are off
    blinkingPattern1();
  }
  else if (switch1storage == HIGH && switch2storage == LOW){ //if switch1 is off and switch2 is on
   blinkingPattern2(); 
  }

  else if (switch1storage == LOW && switch2storage == HIGH){ //if switch1 is on and switch2 is off
    blinkingPattern3();
  }
  else { //or if both switches are on
    allOff();
  }
}

// The fourth section is for functions that are called up by the third section.
/*Below we say what each blinking pattern does using 
 "functions" or "procedures" in Arduino.
 - blinkingPattern1 turns each light on in turn, 
 and then goes backwards to turn each one off.
 (If we want this pattern to go faster or slower 
 we just change the value of "delaytime1" in the 
 NAMING SECTION at the top).
 - blinkingPattern2 blinks  all the lights on 
 and off
 - blinkingPattern3 turns all the lights on
 - Alloff turns all the lights off
 */
void blinkingPattern1(){ 
 digitalWrite(led1, HIGH);   
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 delay(delaytime1);
 digitalWrite(led2, HIGH);    
 delay(delaytime1);
 digitalWrite(led2, LOW);  
 delay(delaytime1);
 digitalWrite(led3, HIGH);   
 delay(delaytime1);
 digitalWrite(led3, LOW);  
 delay(delaytime1);
  digitalWrite(led3, HIGH);   
 delay(delaytime1);
 digitalWrite(led3, LOW);  
 delay(delaytime1);
 digitalWrite(led2, HIGH);   
 delay(delaytime1);
 digitalWrite(led2, LOW);  
 delay(delaytime1);
 digitalWrite(led1, HIGH);   
 delay(delaytime1);
 digitalWrite(led1, LOW); 
 delay(delaytime1);
}

void blinkingPattern2()
{ 
 digitalWrite(led1, HIGH);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, HIGH); 
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, LOW);
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 digitalWrite(led2, HIGH);  
 digitalWrite(led3, LOW);
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, LOW);
 delay(delaytime1);
}

void blinkingPattern3(){ 
 digitalWrite(led1, HIGH);   
 delay(delaytime1);
 digitalWrite(led2, HIGH);   
 delay(delaytime1);
 digitalWrite(led2, HIGH);   
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, LOW);
 delay(delaytime1);
 digitalWrite(led3, HIGH);   
 delay(delaytime1);
 digitalWrite(led2, HIGH);   
 delay(delaytime1);
 digitalWrite(led1, HIGH);   
 delay(delaytime1);
 digitalWrite(led1, LOW);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, LOW);
 delay(delaytime1);
}

void allOff(){
 digitalWrite(led1, LOW);  
 digitalWrite(led2, LOW);  
 digitalWrite(led3, LOW); 
}


