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
    return a / b;
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


int main() {
    std::cout << "----Calculator27----" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Raise to power" << std::endl;
    std::cout << "6. Find square root" << std::endl;
	std::cout << "7. Pythagorean Theorem" << std::endl;
    std::cout << "8. Exit program" << std::endl;

    while (true) {
        double a, b;
        int choice;

        std::cout << "\nChoose a number between 1-8: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-Invalid input. Please enter a number between 1-8." << std::endl;
            continue;
        }

        if (choice == 8) {
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
            default:
                std::cout << "Invalid input. Please try entering a number between 1-8." << std::endl;
        }
    }
    return 0;
}