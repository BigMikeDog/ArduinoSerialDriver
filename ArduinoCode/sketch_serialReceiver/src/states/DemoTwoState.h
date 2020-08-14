#ifndef DEMO_TWO_STATE
#define DEMO_TWO_STATE

#include "State.h"

class DemoTwoState : public State{
public:
    void handleExecute() override;
};

#endif //DEMO_TWO_STATE