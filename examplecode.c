

#define KEY_LEFT_CTRL	0x01
#define KEY_LEFT_SHIFT	0x02
#define KEY_RIGHT_CTRL	0x10
#define KEY_RIGHT_SHIFT	0x20

uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */

#define PIN 7

int state = 1;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN, INPUT);
  // Enable internal pull-ups

  digitalWrite(PIN, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL; 
    buf[2] = 23;  
    Serial.write(buf, 8);
    releaseKey();
    
    buf[2] = 12;
    Serial.write(buf, 8);
    releaseKey();
    
    buf[2] = 10;
    Serial.write(buf, 8);
    releaseKey();
    
    buf[2] = 17;
    Serial.write(buf, 8);
    releaseKey();
    
    buf[2] = 40;
    Serial.write(buf, 8);
    releaseKey();
    
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
  delay(1000);
}
