#ifndef eEprom_H
#define eEprom_H
#include <Arduino.h>
#include <EEPROM.h>

/*
 * **************************************************
 EEPROM'a veri yazdırıp okutma fonksiyonları
 * **************************************************
*/
class eEprom {
  private:

  public:
    eEprom ();
    void byteWrite(int adrr, byte bytevalue) ;
    byte byteRead(int addr);
    void intWrite(int adrr, int integer);
    int intRead(int addr);
    void longintWrite(int addr, long longint);
    long longintRead(int addr);
    void floatWrite(int addr, float f);
    float floatRead(int addr, float f);// max 9999999.00 or 999999.49
    void stringWrite(int addr, String txt);
    String stringRead(int addr);
};
/*
* *************************************************
*/

#endif
