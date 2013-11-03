#include <avr/io.h>
#include <util/delay.h>

int speakerPin = 9;
int length = 15;
char notes[] = "ccggaagffeeddc ";
//char notes[] = "cfcfcfcfcf";
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; 
int tempo = 300;

int main (void) 
{
  DDRB |= _BV(DDB5);
  
  while(1) {
      int i;
      for(i = 0; i < length; i++) {
	  if (notes[i] == ' ') {
	      delay_ms(beats[i] * tempo);	      
	      //_delay_ms(300);
	  } else {
	      playNote(notes[i], beats[i] * tempo);
	  }
	  
	  //_delay_ms(300);
	  delay_ms(tempo/2);
      }
  }	
}


void playTone(int tone, int duration) {
    long i;
    for (i = 0; i < duration * 1000L; i += tone*2) {
	PORTB |= _BV(PORTB5);		
	//delayMicroseconds(tone);
	delay_us(tone);
	//_delay_ms(200);
	PORTB &= ~_BV(PORTB5);	
	//_delay_ms(200);
	delay_us(tone);
	//delayMicroseconds(tones[i],duration);
    }
}


void playNote(char note, int duration){
    char names[] = {'c','d','e','f','g','a','b','c'};
    int tones[] = {1915,1700,1519,1432,1275,1136,1014,956};
    int i;
    for (i=0;i<8;i++){
      if (names[i]==note){
	  playTone(tones[i],duration);
      }
    }
}

void delay_ms(uint16_t count) {
  while(count--) {
    _delay_ms(1);

  }
}

void delay_us(uint16_t count) {
  while(count--) {
    _delay_us(1);

  }
} 