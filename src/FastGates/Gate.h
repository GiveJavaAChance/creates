#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#pragma once

#include <cstdint>

struct Node;

struct Gate {
private:
    Node* inputA;
    Node* inputB;

    uint8_t type;
    bool state = false;
    bool hasUpdated = false;

public:
    Gate(uint8_t type_);

    void connectInputA(Node& node);
    void connectInputB(Node& node);

    bool evaluate();

    void reset();
};

#endif
