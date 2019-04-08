const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;
const int sensor = A0;

float vout;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(sensor, INPUT);
  ledShow(10);
  Serial.begin(9600);
}

void loop() {
  vout = analogRead(sensor);
  vout = (vout * 500) / 1023; //Celcius conversion
  Serial.print(vout);
  Serial.print("\n");
  if (vout >= 0.5) {
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
  else if (vout <= -0.5) {
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  }
  else if ((vout < 0.5) && (vout > -0.5)){
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
  }
  else {
    ledShow(3); //something went wrong
  }
  delay(3000);
}

void ledShow(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(100);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(100);
    digitalWrite(redLed, LOW);
  }
}

