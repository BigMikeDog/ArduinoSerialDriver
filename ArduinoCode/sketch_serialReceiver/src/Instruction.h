#ifndef INSTRUCTION
#define INSTRUCTION

class Instruction {
public:
    Instruction();

    const char getCurrentInstruction(); //Returns a char containing the instruction.
    const bool needsHandled(); //Returns true if the Instruction needs to be handled

    void setInstruction(char instruction);
    void setHandled();
private:
    bool _needsHandled; //true if the Instruction needs to be handled, false if handled or not initialized.
    char _instructionChar; //Holds the Instruction.
};

#endif //INSTRUCTION