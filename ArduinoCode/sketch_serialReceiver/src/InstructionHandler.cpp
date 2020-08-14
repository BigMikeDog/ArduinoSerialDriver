#include <Arduino.h>
#include "vendor/FastLED/FastLED.h"
#include "InstructionHandler.h"
#include "InstructionSet.h"

#include "states/PlayState.h"
#include "states/DefaultState.h"
#include "states/DemoOneState.h"
#include "states/DemoTwoState.h"


namespace InstructionHandler{
    
    void handlePing(){
        Serial.write(INSTRUCTION_ACK);
    }
//*******************************************
    void handleSetScene(){
        
    }
    void handleSetSceneDelay(Context* currentContext){
        char msb;
        char lsb;
        while(true){
            if(Serial.available() > 0){
                msb = Serial.read(); 
                break;
            }
        }
        while(true){
            if(Serial.available() > 0){
                lsb = Serial.read();
                break;
            }
        }
        currentContext->setSceneDelay((msb << 8) | (lsb & 0xff));
        Serial.write(INSTRUCTION_COMPLETED);
    }
    void handleSetColor(){
        
    }
    void handleSetBrightness(){
        
    }
    void handleSetCorrection(){
        
    }
    void handleSetTemperature(){
        
    }
//*******************************************
    void handleGetMaxLeds(){
        
    }
    void handleGetMaxNumColors(){
        
    }
    void handleGetMaxScenes(){
        
    }
    void handleGetScene(){
        
    }
    void handleGetSceneDelay(Context* currentContext){
        Serial.write(currentContext->getSceneDelay() >> 8);
        Serial.write(currentContext->getSceneDelay() & 0xff);
    }
    void handleGetColor(){
        
    }
    void handleGetBrightness(){
        
    }
    void handleGetCorrection(){
        
    }
    void handleGetTemperature(){
        
    }
//*******************************************
    void handleDemoMode(Context* currentContext){
        while(true){
            if(Serial.available() > 0){
                switch(Serial.read()){
                    case 1:{currentContext->transitionTo(new DemoOneState); break;}
                    case 2:{currentContext->transitionTo(new DemoOneState); break;}
                }
            }
        }
    }
    void handleClearScreen(Context* currentContext){
        for (int i = 0; i < currentContext->getMaxNumLeds(); i++) {
            *(currentContext->getScreen()+i) = CRGB(0,0,0);
        }
        FastLED.show();
        Serial.write(INSTRUCTION_COMPLETED);
    }
    void handleShowScene(){
        
    }
    void handlePlay(){
        
    }
    void handlePause(){
        
    }
    void handleStop(Context* currentContext){
        currentContext->transitionTo(new DefaultState);
        Serial.write(INSTRUCTION_COMPLETED);
    }
    void handleReset(){
        
    }
}