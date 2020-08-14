#include "State.h"

void State::set_context(Context *context){
    this->_context = context;
}

State::~State(){}

Context::Context(State *state, short int maxNumLeds, CRGB *screen):_state(nullptr){
    this->transitionTo(state);
    this->_maxNumLeds = maxNumLeds;
    this->_screen = screen;
}

Context::~Context(){
    delete _state;
}

void Context::transitionTo(State *state){
    if(this->_state != nullptr){
        delete this->_state;
    }
    this->_state = state;
    this->_state->set_context(this);
}

void Context::executeState(){
    this->_state->handleExecute();
}

const CRGB* Context::getScreen(){
    return(this->_screen);
}

void Context::setSceneDelay(short int milliSec){
    this->_sceneDelayMilliSec = milliSec;
}

const short int Context::getSceneDelay(){
    return(this->_sceneDelayMilliSec);
}

const short int Context::getMaxNumLeds(){
    return(this->_maxNumLeds);
}