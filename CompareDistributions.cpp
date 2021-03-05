#include <iostream>
#include <fstream>
#include "Utils/ks-test.h"

// Compare the distributions of the original MCSS program with the multi-threaded
// implementation in order to check correctness.
int main() {
    std::ofstream file;
    file.open("K-S Test Results.txt");

    std::list<double> list1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::list<double> list2 = {1.1, 5.2, 4.4, 6.6, 1.6, 6.56, 24.2, 3, 45.1, 55};

    double p = ks_test(list1, list2, file);
    std::cout << "K-S test p-value is " << p << std::endl;
    file.close();

//    runSimulation();
    return 0;
}

