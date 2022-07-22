
const int led1=3;
const int trigPin = 4;
const int echoPin = 5;
const int rain = 6;
const int led2 = 7;




//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(rain, INPUT); 
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_VELOCITY/2;  
  
  distanceInch = distanceCm * CM_TO_INCH; 
  
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
 
   if(distanceCm<50)
   {
    
    digitalWrite(led1,LOW);
    Serial.println("OBSTACLE DETECTED");
delay(4000);
   }
   else
   { 
    digitalWrite(led1,HIGH);
    Serial.println("NO OBSTACLE");

   }
   if(digitalRead(rain)==LOW)
   {   
 
    digitalWrite(led2,LOW);
    Serial.println("WATER  DETECTED");
    delay(3000);
   }
   else
   { 
    digitalWrite(led2,HIGH);
    Serial.println("NO WATER");

  delay(1000);
}
}
