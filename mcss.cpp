#include "mcss_multithread.h"

#include <cstdlib>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "m:n:t:")) != -1) {
        switch (opt) {
            case 'm':
                theMaterial = (Material) atoi(optarg);
                break;
            case 'n':
                numHists = atoi(optarg);
                break;
            case 't':
                numThreads = atoi(optarg);
                break;
            default:
                std::cerr << "Invalid program options" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    std::cout << theMaterial << std::endl;
    std::cout << numHists << std::endl;
    std::cout << numThreads << std::endl;

    Multithread::Simulate();
    exit(EXIT_SUCCESS);
}