//
// Created by Lautaro Cavichia on 15/11/23.
//

#ifndef SIMPLEXMETHOD_DICTIONARY_H
#define SIMPLEXMETHOD_DICTIONARY_H

#include "equation.h"
#include <ostream>
#include "Utils.h"


class Dictionary {
public:
    Dictionary(int numberOfVariables, int numberOfEquations, std::vector<equation> &equations,
               equation &objectiveFunction) :
            numberOfVariables(numberOfVariables), numberOfEquations(numberOfEquations), equations(equations),
            objectiveFunction(objectiveFunction) {};


    int getNumberOfVariables() const {
        return numberOfVariables;
    }

    void setNumberOfVariables(int numberOfVariables) {
        Dictionary::numberOfVariables = numberOfVariables;
    }

    int getNumberOfEquations() const {
        return numberOfEquations;
    }

    void setNumberOfEquations(int numberOfEquations) {
        Dictionary::numberOfEquations = numberOfEquations;
    }

    const std::vector<equation> &getEquations() const {
        return equations;
    }

    void setEquations(const std::vector<equation> &equations) {
        Dictionary::equations = equations;
    }

    const equation &getObjectiveFunction() const {
        return objectiveFunction;
    }

    void setObjectiveFunction(const equation &objectiveFunction) {
        Dictionary::objectiveFunction = objectiveFunction;
    }

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary) {
        os << "Z: ";
        os  << Utils::getSign(dictionary.getObjectiveFunction().getResult()) << dictionary.getObjectiveFunction().getResult();
        for (const auto& var : dictionary.getObjectiveFunction().getVariables()) {
            os << Utils::getSign(var.getValue()) << var.getValue() << "X" << var.getIndex()+1 << " ";
        }
        os << "\n";
        os << "Equations:\n";
        for (const auto& eq : dictionary.equations) {
            for (const auto& var : eq.getVariables()) {
                os << Utils::getSign(var.getValue()) << var.getValue() << "X" << var.getIndex()+1 << " ";
            }
            switch (static_cast<int>(eq.getType())) {
                case 0: os << "="; break;
                case 1: os << "<="; break;
                case 2: os << ">="; break;
            }
            os << Utils::getSign(eq.getResult()) << eq.getResult() << "\n";
        }





        return os;
    }

private:
    int numberOfVariables;
    int numberOfEquations;
    std::vector<equation> equations;
    equation objectiveFunction;
};


#endif //SIMPLEXMETHOD_DICTIONARY_H
