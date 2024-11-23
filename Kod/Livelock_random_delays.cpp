#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <cstdlib> // Dla funkcji rand()

using namespace std;

atomic<bool> resource_free = true;

void funkcja1() {
    while (true) {
        if (resource_free) { // Jeśli zasób jest wolny
            cout << "Wątek 1: Zasób wolny, próbuję go zająć...\n";
            resource_free = false;
            this_thread::sleep_for(chrono::milliseconds(rand() % 100 + 50)); // Losowe opóźnienie
            cout << "Wątek 1: Używam zasobu\n";
            this_thread::sleep_for(chrono::milliseconds(100)); // Symulacja pracy
            resource_free = true; // Zwolnienie zasobu
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(rand() % 50 + 10)); // Losowe opóźnienie
    }
}

void funkcja2() {
    while (true) {
        if (resource_free) { // Jeśli zasób jest wolny
            cout << "Wątek 2: Zasób wolny, próbuję go zająć...\n";
            resource_free = false;
            this_thread::sleep_for(chrono::milliseconds(rand() % 100 + 50)); // Losowe opóźnienie
            cout << "Wątek 2: Używam zasobu\n";
            this_thread::sleep_for(chrono::milliseconds(100)); // Symulacja pracy
            resource_free = true; // Zwolnienie zasobu
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(rand() % 50 + 10)); // Losowe opóźnienie
    }
}

int main() {
    thread t1(funkcja1);
    thread t2(funkcja2);

    t1.join();
    t2.join();

    return 0;
}
