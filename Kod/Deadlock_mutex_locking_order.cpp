#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mutex1;
mutex mutex2;

void funkcja1() {
    lock_guard<mutex> lock1(mutex1); // Zawsze najpierw blokujemy mutex1
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mutex2); // Następnie blokujemy mutex2
    cout << "Watek 1: uzyskal oba muteksy" << endl;
}

void funkcja2() {
    lock_guard<mutex> lock1(mutex1); // Zawsze najpierw blokujemy mutex1
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mutex2); // Następnie blokujemy mutex2
    cout << "Watek 2: uzyskal oba muteksy" << endl;
}

int main() {
    thread t1(funkcja1);
    thread t2(funkcja2);

    t1.join();
    t2.join();

    return 0;
}


