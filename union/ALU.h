#ifndef ALU_H_
#define ALU_H_
#include "PolymorphicType.h"

class ALU {
public:
    static const int INT = 0;
    static const int FLOAT = 1;
    int mode = INT;
    PolymorphicType add(PolymorphicType i, PolymorphicType j);
    PolymorphicType sub(PolymorphicType i, PolymorphicType j);
    PolymorphicType mul(PolymorphicType i, PolymorphicType j);
    PolymorphicType div(PolymorphicType i, PolymorphicType j);

};

#endif
