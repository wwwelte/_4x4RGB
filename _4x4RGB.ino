#include "icon.h"

unsigned char i,j,x,y,line;
byte I[8] = 
{
  B00000000,
  B00100010,
  B01110111,
  B01111111,
  B01111111,
  B00111110,
  B00011100,
  B00001000
};

// byte IMAGES[200][8];

void setup() 
{
  // X - Achse  // PD2-7 PB0-1  //  Pin 2-13  // // Active HIGH
  DDRD |= 0b11111100;
  DDRB |= 0b00000011; 
  DDRB |= 0b00111100; 
  
  PORTD &= ~0b11111100;
  PORTB &= ~0b00000011; 
  PORTB &= ~0b00111100;
  
  // Y - Achse  // PB2-5 PC0-3 // Pin 14-17(A3) // Active LOW
  DDRC  |= 0b00001111;
  PORTC |= 0b00001111;

// Serial.begin(9600);
}

void loop()
{
  //testloop();
  // bitTest();

    testLine();
}

void testLine()
{
  //I = IMAGES[line];
  if (i++ > 25) { i = 0; if(j++ > 100) { j = 0; } }
    
  for ( line = 0; line < 4 ; line++ )
  {
    //  x = (  IMAGES[line] << (1 * line) );
    // x = (  xx << (1 * line) );
    PORTD &= ~0b11111100;
    PORTB &= ~0b00111111;
    PORTC |= 0b00001111;
    
    PORTD |= ( IMAGES[j][line] << 2 );    // X Zeile n -- Muster SETZEN
    PORTB |= ( IMAGES[j][line] >> 2 ); 

 
         if ( line == 0 ) { PORTC &= ~0b00000001; }  // Y 4 EIN
    else if ( line == 1 ) { PORTC &= ~0b00000010; }  // Y 5 EIN
    else if ( line == 2 ) { PORTC &= ~0b00000100; }  // Y 6 EIN
    else if ( line == 3 ) { PORTC &= ~0b00001000; }  // Y 7 EIN
    //Serial.println( IMAGES[line], BIN ); 
   delay(2);
  }

}

void bitTest()
{
  for ( i = 2; i > 8; i++ )
  {
    PORTB &= ~ 0b00111100; // Y  AUS
    PORTC &= ~ 0b00001111; // Y  AUS

    PORTD |= 0b11111100;    // X Zeile Muster AN
    // PORTD |= 
    //  PORTB |= 0b00000011; 

    PORTB |= 0b00111100;   // Y  EIN
    PORTC |= 0b00001111;   // Y  EIN

    PORTD &= ~( 1 << i );  // X Zeile Muster AUS
    delay(100);
  } 
}

void testloop()
{
  for( x = 10; x < 19; x++ )   // HIGH Active
  {
    for ( y = 2; y < 10; y++ ) // LOW Active
    {
      digitalWrite( x, 0 );
      digitalWrite( y, 1 );
      delay( 50 );
      digitalWrite( y, 0 );      
      digitalWrite( x, 1 ); 
    }
  } 
}
