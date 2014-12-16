#include "Menu.h"
#include "Arduino.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"

Menu::Menu() {

	button1 = 0;
	button2 = 0;
	button3 = 0;
	pinMode(Menu::button1Pin, INPUT);
	pinMode(Menu::button2Pin, INPUT);
	pinMode(Menu::button3Pin, INPUT);

	dtState = SETMINUTES;
	menuState = TIMEDATEEDIT;

}

void Menu::setMode(int state) {
}

void Menu::setEditionState(int state) {
}

void Menu::drawMenu() {

	Adafruit_PCD8544 display = Adafruit_PCD8544(NokiaSCLKpin, NokiaDNpin,
			NokiaDCpin, 0, NokiaRESETpin);

	display.begin();
	// init done
	// you can change the contrast around to adapt the display
	// for the best viewing!
	display.setContrast(70);

	display.display(); // show splashscreen
	delay(2000);
	display.clearDisplay();   // clears the screen and buffer

	// text display tests
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(0, 0);
	display.println("Hello, world!");
	display.setTextColor(WHITE, BLACK); // 'inverted' text
	display.println(3.141592);
	display.setTextSize(2);
	display.setTextColor(BLACK);
	display.print("0x");
	display.println(0xDEADBEEF, HEX);
	display.display();
	delay(2000);
	display.drawRect(0, 0, display.width(), display.height(), BLACK);

}

void Menu::processKeys() {

	button1 = digitalRead(button1Pin); //MODE button Variable
	button2 = digitalRead(button2Pin); //SELECT button Variable
	button3 = digitalRead(button3Pin); //MOVE button Variable
}
