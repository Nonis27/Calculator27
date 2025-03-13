#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <sstream>


std::vector<std::string> history;


std::string doubleToString(double value) {
    std::ostringstream out;
    out.precision(15);
    out << std::fixed << value;
    std::string str = out.str();

    //Remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') {
        str.pop_back(); // If the last character is a '.', remove it

    }

    return str;
}


double add(double a, double b) {
    double result = a + b;
    history.push_back(doubleToString(a) + " + " + doubleToString(b) + " = " + doubleToString(result));
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    history.push_back(doubleToString(a) + " - " + doubleToString(b) + " = " + doubleToString(result));
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    history.push_back(doubleToString(a) + " * " + doubleToString(b) + " = " + doubleToString(result));
    return result;
}

double divide(double a, double b) {

    if (b != 0) {
        double result = a / b;
        history.push_back(doubleToString(a) + " / " + doubleToString(b) + " = " + doubleToString(result));
        return result;

    }
    else if (b == 0){
        std::cout << "You can't divide a number by 0." << std::endl;
        history.push_back("Attempted to divide by zero.");
        return 0;

    }
    else {
        return 0;

    }
    
}

double raiseToPower(double a, double b) {
    double result = std::pow(a, b);
    history.push_back("Raised " + doubleToString(a) + " to the power of " + doubleToString(b) + ": " + doubleToString(result));
    return result;
}

double squareRoot(double a) {
    double result = std::sqrt(a);
    history.push_back("Calculated the square root of " + doubleToString(a) + ": " + doubleToString(result));
    return result;
}

double pythagoreanTheorem(double a, double b) {
    double result = std::sqrt(a * a + b * b);
    history.push_back("Hypotenuse of sides " + doubleToString(a) + " and " + doubleToString(b) + ": " + doubleToString(result));
    return result;
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

    history.push_back("Converted " + doubleToString(length) + " " + unit + " to " + doubleToString(convertedLength) + " " + targetUnit);
    std::cout << "The length in " << targetUnit << " is equal to " << convertedLength << std::endl;
    
    return 0;
}

void printHistory() {
    std::cout << "Calculation History:" << std::endl;
    for (const auto& entry : history) {
        std::cout << entry << std::endl;

    }
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
    std::cout << "9. Print history" << std::endl;
    std::cout << "10. Exit program" << std::endl;

    while (true) {
        double a, b;
        int choice;

        std::cout << "\nChoose a number between 1-10: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-Invalid input. Please enter a number between 1-10." << std::endl;
            continue;
        }

        if (choice == 10) {
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
            case 9:
                printHistory();
                break;
            default:
                std::cout << "Invalid input. Please try entering a number between 1-10." << std::endl;
        }
    }
    return 0;
}