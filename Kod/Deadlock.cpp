#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mutex1;
mutex mutex2;

void funkcja1() {
    lock_guard<mutex> lock1(mutex1); // Blokujemy mutex1
    this_thread::sleep_for(chrono::milliseconds(100)); // Krótkie opóźnienie
    lock_guard<mutex> lock2(mutex2); // Próba zablokowania mutex2
    cout << "Wątek 1: uzyskał oba mutexy" << endl;
}

void funkcja2() {
    lock_guard<mutex> lock2(mutex2); // Blokujemy mutex2
    this_thread::sleep_for(chrono::milliseconds(100)); // Krótkie opóźnienie
    lock_guard<mutex> lock1(mutex1); // Próba zablokowania mutex1
    cout << "Wątek 2: uzyskał oba mutexy" << endl;
}

int main() {
    thread t1(funkcja1);
    thread t2(funkcja2);

    t1.join();
    t2.join();

    return 0;
}
