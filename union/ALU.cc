#include <iostream>
#include "ALU.h"
#include "PolymorphicType.h"
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

PolymorphicType ALU::add(PolymorphicType x, PolymorphicType y) {
    PolymorphicType result;
    if(mode == FLOAT) {
        result.asFloat = x.asFloat + y.asFloat;
    }
    else {
        result.asInt = x.asInt + y.asInt;
    }
    return result;
}

PolymorphicType ALU::sub(PolymorphicType x, PolymorphicType y) {
    PolymorphicType result;
    if(mode == FLOAT) {
        result.asFloat = x.asFloat - y.asFloat;
    }
    else {
        result.asInt = x.asInt - y.asInt;
    }
    return result;
}

PolymorphicType ALU::mul(PolymorphicType x, PolymorphicType y) {
    PolymorphicType result;
    if(mode == FLOAT) {
        result.asFloat = x.asFloat * y.asFloat;
    }
    else {
        result.asInt = x.asInt * y.asInt;
    }
    return result;
}

PolymorphicType ALU::div(PolymorphicType x, PolymorphicType y) {
    PolymorphicType result;
    if(mode == FLOAT) {
        result.asFloat = x.asFloat / y.asFloat;
    }
    else {
        result.asInt = x.asInt / y.asInt;
    }
    return result;
}

int main(int argc, char *argv[]) {
    ALU &alu = *new ALU();
    if(argc != 4) {
        cout << "Usage: ALU [-f|-i] input1 input2" << endl;
        cout << "-i = INT mode, -f = FLOAT mode" << endl;
        return 0;
    }
    string &mode = * new string(argv[1]);
    if(boost::starts_with(mode, "-f") || boost::starts_with(mode, "-F")) {
        alu.mode = ALU::FLOAT;
    }
    else if(boost::starts_with(mode, "-i") || boost::starts_with(mode, "-I")) {
        alu.mode = ALU::INT;
    }
    else {
        cout << "Wrong mode is given." << endl;
        return 1;
    }

    PolymorphicType x;
    PolymorphicType y;

    if(alu.mode == ALU::FLOAT) {
        x.asFloat = atof(argv[2]);
        y.asFloat = atof(argv[3]);
    }
    else {
        x.asInt = atoi(argv[2]);
        y.asInt = atoi(argv[3]);
    }

    switch(alu.mode) {
        case ALU::FLOAT:
            cout << "Mode = FLOAT" << endl;
            cout << "Add: " << alu.add(x, y).asFloat << endl;
            cout << "Sub: " << alu.sub(x, y).asFloat << endl;
            cout << "Mul: " << alu.mul(x, y).asFloat << endl;
            cout << "Div: " << alu.div(x, y).asFloat << endl;
            break;
        case ALU::INT:
        default:
            cout << "Mode = INT" << endl;
            cout << "Add: " << alu.add(x, y).asInt << endl;
            cout << "Add: " << alu.sub(x, y).asInt << endl;
            cout << "Add: " << alu.mul(x, y).asInt << endl;
            cout << "Add: " << alu.div(x, y).asInt << endl;
    }
    return 0;
}
