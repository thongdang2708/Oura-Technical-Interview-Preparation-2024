#include <iostream>
#include <set>
#include <stack>
#include <queue>

void validPalindrome ();
bool isPalindrome(std::string s);
void pow();
double myPow(double x, int n);
void removeElementTask();
int removeElement(std::vector<int>& nums, int val);
int removeDuplicates(std::vector<int>& nums);
void removeDuplicatesTask();
void lengthOfLastWordTask();
int lengthOfLastWord(std::string s);
void palindromeNumber ();
bool isPalindromeTwo(int x);
int countNumberOfDigits (int x);
double getReverseNumber(int x, int numberOfDigits);
int findMultiplyBy10BelowOneDigit (int number);
void twoSumTask ();
std::vector<int> twoSum(std::vector<int>& nums, int target);
void singleNumberTask();
int singleNumber(std::vector<int>& nums);
void indexOfFirstOccurrence();
int strStr(std::string haystack, std::string needle);
void containsDuplicateTask ();
bool containsDuplicate(std::vector<int>& nums);
void containsDuplicateTaskTwo ();
bool containsNearbyDuplicate(std::vector<int>& nums, int k);
void bestTimeToBuyAndSellStock();
int maxProfit(std::vector<int>& prices);
void validAnagram ();
bool isAnagram(std::string s, std::string t);
void reverseVowelsOfStrings();
std::string reverseVowels(std::string s);
void testSet ();
void bubbleSort();
void swapPosition (int array[], int i, int f);
void uniqueNumberOfOccurences ();
bool uniqueOccurrences(std::vector<int>& arr);
void implementQueueTask();
void swapPositionForStack (std::stack<int>& stack, int i, int f);
void happyNumber ();
bool isHappy (int number);
int findHappyNumber (int number);
int squareOfDigits (int number);
void addDigitsTask();
int findSingleDigit (int num);
int countSum(int num);
void implementStack ();
void majorityElementTask ();
int majorityElement(std::vector<int>& nums);
void pascalTriangle();
std::vector<std::vector<int>> generate(int numRows);
int missingNumber (std::vector<int>& nums);
void missingNumberTask ();
int main() {
//    validPalindrome();
//    pow();
//    removeElementTask();
//    removeDuplicatesTask();
//    lengthOfLastWordTask();
//    palindromeNumber();
//    twoSumTask();
//    singleNumberTask();
//    indexOfFirstOccurrence();
//    containsDuplicateTask();
//    containsDuplicateTaskTwo();
//    bestTimeToBuyAndSellStock();
//    validAnagram();
//    reverseVowelsOfStrings();
//    testSet();
//    bubbleSort();
//    bestTimeToBuyAndSellStock();
//    uniqueNumberOfOccurences();
//      implementQueueTask();
//    happyNumber();
//    addDigitsTask();
//    implementStack();
//      majorityElementTask();
//    pascalTriangle();
    missingNumberTask();
    return 0;
};

