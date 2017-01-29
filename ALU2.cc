#include <iostream>
#include "ALU2.h"
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

float ALU2::asFloat(int i) {
    return *reinterpret_cast<float*>(&i);
}

int ALU2::asInt(float i) {
    return *reinterpret_cast<int*>(&i);
}

int ALU2::add(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatResult = asFloat(x) + asFloat(y);
        result = asInt(floatResult);
    }
    else {
        result = x + y;
    }
    return result;
}

int ALU2::sub(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatResult = asFloat(x) - asFloat(y);
        result = asInt(floatResult);
    }
    else {
        result = x - y;
    }
    return result;
}

int ALU2::mul(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatResult = asFloat(x) * asFloat(y);
        result = asInt(floatResult);
    }
    else {
        result = x * y;
    }
    return result;
}

int ALU2::div(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatResult = asFloat(x) / asFloat(y);
        result = asInt(floatResult);
    }
    else {
        result = x / y;
    }
    return result;
}

int main(int argc, char *argv[]) {
    ALU2 &alu = *new ALU2();
    if(argc != 4) {
        cout << "Usage: ALU2 [-f|-i] input1 input2" << endl;
        cout << "-i = INT mode, -f = FLOAT mode" << endl;
        return 0;
    }
    string &mode = * new string(argv[1]);
    if(boost::starts_with(mode, "-f") || boost::starts_with(mode, "-F")) {
        alu.mode = ALU2::FLOAT;
    }
    else if(boost::starts_with(mode, "-i") || boost::starts_with(mode, "-I")) {
        alu.mode = ALU2::INT;
    }
    else {
        cout << "Wrong mode is given." << endl;
        return 1;
    }

    int x;
    int y;

    if(alu.mode == ALU2::FLOAT) {
        float floatX = atof(argv[2]);
        float floatY = atof(argv[3]);
        x = alu.asInt(floatX);
        y = alu.asInt(floatY);
    }
    else {
        x = atoi(argv[2]);
        y = atoi(argv[3]);
    }

    int addResult = 0, subResult = 0, mulResult = 0, divResult = 0;

    addResult = alu.add(x, y);
    subResult = alu.sub(x, y);
    mulResult = alu.mul(x, y);
    divResult = alu.div(x, y);

    switch(alu.mode) {
        case ALU2::FLOAT:
            cout << "Mode = FLOAT" << endl;
            cout << "Add: " << alu.asFloat(addResult) << endl;
            cout << "Sub: " << alu.asFloat(subResult) << endl;
            cout << "Mul: " << alu.asFloat(mulResult) << endl;
            cout << "Div: " << alu.asFloat(divResult) << endl;
            break;
        case ALU2::INT:
        default:
            cout << "Mode = INT" << endl;
            cout << "Add: " << addResult << endl;
            cout << "Add: " << subResult << endl;
            cout << "Add: " << mulResult << endl;
            cout << "Add: " << divResult << endl;
    }
    return 0;
}
