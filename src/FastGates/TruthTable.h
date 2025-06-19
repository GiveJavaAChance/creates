#ifndef TRUTHTABLE_H_INCLUDED
#define TRUTHTABLE_H_INCLUDED

#pragma once
#include <cstdint>
#include <vector>

struct Circuit;

struct TruthTable {
private:
    uint32_t* outputStates;
    const uint32_t numStates;
    const uint32_t numInputs;
    const uint32_t numOutputs;

public:
    TruthTable(Circuit& ic);
    ~TruthTable();

    void evaluate(const std::vector<bool*>& inputs, std::vector<bool*>& outputs) const;
};

#endif
