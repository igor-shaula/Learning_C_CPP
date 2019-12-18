int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

void testRangeBasedForLoop() {
    int sum = 0;
    for (int x : array) // here 'x' is assigned by value - array's content cannot be changed
        sum += x;
    for (int &x : array) // here 'x' is assigned by reference - array's content may be changed
        x *= 2;
}

int main() {
    testRangeBasedForLoop();
    return 0;
}

/*
 * range-based-for is applied to:
 * - embedded arrays
 * - initialization lists
 * - containers from standard library
 * - any types which have defined functions begin() and end() and returning iterators
 */