//
// Created by Lautaro Cavichia on 15/11/23.
//

#ifndef SIMPLEXMETHOD_VARIABLE_H
#define SIMPLEXMETHOD_VARIABLE_H


class variable {
public:
    variable(int index,int value):index(index),value(value){
        isNegative = isNegativeMethod(value);
    };
    static bool isNegativeMethod(int value);
    int getIndex() const;
    int getValue() const;

private:
    int index;
    int value;
    bool isNegative{};
};


#endif //SIMPLEXMETHOD_VARIABLE_H
