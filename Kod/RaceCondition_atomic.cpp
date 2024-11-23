#include <iostream>
#include <thread>
#include <vector>
#include <atomic> // Biblioteka do obsługi zmiennych atomowych

std::atomic<int> X(5); // Wspólna zmienna współdzielona, ale atomowa

// Funkcja, którą wykonują wątki: zwiększenie wartości X o 1
void increment() {
    for (int i = 0; i < 1000; ++i) {
        X.fetch_add(1); // Atomowe zwiększenie wartości X o 1
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
    std::cout << "Koncowa wartosc X: " << X.load() << std::endl;

    return 0;
}
