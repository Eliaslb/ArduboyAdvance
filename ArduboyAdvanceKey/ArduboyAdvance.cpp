#include "ArduboyAdvance.h"

ArduboyAdvance::ArduboyAdvance() {
  screen = new TFT(CS,DC,RS);
}

bool ArduboyAdvance::pressed(byte key) {
  int val = digitalRead(key);  
  if (val == 1) {
    return true;
  } else {
    return false;
  }
}

int ArduboyAdvance::held(byte key) {
  int val = pulseIn(key,HIGH);  
  return val;
}

void ArduboyAdvance::setHeldTime(int time) {
  heldTime = time;  
}

void ArduboyAdvance::init() {
  interrupts();
}

