
#include "LedControl.h"

LedControl lc=LedControl(12,10,11,1);

int buttonApin = 9;
int buttonBpin = 8;

bool snakeup = true;
bool snakedown = false;
bool snakeright = false;
bool snakeleft = false;

bool goleft = false;
bool goright = false;

int srow = 4;
int scol = 7;

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);  
}

void loop() 
{
  delay(500);
  lc.clearDisplay(0); 
  goleft = false;
  goright = false;
  
  
  if (digitalRead(buttonApin) == LOW)
  {
    goleft = true;
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    goright = true;
  }

  if (snakeup == true) {
    
    lc.setLed(0,srow,scol,true);
    scol -= 1;


    if (goright == true) {
      snakeright = true;
      snakeup = false;
      loop();    
    }
    if (goleft == true) {
      snakeleft = true;
      snakeup = false;
      loop();    
    }
  }

  if (snakedown == true) {
    
    lc.setLed(0,srow,scol,true);
    scol += 1;
    if (goright == true) {
      snakeleft = true;
      snakedown = false;
      loop();    
    }
    if (goleft == true) {
      snakeright = true;
      snakedown = false;
      loop();    
    }
  }
  if (snakeright == true) {
    
    lc.setLed(0,srow,scol,true);
    srow -= 1;

    if (goright == true) {
      snakedown = true;
      snakeright = false;
      loop();    
    }
    if (goleft == true) {
      snakeup = true;
      snakeright = false;
      loop();    
    }
  }
  if (snakeleft == true) {
    
    lc.setLed(0,srow,scol,true);
    srow += 1;
    if (goright == true) {
      snakeup = true;
      snakeleft = false;
      loop();    
    }
    if (goleft == true) {
      snakedown = true;
      snakeleft = false;
      loop();    
    }
  }
  
  //0,0 is top right
  //lc.setLed(0,0,0,true);
}
