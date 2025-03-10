#include <iostream>
#include <cmath>
#include <limits>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {

    if (b != 0) {
        return a / b;

    }
    else if (b == 0){
        std::cout << "You can't divide a number by 0." << std::endl;
        return 0;

    }
    else {
        return 0;

    }
    
}

double raiseToPower(double a, double b) {
    return std::pow(a, b);
}

double squareRoot(double a) {
    return std::sqrt(a);
}

double pythagoreanTheorem(double a, double b) {

    return std::sqrt(a * a + b * b);
}

double convertLength() {

    double length;
    double convertedLength = 0;
    std::string unit;
    std::string targetUnit;

    while (true) {
        std::cout << "Enter the length: ";
        std::cin >> length;

        if (!std::cin.fail()) {
            // Clear the input buffer after a valid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;

        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "-Error, please enter a valid length.\n";

    }

	std::cout << "Enter the unit (km, m, cm, mm): ";
    std::cin >> unit;

    while (unit != "km" && unit != "m" && unit != "cm" && unit != "mm") {
        std::cout << "Invalid unit, please enter a valid unit(km, m, cm, mm): ";
        std::cin >> unit;

    }

    std::cout << "Enter the trarget unit(km, m, cm, mm): ";
    std::cin >> targetUnit;

    while (targetUnit != "km" && targetUnit != "m" && targetUnit != "cm" && targetUnit != "mm") {
        std::cout << "Invalid target unit, please enter a valid target unit(km, m, cm, mm): ";
        std::cin >> targetUnit;

    }


    if (unit == "km" && targetUnit == "km") {
        convertedLength = length;

    }
    else if (unit == "km" && targetUnit == "m") {
        convertedLength = length * 1000;

    }
    else if (unit == "km" && targetUnit == "cm") {
        convertedLength = length * 100000;

    }
    else if (unit == "km" && targetUnit == "mm") {
        convertedLength = length * 1000000;

    }
    else if (unit == "m" && targetUnit == "km") {
        convertedLength = length / 1000;

    }
    else if (unit == "m" && targetUnit == "m") {
        convertedLength = length;

    }
    else if (unit == "m" && targetUnit == "cm") {
        convertedLength = length * 100;

    }
    else if (unit == "m" && targetUnit == "mm") {
        convertedLength = length * 1000;

    }
    else if (unit == "cm" && targetUnit == "km") {
        convertedLength = length / 100000;

    }
    else if (unit == "cm" && targetUnit == "m") {
        convertedLength = length / 100;

    }
    else if (unit == "cm" && targetUnit == "cm") {
        convertedLength = length;

    }
    else if (unit == "cm" && targetUnit == "mm") {
        convertedLength = length * 10;

    }
    else if (unit == "mm" && targetUnit == "km") {
        convertedLength = length / 1000000;

    }
    else if (unit == "mm" && targetUnit == "m") {
        convertedLength = length / 1000;

    }
    else if (unit == "mm" && targetUnit == "cm") {
        convertedLength = length / 10;

    }
    else if (unit == "mm" && targetUnit == "mm") {
        convertedLength = length;

    }
    else {
        std::cout << "There was an error. ";

    }

    std::cout << "The length in " << targetUnit << " is equal to " << convertedLength << std::endl;
    
    return 0;
}


int main() {
    std::cout << "----Calculator27----" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Raise to power" << std::endl;
    std::cout << "6. Find square root" << std::endl;
	std::cout << "7. Pythagorean Theorem" << std::endl;
    std::cout << "8. Convert length" << std::endl;
    std::cout << "9. Exit program" << std::endl;

    while (true) {
        double a, b;
        int choice;

        std::cout << "\nChoose a number between 1-9: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-Invalid input. Please enter a number between 1-9." << std::endl;
            continue;
        }

        if (choice == 9) {
            std::cout << "Exiting program.";
            break;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << add(a, b) << std::endl;
                break;
            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << subtract(a, b) << std::endl;
                break;
            case 3:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << multiply(a, b) << std::endl;
                break;
            case 4:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << divide(a, b) << std::endl;
                break;
            case 5:
                std::cout << "Enter the base: ";
                std::cin >> a;
                std::cout << "Enter the exponent: ";
                std::cin >> b;
                std::cout << "Result: " << raiseToPower(a, b) << std::endl;
                break;
            case 6:
                std::cout << "Enter a number: ";
                std::cin >> a;
                std::cout << "Result: " << squareRoot(a) << std::endl;
                break;
            case 7:
                std::cout << "Enter the length of side A: ";
                std::cin >> a;
                std::cout << "Enter the length of side B: ";
                std::cin >> b;
                std::cout << "Result: " << pythagoreanTheorem(a, b) << std::endl;
                break;
            case 8:
                convertLength();
                break;
            default:
                std::cout << "Invalid input. Please try entering a number between 1-9." << std::endl;
        }
    }
    return 0;
}