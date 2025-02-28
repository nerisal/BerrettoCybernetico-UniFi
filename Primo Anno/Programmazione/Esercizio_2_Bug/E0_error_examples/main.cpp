#include <iostream>

// Exercise: find and correct all the bugs of this program

int maxVal(int* A, int n) {
    int currMax =0;

    for (int i=0; i<n; i++)
        if (A[i] > currMax)
            currMax = A[i];
    return currMax;
}

int main() {
    int* myArray = (int*)malloc(sizeof(int)*10);
    for (int i=0; i<9; i++)
        myArray[i] = 10-i;

    int result = maxVal(myArray, 10);
    std::cout << result << std::endl;
    return 0;
}