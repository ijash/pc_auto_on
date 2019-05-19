

int sensorLedPin = 2;
int turnOnLedPin = 3;
int pwrSensorPin = 4;
int turnOnPin = 5;

bool isPwrLedOn = false;
bool isPwrSensorOn = false;

int afterTurnOffDelay = 6197;
int turnOnDelay = 4163;
int runningLoopDelay = 3231;

void turnOnOnce()
{
  while (digitalRead(pwrSensorPin) == false)
  {
    digitalWrite(turnOnPin, HIGH);
    digitalWrite(turnOnLedPin, HIGH);
    delay(100);
    digitalWrite(turnOnPin, LOW);
    digitalWrite(turnOnLedPin, LOW);
    delay(turnOnDelay);
  }
}

void setup()
{

  pinMode(pwrSensorPin, INPUT);
  pinMode(sensorLedPin, OUTPUT);
  pinMode(turnOnPin, OUTPUT);
  pinMode(turnOnLedPin, OUTPUT);
  delay(1000);
}

void loop()
{

  isPwrSensorOn = digitalRead(pwrSensorPin);

  if (isPwrSensorOn == false)
  {
    checkTurnOn();
  }
  else
  {
    checkPwrLed();
    delay(runningLoopDelay);
  }
}

void checkTurnOn()
{
  if (isPwrLedOn)
  {
    digitalWrite(sensorLedPin, LOW);
    isPwrLedOn = false;
    delay(afterTurnOffDelay);
  }
  else
  {
    turnOnOnce();

    digitalWrite(sensorLedPin, HIGH);
    isPwrLedOn = true;
  }
}
void checkPwrLed()
{
  if (isPwrLedOn == false)
  {
    digitalWrite(sensorLedPin, HIGH);
    isPwrLedOn = true;
  }
}