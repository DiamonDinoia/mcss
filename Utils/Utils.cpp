#include "Utils.h"

std::list<double> getListFromFile(std::string filename) {
    std::list<double> result;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        double d = std::stod(line);
        result.push_back(d);
    }
    return result;
}