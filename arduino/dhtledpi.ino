// 
//   FILE:  dht_test.pde
// PURPOSE: DHT library test sketch for Arduino
//
// SENSOR

#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define DHT22_PIN 5

// LEDS

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 


// Some logo, supposed to be Deer and the Cat, but something is messed up.
static unsigned char PROGMEM logo16_glcd_bmp[] =
{B1111,
 B11111110,
 B11111111,
 B10011111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11111110,
 B11111111,
 B11001111,
 B1111,
 B11111110,
 B11111111,
 B10001111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11111100,
 B11111111,
 B10000111,
 B1111,
 B11111111,
 B11111111,
 B10000011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11111010,
 B11111111,
 B11001011,
 B1111,
 B11111111,
 B11111100,
 B11100101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11110110,
 B11111111,
 B10010101,
 B1111,
 B10111111,
 B11110101,
 B10101011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11101000,
 B11111111,
 B10010011,
 B1111,
 B10011111,
 B10110001,
 B11001011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11011010,
 B11111111,
 B10010110,
 B1111,
 B10010111,
 B11001001,
 B10010011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11011110,
 B1111111,
 B11011110,
 B1111,
 B10101111,
 B11001001,
 B10010011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B10011100,
 B1111111,
 B11001110,
 B1111,
 B10101111,
 B10001001,
 B10010111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11100,
 B111111,
 B11001111,
 B1111,
 B10111111,
 B110110,
 B11011111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B111101,
 B111110,
 B11101111,
 B1111,
 B1011111,
 B10111101,
 B11101111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B111011,
 B100001,
 B11110111,
 B1111,
 B1111111,
 B111101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1100000,
 B11111010,
 B1111,
 B11111111,
 B11111110,
 B11111110,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11000001,
 B11111111,
 B1111,
 B11111111,
 B11011111,
 B11101110,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11110001,
 B11111111,
 B1111,
 B11111111,
 B11110,
 B11111101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B111111,
 B100001,
 B11111111,
 B1111,
 B11111111,
 B110,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B111111,
 B1,
 B11111111,
 B1111,
 B11110101,
 B11001001,
 B11111010,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B10111111,
 B100000,
 B11111111,
 B1111,
 B11011100,
 B11111110,
 B11111101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11100001,
 B11111111,
 B1111,
 B11011011,
 B11111010,
 B11111101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B100101,
 B11111111,
 B1111,
 B11111011,
 B11110101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11101011,
 B11111111,
 B1111,
 B11110101,
 B11111011,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11100000,
 B11111111,
 B1111,
 B11111111,
 B11111111,
 B11011111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B10000000,
 B11111111,
 B1111,
 B11110100,
 B11110111,
 B11111100,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11011001,
 B11111111,
 B1111,
 B11010100,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111011,
 B10011111,
 B11111111,
 B1111,
 B11010111,
 B11101111,
 B11110111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11000011,
 B11111111,
 B1111,
 B11010011,
 B11111011,
 B11110111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111011,
 B11111111,
 B1111,
 B10101101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111111,
 B11111111,
 B1111,
 B11101010,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111110,
 B1111,
 B1101011,
 B11111101,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B11111111,
 B1111};

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


// In the setup we make some little mess the LED - so we can be sure that
// it works

 void setup()
 {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();
  display.setCursor(0,0);
  display.println("Hey...");
  display.display();  
  display.clearDisplay();
  display.drawBitmap(0, 0,  logo16_glcd_bmp, 100, 30, 1);
  delay(10000);
  display.println("Ok, ok, easy...");
  display.display(); 
  delay(5000);

}

void loop()
{
  display.setCursor(0,0);  
  display.display();
  display.setCursor(0,0);
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    //            Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
      //          Serial.print("Time out error,\t"); 
    break;
    default: 
        //        Serial.print("Unknown error,\t"); 
    break;
  }
 // DISPLAY DATA
  Serial.print(DHT.humidity,1);
  Serial.print(",\t");
  Serial.println(DHT.temperature,1);
  
  display.display(); 
  delay(5000);
  display.clearDisplay();
  
  // some 'random' message 
  display.println("did you spank Biche lately?");
  
  display.display(); 
  delay(1000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  String myTemp = doubleToString(DHT.temperature,2);
  String myHum = doubleToString(DHT.humidity,2);
  display.clearDisplay();
  display.println("tranquilo, no?");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Temperature: " + myTemp + "\nHumidity: " + myHum + "%");

  display.setCursor(0,0);
}
void testdrawrect(void) {
  for (int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
  }
}

// Simply conversion doubleToString
// http://lordvon64.blogspot.com.es/2012/01/simple-arduino-double-to-string.html
String doubleToString(double input,int decimalPlaces){
  if(decimalPlaces!=0){
    String string = stringg((int)(input*pow(10,decimalPlaces)));
    if(abs(input)<1){
      if(input>0)
        string = "0"+string;
      else if(input<0)
        string = string.substring(0,1)+"0"+string.substring(1);
    }
    return string.substring(0,string.length()-decimalPlaces)+"."+string.substring(string.length()-decimalPlaces);
  }
  else {
    return String((int)input);
  }
}
