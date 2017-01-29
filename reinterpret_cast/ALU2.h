#ifndef ALU2_H_
#define ALU2_H_

class ALU2 {
public:
    static const int INT = 0;
    static const int FLOAT = 1;
    int mode = INT;
    int add(int i, int j);
    int sub(int i, int j);
    int mul(int i, int j);
    int div(int i, int j);

    float asFloat(int i);
    int asInt(float i);
};

#endif
