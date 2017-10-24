#ifndef ARDUBOYADVANCE_H
#define ARDUBOYADVANCE_H

#include <Arduino.h>
#include <SD.h>
#include <TFT.h>

#define UP
#define DOWN
#define LEFT
#define RIGHT
#define A
#define B
#define X
#define Y

typedef struct {
  byte r;
  byte g;
  byte b;  
} RGB_t;

class ArduboyAdvance {
  
  public:
    ArduboyAdvance();
    void init();

    //Keys
    bool pressed(byte key);
    int held(byte key); 
    void setHeldTime(int time);

    //Screen
    void clear();
    void drawPixel(int x, int y, RGB_t color);
    
    void background(byte r, byte g, byte b);
    void background(RGB_t color);

    void drawRect(int x, int y, int x2, int y2, RGB_t color);
  private:
    //Keys
    int heldTime; //Time needed for the key to be set to held 

    //Screen
};


#endif //ARDUBOYADVANCE_H
