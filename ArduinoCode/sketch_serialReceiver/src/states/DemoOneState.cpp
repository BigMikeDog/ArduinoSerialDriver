#include "DemoOneState.h"

#include "../vendor/FastLED/FastLED.h"
#include <Arduino.h>

void DemoOneState::handleExecute(){ 
    switch(_color){
        case 0:{
            for (int i = 0; i < _context->getMaxNumLeds(); i++) {
                *(_context->getScreen()+i) = CRGB(255,0,0);
            }
            _color++;
            break;
        }
        case 1:{
            for (int i = 0; i < _context->getMaxNumLeds(); i++) {
                *(_context->getScreen()+i) = CRGB(0,255,0);
            }
            _color++;
            break;
        }
        case 2:{
            for (int i = 0; i < _context->getMaxNumLeds(); i++) {
                *(_context->getScreen()+i) = CRGB(0,0,255);
            }
            _color = 0;
            break;
        }
    }
    FastLED.show();
    delay(_context->getSceneDelay());
}