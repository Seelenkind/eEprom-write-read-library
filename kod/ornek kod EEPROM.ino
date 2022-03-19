#include <eEprom.h>

eEprom eprom;

void setup()
{
  Serial.begin(115200);

  eprom.byteWrite(0, 255);// 1 byte yer kaplar adres 0 kullanılmıştır
  byte bite = eprom.byteRead(0);
  Serial.println(String(bite));

  eprom.intWrite(1, -32768); // 2 byte yer kaplar adres 1 ve 2 kullanılmıştır
  int ingr = eprom.intRead(1);
  Serial.println(String(ingr));

  eprom.longintWrite(3, -2147483648); // 4 byte yer kaplar adres 3,4,5,6 kullanılmıştır
  long lngint = eprom.longintRead(3);
  Serial.println(String(lngint));

  eprom.floatWrite(7, 999999.494949494);// 4 byte yer kaplar adres 7,8,9,10 kullanılmıştır
  float flt = eprom.floatRead(7, flt);
  Serial.println(flt, 3);

  eprom.stringWrite(11, "Hallo"); // 6 byte yer kaplar 5+1 , 6. byte \0 sıfır ile kapanıştır
  String stringRead = eprom.stringRead(11);
  Serial.println(stringRead);
}

void loop()
{

}
