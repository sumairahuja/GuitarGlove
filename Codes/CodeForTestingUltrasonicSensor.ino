const int trigPin = D6;
const int echoPin = D5;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(10);
  if (distance >= 6 && distance <= 8) {
    digitalWrite(LED_BUILTIN, LOW);

  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}