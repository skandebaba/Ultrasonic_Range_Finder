/* 
 *  A simple program that makes use of a HY-SFR05 to find the distance of an object 
 *  Assuming a room temp of 20 degrees centigrade
 *
 *  The circuit:
 *  VCC connection of the sensor attached to +5V
 *  GND connection of the sensor attached to GND
 *  ECHO connection of the sensor attached to 2
 *  TRIG connection of the sensor attached to 3
 *
 *  Datasheet can be found at: http://www.robot-electronics.co.uk/htm/srf05tech.htm
 */
 
//#define  INCHES    // Uncomment if you want to display inches
 
const char  ECHO_PIN = 2;
const char  TRIG_PIN = 3;

void setup(){
  // Start serial communication
  Serial.begin(9600);
  
  // Pin configuration
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  float duration, distanceCm, distanceIn;
  
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH);
  
  // Convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;
  distanceIn = duration / 74 / 2;
  
  if (distanceCm <= 0){
//    Serial.println("Out of range");
  }
  else {
    Serial.print(millis());  // Print the time in milliseconds since the program started
#ifdef INCHES
    Serial.print(',');
    Serial.print(distanceIn, 3);
#endif
    Serial.print(',');
    Serial.print(distanceCm, 3);
    Serial.println();
  }
  delay(20);
}
