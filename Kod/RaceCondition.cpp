#include <iostream>
#include <thread>
#include <vector>
#include <chrono> // Do opóźnienia

int X = 5; // Wspólna zmienna współdzielona przez wątki

// Funkcja, którą wykonują wątki: zwiększenie wartości X o 1
void increment() {
    for (int i = 0; i < 1000; ++i) {
        int temp = X; // Wątek odczytuje wartość X
        std::this_thread::sleep_for(std::chrono::microseconds(1)); // Celowe opóźnienie
        temp = temp + 1; // Wątek wykonuje operację zwiększenia
        std::this_thread::sleep_for(std::chrono::microseconds(1)); // Kolejne opóźnienie
        X = temp; // Wątek zapisuje zmienioną wartość X
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
