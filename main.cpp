#include<iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	    return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	    return false;
    } else {
	    return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i%4);
}

int main() {
    list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist;

    const int largest = 7;
    const int steps = 4+largest;

    bool answer = true;

    for (int i = largest-1; i>=0; i--) {
        original = list_make(i, original);
        rotated = list_make((i+steps)%largest, rotated);
    }
    
    testlist = rotate(original, 4);
    bool results  = ListEqual(testlist, rotated);

    list_print(rotated);
    list_print(testlist);

    list_t testappend = list_make();
    list_t testappend2 = list_make();
    for (int i = 7; i>=0; i--) {
        testappend = list_make(i, testappend);
        testappend2 = list_make(i+7, testappend2);
    }

    std::cout << endl;
    list_print(original);
    std::cout << endl << "sum: " << sum(original) << endl;
    std::cout << "product: " << product(original) << endl;
    std::cout << "reverse: ";
    list_print(reverse(original));
    std::cout << endl;
    std::cout << "append: ";
    list_print(append(testappend, testappend2));
    std::cout << endl;
    std::cout << "filter odd: ";
    list_print(filter_odd(original));
    std::cout << endl;
    std::cout << "filter even: ";
    list_print(filter_even(original));
    std::cout << endl;
    std::cout << "rotate: ";
    list_print(rotate(original, 2));
    std::cout << endl;
    std::cout << "insert_list: ";
    list_print(insert_list(testappend, testappend2, 8));
    std::cout << endl;
    std::cout << "chop: ";
    list_print(chop(original, 3));
    std::cout << endl;
}