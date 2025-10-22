// Smart Door System
// Opens the door for 3 seconds when someone presses the button

const int doorPin = 2;   // Relay or LED representing the door
const int buttonPin = 3; // Button or sensor input
bool doorOpen = false;

void setup() {
  pinMode(doorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("System Ready - Waiting for someone at the door...");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !doorOpen) {
    doorOpen = true;
    Serial.println("🚪 Someone detected! Opening door...");
    digitalWrite(doorPin, HIGH);
    delay(3000);
    digitalWrite(doorPin, LOW);
    Serial.println("✅ Door closed again.");
    delay(500); // Debounce delay
    doorOpen = false;
  }
}
