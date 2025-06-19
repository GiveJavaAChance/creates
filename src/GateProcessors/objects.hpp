#pragma once

// Just for uint8_t
#include <cstdint>

struct Gate {
    // Gate type (0 = and, 1 = or, 2 = xor, 3 = nand, 4 = nor, 5 = xnor)
    const uint8_t type;

    // Position
    float x;
    float y;

    // Pointers to the input networks
    // Could be other types too if more states are needed
    bool* inputNodeA;
    bool* inputNodeB;

    // Pointer to the output network
    bool* outputNode;

    // Constructor for the gate
    Gate(uint8_t type_) : type(type_), inputNodeA(nullptr), inputNodeB(nullptr), outputNode(nullptr) {}


    // functions to connect the gate's inputs and output to networks
    void connectInputA(bool& network) {
        inputNodeA = &network;
    }

    void connectInputB(bool& network) {
        inputNodeB = &network;
    }

    void connectOutput(bool& network) {
        outputNode = &network;
    }


    // Here's an example of how you'd normally update the gate
    void step() {
        // If the gate's output isn't connected, the gate can be skipped
        if(!outputNode) {
            return;
        }

        // Default states of the inputs can be false if the inputs aren't connected
        bool a = false;
        bool b = false;
        if(inputNodeA) {
            a = *inputNodeA;
        }
        if(inputNodeB) {
            b = *inputNodeB;
        }

        switch (type) {
            case 0: // And gate
                *outputNode = a && b;
                break;

            case 1: // Or gate
                *outputNode = a || b;
                break;

            case 2: // Xor gate
                *outputNode = a != b;
                break;

            case 3: // Nand gate
                *outputNode = !(a && b);
                break;

            case 4: // Nor gate
                *outputNode = !(a || b);
                break;

            case 5: // Xnor gate
                *outputNode = a == b;
                break;
        }
    }
};
