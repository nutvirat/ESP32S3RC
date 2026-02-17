#include <Arduino.h>
#include "Motor.h"
#include "WARC.h"

void setup()
{
  Serial.begin(115200);
  motorsetup();
  warcSetup();
}

void loop()
{
  warcLoop();
}