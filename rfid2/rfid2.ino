#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(9600);
  mySerial.begin (9600);
}

void loop()
{
  char i, ch, val;
  int msb, lsb, temp, csum;
  char xcode[20];
  
  if ( Serial.available() > 0 )
  {
    ch = Serial.read();
    if ( ch == 0x02 )
    {
      delay(1000);
      i = 0;
      while( Serial.available() > 0 )
      {
         xcode[i] = Serial.read();
         i++;   
         if ( i > 11 )
           break;
      } 
      xcode[i] = 0;
      i = 0;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      temp = ( msb << 4 ) + lsb;

      i = 2;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      temp ^= ( msb << 4 ) + lsb;
      i = 4;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      temp ^= ( msb << 4 ) + lsb;
      i = 6;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      temp ^= ( msb << 4 ) + lsb;
      i = 8;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      temp ^= ( msb << 4 ) + lsb;

      i = 10;
      val = xcode[i];
      if ( val >= '0' && val <= '9' )
         msb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         msb = 10 + val - 'A'; 
      val = xcode[i+1];
      if ( val >= '0' && val <= '9' )
         lsb = val - '0';
      else if ( val >= 'A' && val <= 'F' )
         lsb = 10 + val - 'A'; 
      csum = ( msb << 4 ) + lsb;
 

      if ( temp == csum )
      {
        mySerial.println(xcode);
      }  
    }  
  }
}

