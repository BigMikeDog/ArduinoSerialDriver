#ifndef PLAY_STATE
#define PLAY_STATE

#include "State.h"

class PlayState : public State{
public:
    void handleExecute() override;
};

#endif //PLAY_STATE