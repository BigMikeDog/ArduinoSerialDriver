#ifndef STATE
#define STATE

#include "../vendor/FastLED/FastLED.h"

class Context;

class State{
public:
    virtual ~State();

    void set_context(Context *context);

    virtual void handleExecute() = 0;
protected:
    Context *_context;
};

class Context{
public:
    Context(State *state, short int maxNumLeds, CRGB *screen);
    ~Context();

    void transitionTo(State *state);
    void executeState();

    const CRGB* getScreen();

    void setSceneDelay(short int milliSec);
    const short int getSceneDelay();

    const short int getMaxNumLeds();
private:
    State *_state;
    CRGB *_screen;
    short int _sceneDelayMilliSec;
    short int _maxNumLeds;
};
#endif //STATE