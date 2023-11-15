//
// Created by Lautaro Cavichia on 15/11/23.
//
#include <vector>
#include "variable.h"


#ifndef SIMPLEXMETHOD_EQUATION_H
#define SIMPLEXMETHOD_EQUATION_H

enum class equationType {
    EQUAL,
    LESS_OR_EQUAL,
    GREATER_OR_EQUAL
};


class equation {
public:
    equation(int index, std::vector<variable> &variables,equationType type,int result):index(index),variables(variables),type(type),result(result){};

    int getIndex() const {
        return index;
    }

    void setIndex(int index) {
        equation::index = index;
    }

    const std::vector<variable> &getVariables() const {
        return variables;
    }

    void setVariables(const std::vector<variable> &variables) {
        equation::variables = variables;
    }

    equationType getType() const {
        return type;
    }

    void setType(equationType type) {
        equation::type = type;
    }

    int getResult() const {
        return result;
    }

    void setResult(int result) {
        equation::result = result;
    }

private:
    int index;
    std::vector<variable> variables;
    equationType type;
    int result;

};

class CostFunction: public equation{
public:
    CostFunction(int index, std::vector<variable> &variables,equationType type,int result):equation(index,variables,equationType::EQUAL,result){};
};

#endif //SIMPLEXMETHOD_EQUATION_H
