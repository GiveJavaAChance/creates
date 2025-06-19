#include "Circuit.h"
#include "Gate.h"
#include "TruthTable.h"

Circuit::Circuit() : table(nullptr), hasUpdated(false) {
}

Circuit::~Circuit() {
    if(table) {
        delete table;
    }
}

void Circuit::compile() {
    if(table) {
        delete table;
    }
    table = new TruthTable(*this);
}

void Circuit::addGate(Gate& gate) {
    gates.push_back(&gate);
}

bool* Circuit::addInput() {
    bool* in = new bool[1]{};
    inputs.push_back(in);
    return in;
}

bool* Circuit::addOutput() {
    bool* out = new bool[1]{};
    outputs.push_back(out);
    return out;
}

void Circuit::evaluate() {
    if(hasUpdated) {
        return;
    }
    hasUpdated = true;
    if(table) {
        table->evaluate(inputs, outputs);
        return;
    }
    for(Gate* gate : gates) {
        gate->evaluate();
    }
    for(Gate* gate : gates) {
        gate->reset();
    }
}

void Circuit::reset() {
    hasUpdated = false;
}
