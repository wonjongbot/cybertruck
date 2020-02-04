
const int left_trigPin =  5 ;
const int left_echoPin = 6 ;

const int trigPin =  9 ;
const int echoPin = 10 ;

//const int right_trigPin =  5 ;
//const int right_echoPin = 6 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);        
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   // pinMode(right_trigPin, OUTPUT);
 // pinMode(right_echoPin, INPUT);
    pinMode(left_trigPin, OUTPUT);
  pinMode(left_echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, cm;
  long left_duration, left_cm;
//  long right_duration, right_cm;

  digitalWrite(trigPin, LOW);
  digitalWrite(left_trigPin, LOW);
  //digitalWrite(right_trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  digitalWrite(left_trigPin, HIGH);
 // digitalWrite(right_trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    digitalWrite(left_trigPin, LOW);
   //   digitalWrite(right_trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
    
  left_duration = pulseIn(left_echoPin, HIGH);

    
  //right_duration = pulseIn(right_echoPin, HIGH);

   cm =  duration / 29 / 2;
      left_cm =  left_duration / 29 / 2;
//   right_cm =  right_duration / 29 / 2;

   

  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

 
  Serial.print(left_cm);
  Serial.print(" cm");
  Serial.println(); 


  //Serial.print(right_cm);
  //Serial.print(" cm");
  //Serial.println();
  
}
