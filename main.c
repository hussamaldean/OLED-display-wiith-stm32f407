/**
 This code demonstrate the usage of OLED display (SSD1306 i2c ) with stm32f4xx mcu
 The utilitiezed mcu is stm32f407vetx and the code is ddeveloped using keil uvision software 
 The code use bare metal method ( direct register manipulation ) to drive the oled display 
 The setting for the mcu was as following
 core speed =18MHz
 i2c speed = 100KHz
 
 */



#include "oled.h"
#include "test.h"
#include "bitmap.h"
#include "horse_anim.h"
#include "stdio.h"
char zz[10];
int main(void)
{

SSD1306_Init();
SSD1306_GotoXY (0,0);
	
SSD1306_Puts ("STM32", &Font_11x18, 1);
	
SSD1306_GotoXY (10, 30);
	
SSD1306_Puts ("developers:)", &Font_11x18, 1);
	
SSD1306_UpdateScreen(); //display
	
delay (2000);
	
SSD1306_ScrollRight(0,7);  // scroll entire screen

delay(2000);  // 2 sec

SSD1306_ScrollLeft(0,7);  // scroll entire screen
	
delay(2000);  // 2 sec

SSD1306_Stopscroll();
	
SSD1306_Clear();

delay(2000);

SSD1306_ScrollRight(0x00, 0x0f);    // scroll entire screen right

delay (2000);

SSD1306_ScrollLeft(0x00, 0x0f);  // scroll entire screen left

delay (2000);

SSD1306_Scrolldiagright(0x00, 0x0f);  // scroll entire screen diagonal right

delay (2000);

SSD1306_Scrolldiagleft(0x00, 0x0f);  // scroll entire screen diagonal left

delay (2000);

SSD1306_Stopscroll();   // stop scrolling. If not done, screen will keep on scrolling


SSD1306_InvertDisplay(1);   // invert the display

delay(2000);

SSD1306_InvertDisplay(0);  // normalize the display


delay(2000);
SSD1306_Clear();
SSD1306_GotoXY (0,0);
SSD1306_Puts ("variable", &Font_11x18, 1);
SSD1306_UpdateScreen();

for (int i=0; i<100;i++)
{
sprintf(zz,"%i",i);
SSD1306_GotoXY (10, 30);	
SSD1306_Puts (zz, &Font_11x18, 1);
SSD1306_UpdateScreen();
delay(100);

}


while(1)
{
SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse1,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse2,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse3,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse4,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse5,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse6,128,64,1);
SSD1306_UpdateScreen();


SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse7,128,64,1);
SSD1306_UpdateScreen();

SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse8,128,64,1);
SSD1306_UpdateScreen();


SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse9,128,64,1);
SSD1306_UpdateScreen();


SSD1306_Clear();
SSD1306_DrawBitmap(0,0,horse10,128,64,1);
SSD1306_UpdateScreen();	
	
}


}