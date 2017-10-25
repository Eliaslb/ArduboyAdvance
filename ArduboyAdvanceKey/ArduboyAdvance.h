#ifndef ARDUBOYADVANCE_H
#define ARDUBOYADVANCE_H

#include <Arduino.h>
#include <SD.h>
#include <TFT.h>
#include "Tones.h"

#define CS  10
#define DC  9
#define RS  8

#define UP
#define DOWN
#define LEFT
#define RIGHT
#define A
#define B
#define X
#define Y

#define SPEAKER1
#define SPEAKER2
#define SPEAKER3

typedef struct {
  int dur[];
  int c1[];
  int c2[];
  int c3[];  
} Song_t;

#define Tile PImage

typedef struct {
  byte r;
  byte g;
  byte b;  
} RGB_t;


typedef struct {
  byte pos[64][32];  
} Tilemap_t;

typedef struct {
  Tile tile[16]; 
} Tileset_t;

typedef struct {
  int x;
  int y;
  int w;
  int h; 
} Rect_t;

typedef struct {
  int x; 
  int y;  
} Point_t;


class ArduboyAdvance {
  
  public:
    ArduboyAdvance();

    //Main
    void init(); //Run in the setup

    void setFrameRate(byte newFps); //Set the framerate max

    int cpuLoad(); //Get the cpuload

    bool nextFrame(); 

    int everyXFrames(int frames);

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

    void drawSprite(int x, int y, PImage sprite);

    void drawTilemap(int x, int y, Tilemap_t map);

    void setTileset(Tileset_t newSet);


    bool collide(Point_t point, Rect_t rect);

    bool collide(Rect_t rect1, Rect_t rect2);


    //Sound
    void playSound(byte speaker, int note);
    
    void playSong(Song_t song);
    
  private:
    //Keys
    int heldTime; //Time needed for the key to be set to held 

    //Screen
    Tileset_t currentTileset;
    
    TFT *screen;

    //Sound
    
};


#endif //ARDUBOYADVANCE_H
