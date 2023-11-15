//
// Created by Lautaro Cavichia on 15/11/23.
//

#include "variable.h"

int variable::getValue() const {
    return value;
}

int variable::getIndex() const {
    return index;
}

bool variable::isNegativeMethod(int value) {
    if (value < 0) {
        return true;
    }
    return false;
}
