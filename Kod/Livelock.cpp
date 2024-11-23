#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

using namespace std;

// Zmienna do kontrolowania wątpliwego stanu
atomic<bool> resource_free = true;

void funkcja1() {
    while (true) {
        if (resource_free) { // Jeśli zasób jest wolny
            cout << "Watek 1: Zasob wolny, probuje go zajac...\n";
            resource_free = false;
            this_thread::sleep_for(chrono::milliseconds(50)); // Krótkie opóźnienie
            cout << "Watek 1: Zwalniam zasob, aby pierwszy mogl go uzyc\n";
            resource_free = true; // Zwolnij zasób, aby drugi wątek mógł go zająć
        }
        this_thread::sleep_for(chrono::milliseconds(50)); // Czekaj przed kolejną próbą
    }
}

void funkcja2() {
    while (true) {
        if (resource_free) { // Jeśli zasób jest wolny
            cout << "Watek 2: Zasob wolny, probuje go zajac...\n";
            resource_free = false;
            this_thread::sleep_for(chrono::milliseconds(50)); // Krótkie opóźnienie
            cout << "Watek 2: Zwalniam zasob, aby pierwszy mogl go uzyc.\n";
            resource_free = true; // Zwolnij zasób, aby pierwszy wątek mógł go zająć
        }
        this_thread::sleep_for(chrono::milliseconds(50)); // Czekaj przed kolejną próbą
    }
}

int main() {
    thread t1(funkcja1);
    thread t2(funkcja2);

    t1.join();
    t2.join();

    return 0;
}
