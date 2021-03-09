#include "MultithreadedMCSS.h"

int main() {
    std::cout <<" ==== Starts the simulation of " << theNumHists << " trajectory histories..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    Histograms histograms = Simulate();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<real_type> time_span =
            std::chrono::duration_cast<std::chrono::duration<real_type>>(end -
                                                                         start);
    std::cout << time_span.count() << " seconds" << std::endl;
    std::cout << "Finished." << std::endl;
    return 0;
}