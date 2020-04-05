#include <iostream>
#include <fstream>
#include <chrono>
#include "queue.h"
int main() {

    Queue<int> queue;


    srand(time(NULL));
    int n=500000;
    ofstream zapis;
    for (int j = 0; j < n; ++j) {
        queue.pushLow(j);
    }

    zapis.open("/home/sony/CLionProjects/AISD2/Zestaw3A/daneDeleteLow.txt",ios::out | ios::app);

    double totalTime=0;
    if (zapis.good()) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j <n ; j++) {
            queue.popAddEnd();
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        totalTime = elapsed.count();
    }
    zapis << n  << " " << totalTime << endl;

    //zapis << "e" << endl;
    zapis.flush();
    zapis.close();

    return 0;
}
