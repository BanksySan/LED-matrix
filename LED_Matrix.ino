const byte xPins[] = { 4, 5, 6, 7 };
const byte yPins[] = { 11, 10, 9, 8 };

const int PERIOD = 250;

const int coords1[4][2] = {
  { 0, 0 },
  { 0, 3 },
  { 3, 3 },
  { 3, 0 }
};

const int coords2[4][2] = {
  { 1, 1 },
  { 1, 2 },
  { 2, 2 },
  { 2, 1 }
};

void serialEvent() {
  switch (Serial.read()) {
    default:
      Serial.println("Unknown");
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("LED Matrix");

  for (int i = 0; i > 4; i++) {
    const int xPin = xPins[i];
    const int yPin = yPins[i];
    pinMode(xPin, OUTPUT);
    pinMode(yPin, OUTPUT);
    digitalWrite(xPin, LOW);
    digitalWrite(yPin, LOW);
  }
}

void loop() {
  writeSweep(coords1, 4U, 1000U);
  writeSweep(coords2, 4U, 500U);
}

void writeSweep(const int coords[][2], const unsigned int length, const unsigned int duration) {
  unsigned long now = millis();
  unsigned long end = now + duration;

  while (millis() < end) {
    for (byte i = 0; i < length; i++) {
      writePixel(coords[i][0], coords[i][1]);
    }
  }
}

void writePixel(int x, int y) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(xPins[i], i == x);
    for (byte j = 0; j < 4; j++) {
      digitalWrite(yPins[j], j == y);
    }
  }
}