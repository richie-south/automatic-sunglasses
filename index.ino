#include <Servo.h>

Servo myservo;
const int pResistor = A1;
int pos = 0;
int value;
boolean isOpen = true;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(pResistor, INPUT);
  close();
}

void open() {
  if (!isOpen) {
    isOpen = true;
    for (pos = 170; pos >= 70; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}

void close() {

  if (isOpen) {
    isOpen = false;
    for (pos = 70; pos <= 170; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}

void loop() {
  value = analogRead(pResistor);
   Serial.println(value);
  delay(100);
  if (value > 200) {
    open();
  } else {
    close();
  }
}
