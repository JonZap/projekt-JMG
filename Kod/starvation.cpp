#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex resourceMutex;
bool stopThreads = false;

// Funkcja, która symuluje dostęp do zasobu przez wątki
void threadFunction(int threadId, int priority) {
    while (!stopThreads) {
        std::this_thread::sleep_for(std::chrono::milliseconds(priority * 100)); // Symulacja priorytetów
        if (resourceMutex.try_lock()) {
            std::cout << "Watek " << threadId << " o priorytecie " << priority << " uzyskal dostep do zasobu." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Czas korzystania z zasobu
            resourceMutex.unlock();
        }
        else {
            std::cout << "Watek " << threadId << " o priorytecie " << priority << " nie uzyskal dostepu do zasobu." << std::endl;
        }
    }
}

int main() {
    const int threadCount = 5;
    std::vector<std::thread> threads;

    // Tworzenie wątków o różnych priorytetach
    for (int i = 0; i < threadCount; ++i) {
        threads.push_back(std::thread(threadFunction, i + 1, i + 1)); // Priorytet odpowiada numerowi wątku
    }

    // Symulacja działania programu przez 5 sekund
    std::this_thread::sleep_for(std::chrono::seconds(5));
    stopThreads = true;

    // Zakończenie wątków
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    std::cout << "Wszystkie watki zakonczyly dzialanie." << std::endl;
    return 0;
    }
    
