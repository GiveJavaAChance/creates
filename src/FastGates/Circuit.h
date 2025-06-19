#ifndef CIRCUIT_H_INCLUDED
#define CIRCUIT_H_INCLUDED

#include <cstdint>
#include <vector>

struct TruthTable;
struct Gate;

struct Circuit {
private:
    std::vector<bool*> inputs;
    std::vector<bool*> outputs;

    TruthTable* table;

    std::vector<Gate*> gates;

    bool hasUpdated;

    friend TruthTable;
public:

    Circuit();
    ~Circuit();

    void compile();
    void addGate(Gate& gate);
    bool* addInput();
    bool* addOutput();
    void evaluate();
    void reset();
};

#endif
