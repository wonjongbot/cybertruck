#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(3);



const int mtrigPin =  9 ;
const int mechoPin = 10 ;


const int ltrigPin =  5 ;
const int lechoPin = 6 ;


const int rtrigPin =  11 ;
const int rechoPin = 12 ;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  AFMS.begin();  // create with the default frequency 1.6KHz
  // set motor speed, turn them on for a moment then back off
  Serial.println("initializing");
  motor1->setSpeed(200);
  motor1->run(FORWARD);
  motor1->run(RELEASE);
  motor2->setSpeed(200);
  motor2->run(FORWARD);
  motor2->run(RELEASE);

  pinMode(mtrigPin, OUTPUT);
  pinMode(mechoPin, INPUT);

}

void loop() {
  long duration, mcm; //establish variables for duration of the ping, and the distance result incentimeters:
  long lduration, lcm;
  long rduration, rcm;
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(mtrigPin, LOW);
  digitalWrite(ltrigPin, LOW);
  digitalWrite(rtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(mtrigPin, HIGH);
  digitalWrite(ltrigPin, HIGH);
  digitalWrite(rtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(mtrigPin, LOW);
  digitalWrite(ltrigPin, LOW);
  digitalWrite(rtrigPin, LOW);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.

  duration = pulseIn(mechoPin, HIGH);
  lduration = pulseIn(lechoPin, HIGH);
  rduration = pulseIn(rechoPin, HIGH);

  // convert the time into a distance
  mcm =  duration / 29 / 2;
  lcm =  lduration / 29 / 2;
  rcm =  rduration / 29 / 2;


  Serial.print(mcm);
  Serial.print(" cm");
  Serial.println();
  
  Serial.print(lcm);
  Serial.print(" cm");
  Serial.println();
  
  Serial.print(rcm);
  Serial.print(" cm");
  Serial.println();
  
  if (mcm < 20) {
    Serial.println("backward");
    motor1->run(BACKWARD);
    motor2->run(RELEASE);
  }


  if (mcm > 20) {
    Serial.println("forward");
    motor1->run(FORWARD);
    motor2->run(FORWARD);
  }


  delay(100);
  //Serial.println("forward");
  //motor1->run(FORWARD);
  //motor2->run(FORWARD);
  //delay(2000);
  //motor1->run(RELEASE);
  //motor2->run(RELEASE);


  //Serial.println("backward");
  //motor1->run(BACKWARD);
  //motor2->run(BACKWARD);
  //delay(2000);
  //motor1->run(RELEASE);
  //motor2->run(RELEASE);
  //delay(1000);


}
