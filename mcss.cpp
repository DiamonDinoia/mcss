#include "MultithreadedMCSS.h"

int main() {
    runSimulation();
//    int i;
//    int threadID = 0;
//#pragma omp parallel for private(i, threadID)
//    for(i = 0; i < 16; i++ )
//    {
//        threadID = omp_get_thread_num();
//#pragma omp critical
//        {
//            printf("Thread %d reporting\n", threadID);
//        }
//    }
//    return 0;

    return 0;
}