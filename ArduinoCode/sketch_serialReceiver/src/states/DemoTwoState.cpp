#include "DemoTwoState.h"

#include "../vendor/FastLED/FastLED.h"

void DemoTwoState::handleExecute(){
    for (int i = 0; i < _context->getMaxNumLeds(); i++) {
        *(_context->getScreen()+i) = CHSV(((float)i/_context->getMaxNumLeds())*255,255,255);
    }
    FastLED.show();
}