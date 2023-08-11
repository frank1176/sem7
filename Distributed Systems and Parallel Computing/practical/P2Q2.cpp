#include <iostream>
#include <vector>
#include <pthread.h>
#include <thread>

using namespace std;
#define NTHREADS 10
const int c = 100000000000;
double timerResult[NTHREADS];


class timer {
public:
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
    timer() : lastTime(std::chrono::high_resolution_clock::now()) {}
    inline double elapsed() {
        std::chrono::time_point<std::chrono::high_resolution_clock> thisTime = std::chrono::high_resolution_clock::now();
        double deltaTime = std::chrono::duration<double>(thisTime - lastTime).count();
        lastTime = thisTime;
        return deltaTime;
    }
};

void* f_count(void* v)
{
    volatile int i = 0; // volatile eliminates optimization removal
    timer stopwatch;
    while (i++ < c);
    (*(double*)timerResult) = stopwatch.elapsed();

    //(*(int*)v)++;

    return NULL;
}

int main()
{
   /* int* count = new int(0);

    vector<pthread_t> vt;

    pthread_t t;

    for (int i = 0; i < 100; i++)
        vt.push_back(t);

    for (auto x : vt)
        pthread_create(&x, NULL, &f_count, count),
        pthread_join(x, NULL);

    cout << *count;*/
    std::cout.precision(6);
    std::cout << std::fixed;
    f_count(&timerResult[0]);
    std::cout << "f1 execution time " << timerResult[0] << std::endl;
    timer stopwatch;
    {
        pthread_t THREAD_ID[NTHREADS];
        for (int i = 0; i < NTHREADS; i++) {
            pthread_create(&THREAD_ID[i], NULL, f_count, &timerResult[i]);

        }
        for (int i = 0; i < NTHREADS; i++) {
            pthread_join(THREAD_ID[i], NULL);

        }
    }
    double elapsed = stopwatch.elapsed();
    for (int i = 0; i < NTHREADS; i++) {
        
        std::cout << "thread "<< i <<" execution time " << timerResult[i] << std::endl;
    }
    std::cout << "f1 -"<< NTHREADS <<" execution time " << elapsed << std::endl;
    std::cout << "DONE" << std::endl;
    return 0;
}