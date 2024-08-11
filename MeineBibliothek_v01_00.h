#ifndef MEINEBIBLIOTHEK_V01_00_H
#define MEINEBIBLIOTHEK_V01_00_H

#include <Arduino.h>

class MeineBibliothek {
public:
    MeineBibliothek(int pin);
    void einschalten(int helligkeit);
    void ausschalten();
    void blinken(int helligkeit, int blinkIntervall);
    bool istEingeschaltet();

private:
    int _pin;
    bool _status;
};

#endif
