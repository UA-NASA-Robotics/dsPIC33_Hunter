/*
    dsPIC33EP512GM604
*/

#include "Config.h"
#include <stdbool.h>
#include <xc.h>
#include "Initialize.h"

#define FCY 60000000UL

#include <libpic30.h>

#define DelayVal 50

#include "TinierScreen.h"
#include "GraphicsBuffer.h"

/* * * * * * * * * * 0.42" OLED * * * * * * * * * */
#define OLED_042_WIDTH 72
#define OLED_042_HEIGHT 40
TinierScreen display042 = TinierScreen(TinierScreen042);
GraphicsBuffer screenBuffer042 = GraphicsBuffer(OLED_042_WIDTH, OLED_042_HEIGHT, colorDepth1BPP);

void showBinary(uint8_t n);
void floatText();
void whatSethHad();

int pos = 0; // current position
int xMax, yMax, x = 0, y = 0;

int main(void)
{
    bufferBegin();
    if (bufferBegin()) {
      //memory allocation error- buffer too big!
    }
    setFont(thinPixel7_10ptFontInfo);
    
    //__delay_ms(50);
    Start_Initialization();
    //SYSTEM_Initialize();
    
    while(1) {
        
        floatText(OLED_042_PORT, display042, screenBuffer042, "0.42\"");
//      whatSethHad();
    }
}

void showBinary(uint8_t n) {
    LED1 = n;
    LED2 = n >> 1;
    LED3 = n >> 2;
    LED4 = n >> 3;
    LED5 = n >> 4;
    LED6 = n >> 5;
    LED7 = n >> 6;
    LED8 = n >> 7;
}

void floatText(int port, TinierScreen screen, GraphicsBuffer &buffer, char *text) {
  // get the buffer size passed to the function to determine screen dimensions
  int bufferSize = getBufferSize();

  int padding_w = 0;  // how many pixels will go offscreen past the left and right sides
  int padding_h = 0;  // how many pixels will go offscreen past the top and bottom sides

  // each byte in the buffer holds data for 8 pixels (one per byte)
  // because of this, the buffer size is determined by 1/8th the
  // value of the ((display width) * (display_height))
  if (bufferSize == OLED_042_WIDTH * (OLED_042_HEIGHT >> 3)) {        // 0.42" OLED
    xMax = OLED_042_WIDTH + padding_w - getPrintWidth(text);   // set x bounds
    yMax = OLED_042_HEIGHT + 0 - getFontHeight();              // set y bounds
  }

  x = pos % xMax; if ((pos / xMax) & 1) x = xMax - x;
  y = pos % yMax; if ((pos / yMax) & 1) y = yMax - y;
  x -= padding_w >> 1; // subtract half of the width padding value from the x-coordinate
  y -= padding_h >> 1; // subtract half of the height padding value from the y-coordinate

  clear();             // clear the graphics buffer
  setCursor(x, y);     // set the cursor in the buffer to write text
  print(text);   // the text to be printed
  writeBuffer(getBuffer(), getBufferSize()); // write buffer to the screen
}

void whatSethHad() {
    LED1 = ON;
    __delay_ms(DelayVal);
    LED2 = ON;
    __delay_ms(DelayVal);
    LED3 = ON;
    __delay_ms(DelayVal);
    LED4 = ON;
    __delay_ms(DelayVal);
    LED5 = ON;
    __delay_ms(DelayVal);
    LED6 = ON;
    __delay_ms(DelayVal);
    LED7 = ON;
    __delay_ms(DelayVal);
    LED8 = ON;
    __delay_ms(DelayVal);

    LED1 = OFF;
    __delay_ms(DelayVal);
    LED2 = OFF;
    __delay_ms(DelayVal);
    LED3 = OFF;
    __delay_ms(DelayVal);
    LED4 = OFF;
    __delay_ms(DelayVal);
    LED5 = OFF;
    __delay_ms(DelayVal);
    LED6 = OFF;
    __delay_ms(DelayVal);
    LED7 = OFF;
    __delay_ms(DelayVal);
    LED8 = OFF;
    __delay_ms(DelayVal);
}