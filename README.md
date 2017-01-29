# UnionALU
An example of using union to calculate int or float types.

# Compile for union version
g++ union/*.cc -o ALU -std=c++11

# Compile for reinterpret_cast version
g++ reinterpret_cast/*.cc -o ALU2 -std=c++11

# Usage
Usage: ALU [-f|-i] input1 input2
-i = INT mode, -f = FLOAT mode
