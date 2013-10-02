#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

volatile int count = 0;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, riser, RISING);
  emon1.current(1, 111.1);             // Current: input, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.print(Irms*120.0);	       // Apparent power
  Serial.print(" ");
  Serial.print(Irms);		       // Irms
  Serial.print(" ");
  Serial.println(count);
  
  delay(500);
}

void riser()
{
  count++;
}
