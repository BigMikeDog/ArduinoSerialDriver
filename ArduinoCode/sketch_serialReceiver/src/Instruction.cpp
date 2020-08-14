#include "Instruction.h"

Instruction::Instruction(){
    Instruction::_needsHandled = false;
    Instruction::_instructionChar = 0;
}

const char Instruction::getCurrentInstruction(){
    return(Instruction::_instructionChar);
}

const bool Instruction::needsHandled(){
    return(Instruction::_needsHandled);
}

void Instruction::setInstruction(char instruction){
    Instruction::_instructionChar = instruction;
    Instruction::_needsHandled = true;
}

void Instruction::setHandled(){
    Instruction::_instructionChar = 0;
    Instruction::_needsHandled = false;
}