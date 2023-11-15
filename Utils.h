//
// Created by Lautaro Cavichia on 15/11/23.
//

#ifndef SIMPLEXMETHOD_UTILS_H
#define SIMPLEXMETHOD_UTILS_H

#include "variable.h"


namespace Utils {
    static char getSign(int value){
        if (value > 0) {
            return '+';
        }
        return ' ';
    }

};


#endif //SIMPLEXMETHOD_UTILS_H
