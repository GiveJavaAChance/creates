#include "Node.h"
#include "Gate.h"

Node::Node(Gate& gate) : ptr(&gate), signature(0) {}
Node::Node(bool& state) : ptr(&state), signature(1) {}
