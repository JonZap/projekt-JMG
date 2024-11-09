#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int sharedCounter = 0; // Wspólny zasób (zmienna)
std::mutex counterMutex; // Mutex do synchronizacji

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> guard(counterMutex); // Blokowanie dostępu do zmiennej
        ++sharedCounter; // Modyfikacja wspólnej zmiennej
    }
}

int main() {
    std::vector<std::thread> threads;

    // Tworzenie 5 wątków
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(incrementCounter));
    }

    // Czekamy na zakończenie działania wątków
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    // Wynik końcowy
    std::cout << "Koncowa wartosc sharedCounter: " << sharedCounter << std::endl;

    return 0;
}
