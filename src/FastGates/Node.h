#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#pragma once
#include <cstdint>
#include "Gate.h"

struct Node {
private:
    void* ptr;
    const uint8_t signature;

public:
    Node(Gate& gate);
    Node(bool& state);

    inline bool evaluate() {
        switch (signature) {
            case 0: return static_cast<Gate*>(ptr)->evaluate();
            case 1: return *static_cast<bool*>(ptr);
            default: return false;
        }
    }
};

#endif
