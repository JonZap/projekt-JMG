import threading
import time

# Funkcja, która wykonuje długą operację
def wykonaj_ciezka_operacje():
    total = 0
    for _ in range(10**7):  # Wykonujemy dużo operacji
        total += 1
    return total

# Funkcja uruchamiająca wątki
def watek(wynik, indeks):
    wynik[indeks] = wykonaj_ciezka_operacje()

def main():
    liczby_watkow = [1, 2, 4, 8, 16]  # Liczba wątków, którą przetestujemy
    for liczba in liczby_watkow:
        wynik = [0] * liczba  # Lista do przechowywania wyników
        watki = []
        
        start = time.time()
        
        # Tworzenie i uruchamianie wątków
        for i in range(liczba):
            t = threading.Thread(target=watek, args=(wynik, i))
            watki.append(t)
            t.start()

        # Czekamy na zakończenie wszystkich wątków
        for t in watki:
            t.join()

        end = time.time()

        print(f"Liczba wątków: {liczba}, Czas wykonania: {end - start:.4f} sekundy")

if __name__ == "__main__":
    main()
