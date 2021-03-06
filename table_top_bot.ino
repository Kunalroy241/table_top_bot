//Arduino Project
//two wheel
//Table Top Bot Using Two Ultrasonic sensors

const int trigPin=11; // initializing ultrasonic sensor1 trig pin(front)
const int echoPin=10; //initializing ultrasonic sensor1 echo pin(front) 
const int trigPin1=6; //initializing ultrasonic sensor2 trig pin(side)
const int echoPin1=9; //ultrasonic sensor2 echo pin(side)
long duration,duration1; //variable to calculate time
int distance,distance1; //variable to calculate distance

void setup() 
{
  pinMode(trigPin,OUTPUT);//set trig pin as output
  pinMode(echoPin,INPUT);//set echo pin as input to capture the reflected waves
  pinMode(trigPin1,OUTPUT);
   pinMode(echoPin1,INPUT);
  pinMode(2,OUTPUT);//enable 1 of motor driver
  pinMode(4,OUTPUT);//left motor
  pinMode(7,OUTPUT);//left motor
  pinMode(8,OUTPUT);//right motor
  pinMode(12,OUTPUT);//right motor
  pinMode(13,OUTPUT);//enable 2 of motor driver
  pinMode(5,OUTPUT);//vcc of front sensor
  pinMode(3,OUTPUT);//vcc of side sensor
  digitalWrite(13,HIGH);//set enable pin 1 of motor driver as high
  digitalWrite(2,HIGH);//set enable pin 2 of motor driver as high
  digitalWrite(5,HIGH);//set vcc as high
  digitalWrite(3,HIGH);//set vcc as high
  Serial.begin(9600);//to begin serial monitor
}
void forward()
{
  //set motor pins as high and low for forward movement of bot
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
}
void backward()
{
   //set motor pins as high and low for reverse movement of bot
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
}
void right()
{
  //set motor pins as high and low for right movement of bot
  digitalWrite(12,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
}
void left()
{
  //set motor pins as high and low for left movement of bot
  digitalWrite(12,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
}
void stop()
{
  //set motor pins as high and low to stop the bot
  digitalWrite(12,LOW);
  digitalWrite(8,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
}

void loop() 
{
 digitalWrite(trigPin,LOW);//to reset the front sensor
 delayMicroseconds(2);
 digitalWrite(trigPin1,LOW);//to reset the side sensor
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);//to send the ultrasonic wave 
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);//to stop sending waves
 duration=pulseIn(echoPin,HIGH);//pulse in returns the time 
 distance=duration*0.034/2;// to calculate the distance
 Serial.print("Distance:");// to print the distance
 Serial.print(distance);// to print the distance
  digitalWrite(trigPin1,HIGH);//same as the front sensor
 delayMicroseconds(10);
 digitalWrite(trigPin1,LOW);
 duration1=pulseIn(echoPin1,HIGH);
 distance1=duration1*0.034/2;
 Serial.print("Distance side:");
 Serial.print(distance1);
 if((distance<=10)&&(distance1<=10))//condition to move forward
 forward();//calling forward function
 if((distance>10)||(distance1>10))//condition to prevent falling
 {
  backward();//calling backward function
  delay(500);//delay in time
  right();//calling right function
  delay(500);//delay in time
  forward();//calling forward function
  
 }
}


