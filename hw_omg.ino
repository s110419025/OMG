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

static const unsigned char PROGMEM start[]={
  0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x1f,0x80,0x00,0x00,0x38,0x07,0xf0,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x1f,0xc0,0x00,0x00,0x0f,0xc0,0x39,0xcf,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0f,0xf0,0x00,0x00,0x00,0x7e,0xf3,0x06,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0xf8,0x00,0x00,0xfe,0x03,0x87,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xfc,0x00,0x00,0xc7,0xf8,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x7f,0x00,0x00,0xe0,0x0f,0x8f,0xff,0xff,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0xff,0xff,0xfc,0xff,0xe1,0x9c,0x7e,0x7f,0xf8,0x00,0x00,0x00,0x00,
  0x00,0x00,0x7f,0xff,0xff,0xfe,0x01,0xff,0x98,0x70,0x00,0x1f,0x80,0x00,0x00,0x00,
  0x00,0x01,0xff,0xe0,0xff,0xfe,0x00,0x00,0x0f,0xe3,0xff,0x00,0x7e,0x00,0x00,0x00,
  0x00,0x00,0x7c,0x00,0x03,0xfc,0x00,0x00,0x3e,0x0f,0x00,0xe0,0x07,0xf8,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x78,0x0e,0x0c,0x70,0x00,0x7f,0x80,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x0e,0x00,0x30,0x00,0x01,0xfc,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xc0,0x07,0xff,0xe0,0x00,0x00,0x1e,0x00,
  0x00,0x00,0x3f,0x00,0x1f,0xe0,0x00,0x03,0x80,0x00,0xff,0x81,0xff,0xff,0x07,0x80,
  0x00,0x00,0x3f,0xe0,0x1f,0xc0,0x00,0x07,0x80,0x00,0x00,0x01,0xc0,0x03,0xc1,0xc0,
  0x17,0x00,0x1f,0xf0,0x3f,0x80,0x00,0x07,0x80,0x00,0x00,0x01,0x80,0x00,0xe0,0xc0,
  0x1f,0x80,0x0f,0xfc,0x3f,0x00,0x00,0x03,0x80,0x00,0x00,0x01,0x80,0x00,0x60,0xc0,
  0x0f,0xc0,0x0f,0xfe,0x3c,0x00,0x00,0x03,0x80,0x00,0xfe,0x01,0xc0,0x00,0x60,0xc0,
  0x07,0xe0,0x07,0xff,0xb8,0x00,0x00,0x03,0x80,0x07,0xff,0xc0,0xf0,0x00,0xc0,0xe0,
  0x07,0xf0,0x03,0xff,0xc0,0x00,0x00,0x03,0x80,0x1e,0x00,0xe0,0x7f,0xff,0xc0,0xc0,
  0x03,0xf9,0xff,0xff,0xf0,0x00,0x00,0x03,0x80,0x3c,0x3c,0x70,0x00,0x00,0x03,0xc0,
  0x01,0xff,0xff,0xff,0xff,0xff,0xe0,0x01,0xc0,0x1c,0x00,0x70,0x00,0x00,0x3f,0x00,
  0x00,0xff,0xff,0xff,0xff,0xff,0xf8,0x00,0xf0,0x0f,0xff,0xe0,0x00,0x01,0xfc,0x00,
  0x00,0x7f,0x83,0xff,0xff,0xff,0xfc,0x00,0x7c,0x01,0xfe,0x00,0x00,0x7f,0xc0,0x00,
  0x00,0x1f,0xc0,0x0f,0xff,0x80,0x00,0x00,0x1e,0x00,0x00,0x00,0xff,0xfc,0x00,0x00,
  0x00,0x0f,0xe0,0x07,0xff,0x80,0x00,0x00,0x0f,0xe0,0x00,0x7f,0x80,0x00,0x00,0x00,
  0x00,0x07,0xf0,0x03,0xff,0x00,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,
  0x00,0x03,0xfc,0x00,0xf0,0x00,0x00,0x00,0x00,0x3f,0xe0,0x00,0x00,0x00,0x00,0x00,
  0x00,0x01,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char PROGMEM ge[]= { //goodend
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0xf0,0x3f,0xff,0xf9,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xf2,0x1f,0x78,0x00,0x00,0x0f,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xf7,0xc0,0x39,0xff,0xff,0xe3,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xf7,0xff,0x9c,0x00,0x06,0x31,0xff,0xfc,0x7f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfc,0x0f,0xfc,0x7f,0xff,0x8c,0x11,0xff,0xfc,0x7f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xf0,0xff,0xfe,0xff,0xff,0x8f,0x31,0xff,0xfe,0x7f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfe,0x3f,0xff,0x3f,0xff,0xc0,0x07,0xff,0xfe,0x3f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xe3,0xff,0x9f,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfb,0xff,0xf8,0x3f,0x80,0x03,0xff,0xff,0x3f,0xe0,0x1f,0xff,0xff,
  0xff,0xff,0xff,0xf9,0xe0,0x01,0x1f,0x0f,0xf1,0xf0,0x03,0xff,0x0f,0xff,0xff,0xff,
  0xff,0xff,0xff,0xf9,0x03,0xc1,0x9e,0x7e,0x01,0xe1,0xf1,0xf8,0x7f,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfc,0x8f,0x31,0x9c,0x78,0xff,0xe3,0xf0,0x00,0x03,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xc7,0x1f,0x1e,0x38,0x03,0xe3,0xf2,0x0f,0xe0,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfc,0x70,0x78,0x1c,0x1f,0xf1,0xf8,0x00,0xff,0xc4,0x7f,0xff,0xff,
  0xf1,0xff,0xff,0x80,0x78,0x00,0x0e,0x00,0x03,0xfe,0x03,0xff,0xc7,0x1f,0xff,0xff,
  0xe0,0x0f,0xf8,0x1f,0xf1,0xff,0x0f,0xe0,0x81,0xff,0x1f,0xe7,0x8f,0xc0,0xff,0xff,
  0xf3,0xe1,0xc7,0xff,0xe3,0x80,0x7f,0x8c,0x19,0xfc,0x7f,0xf3,0x8f,0xfc,0x1f,0xff,
  0xf9,0xfc,0x1f,0xff,0xe1,0x87,0xff,0x1f,0x19,0xfd,0xff,0xf1,0xc3,0xff,0xdf,0xff,
  0xfc,0xff,0xff,0xe0,0x01,0xe3,0xff,0x11,0x99,0xff,0xff,0xf9,0xf1,0xff,0xff,0xff,
  0xfe,0x3f,0xff,0xf1,0xff,0xfc,0x3f,0x1f,0xb1,0xff,0xff,0xf8,0xfc,0x7f,0xff,0xff,
  0xff,0x0f,0xff,0xf8,0x00,0x00,0x1f,0xc7,0xe3,0xff,0xff,0xfc,0xff,0x3f,0xff,0xff,
  0xfc,0x3f,0xff,0xfc,0x07,0xff,0xff,0xf0,0x1f,0xff,0xff,0xfe,0x7f,0xff,0xff,0xff,
  0xf0,0xff,0xff,0xfc,0x67,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7f,0xff,0xff,0xff,
  0x87,0xff,0xff,0xfc,0x70,0x00,0x1f,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,0xff,
  0x1f,0xff,0xff,0xfe,0x7f,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xff,
  0x1f,0xff,0xff,0xfe,0x3c,0x00,0x0f,0xff,0xff,0xff,0xff,0xff,0x9f,0xff,0xff,0xff,
  0x00,0x03,0xff,0xff,0x38,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,
  0xff,0xe0,0xff,0xc3,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xff,0xff,0xff,
  0xff,0xf8,0xff,0x87,0xcc,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,
  0xff,0xfc,0x7f,0x9f,0xe0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,
  0xff,0xfe,0x3f,0x0f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xff,0xff,0xff,
};

static const unsigned char PROGMEM be[]= { //bad end
  0x00,0x00,0x00,0x09,0x28,0x00,0x00,0x00,0x60,0x00,0x18,0x00,0x00,0x20,0x00,0x00,
  0x00,0x00,0x00,0xbf,0xff,0xe0,0x00,0x00,0x60,0x00,0x18,0xc4,0x00,0x30,0x00,0x00,
  0x00,0x00,0x00,0xf8,0x03,0xfe,0x00,0x00,0x40,0x00,0x11,0x82,0x00,0x30,0x00,0x00,
  0x00,0x00,0x07,0x80,0x00,0x3f,0x80,0x00,0x40,0x00,0x30,0x81,0x00,0x30,0x00,0x00,
  0x00,0x00,0x1e,0x0e,0xfe,0x07,0x20,0x00,0x40,0x00,0x30,0xc0,0xc0,0x30,0x08,0x00,
  0x00,0x00,0xdc,0x18,0x45,0x83,0x90,0x00,0xc0,0x00,0x30,0x60,0x20,0x30,0x7c,0x00,
  0x00,0x00,0x38,0x30,0x02,0xc1,0x80,0x00,0xc0,0x00,0x30,0x07,0xfc,0x31,0xe0,0x00,
  0x00,0x01,0xf0,0x78,0x01,0xe0,0xc0,0x00,0xc0,0x00,0x30,0x00,0x00,0x37,0x80,0x00,
  0x00,0x01,0xf0,0x70,0x01,0xe0,0xc0,0x00,0xc0,0x00,0x30,0x3f,0xf8,0x3e,0x00,0x00,
  0x00,0x00,0x60,0x78,0x00,0x60,0xc0,0x00,0xc0,0x00,0x31,0xe0,0x07,0xf8,0x00,0x00,
  0x00,0x03,0xe0,0x6c,0x0e,0x60,0xc0,0x00,0xc0,0x00,0x7f,0x00,0x01,0xf8,0x00,0x00,
  0x00,0x03,0x60,0x1f,0x2b,0x81,0xc0,0x00,0xc0,0x00,0x38,0x00,0x00,0x78,0x00,0x00,
  0x00,0x00,0x30,0x00,0xf0,0x07,0x80,0x00,0xc0,0x00,0x60,0x0f,0xc0,0x18,0x00,0x00,
  0x00,0x00,0x3c,0x00,0x00,0x1e,0x80,0x00,0xc0,0x00,0xc0,0x31,0xc0,0x7f,0xfe,0x00,
  0x00,0x00,0xf7,0xf0,0x01,0xf7,0x80,0x00,0xc0,0x01,0x80,0x67,0x03,0x80,0x03,0x00,
  0x00,0x00,0x07,0x1f,0xfe,0x52,0x80,0x00,0xc0,0x01,0x80,0x7c,0x06,0x00,0x01,0x80,
  0x00,0x01,0x14,0x30,0x00,0xff,0x88,0x00,0xc0,0x01,0x80,0x00,0x06,0x00,0x01,0x80,
  0x00,0x1f,0xff,0xff,0xfc,0x00,0x3c,0x00,0x80,0x01,0x80,0x00,0x06,0x00,0x07,0x80,
  0x00,0x2c,0x00,0x00,0x00,0x00,0x1f,0x01,0x80,0x00,0xc0,0x00,0x06,0x00,0x7e,0x00,
  0x00,0x07,0xf0,0x00,0x00,0x00,0x38,0x01,0x80,0x00,0xc0,0x7c,0x07,0xff,0x80,0x00,
  0x00,0x0b,0x07,0xe0,0x00,0x00,0xc0,0x01,0x80,0x00,0xe0,0x67,0x80,0x18,0x00,0x00,
  0x00,0x00,0xa0,0xcf,0xe0,0x03,0x84,0x01,0x80,0x00,0x78,0x30,0xe0,0x3c,0x00,0x00,
  0x00,0x00,0x09,0x2d,0xc0,0x1f,0x00,0x03,0x00,0x00,0x6e,0x0f,0xe0,0xff,0x00,0x00,
  0x00,0x00,0x00,0x33,0x00,0x31,0xc0,0x03,0x00,0x00,0x63,0x80,0x03,0xdb,0xe0,0x00,
  0x00,0x00,0x00,0x6e,0x00,0x7e,0x00,0x00,0xe0,0x00,0x60,0xff,0xfc,0x18,0x7c,0x00,
  0x00,0x00,0x01,0xf8,0x00,0x0f,0xf0,0x00,0x1c,0x00,0x60,0x07,0x03,0x98,0x07,0x00,
  0x00,0x00,0x0d,0xe0,0x00,0x00,0x3c,0x00,0x03,0x80,0x60,0x00,0x0f,0x18,0x00,0x00,
  0x00,0x00,0x77,0x00,0x00,0xff,0xf0,0x00,0x00,0x38,0x60,0x00,0x33,0x18,0x00,0x00,
  0x00,0x00,0x1c,0x00,0x7f,0x48,0x1c,0x00,0x00,0x03,0xe0,0x0f,0xe3,0x10,0x00,0x00,
  0x00,0x00,0x30,0x7f,0xaa,0x49,0xc0,0x00,0x00,0x00,0x3f,0x1d,0x86,0x00,0x00,0x00,
  0x00,0x00,0x3f,0x14,0xa9,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0xc6,0x00,0x00,0x00,
  0x00,0x00,0x03,0x72,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,
};

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
  
  if( (box_x==111)&&(man_y<box_y[i])&&( (man_y+8)>(box_y[i]+space+1) )// (人的頭與天空的高度相同)&&(人站的地方在左雲的範圍內)&&(人站的地方在右雲的範圍內)
     {
       gameover();//遊戲失敗
     }
  
}


void gameover(){ //遊戲失敗
  display.clearDisplay();
  display.drawBitmap(0,0,be,128,32,WHITE);
  display.display();
}






void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buttonleft,INPUT);
  pinMode(buttonright,INPUT);
  
  man_y=12;
  
  display.begin(SSD1306_SWITCHCAPVCC,0x3D);
  display.clearDisplay();
  //display.drawBitmap(111,man_y,stand,16,8,WHITE);
  //display.drawBitmap(0,0,start,128,32,WHITE);
  display.drawBitmap(0,0,ge,128,32,WHITE);
  //display.drawBitmap(0,0,be,128,32,WHITE);
  display.display();
}








void loop() {
  //if(box_y[i]!=0)drop();
  movement();
  draw();
}
