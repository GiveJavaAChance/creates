#include <iostream>
#include "Gate.h"
#include "Circuit.h"
#include "Node.h"

int main() {
    Gate gate(AND);

    bool pa = false;
    Node inA(pa);

    bool pb = false;
    Node inB(pb);

    gate.connectInputA(inA);
    gate.connectInputB(inB);

    std::cout << gate.evaluate() << std::endl;
    gate.reset();

    pa = true;
    std::cout << gate.evaluate() << std::endl;
    gate.reset();

    pa = false;
    pb = true;
    std::cout << gate.evaluate() << std::endl;
    gate.reset();

    pa = true;
    std::cout << gate.evaluate() << std::endl;
    gate.reset();
}
