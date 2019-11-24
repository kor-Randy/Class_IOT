// the number of the LED pin
const int ledPin = 16; // 16 corresponds to GPIO16
const int ledPin2 = 17; // 17 corresponds to GPIO17
const int ledPin3 = 5; // 5 corresponds to GPIO5
// setting PWM properties
const int freq1 = 5000;
const int ledChannel1 = 0;
const int resolution1 = 8;
const int freq2 = 5000;
const int ledChannel2 = 1;
const int resolution2 = 8;
const int freq3 = 5000;
const int ledChannel3 = 2;
const int resolution3 = 8;
const int buttonPin = 4;
int state = 0;
int a,b,c=0;
void setup() {
  Serial.begin(115200);
pinMode(buttonPin, INPUT);

// configure LED PWM functionalitites
ledcSetup(ledChannel1, freq1, resolution1);
ledcSetup(ledChannel2, freq2, resolution2);
ledcSetup(ledChannel3, freq3, resolution3);
// attach the channel to the GPIOs
ledcAttachPin(ledPin, ledChannel1);
ledcAttachPin(ledPin2, ledChannel2);
ledcAttachPin(ledPin3, ledChannel3);
}
void loop(){

 
// increase the LED brightness
for(int dutyCycle = 0; dutyCycle <= 1023; dutyCycle++) {
// changing the LED brightness with PWM
if(dutyCycle==255)
{
    a=1;
  }
  else if(dutyCycle==511)
  {
    b=1;
    a=0;
    }
    else if(dutyCycle==767)
    {
      a=1;
      }
if(digitalRead(buttonPin)==LOW)
{
  if(a==0)
  {
    if(dutyCycle<256)
    {
    ledcWrite(ledChannel1, dutyCycle);
    }
    else
    {
      
       ledcWrite(ledChannel1, dutyCycle-511);
      }
  }
    else
    {
      if(dutyCycle<512)
      {
      ledcWrite(ledChannel1, 255-(dutyCycle-255));
      }
      else
      {
        ledcWrite(ledChannel1, 255-(dutyCycle-767));
        }
    }

    if(b==0)
    {
      ledcWrite(ledChannel2, dutyCycle/2);
      }
      else
      {
           
            ledcWrite(ledChannel2, (1023-dutyCycle)/2);
            
            
        }

    
  ledcWrite(ledChannel3, dutyCycle/4);
  delay(15);
}
else
{
  while(true)
  {
    if(digitalRead(buttonPin)==LOW)
    {
      break;
      }
    }  
}

}
b=0;
a=0;
// decrease the LED brightness
for(int dutyCycle = 1023; dutyCycle >= 0; dutyCycle--) {

if(dutyCycle==767)
{
    a=1;
  }
  else if(dutyCycle==511)
  {
    b=1;
    a=0;
    }
    else if(dutyCycle==255)
    {
      a=1;
      }
  
// changing the LED brightness with PWM
if(digitalRead(buttonPin)==LOW)
{
  if(a==0)
  {
    if(dutyCycle>767)
    {
      ledcWrite(ledChannel1, -(dutyCycle-1023));
    }
    else
    {
      ledcWrite(ledChannel1, -(dutyCycle-511));
      }
  }
  else
  {
    if(dutyCycle>511)
    {
      
       ledcWrite(ledChannel1, -(511-dutyCycle));
      }
      else
      {
          ledcWrite(ledChannel1, dutyCycle);
        }
    }

if(b==0)
{
 ledcWrite(ledChannel2, -(dutyCycle-1023)/2);   
  }
  else
  {
       ledcWrite(ledChannel2, dutyCycle/2);   
    }
    
ledcWrite(ledChannel3, dutyCycle/4);
delay(15);
}
else
{
  while(true)
  {//HIGH
    if(digitalRead(buttonPin)==LOW)
    {
      break;
      }
    }  
}
}
}
