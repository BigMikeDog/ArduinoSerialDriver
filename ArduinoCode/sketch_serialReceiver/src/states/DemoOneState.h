#ifndef DEMO_ONE_STATE
#define DEMO_ONE_STATE

#include "State.h"
#include <Arduino.h>

class DemoOneState : public State{
public:
    void handleExecute() override;
private:
    int8_t _color;
};

#endif //DEMO_ONE_STATE