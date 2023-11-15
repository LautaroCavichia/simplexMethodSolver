#include <iostream>
#include <vector>
#include "variable.h"
#include "equation.h"
#include "Dictionary.h"

int main() {
    // Get the number of variables and equations from the user
    int numberOfVariables, numberOfEquations;
    std::cout << "Enter the number of variables: ";
    std::cin >> numberOfVariables;
    std::cout << "Enter the number of equations: ";
    std::cin >> numberOfEquations;

    // Get variables for each equation
    std::vector<equation> equations;
    for (int i = 0; i < numberOfEquations; ++i) {
        std::vector<variable> variables;
        std::cout << "Enter variables for equation " << i + 1 << ":\n";
        for (int j = 0; j < numberOfVariables; ++j) {
            int value;
            std::cout << "Enter the value for variable X" << j + 1 << ": ";
            std::cin >> value;
            variables.emplace_back(j, value);
        }
        std::cout << "Enter the result for equation " << i + 1 << ": ";
        int result;
        std::cin >> result;
        // Add the equation to the vector
        equations.emplace_back(i, variables, equationType::EQUAL, result);
    }

    // Get the objective function
    std::vector<variable> objectiveVariables;
    std::cout << "Enter variables for the objective function:\n";
    for (int i = 0; i < numberOfVariables; ++i) {
        int value;
        std::cout << "Enter the value for variable X" << i + 1 << ": ";
        std::cin >> value;
        objectiveVariables.emplace_back(i, value);
    }
    std::cout << "Enter the result for the objective function: ";
    int result;
    std::cin >> result;
    // Create the objective function equation
    equation objectiveFunction(0, objectiveVariables, equationType::EQUAL, result);

    // Create the Dictionary object
    Dictionary lpDictionary(numberOfVariables, numberOfEquations, equations, objectiveFunction);

    // Print the Dictionary object (you can implement a __str__ method in Dictionary)
    std::cout << "Dictionary:\n" << lpDictionary << std::endl;

    // Now, you can proceed with implementing the Simplex method using the created Dictionary object

    return 0;
}
