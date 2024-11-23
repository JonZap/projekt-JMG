#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mutex1;
mutex mutex2;

void funkcja1() {
    while (true) { // Próba blokady mutex1
        if (mutex1.try_lock()) {
            if (mutex2.try_lock()) { // Próba blokady mutex2
                cout << "Watek 1: uzyskal oba muteksy" << endl;
                mutex2.unlock();
                mutex1.unlock();
                break;
            }
            else {
                mutex1.unlock(); // Zwolnij mutex1, jeśli nie uda się zablokować mutex2
            }
        }
        this_thread::sleep_for(chrono::milliseconds(50)); // Krótkie oczekiwanie przed kolejną próbą
    }
}

void funkcja2() {
    while (true) { // Próba blokady mutex2
        if (mutex2.try_lock()) {
            if (mutex1.try_lock()) { // Próba blokady mutex1
                cout << "Watek 2: uzyskal oba muteksy" << endl;
                mutex1.unlock();
                mutex2.unlock();
                break;
            }
            else {
                mutex2.unlock(); // Zwolnij mutex2, jeśli nie uda się zablokować mutex1
            }
        }
        this_thread::sleep_for(chrono::milliseconds(50)); // Krótkie oczekiwanie przed kolejną próbą
    }
}

int main() {
    thread t1(funkcja1);
    thread t2(funkcja2);

    t1.join();
    t2.join();

    return 0;
}
