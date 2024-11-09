#include <iostream>
#include <thread>
#include <vector>

int sharedCounter = 0; // Wspólny zasób (zmienna)

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
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
