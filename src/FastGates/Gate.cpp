#include "Gate.h"
#include "Node.h"

Gate::Gate(uint8_t type_) : type(type_) {}

void Gate::connectInputA(Node& node) {
    inputA = &node;
}

void Gate::connectInputB(Node& node) {
    inputB = &node;
}

bool Gate::evaluate() {
    if (hasUpdated) return state;
    hasUpdated = true;

    bool a = inputA ? inputA->evaluate() : false;
    bool b = inputB ? inputB->evaluate() : false;

    switch (type) {
        case 0: state = a && b; break;
        case 1: state = a || b; break;
        case 2: state = a != b; break;
        case 3: state = !(a && b); break;
        case 4: state = !(a || b); break;
        case 5: state = a == b; break;
        default: state = false; break;
    }

    return state;
}

void Gate::reset() {
    hasUpdated = false;
}
