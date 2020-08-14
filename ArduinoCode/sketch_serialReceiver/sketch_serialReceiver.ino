#include "src/vendor/FastLED/FastLED.h"
#include "src/InstructionSet.h"
#include "src/InstructionHandler.h"
#include "src/Instruction.h"

#include "src/states/State.h"
#include "src/states/DemoOneState.h"
#include "src/states/DemoTwoState.h"
#include "src/states/PlayState.h"
#include "src/states/DefaultState.h"

//Defines
#define BAUD 9600

#define BOARD_LED 13

#define MAX_NUM_LEDS 49
#define DATA_PIN 12

//Forward Declerations 
void getInstruction();
void executeInstruction();

//Global Variables
CRGB screen[MAX_NUM_LEDS];
Instruction currentInstruction;
Context *currentContext = new Context(new DefaultState, MAX_NUM_LEDS,screen);

void setup() {
    Serial.begin(BAUD);
    Serial.write("Setup Entered!");
    pinMode(BOARD_LED, OUTPUT);
    digitalWrite(BOARD_LED, LOW);
    currentContext->setSceneDelay(1000);

    FastLED.addLeds<WS2811, DATA_PIN, RGB>(screen, currentContext->getMaxNumLeds());
    for (int i = 0; i < currentContext->getMaxNumLeds(); i++) {
        screen[i] = CRGB(0,0,0);
    }
}

void loop(){
    getInstruction();
    executeInstruction();
    currentContext->executeState();
}

void getInstruction(){
    if(Serial.available() > 0){
        currentInstruction.setInstruction(Serial.read());
    }
}

void executeInstruction(){
    if(currentInstruction.needsHandled() == true){
        switch ( currentInstruction.getCurrentInstruction() ){
            case INSTRUCTION_PING:            {InstructionHandler::handlePing();                        break;} // ' '

            case INSTRUCTION_SETSCENE:        {InstructionHandler::handleSetScene();                    break;} // 'A'
            case INSTRUCTION_SETSCENEDELAY:   {InstructionHandler::handleSetSceneDelay(currentContext); break;} // 'B'
            case INSTRUCTION_SETCOLOR:        {InstructionHandler::handleSetColor();                    break;} // 'C'
            case INSTRUCTION_SETBRIGHTNESS:   {InstructionHandler::handleSetBrightness();               break;} // 'D'
            case INSTRUCTION_SETCORRECTION:   {InstructionHandler::handleSetCorrection();               break;} // 'E'
            case INSTRUCTION_SETTEMPERATURE:  {InstructionHandler::handleSetTemperature();              break;} // 'F'

            case INSTRUCTION_GETMAXLEDS:      {InstructionHandler::handleGetMaxLeds();                  break;} // '^'
            case INSTRUCTION_GETMAXNUMCOLORS: {InstructionHandler::handleGetMaxNumColors();             break;} // '_'
            case INSTRUCTION_GETMAXSCENES:    {InstructionHandler::handleGetMaxScenes();                break;} // '`'
            case INSTRUCTION_GETSCENE:        {InstructionHandler::handleGetScene();                    break;} // 'a'
            case INSTRUCTION_GETSCENEDELAY:   {InstructionHandler::handleGetSceneDelay(currentContext); break;} // 'b'
            case INSTRUCTION_GETCOLOR:        {InstructionHandler::handleGetColor();                    break;} // 'c'
            case INSTRUCTION_GETBRIGHTNESS:   {InstructionHandler::handleGetBrightness();               break;} // 'd'
            case INSTRUCTION_GETCORRECTION:   {InstructionHandler::handleGetCorrection();               break;} // 'e'
            case INSTRUCTION_GETTEMPERATURE:  {InstructionHandler::handleGetTemperature();              break;} // 'f'

            case INSTRUCTION_DEMOMODE:        {InstructionHandler::handleDemoMode(currentContext);      break;} // 'x'
            case INSTRUCTION_CLEARSCREEN:     {InstructionHandler::handleClearScreen(currentContext);   break;} // 'y'
            case INSTRUCTION_SHOWSCENE:       {InstructionHandler::handleShowScene();                   break;} // 'z'
            case INSTRUCTION_PLAY:            {InstructionHandler::handlePlay();                        break;} // '{'
            case INSTRUCTION_PAUSE:           {InstructionHandler::handlePause();                       break;} // '|'
            case INSTRUCTION_STOP:            {InstructionHandler::handleStop(currentContext);          break;} // '}'
            case INSTRUCTION_RESET:           {InstructionHandler::handleReset();                       break;} // '~'
            
            default: {Serial.write(INSTRUCTION_NAK); break;} //Send NAK if instruction is not valid.
        }
        //Once handled, reset the instruction.
        currentInstruction.setHandled();
    }
}