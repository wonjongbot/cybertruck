#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(3);



const int trigPin1 =  9 ;
const int echoPin1 = 10 ;


const int trigPin2 = 5 ;
const int echoPin2 = 6 ;


const int trigPin3 =  11 ;
const int echoPin3 = 12 ;

long duration, cm, UltraSensor1, UltraSensor2, UltraSensor3; //establish variables for duration of the ping, and the distance result incentimeters:

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

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);


}

void loop() {

  SonarSensor(trigPin1, echoPin1);
  UltraSensor1 = cm;
  SonarSensor(trigPin2, echoPin2);
  UltraSensor2 = cm;
  SonarSensor(trigPin3, echoPin3);
  UltraSensor3 = cm;
   


  Serial.print(UltraSensor1);
  Serial.print(" cm");
  Serial.println();
  
  Serial.print(UltraSensor2);
  Serial.print(" cm");
  Serial.println();
  
  Serial.print(UltraSensor3);
  Serial.print(" cm");
  Serial.println();
  
 if (UltraSensor1 < 20) {
    Serial.println("backward");
    motor1->run(BACKWARD);
    motor2->run(RELEASE);
  }


  if (UltraSensor1 > 20) {
    Serial.println("forward");
    motor1->run(FORWARD);
    motor2->run(FORWARD);
  }


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

void SonarSensor (int trigPinSensor, int echoPinSensor){
  digitalWrite(trigPinSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor, LOW);
  duration = pulseIn(echoPinSensor, HIGH);
  cm = (duration/2)/29.1;
}
