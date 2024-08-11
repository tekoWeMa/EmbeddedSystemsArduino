#include "MeineBibliothek_v01_00.h"

#define BUTTON_PIN 2
#define LED_PIN 9

MeineBibliothek taschenlampe(LED_PIN);

unsigned long lastPressTime = 0;
unsigned long lastReleaseTime = 0;
int clickCount = 0;
bool isHolding = false;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);
    unsigned long currentTime = millis();

    if (buttonState == HIGH) {
        if (currentTime - lastPressTime > 1000 && !isHolding) {
            lastPressTime = currentTime;
            clickCount++;
        } else if (currentTime - lastPressTime > 1000 && isHolding) {
            isHolding = false;
        }
    } else {
        if (clickCount > 0 && currentTime - lastPressTime > 1000) {
            executeClickAction();
            clickCount = 0;
        } else if (currentTime - lastReleaseTime > 1000 && buttonState == LOW && taschenlampe.istEingeschaltet()) {
            lastReleaseTime = currentTime;
            taschenlampe.ausschalten();
        }
    }

    if (buttonState == HIGH && currentTime - lastPressTime > 2000) {
        if (!isHolding) {
            isHolding = true;
            taschenlampe.blinken(128, 500);  // Mittlere Helligkeit und 500ms Blinkintervall
        }
    }
}

void executeClickAction() {
    switch (clickCount) {
        case 1:
            taschenlampe.einschalten(64);  // Niedrige Helligkeit
            break;
        case 2:
            taschenlampe.einschalten(128); // Mittlere Helligkeit
            break;
        case 3:
            taschenlampe.einschalten(255); // Maximale Helligkeit
            break;
        default:
            taschenlampe.ausschalten();
            break;
    }
}
