#include <iostream>
#include <stdexcept>

void testExceptionOne();
void testExceptionTwo();
bool isInteger (std::string string);
void sumOfDigit();
void factorial();
int factorialWithRecursion(int number);
void testCopyArray();
void reverseArray();
std::vector<int> reverseArrayWithRecursion(int array[], int size);
int fibonacciWithRecursion (int number);
int tribonacciWithRecursion (int number);
void fibonacci();
void tribonacci();
void sumOfDigit();
int sumOfDigitWithRecursion (int number);
int sumOfEvenDigitWithRecursion (int number);
void sumOfEvenDigit();
void sumOfOddDigit();
int sumOfOddDigitWithRecursion (int number);
void geometricSum();
double geometricSumWithRecursion (int number, int startingNumber);
void testMap();
void decimalToBinary();
int decimalToBinaryWithRecursion (int number);
void recursiveSumWithNumberAppends();
int numberAppendsWithRecursion (int number, int x);
int recursiveSumWithNumberAppendsWithoutLoop(int number, int x);
int findMultiplyBy10 (int number);
int numberSumWithRecursion (int number);
int sumOfElementsWithRecursion (int number);
void sumOfDigitsTillASingleDigit ();
int sumOfDigitsTillASingleDigitWithoutLoop (int number, int x);
int powerOfNumber(int number, int x);
int sumOfDigitsTillASingleDigitWithRecursion (int number);
int sumOfDigitsForASingleDigitForRecursion (int number);
int getSum (int number);
void findFirstAndLastNumber();
void findFirstAndLastNumberWithRecursion (int number);
int findFirstDigit (int number);
void narcisNumber ();
int findNarcisNumber (int number);
int findNumberOfDigitsOfNumber (int number);
int findSumOfNumberFromPower (int number, int power, int fixedPower);
int findMultiplyBy10BelowDigit (int number);
void checkLetter();

int main() {

//    testExceptionOne();
//    testExceptionTwo();
//    factorial();
//    testCopyArray();
//    reverseArray();
//    fibonacci();
//    tribonacci();
//    sumOfDigit();
//    sumOfEvenDigit();
//    sumOfOddDigit();
//    geometricSum();
//    testMap();
//    decimalToBinary();
//    recursiveSumWithNumberAppends();
//    sumOfDigitsTillASingleDigit();
//    findFirstAndLastNumber();

//    narcisNumber();
    checkLetter();
    return 0;
};

void checkLetter () {

    std::string string = "abcdef";

    std::vector<std::string> listOfStrings;

    for (int i=0; i<string.size(); i++) {
        std::string singleString = "";
        singleString += string[i];
        listOfStrings.push_back(singleString);
    };

    for (const auto& element: string) {
        std::cout << element << std::endl;
    }
}

void testCopyArray () {

    int array[] = {1, 2, 3, 4, 5};

    int* newArray = new int[std::size(array) - 1];
    std::copy(array + 0, array + std::size(array) - 1, newArray);

    for (int i=0; i < std::size(array) - 1; i++) {
        std::cout << *(newArray + i) << std::endl;
    }

    delete[] newArray;

}

void testExceptionOne () {

    try {

        int number;

        std::cout << "Enter a number: ";
        std::cin >> number;

        if (std::cin.fail()) {
            throw std::invalid_argument("String or char is given. Not a valid number!");
        }

        if (number < 0) {
            throw number;
        }

        std::cout << number << " is a valid number!" << std::endl;

    } catch (const std::invalid_argument& exception) {
        std::cerr << exception.what() << std::endl;
    } catch (int number) {
        std::cerr << number << " is invalid as it is negative!" << std::endl;
    }

};

bool isInteger (std::string string) {

    try {
        std::stoi(string);
        return true;
    } catch (const std::invalid_argument& exception) {
        return false;
    } catch (const std::out_of_range& exception) {
        return false;
    }
}

void testExceptionTwo () {

    try {

        std::string string;

        std::cout << "Get a string: ";
        std::getline(std::cin, string);

        if (isInteger(string)) {
            throw std::invalid_argument("This string is a number! Invalid!");
        }

        std::cout << string << " is a valid string!" << std::endl;

    } catch (const std::invalid_argument& exception) {
        std::cerr << exception.what() << std::endl;
    }
};

void factorial () {

    int numberOne = 3;
    int numberTwo = 6;
    int numberThree = 5;
    int numberFour = 4;

    int resultOne = factorialWithRecursion(numberOne);
    int resultTwo = factorialWithRecursion(numberTwo);
    int resultThree = factorialWithRecursion(numberThree);
    int resultFour = factorialWithRecursion(numberFour);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
    std::cout << resultFour << std::endl;
};

