
#pragma GCC optimize ("-O0")

#define PIR_MOTION_SENSOR 8 //Use pin 2 to receive the signal from the module

int statusLed = 17;
int movementLed = A0;

volatile byte detected = LOW;
volatile int movementCount = 0;

int counter = 0;

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, LOW);

  pinMode(movementLed, OUTPUT);
  digitalWrite(movementLed, LOW);

  pinMode(PIR_MOTION_SENSOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIR_MOTION_SENSOR), (voidFuncPtr)movement, CHANGE);
}

// the loop function runs over and over again forever
void loop()
{
  counter++;

  uint8_t state = counter % 2;

  digitalWrite(statusLed, state);

  delay(500);
}

void movement()
{
  detected = digitalRead(PIR_MOTION_SENSOR);
  digitalWrite(movementLed, detected);

  if (detected == HIGH)
  {
    movementCount++;
  }
}
