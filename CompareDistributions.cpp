#include <fstream>
#include <iostream>

#include "MultithreadedMCSS.h"
#include "Utils/Utils.h"
#include "Utils/ks-test.h"

// Compare the distributions of the original MCSS program with the
// multi-threaded implementation in order to check correctness.
int main() {
    std::ofstream fileLong;
    std::ofstream fileTrans;
    fileLong.open("Longitudinal K-S Test Results.txt");
    fileTrans.open("Transverse K-S Test Results.txt");

    std::list<double> originalLong = getListFromFile("Original_Res_Longi.dat");
    std::list<double> originalTrans = getListFromFile("Original_Res_Trans.dat");

    runSimulation();
    std::list<double> newLong = getListFromFile("Res_Longi.dat");
    std::list<double> newTrans = getListFromFile("Res_Trans.dat");
    //    std::list<double> newLong = getListFromFile("Reference_Res_Longi.dat");
    //    std::list<double> newTrans = getListFromFile("Reference_Res_Trans.dat");

    double pLong = ks_test(originalLong, newLong, fileLong);
    double pTrans = ks_test(originalTrans, newTrans, fileTrans);
    std::cout << "Longitudinal K-S test p-value is " << pLong << std::endl;
    std::cout << "Transverse K-S test p-value is " << pTrans << std::endl;

    fileLong.close();
    fileTrans.close();
    return 0;
}
