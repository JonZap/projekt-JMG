#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int X = 5;           // Wspólna zmienna współdzielona przez wątki
std::mutex mtx;      // Mutex do synchronizacji

// Funkcja, którą wykonują wątki: zwiększenie wartości X o 1
void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Automatyczne zablokowanie mutexu
        X = X + 1; // Zabezpieczona operacja
    }
}

int main() {
    std::vector<std::thread> threads;

    // Tworzymy dwa wątki, które jednocześnie modyfikują X
    threads.emplace_back(increment);
    threads.emplace_back(increment);

    // Czekamy na zakończenie obu wątków
    for (auto& t : threads) {
        t.join();
    }

    // Wyświetlenie końcowej wartości X
    std::cout << "Koncowa wartosc X: " << X << std::endl;

    return 0;
}
