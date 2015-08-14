#include <r0ketlib/display.h>
#include <r0ketlib/print.h>
#include <r0ketlib/keyin.h>
#include <r0ketlib/itoa.h>
#include <rad1olib/pins.h>

#include <rad1olib/light_ws2812_cortex.h>
#include <rad1olib/setup.h>
#include <r0ketlib/display.h>

//# MENU ws2812b
void ws1812b_menu(){
    uint8_t pattern2[] = {
                     0, 255, 0,
                     0, 255, 0,

                     128,   0,   255,
                     128,   0,   255,
                     128,   0,   255,
                     128,   0,   255,
                     128,   0,   255,
                     255, 0,   128
                     };
    uint8_t pattern[] = {
                     255, 255, 0,
                     255, 255, 0,

                     0,   0,   255,
                     0,   0,   255,
                     0,   0,   255,
                     0,   0,   255,
                     0,   0,   255,
                     255, 0,   0
                     };

    uint8_t green[] = {255, 0, 0};
	getInputWaitRelease();
    //cpu_clock_set(17);
	SETUPgout(RGB_LED);

	uint8_t speed=51;
cpu_clock_set(speed);
	while(1){
		lcdClear(0xff);
		lcdPrintln("WS2812B test");
		lcdPrintln("UP: pattern");
		lcdPrintln("DOWN: green");
		lcdPrintln("ENTER: exit");
		lcdPrintln("Speed:");
		lcdPrintln(IntToStr(speed, 3, ' '));
		lcdDisplay();

		switch(getInput()){
			case BTN_UP:
                ws2812_sendarray(pattern, sizeof(pattern));
				break;
			case BTN_DOWN:
                ws2812_sendarray(pattern2, sizeof(pattern2));
				break;
			case BTN_LEFT:
				--speed;
		cpu_clock_set(speed);
				break;
			case BTN_RIGHT:
				++speed;
		cpu_clock_set(speed);
				break;
			case BTN_ENTER:
				return;
				break;
		};
	};
	return;
};
