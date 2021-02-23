//digital potentiometer using SPI and changing brightness of LED using voltage input instead of PWM
//Include SPI library
#include <SPI.h>

//By Default, 11 = MOSI, 12 = MISO, 13 = CLK set automatically
int SS = 10;   //SPI Slave Select

void setup()
{
  
  //Set Pin Directions
  pinMode(SS, OUTPUT);
  
  //Initialize SPI
  SPI.begin();
  
}

//fxn to set led to the specififed level
void setLed(int reg, int level)//4 registers available
{
  digitalWrite(SS, LOW);
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SS, HIGH);
}

void loop()
{
  for(int i=0; i<=2; i++) //each led rises to full brightness then to 0 and then moves to the next one
  {
    for (int j=50; j<=255; j++)
    {
      setLed(i,j);
      delay(20);
    }
    delay(500);
    for (int j=255; j>=50; j--)
    {
      setLed(i,j);
      delay(20);
    }
  }
}
