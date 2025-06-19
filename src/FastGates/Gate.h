#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#pragma once

#include <cstdint>

struct Node;

enum GateType : uint8_t {
    AND = 0,
    OR,
    XOR,
    NAND,
    NOR,
    XNOR
};

struct Gate {
private:
    Node* inputA;
    Node* inputB;

    GateType type;
    bool state = false;
    bool hasUpdated = false;

public:
    Gate(GateType type_);

    void connectInputA(Node& node);
    void connectInputB(Node& node);

    bool evaluate();

    void reset();
};

#endif
