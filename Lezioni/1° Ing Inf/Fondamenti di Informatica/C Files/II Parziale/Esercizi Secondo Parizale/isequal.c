typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

#define epsilon 0.00001

boolean isequal(float a, float b) {
    float diff, largest;

    diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);

    largest = a > b ? a : b;
    if (diff <= epsilon * largest) {
        return TRUE;
    } else {
        return FALSE;
    }
}