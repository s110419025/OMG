#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_MOST  11 //D1
#define OLED_CLK   12 //D0
#define OLED_DC     9 //DC
#define OLED_CS     8 //CS
#define OLED_RESET 10 //RES
Adafruit_SSD1306 display(OLED_MOST,OLED_CLK,OLED_DC,OLED_RESET,OLED_CS);

int box_x,box_y[]={28,24,26,18,25,20,18,10,5,0},space=4;//0<=y<=(32-space)
int count=0,i=0;

void drop(){
  display.clearDisplay();
  display.fillRect(127,0,1,32,WHITE);//ground

  for(box_x=0;box_x<128;box_x++){
    display.clearDisplay();
    display.fillRect(127,0,1,32,WHITE);//ground
    
    display.fillRect(box_x,0,3,box_y[i],WHITE);
    display.fillRect(box_x,box_y[i]+5,3,32-(box_y[i]+space),WHITE);
    display.display();
  }
  delay(1000);
  display.display();
  count++;
  i++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC,0x3D);
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(box_y[i]!=0)drop();
}
