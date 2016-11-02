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

static const unsigned char PROGMEM runright1[]={
  0x08,0x00,
  0x64,0x3c,
  0x78,0x40,
  0x1f,0x80,
  0x18,0xe0,
  0x04,0x10,
  0x00,0x08,
  0x00,0x06,
};
static const unsigned char PROGMEM runright2[]={
  0x00,0x00,
  0x60,0x00,
  0x7e,0x3e,
  0x0f,0xe0,
  0x00,0x20,
  0x00,0x30,
  0x00,0x00,
  0x00,0x00,
};
static const unsigned char PROGMEM runright3[]= {
  0x00,0x00,
  0x00,0x00,
  0x60,0x00,
  0x7c,0x60,
  0x0f,0xf8,
  0x00,0x02,
  0x00,0x00,
  0x00,0x00,
};

static const unsigned char PROGMEM runleft1[]={
  0x00,0x06,
  0x00,0x08,
  0x04,0x10,
  0x18,0xe0,
  0x1f,0x80,
  0x78,0x40,
  0x64,0x3c,
  0x08,0x00,
};
static const unsigned char PROGMEM runleft2[]={ 
  0x00,0x00,
  0x00,0x00,
  0x00,0x30,
  0x00,0x20,
  0x0f,0xe0,
  0x7e,0x3e,
  0x60,0x00,
  0x00,0x00,
};
static const unsigned char PROGMEM runleft3[]={
  0x00,0x00,
  0x00,0x00,
  0x00,0x00,
  0x00,0x02,
  0x0f,0xf8,
  0x7c,0x60,
  0x20,0x00,
  0x00,0x00,
};

static const unsigned char PROGMEM stand[]={
  0x00,0x00,
  0x00,0x00,
  0x00,0x00,
  0x7f,0xfe,
  0x3f,0xfc,
  0x00,0x02,
  0x00,0x00,
  0x00,0x00,
};

int box_x=0,box_y[]={8,24,20,18,25,20,7,10,5,0},space=8;//0<=y<=(32-space)
int man_y,manstate=0;
int count=0,i=0;

int buttonright = 6;
int buttonleft = 7; 
int buttonrightstate = 0;
int buttonleftstate = 0;

void draw(){
  display.clearDisplay();
  display.fillRect(127,0,1,32,WHITE);//ground

  //sky
  display.fillRect(box_x,0,3,box_y[i],WHITE);
  display.fillRect(box_x,box_y[i]+space+1,3,32-(box_y[i]+space),WHITE);

  //人的移動
  if(manstate == 1){ //往右
    man_y--;
    if(man_y<0)man_y = 0;   
    display.drawBitmap(111,man_y,runright2,16,8,WHITE);
  }
  else if(manstate == -1){ //往左
    man_y++;
    if(man_y>24)man_y = 24;
    display.drawBitmap(111,man_y,runleft2,16,8,WHITE);
  }
  else{ //站著
    display.drawBitmap(111,man_y,stand,16,8,WHITE);
  }
  
  display.display();
}

void movement(){
  //讀按鈕
  buttonrightstate= digitalRead(buttonright);
  buttonleftstate= digitalRead(buttonleft);

  if(buttonrightstate && buttonleftstate) manstate = 0;
  else if(buttonrightstate) manstate = 1; //往右
  else if(buttonleftstate) manstate = -1; //往左
  else manstate = 0; //站著

  if(box_x<128)box_x++; //天空墜落
  if(box_x==128 && box_y[i]!=0)i++; //下一塊天空的編號  
  if(box_x==128)box_x=0; //下一塊天空開始墜落
 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buttonleft,INPUT);
  pinMode(buttonright,INPUT);
  
  man_y=12;
  
  display.begin(SSD1306_SWITCHCAPVCC,0x3D);
  display.clearDisplay();
  display.drawBitmap(111,man_y,stand,16,8,WHITE);
  display.display();
}

void loop() {
  //if(box_y[i]!=0)drop();
  movement();
  draw();
}
