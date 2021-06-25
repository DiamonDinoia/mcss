#include "mcss_multithread.h"

#include <cstdlib>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    Material material = GOLD;
    int numHists = 1000000;
    unsigned int numThreads = std::thread::hardware_concurrency();
    // Input flag options.
    while ((opt = getopt(argc, argv, "m:n:t:")) != -1) {
        switch (opt) {
            // Material
            case 'm':
                material = (Material)std::stoi(optarg);
                if (material < 0 || material > 4) {
                    std::cerr << "Invalid material" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            // Number of historieshistories
            case 'n':
                numHists = std::stoi(optarg);
                if (numHists < 0) {
                    std::cerr << "Negative number of histories entered" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            // Number of threads
            case 't':
                numThreads = std::stoi(optarg);
                if (numThreads < 0) {
                    std::cerr << "Negative number of threads entered" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                std::cerr << "Invalid program options" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    Multithread::Simulate(material, numHists, numThreads);
    std::cout << typeid(real_type).name() << std::endl;
    exit(EXIT_SUCCESS);
}