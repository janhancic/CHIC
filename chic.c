#define NUM_LEDS 8

int leds[NUM_LEDS] = {2, 3, 4, 5, 6, 7, 8, 9};
int currentIndex = 0;
boolean up = true;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the pins as output pins
  for (int i = 0; i < NUM_LEDS; i++) {
      pinMode(leds[i], OUTPUT);
  }

}

// the loop routine runs over and over again forever:
void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(leds[i], LOW);
  }

  digitalWrite(leds[currentIndex], HIGH);


  if ( up ) {
    currentIndex++;
    if ( currentIndex >= 7 ) {
      up = false;
    }
  } else {
    currentIndex--;
    if ( currentIndex == 0 ) {
      up = true;
    }
  }

  delay (250);
}