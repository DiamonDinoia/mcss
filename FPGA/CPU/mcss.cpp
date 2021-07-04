#include <cstdlib>
#include <unistd.h>

#include "Maxfiles.h"
#include "random_mt.h"

#include "mcss_dfe.h"

int main(int argc, char *argv[]) {
    int opt;
    Material material = GOLD;
    int numHists = 1000000;
    unsigned int numThreads = std::thread::hardware_concurrency();
    // Input flag options.
    while ((opt = getopt(argc, argv, "m:n:")) != -1) {
        switch (opt) {
            // Material
            case 'm':
                material = (Material)std::stoi(optarg);
                if (material < 0 || material > 4) {
                    std::cerr << "Invalid material" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            // Number of histories
            case 'n':
                numHists = std::stoi(optarg);
                if (numHists < 0) {
                    std::cerr << "Negative number of histories entered" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                std::cerr << "Invalid program options" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    Dfe::Simulate(material, numHists);
    exit(EXIT_SUCCESS);
}

//int main(void) {
//	Dfe::Simulate(GOLD, 1000000);
//	return 0;
//}
