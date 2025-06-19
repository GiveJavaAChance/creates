#include "TruthTable.h"
#include "Circuit.h"

TruthTable::TruthTable(Circuit& ic) : numStates(1 << ic.inputs.size()), numInputs(ic.inputs.size()), numOutputs(ic.outputs.size()) {
    uint32_t totalBits = numStates * numOutputs;
    uint32_t numWords = (totalBits + 31) >> 5;
    outputStates = new uint32_t[numWords];

    for (uint32_t i = 0; i < numStates; i++) {
        for (uint32_t j = 0; j < numInputs; j++) {
            *ic.inputs[j] = (i >> j) & 1;
        }
        ic.evaluate();
        ic.reset();

        for (uint32_t j = 0; j < numOutputs; j++) {
            bool bit = *ic.outputs[j];
            uint32_t index = i * numOutputs + j;
            uint32_t word = index >> 5;
            uint32_t bitPos = index & 31;
            if (bit) {
                outputStates[word] |= (1u << bitPos);
            }
        }
    }
}

void TruthTable::evaluate(const std::vector<bool*>& inputs, std::vector<bool*>& outputs) const {
    uint32_t inputIndex = 0;
    for (uint32_t i = 0; i < numInputs; i++) {
        if (*inputs[i]) {
            inputIndex |= (1 << i);
        }
    }

    for (uint32_t j = 0; j < numOutputs; j++) {
        uint32_t index = inputIndex * numOutputs + j;
        uint32_t word = index >> 5;
        uint32_t bit = index & 31;
        *outputs[j] = (outputStates[word] >> bit) & 1;
    }
}

TruthTable::~TruthTable() {
    delete[] outputStates;
}
