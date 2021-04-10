#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48); // ads1115[4] = {0x48, 0x49, 0x4B, 0x4A} ;
 Adafruit_ADS1115 ads1(0x49);/* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */



void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
//   ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
   ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  ads.begin();
}

void loop(void) 
{
  int16_t adc0, adc1, adc2, adc3;
   int16_t adc11, adc12, adc13, adc14;

  adc0 = ads.readADC_SingleEnded(0);
//float  Vol0 = (adc0*0.1875)/1000;
  adc1 = ads.readADC_SingleEnded(1);
//float  Vol1 = (adc1*0.1875)/1000;
  adc2 = ads.readADC_SingleEnded(2);
//float  Vol2 = (adc2*0.1875)/1000;
  adc3 = ads.readADC_SingleEnded(3);
//float  Vol3 = (adc3*0.1875)/1000;
  
  adc11 = ads1.readADC_SingleEnded(0);
float  Vol11 = (adc11*0.1875)/1000;
  adc12 = ads1.readADC_SingleEnded(1);
float  Vol12 = (adc12*0.1875)/1000;
  adc13 = ads1.readADC_SingleEnded(2);
float  Vol13 = (adc13*0.1875)/1000;
  adc14 = ads1.readADC_SingleEnded(3);
float Vol14 = (adc14*0.1875)/1000;
  
  Serial.print("AIN0: "); Serial.println(adc0);
//  Serial.print("Vol0:");  Serial.println(Vol0);
  
  Serial.print("AIN1: "); Serial.println(adc1);
//  Serial.print("Vol1:");  Serial.println(Vol1);
  
  Serial.print("AIN2: "); Serial.println(adc2);
//  Serial.print("Vol2:");  Serial.println(Vol2);
  
  Serial.print("AIN3: "); Serial.println(adc3);
//  Serial.print("Vol3:");  Serial.println(Vol3);
  Serial.println(" ");
  
  Serial.print("AIN2: "); Serial.println(adc11);
  Serial.print("Vol11:");  Serial.println(Vol11);
  
  Serial.print("AIN2: "); Serial.println(adc12);
  Serial.print("Vol12:");  Serial.println(Vol12);
  
  Serial.print("AIN2: "); Serial.println(adc13);
  Serial.print("Vol13:");  Serial.println(Vol13);
  
  Serial.print("AIN2: "); Serial.println(adc14);
  Serial.print("Vol14:");  Serial.println(Vol14);
  Serial.println(" ");
  
  delay(3000);
}
