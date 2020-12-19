#include <eEprom.h>

/*
 * **************************************************
   EEPROM'a veri yazdırıp okutma fonksiyonları
 * **************************************************
*/
eEprom::eEprom ()
{

}

void eEprom::byteWrite(int addr, byte bytevalue)
{
  EEPROM.update(addr, bytevalue);
}

byte eEprom::byteRead(int addr)
{
  return EEPROM.read(addr);
}

void eEprom::intWrite(int addr, int integer)
{
  EEPROM.update(addr, integer >> 8);
  EEPROM.update(addr + 1, integer & 0xFF);
}

int eEprom::intRead(int addr)
{
  byte byte1 = EEPROM.read(addr);
  byte byte2 = EEPROM.read(addr + 1);
  return (byte1 << 8) + byte2;
}

void eEprom::longintWrite(int addr, long longint)
{
  EEPROM.update(addr, (longint >> 24) & 0xFF);
  EEPROM.update(addr + 1, (longint >> 16) & 0xFF);
  EEPROM.update(addr + 2, (longint >> 8) & 0xFF);
  EEPROM.update(addr + 3, longint & 0xFF);
}

long eEprom::longintRead(int addr)
{
  return ((long)EEPROM.read(addr) << 24) +
         ((long)EEPROM.read(addr + 1) << 16) +
         ((long)EEPROM.read(addr + 2) << 8) +
         (long)EEPROM.read(addr + 3);
}

void eEprom::floatWrite(int addr, float f)
{
  EEPROM.put(addr, f);
}

float eEprom::floatRead(int addr, float f)
{
  return EEPROM.get(addr, f);

}

void eEprom::stringWrite(int addr, String data)
{
  int stringSize = data.length();
  for(int i=0;i<stringSize;i++)
  {
    EEPROM.write(addr+i, data[i]);
  }
  EEPROM.write(addr + stringSize,'\0');   //Add termination null character
}

String eEprom::stringRead(int addr)
{
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k = EEPROM.read(addr);
  while(k != '\0' && len < 100)   //Read until null character
  {
    k = EEPROM.read(addr + len);
    data[len] = k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
/*
 * ***************************************************
*/