void missingNumberTask () {
    std::vector<int> numsOne = {3,0,1};
    std::vector<int> numsTwo = {0,1};
    std::vector<int> numsThree = {9,6,4,2,3,5,7,0,1};

    int resultOne = missingNumber(numsOne);
    int resultTwo = missingNumber(numsOne);
    int resultThree = missingNumber(numsThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

int missingNumber (std::vector<int>& nums) {

    std::sort(nums.begin(), nums.end());

    int firstNumber = 0;
    int lastNumber = nums.size();

    for (int i=firstNumber; i<=lastNumber; i++) {
        if (std::count(nums.begin(), nums.end(), i) == 0) {
            return i;
        }
    }

    return -1;



}

void pascalTriangle () {

    int numRows = 5;

    std::vector<std::vector<int>> resultOne = generate(numRows);

    for (const auto& element: resultOne) {
        for (const auto& minorElement: element) {
            std::cout << minorElement << std::endl;
        }
    }

}

std::vector<std::vector<int>> generate(int numRows) {

    std::vector<std::vector<int>> rowNumbers;

    std::vector<int> numbers;
    numbers.push_back(1);
    rowNumbers.push_back(numbers);

    for (int i=1; i<numRows; i++) {
        std::vector<int> previousRowNumber = rowNumbers[i-1];
        std::vector<int> array;
        array.push_back(1);

        for (int j=1; j < previousRowNumber.size(); j++) {

            array.push_back(previousRowNumber[j] + previousRowNumber[j-1]);
        };

        array.push_back(1);

        rowNumbers.push_back(array);
    };

    return rowNumbers;
}


void majorityElementTask () {

    std::vector<int> numsOne = {3,2,3};
    std::vector<int> numsTwo = {2,2,1,1,1,2,2};

    int resultOne = majorityElement(numsOne);
    int resultTwo = majorityElement(numsTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
}

int majorityElement(std::vector<int>& nums) {

    std::unordered_map<int, int> map;

    for (int i=0; i<nums.size(); i++) {
        if (map.count(nums[i]) != 0) {
            map[nums[i]] = map.at(nums[i]) + 1;
        } else {
            map[nums[i]] = 1;
        }
    };


    for (std::pair<int, int> element: map) {
       if (element.second > (nums.size() / 2)) {
           return element.first;
       }
    }

    return 0;

}

class MyStack {
private:
    std::queue<int> queue;
public:
    MyStack() {
        std::queue<int> queue;
        this->queue = queue;
    }

    void push(int x) {
        this->queue.push(x);
    };

    int pop() {

        std::vector<int> result;

        while (!this->queue.empty()) {
            result.push_back(this->queue.front());
            this->queue.pop();
        };

        for (int i=0; i<result.size() - 1; i++) {
            this->queue.push(result[i]);
        };

        return result[result.size() -1];

    }

    int top() {

        std::vector<int> result;

        while (!this->queue.empty()) {

            result.push_back(this->queue.front());
            this->queue.pop();
        };

        for (int i=0; i<result.size(); i++) {
            this->queue.push(result[i]);
        }

        return result[result.size() - 1];
    }

    bool empty() {

        if (this->queue.empty()) {
            return true;
        };

        return false;
    }
};


void implementStack () {

    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    std::cout << std::boolalpha;
    std::cout << myStack->top() << std::endl;
    std::cout << myStack->pop() << std::endl;
    std::cout <<  myStack->empty() << std::endl;

}

void addDigitsTask () {

    int numberOne = 38;
    int numberTwo = 0;

    int resultOne = findSingleDigit(numberOne);
    int resultTwo = findSingleDigit(numberTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;

}

int findSingleDigit (int num) {

    if (num >=0 && num < 10) {
        return num;
    };

    return findSingleDigit(countSum(num));


};

int countSum (int num) {

    int result = 0;

    if (num == 0) {
        return result;
    };

    int newResult = countSum(num / 10);
    newResult += num % 10;
    return newResult;
}

void happyNumber () {
    int numberOne = 19;
    int numberTwo = 2;
    int numberThree = 7;
    int numberFour = 1111111;

    bool resultOne = isHappy(numberOne);
    bool resultTwo = isHappy(numberTwo);
    bool resultThree = isHappy(numberThree);
    bool resultFour = isHappy(numberFour);

    std::cout << std::boolalpha;
    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
    std::cout << resultFour << std::endl;
};

bool isHappy (int number) {


    int happyNumber = findHappyNumber(number < 10 ? squareOfDigits(number) : number);

    if (happyNumber != 1 && happyNumber != 7) {
        return false;
    };

    return true;
};

int findHappyNumber (int number) {

    if (number >= 0 && number < 10) {
        return number;
    };

    return findHappyNumber(squareOfDigits(number));

};

int squareOfDigits (int number) {

    int result = 0;

    if (number == 0) {
        return result;
    };

    int newResult = squareOfDigits(number / 10);
    newResult += std::pow(number % 10, 2);
    return newResult;
}

class MyQueue {
private:
    std::stack<int> stack;
public:
    MyQueue() {
        std::stack<int> stack;
        this->stack = stack;

    }

    void push(int x) {
       this->stack.push(x);

    }

    int pop() {

        std::vector<int> numbers;

        while (!this->stack.empty()) {
            numbers.push_back(this->stack.top());
            this->stack.pop();
        };

        for (int i=numbers.size() - 2; i>=0; i--) {
            this->stack.push(numbers[i]);
        }

        return numbers[numbers.size() - 1];


    }

    int peek() {

        std::vector<int> stackTwo;
        while (!this->stack.empty()) {
            stackTwo.push_back(this->stack.top());
            this->stack.pop();
        }

        for (int i=stackTwo.size() - 1; i>=0; i--) {
            this->stack.push(stackTwo[i]);
        }

        return stackTwo[stackTwo.size() - 1];

    }

    bool empty() {
        if (this->stack.empty()) {
            return true;
        };

        return false;
    }
};

void implementQueueTask () {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    std::cout << std::boolalpha;
    std::cout << myQueue.peek() << std::endl;

    std::cout << myQueue.pop() << std::endl;
    std::cout << myQueue.empty() << std::endl;



}

void uniqueNumberOfOccurences () {
    std::vector<int> arrOne = {1,2,2,1,1,3};
    std::vector<int> arrTwo = {1, 2};
    std::vector<int> arrThree = {-3,0,1,-3,1,1,1,-3,10,0};

    bool resultOne = uniqueOccurrences(arrOne);
    bool resultTwo = uniqueOccurrences(arrTwo);
    bool resultThree = uniqueOccurrences(arrThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

bool uniqueOccurrences (std::vector<int>& number) {

    std::unordered_map<int, int> map;

    for (int i=0; i<number.size(); i++) {
        if (map.count(number[i]) != 0) {
            map[number[i]] = map.at(number[i]) + 1;
        } else {
            map[number[i]] = 1;
        }
    };

    std::vector<int> getNumbers;
    for (const std::pair<int, int> element: map) {
        getNumbers.push_back(element.second);
    };

    std::set<int> set;

    for (int i=0; i<getNumbers.size(); i++) {
        set.insert(getNumbers[i]);
    };

    if (getNumbers.size() == set.size()) {
        return true;
    };

    return false;
}


void bubbleSort () {

    int array[] = {2, 3 ,6, 7 , 1};

    for (int i=std::size(array) - 1; i>=0; i--) {
        for (int j=0; j<i; j++) {
            if (array[j] > array[j+1]) {
                swapPosition(array, j, j + 1);
            }
        }
    }

    for (int i=0; i<std::size(array); i++) {
        std::cout << array[i] << std::endl;
    }
}

void swapPosition (int array[], int i, int j) {

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void testSet () {

    std::set<int> numbers;

    int array[] = {2, 3, 4, 8, 1, 2, 7};

    for (int i=0; i < std::size(array); i++) {
        numbers.insert(array[i]);
    };

    for (const auto& element: numbers) {
        std::cout << element << std::endl;
    }

}

void reverseVowelsOfStrings() {

    std::string stringOne = "hello";
    std::string stringTwo = "leetcode";

    std::string resultOne = reverseVowels(stringOne);
    std::string resultTwo = reverseVowels(stringTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;

};

std::string reverseVowels(std::string s) {

    std::stack<char> characters;

    for (int i=0; i<s.length(); i++) {
        if (std::tolower(s[i]) == 'a' || std::tolower(s[i])  == 'e' || std::tolower(s[i])  == 'i' || std::tolower(s[i])  == 'o' || std::tolower(s[i])  == 'u') {
            characters.push(s[i]);
        }
    }

    std::string result = "";

    for (int i=0; i<s.length(); i++) {
        if ((std::tolower(s[i]) == 'a' || std::tolower(s[i])  == 'e' || std::tolower(s[i])  == 'i' || std::tolower(s[i])  == 'o' || std::tolower(s[i]) == 'u') && !characters.empty()) {
            result += characters.top();
            characters.pop();
        } else {
            result += s[i];
        }
    }

    return result;
}

//std::string reverseVowels(std::string s) {
//
//    for (int i=0; i<s.length(); i++){
//
//    }
//}

void validAnagram () {

    std::string s = "anagram";
    std::string t = "nagaram";

    std::string s2 = "car";
    std::string t2 = "rat";

    std::string s3 = "salvages";
    std::string t3 = "Las Vegas";

    std::string s4 = "ab";
    std::string t4 = "a";

    std::string s5 = "aa";
    std::string t5 = "a";

    std::string s6 = "aacc";
    std::string t6 = "ccac";

    std::string s7 = "acacbac";
    std::string t7 = "bbbbbac";

    std::string s8 = "xaaddy";
    std::string t8 = "xbbccy";


    bool resultOne = isAnagram(s, t);
    bool resultTwo = isAnagram(s2, t2);
    bool resultThree = isAnagram(s3, t3);
    bool resultFour = isAnagram(s4, t4);
    bool resultFive = isAnagram(s5, t5);
    bool resultSix = isAnagram(s6, t6);
    bool resultSeven = isAnagram(s7, t7);
    bool resultEight = isAnagram(s8, t8);

    std::cout << std::boolalpha;

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
    std::cout << resultFour << std::endl;
    std::cout << resultFive << std::endl;
    std::cout << resultSix << std::endl;
    std::cout << resultSeven << std::endl;
    std::cout << resultEight << std::endl;

};

bool isAnagram(std::string s, std::string t) {

    std::unordered_map<char, int> mapOne;
    std::unordered_map<char, int> mapTwo;

    std::string newStringS = "";
    std::string newStringT = "";
    for (int i=0; i<s.length(); i++) {
        if (std::isalnum(s[i])) {
            newStringS += std::tolower(s[i]);
        } else {
            newStringS += "";
        }
    };

    for (int i=0; i<t.length(); i++) {
        if (std::isalnum(t[i])) {
            newStringT += std::tolower(t[i]);
        } else {
            newStringT += "";
        }
    };

    for (int i=0; i<newStringS.length(); i++) {
        if (mapOne.count(newStringS[i]) != 0) {
            mapOne[newStringS[i]] = mapOne.at(newStringS[i]) + 1;
        } else {
            mapOne[newStringS[i]] = 1;
        }
    }

    for (int i=0; i<newStringT.length(); i++) {
        if (mapTwo.count(newStringT[i]) != 0) {
            mapTwo[newStringT[i]] = mapTwo.at(newStringT[i]) + 1;
        } else {
            mapTwo[newStringT[i]] = 1;
        }
    };

    if (mapOne.size() != mapTwo.size()) {
        return false;
    };

    int count = 0;

    for (std::pair<char, int> element: mapOne) {

        if (mapTwo.count(element.first) != 0 && mapTwo[element.first] == element.second) {
            count++;
        }

    }

    std::cout << count << std::endl;
    if (count == mapOne.size()) {
        return true;
    }
    return false;


}

void bestTimeToBuyAndSellStock () {

    std::vector<int> pricesOne = {7,1,5,3,6,4};
    std::vector<int> pricesTwo = {7,6,4,3,1};

    int maxProfitOne = maxProfit(pricesOne);
    int maxProfitTwo = maxProfit(pricesTwo);

    std::cout << maxProfitOne << std::endl;
    std::cout << maxProfitTwo << std::endl;

};

int maxProfit(std::vector<int>& prices) {

    int minNumber = INT_MAX;
    int maxNumber = 0;

    for (int i=0; i<prices.size(); i++) {
        if (prices[i] < minNumber) {
            minNumber = prices[i];
        } else {
            maxNumber = std::max(maxNumber, prices[i] - minNumber);
        }

    }

    return maxNumber;
}

void containsDuplicateTaskTwo () {
    std::vector<int> numsOne = {1,2,3,1};
    int kOne = 3;
    std::vector<int> numsTwo = {1,0,1,1};
    int kTwo = 1;
    std::vector<int> numsThree = {1,2,3,1,2,3};
    int kThree = 2;

    bool resultOne = containsNearbyDuplicate(numsOne, kOne);
    bool resultTwo = containsNearbyDuplicate(numsTwo, kTwo);
    bool resultThree = containsNearbyDuplicate(numsThree, kThree);

    std::cout << std::boolalpha;
    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;

};

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {

    std::unordered_map<int, int> map;std::vector<int> numbers;

    for (int i=0; i<nums.size(); i++) {
        if (map.count(nums[i]) != 0) {
            if (std::abs(i - map.at(nums[i])) <= k) {
                return true;
            }
        }

        map[nums[i]] = i;

    }

    return false;
}



void containsDuplicateTask () {

    std::vector<int> numsOne = {1,2,3,1};
    std::vector<int> numsTwo = {1,2,3,4};
    std::vector<int> numsThree = {1,1,1,3,3,4,3,2,4,2};

    bool resultOne = containsDuplicate(numsOne);
    bool resultTwo = containsDuplicate(numsTwo);
    bool resultThree = containsDuplicate(numsThree);

    std::cout << std::boolalpha;

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

bool containsDuplicate(std::vector<int>& nums) {

    std::unordered_map<int, int> map;

    for (int i=0; i<nums.size(); i++) {
        if (map.count(nums[i]) != 0) {
            map[nums[i]] = map.at(nums[i]) + 1;
        } else {
            map[nums[i]] = 1;
        }
    };

    for (std::pair<int, int> element: map) {
        if (element.second > 1) {
            return true;
        }
    };

    return false;
}



void indexOfFirstOccurrence () {

    std::string haystack = "sadbutsad";
    std::string needle = "sad";

    std::string hayStackTwo = "leetcode";
    std::string needleTwo = "leeto";

    int result = strStr(haystack, needle);
    int resultTwo = strStr(hayStackTwo, needleTwo);

    std::cout << result << std::endl;
    std::cout << resultTwo << std::endl;
};

int strStr (std::string haystack, std::string needle) {

    if (haystack.find(needle) != -1) {
        return haystack.find(needle);
    }

    return -1;
}

void singleNumberTask () {

    std::vector<int> numsOne = {2, 2, 1};
    std::vector<int> numsTwo = {4,1,2,1,2};
    std::vector<int> numsThree = {1};

    int resultOne = singleNumber(numsOne);
    int resultTwo = singleNumber(numsTwo);
    int resultThree = singleNumber(numsThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

int singleNumber (std::vector<int>& nums) {

    std::unordered_map<int, int> map;

    for (int i=0; i<nums.size(); i++) {
        if (map.count(nums[i]) != 0) {
            map[nums[i]] = map.at(nums[i]) + 1;
        } else {
            map[nums[i]] = 1;
        }
    };

    for (std::pair<int, int> element: map) {
        if (element.second == 1) {
            return element.first;
        }
    };

    return 0;
};

void twoSumTask () {

    std::vector<int> numsOne = {2,7,11,15};
    int targetOne = 9;

    std::vector<int> numsTwo = {3,2,4};
    int targetTwo = 6;

    std::vector<int> numsThree = {3, 3};
    int targetThree = 6;

    std::vector<int> resultOne = twoSum(numsOne, targetOne);
    std::vector<int> resultTwo = twoSum(numsTwo, targetTwo);
    std::vector<int> resultThree = twoSum(numsThree, targetThree);

    for (const auto& element: resultOne) {
        std::cout << element << std::endl;
    };

    for (const auto& element: resultTwo) {
        std::cout << element << std::endl;
    };

    for (const auto& element: resultThree) {
        std::cout << element << std::endl;
    }
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {

    std::vector<int> result;

    std::unordered_map<int, int> map;

    for (int i=0; i<nums.size(); i++) {
        int diff = target - nums[i];

        if (map.count(diff) != 0) {
            result.push_back(map.at(diff));
            result.push_back(i);
            return result;
        };

        map[nums[i]] = i;
    }

    return result;
}



void palindromeNumber () {

    int xOne = 121;
    int xTwo = -121;
    int xThree = 10;
    int xFour = -1234;

    bool resultOne = isPalindromeTwo(xOne);
    bool resultTwo = isPalindromeTwo(xTwo);
    bool resultThree = isPalindromeTwo(xThree);
    bool resultFour = isPalindromeTwo(xFour);
    bool resultFive = isPalindromeTwo(1234567899);

    std::cout << std::boolalpha;
    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
    std::cout << resultFour << std::endl;
    std::cout << resultFive << std::endl;
};

bool isPalindromeTwo(int x) {

    int numberOfDigits = countNumberOfDigits(x);
    double reverseNumber = getReverseNumber(x, numberOfDigits) > 0 ? getReverseNumber(x, numberOfDigits) : getReverseNumber(x, numberOfDigits) * -1;

    if (x < 0) {
        return false;
    };

    if (x == reverseNumber) {
        return true;
    };

    return false;

};

int countNumberOfDigits (int x) {

    int count = 0;

    if (x == 0) {
        return count;
    };

    int newResult = countNumberOfDigits(x / 10);
    newResult++;
    return newResult;
};

double getReverseNumber(int x, int numberOfDigits) {

    double result = 0;

    if (numberOfDigits == 0) {
        return result;
    };

    double newResult = getReverseNumber(x, numberOfDigits - 1);
    newResult = newResult * 10 + (x / findMultiplyBy10BelowOneDigit(numberOfDigits - 1)) % 10;
    return newResult;
};

int findMultiplyBy10BelowOneDigit (int number) {

    int result = 1;

    if (number == 0) {
        return result;
    };

    int newResult = findMultiplyBy10BelowOneDigit(number - 1);
    newResult *= 10;
    return newResult;
}

void lengthOfLastWordTask () {

    std::string stringOne = "Hello World";
    std::string stringTwo = "   fly me   to   the moon  ";
    std::string stringThree = "luffy is still joyboy";

    int resultOne = lengthOfLastWord(stringOne);
    int resultTwo = lengthOfLastWord(stringTwo);
    int resultThree = lengthOfLastWord(stringThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

int lengthOfLastWord(std::string s) {

    std::vector<std::string> listOfStrings;
    std::vector<std::string> removeEmptyStringElements;
    std::string parsedString = "";

    for (int i=0; i<s.length(); i++) {
        if (std::isalnum(s[i])) {
            parsedString += s[i];
        } else {
            listOfStrings.push_back(parsedString);
            parsedString = "";
        }

    };

    listOfStrings.push_back(parsedString);

    for (int i=0; i<listOfStrings.size(); i++) {
        if (listOfStrings[i].length() != 0) {
            removeEmptyStringElements.push_back(listOfStrings[i]);
        }
    }

    return removeEmptyStringElements[removeEmptyStringElements.size() - 1].length();
}


void removeDuplicatesTask () {

    std::vector<int> numsOne = {1, 1, 2};
    std::vector<int> numsTwo = {0,0,1,1,1,2,2,3,3,4};
    int resultOne = removeDuplicates(numsOne);
    int resultTwo = removeDuplicates(numsTwo);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
};

int removeDuplicates(std::vector<int>& nums) {

    int count = 1;


    for (int i=1; i<nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            nums[count++] = nums[i];
        }
    };

    return count;
}

void removeElementTask () {

    std::vector<int> numsOne = {3, 2, 2, 3};
    int valOne = 3;

    int resultOne = removeElement(numsOne, valOne);

    std::cout << resultOne << std::endl;
}

int removeElement(std::vector<int>& nums, int val) {

    int count = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != val) {
            nums[count++] = nums[i];
        }
    };

    return count;
}



void pow () {

    double xOne = 2.00000;
    int nOne = 10;

    double xTwo = 2.10000;
    int nTwo = 3;

    double xThree = 2.00000;
    int nThree = -2;

    double resultOne = myPow(xOne, nOne);
    double resultTwo = myPow(xTwo, nTwo);
    double resultThree = myPow(xThree, nThree);

    std::cout << resultOne << std::endl;
    std::cout << resultTwo << std::endl;
    std::cout << resultThree << std::endl;
};

double myPow(double x, int n) {

    return std::pow(x, n);
}




void validPalindrome () {
    std::string s_1 = "A man, a plan, a canal: Panama";
    std::string s_2 = "race a car";
    std::string s_3 = " ";
    bool isPalindromeOne = isPalindrome(s_1);
    bool isPalindromeTwo = isPalindrome(s_2);
    bool isPalindromeThree = isPalindrome(s_3);

    std::cout << std::boolalpha;
    std::cout<< isPalindromeOne << std::endl;
    std::cout<< isPalindromeTwo << std::endl;
    std::cout << isPalindromeThree << std::endl;
}

bool isPalindrome(std::string s) {

    std::vector<std::string> listOfStrings;

    for (int i=0; i < s.size(); i++) {

        if (std::isalnum(s[i])) {
            std::string singleString = "";
            singleString += std::tolower(s[i]);
            listOfStrings.push_back(singleString);
        };

    };

    std::string resultOne = "";
    for (int i=listOfStrings.size() - 1; i>=0; i--) {
        resultOne += listOfStrings[i];
    };

    std::string resultTwo = "";

    for (int i=0; i<listOfStrings.size(); i++) {
        resultTwo += listOfStrings[i];
    }

    if (resultOne == resultTwo) {
        return true;
    };

    return false;


}

