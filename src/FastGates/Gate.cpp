#include "Gate.h"
#include "Node.h"

Gate::Gate(GateType type_) : type(type_) {}

void Gate::connectInputA(Node& node) {
    inputA = &node;
}

void Gate::connectInputB(Node& node) {
    inputB = &node;
}

bool Gate::evaluate() {
    if (hasUpdated) {
        return state;
    }
    hasUpdated = true;

    bool a = inputA ? inputA->evaluate() : false;
    bool b = inputB ? inputB->evaluate() : false;

    switch (type) {
        case AND: state = a && b; break;
        case OR:  state = a || b; break;
        case XOR: state = a != b; break;
        case NAND: state = !(a && b); break;
        case NOR:  state = !(a || b); break;
        case XNOR: state = a == b; break;
    }
    return state;
}

void Gate::reset() {
    hasUpdated = false;
}
