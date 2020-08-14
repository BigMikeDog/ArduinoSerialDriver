#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

class DefaultState : public State{
public:
    void handleExecute() override{};
};

#endif //DEFAULT_STATE