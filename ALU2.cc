#include <iostream>
#include "ALU2.h"
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

int ALU2::add(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatX = *reinterpret_cast<float*>(&x);
        float floatY = *reinterpret_cast<float*>(&y);
        float floatResult = floatX + floatY;
        result = *reinterpret_cast<int*>(&floatResult);
    }
    else {
        result = x + y;
    }
    return result;
}

int ALU2::sub(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatX = *reinterpret_cast<float*>(&x);
        float floatY = *reinterpret_cast<float*>(&y);
        float floatResult = floatX - floatY;
        result = *reinterpret_cast<int*>(&floatResult);
    }
    else {
        result = x - y;
    }
    return result;
}

int ALU2::mul(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatX = *reinterpret_cast<float*>(&x);
        float floatY = *reinterpret_cast<float*>(&y);
        float floatResult = floatX * floatY;
        result = *reinterpret_cast<int*>(&floatResult);
    }
    else {
        result = x * y;
    }
    return result;
}

int ALU2::div(int x, int y) {
    int result;
    if(mode == FLOAT) {
        float floatX = *reinterpret_cast<float*>(&x);
        float floatY = *reinterpret_cast<float*>(&y);
        float floatResult = floatX / floatY;
        result = *reinterpret_cast<int*>(&floatResult);
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
        x = *reinterpret_cast<int*>(&floatX);
        y = *reinterpret_cast<int*>(&floatY);
    }
    else {
        x = atoi(argv[2]);
        y = atoi(argv[3]);
    }

    int addResult = 0, subResult = 0, mulResult = 0, divResult = 0;

    switch(alu.mode) {
        case ALU2::FLOAT:
            cout << "Mode = FLOAT" << endl;
            addResult = alu.add(x, y);
            subResult = alu.sub(x, y);
            mulResult = alu.mul(x, y);
            divResult = alu.div(x, y);
            cout << "Add: " << *reinterpret_cast<float*>(&addResult) << endl;
            cout << "Sub: " << *reinterpret_cast<float*>(&subResult) << endl;
            cout << "Mul: " << *reinterpret_cast<float*>(&mulResult) << endl;
            cout << "Div: " << *reinterpret_cast<float*>(&divResult) << endl;
            break;
        case ALU2::INT:
        default:
            cout << "Mode = INT" << endl;
            addResult = alu.add(x, y);
            subResult = alu.sub(x, y);
            mulResult = alu.mul(x, y);
            divResult = alu.div(x, y);
            cout << "Add: " << addResult << endl;
            cout << "Add: " << subResult << endl;
            cout << "Add: " << mulResult << endl;
            cout << "Add: " << divResult << endl;
    }
    return 0;
}