int factorialWithRecursion (int number) {

    int result = 1;

    if (number == 0) {
        return result;
    }

    int newResult = factorialWithRecursion(number -1);
    newResult *= number;
    return newResult;
}

void reverseArray () {

    int array[] = {2, 3, 5, 2, 6};
    int size = std::size(array);
    std::vector<int> result = reverseArrayWithRecursion(array, size);

    for (const auto& element : result) {
        std::cout << element << std::endl;
    }
};

std::vector<int> reverseArrayWithRecursion (int array[], int size) {

    std::vector<int> result;

    if (size == 0) {
        return result;
    }

    int* newArray = new int[size-1];
    std::copy(array + 1, array + size, newArray);
    std::vector<int> newResult = reverseArrayWithRecursion(newArray, size-1);
    newResult.push_back(*(array + 0));
    return newResult;
};

void fibonacci() {

    int indexOne = 1;
    int indexTwo = 8;
    int indexThree = 9;

    int resultOne = fibonacciWithRecursion(indexOne);
    int resultTwo = fibonacciWithRecursion(indexTwo);
    int resultThree = fibonacciWithRecursion(indexThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
}

int fibonacciWithRecursion (int number) {

    if (number < 2) {
        return number;
    }

    return fibonacciWithRecursion(number -1) + fibonacciWithRecursion(number -2);

}

void tribonacci () {
    int indexOne = 1;
    int indexTwo = 8;
    int indexThree = 9;

    int resultOne = tribonacciWithRecursion(indexOne);
    int resultTwo = tribonacciWithRecursion(indexTwo);
    int resultThree = tribonacciWithRecursion(indexThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;

};

int tribonacciWithRecursion (int number) {

    if (number < 2) {
        return 0;
    }

    if (number == 2) {
        return 1;
    }

    return tribonacciWithRecursion(number - 1) + tribonacciWithRecursion(number -2) + tribonacciWithRecursion(number -3);
}

void sumOfDigit () {

    int numberOne = 12345;
    int numberTwo = 45632;
    int numberThree = 8657143;

    int resultOne = sumOfDigitWithRecursion(numberOne);
    int resultTwo = sumOfDigitWithRecursion(numberTwo);
    int resultThree = sumOfDigitWithRecursion(numberThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;

}

int sumOfDigitWithRecursion (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    }

    int newResult = sumOfDigitWithRecursion(number / 10);
    newResult += number % 10;
    return newResult;
};

void sumOfEvenDigit () {

    int numberOne = 12345;
    int numberTwo = 45632;
    int numberThree = 8657143;

    int resultOne = sumOfEvenDigitWithRecursion(numberOne);
    int resultTwo = sumOfEvenDigitWithRecursion(numberTwo);
    int resultThree = sumOfEvenDigitWithRecursion(numberThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

int sumOfEvenDigitWithRecursion (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    }

    int newResult = sumOfEvenDigitWithRecursion(number / 10);
    newResult += number % 2 == 0 ? number % 10 : 0;
    return newResult;

}

void sumOfOddDigit () {

    int numberOne = 12345;
    int numberTwo = 45632;
    int numberThree = 8657143;

    int resultOne = sumOfOddDigitWithRecursion(numberOne);
    int resultTwo = sumOfOddDigitWithRecursion(numberTwo);
    int resultThree = sumOfOddDigitWithRecursion(numberThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

int sumOfOddDigitWithRecursion (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    }

    int newResult = sumOfOddDigitWithRecursion(number / 10);
    newResult += number % 2 != 0 ? number % 10 : 0;
    return newResult;
};

void geometricSum () {

    int numberOne = 5;
    int numberTwo = 7;

    int startingNumber = 1;
    double resultOne = geometricSumWithRecursion(numberOne, startingNumber);
    double resultTwo = geometricSumWithRecursion(numberTwo, startingNumber);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
};

double geometricSumWithRecursion (int number, int startingNumber) {

    double result = 1.0;

    if (startingNumber > number) {
        return result;
    }

    double newResult = geometricSumWithRecursion(number, startingNumber + 1);
    newResult += (double) 1.0 / std::pow(3, startingNumber);
    return newResult;
}

void testMap () {

    std::unordered_map<int, int> map;

    int array[] = {2, 3, 6, 7, 10, 2, 3, 5, 11};

    for (int i=0; i<std::size(array); i++) {
        if (map.count(array[i]) != 0) {
            map[array[i]] = map.at(array[i]) + 1;
        } else {
            map[array[i]] = 1;
        }
    };

    for (std::pair<int, int>  element : map) {
        std::cout << element.first << " and " << element.second << std::endl;
    }
};

void decimalToBinary () {

    int numberOne = 7;
    int numberTwo = 10;

    int resultOne = decimalToBinaryWithRecursion(numberOne);
    int resultTwo = decimalToBinaryWithRecursion(numberTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
};

int decimalToBinaryWithRecursion (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    }

    int newResult = decimalToBinaryWithRecursion(number / 2);
    newResult = number % 2 + 10 * newResult;
    return newResult;
};

void recursiveSumWithNumberAppends () {

    int numberOne = 24;
    int xOne = 3;

    int numberTwo = 4;
    int xTwo = 4;

    int resultOne = recursiveSumWithNumberAppendsWithoutLoop(numberOne, xOne);
    int resultTwo = recursiveSumWithNumberAppendsWithoutLoop(numberTwo, xTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
};

int recursiveSumWithNumberAppendsWithoutLoop (int number, int x) {

    int numberAppends = numberAppendsWithRecursion(number, x);
    int totalSum = numberSumWithRecursion(numberAppends);
    return totalSum;
};

int numberAppendsWithRecursion (int number, int x) {

    int result = 0;

    if (x == 0) {
        return result;
    };

    int newResult = numberAppendsWithRecursion(number, x - 1);
    newResult = newResult * findMultiplyBy10(number) + number;
    return newResult;
};

int findMultiplyBy10 (int number) {

    int result = 1;

    if (number == 0) {
        return result;
    };

    int newResult = findMultiplyBy10(number / 10);
    newResult *= 10;
    return newResult;
};

int numberSumWithRecursion (int number) {

    int result = 0;

    if (number >= 0 && number < 10) {
        return number;
    };

    return numberSumWithRecursion(sumOfElementsWithRecursion(number));
}

int sumOfElementsWithRecursion (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    };

    int newResult = sumOfElementsWithRecursion(number / 10);
    newResult += number % 10;
    return newResult;
};

void sumOfDigitsTillASingleDigit () {

    int numberOne = 5;
    int xOne = 4;

    int numberTwo = 2;
    int xTwo = 8;

    int resultOne = sumOfDigitsTillASingleDigitWithoutLoop(numberOne, xOne);
    int resultTwo = sumOfDigitsTillASingleDigitWithoutLoop(numberTwo, xTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
};

int sumOfDigitsTillASingleDigitWithoutLoop (int number, int x) {

    int numberWithPower = powerOfNumber(number, x);
    int totalSum = sumOfDigitsTillASingleDigitWithRecursion(numberWithPower);

    return totalSum;
};

int powerOfNumber (int number, int x) {

    int result = 1;

    if (x == 0) {
        return result;
    };

    int newResult = powerOfNumber(number, x -1);
    newResult *= number;
    return newResult;
}

int sumOfDigitsTillASingleDigitWithRecursion (int number) {

    if (number >=0 && number < 10) {
        return number;
    };

    return sumOfDigitsTillASingleDigitWithRecursion(getSum(number));
};

int getSum (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    };

    int newResult = getSum(number / 10);
    newResult += number % 10;
    return newResult;

};

void findFirstAndLastNumber () {

    int numberOne = 12345;
    int numberTwo = 98562;

    findFirstAndLastNumberWithRecursion(numberOne);
    findFirstAndLastNumberWithRecursion(numberTwo);

};

void findFirstAndLastNumberWithRecursion (int number) {

    int firstDigit = findFirstDigit(number);
    int lastDigit = number % 10;

    std::cout << "First digit: " << firstDigit << std::endl;
    std::cout << "Last digit: " << lastDigit << std::endl;
};

int findFirstDigit (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    }

    int newResult = findFirstDigit(number / 10);
    newResult += number < 10 ? number : 0;
    return newResult;
};

void narcisNumber () {

    int numberOne = 153;
    int numberTwo = 1634;

    int resultOne = findNarcisNumber(numberOne);
    int resultTwo = findNarcisNumber(numberTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;

};

int findNarcisNumber (int number) {

    int numberOfDigitsOfNumber = findNumberOfDigitsOfNumber(number);

    int sumOfNumberFromPower = findSumOfNumberFromPower(number, numberOfDigitsOfNumber, numberOfDigitsOfNumber);

    return sumOfNumberFromPower;
};

int findSumOfNumberFromPower (int number, int power, int fixedPower) {

    int result = 0;

    if (power == 0) {
        return result;
    };

    int newResult = findSumOfNumberFromPower(number, power - 1, fixedPower);
    newResult += std::pow((number / findMultiplyBy10BelowDigit(power - 1)) % 10, fixedPower);
    return newResult;
}


int findMultiplyBy10BelowDigit (int number) {

    int result = 1;

    if (number == 0) {
        return result;
    };

    int newResult = findMultiplyBy10BelowDigit(number - 1);
    newResult *= 10;
    return newResult;
}


int findNumberOfDigitsOfNumber (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    };

    int newResult= findNumberOfDigitsOfNumber(number / 10);
    newResult++;
    return newResult;

};























