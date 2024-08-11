#include "MeineBibliothek_v01_00.h"

MeineBibliothek::MeineBibliothek(int pin) {
    _pin = pin;
    _status = false;
    pinMode(_pin, OUTPUT);
}

void MeineBibliothek::einschalten(int helligkeit) {
    analogWrite(_pin, helligkeit);
    _status = true;
}

void MeineBibliothek::ausschalten() {
    analogWrite(_pin, 0);
    _status = false;
}

void MeineBibliothek::blinken(int helligkeit, int blinkIntervall) {
    while (true) {
        einschalten(helligkeit);
        delay(blinkIntervall);
        ausschalten();
        delay(blinkIntervall);
    }
}

bool MeineBibliothek::istEingeschaltet() {
    return _status;
}
