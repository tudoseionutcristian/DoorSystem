const int trigPin = 12;
const int echoPin = 13;
const int enA = 10;
const int in1 = 6;
const int in2 = 7;
bool usa = 0;
// defines variables
long duration;
int distance;
int errUp = 0;
int errUnder = 0;

void setup() {
  
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
//digitalWrite(in1, LOW);
//digitalWrite(in2, HIGH);
 
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
// Calculating the distance
distance= duration*0.034/2;
analogWrite(enA, 255);
if( usa == 0 && distance >= 20)
{
digitalWrite(in1,LOW );
digitalWrite(in2,LOW);
}
else
if(usa == 0 && distance < 19)
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    usa = 1;
    delay(1000);
    errUp = 0;
}
else
if(usa == 1 && distance >=19)
{
    digitalWrite(in1,LOW );
    digitalWrite(in2, HIGH);
    usa = 0;
    delay(1000);
    errUnder = 0;
}

if(usa == 1 && distance < 19)
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

Serial.print("Distance: ");
Serial.print(distance);
Serial.print(" Usa: ");
Serial.println(usa);
}
