#ifndef INSTRUCTION_HANDLER
#define INSTRUCTION_HANDLER

#include "states/State.h"

namespace InstructionHandler{
    void handlePing();
    
    void handleSetScene();
    void handleSetSceneDelay(Context* currentContext);
    void handleSetColor();
    void handleSetBrightness();
    void handleSetCorrection();
    void handleSetTemperature();

    void handleGetMaxLeds();
    void handleGetMaxNumColors();
    void handleGetMaxScenes();
    void handleGetScene();
    void handleGetSceneDelay(Context* currentContext);
    void handleGetColor();
    void handleGetBrightness();
    void handleGetCorrection();
    void handleGetTemperature();

    void handleDemoMode(Context* currentContext);
    void handleClearScreen(Context* currentContext);
    void handleShowScene();
    void handlePlay();
    void handlePause();
    void handleStop(Context* currentContext);
    void handleReset();
}

#endif //INSTRUCTION_HANDLER