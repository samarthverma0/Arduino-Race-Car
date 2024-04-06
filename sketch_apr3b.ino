char t;
int IN1 = 5;
int IN2 = 6;
int IN3 = 7;
int IN4 = 8;
 
void setup() {
pinMode(5,OUTPUT);   //left motors  forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(7,OUTPUT);   //right  motors forward
pinMode(8,OUTPUT);   //right motors reverse
//pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  forward();
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  backward();
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  rightturn();
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  leftturn();
}
else if (t == 'G'){
  forwardleft();
}
else if(t == 'I'){
  forwardright();
}
else{
  stop();
}

}

void forward()
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void backward()
{

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}


void leftturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
}
void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void forwardright()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void forwardleft()
{
  //ENA 1--backward 2-forward ENB 3-backward 4-forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void rightturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}