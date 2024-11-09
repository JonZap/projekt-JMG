import threading
import time
import os

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
    liczba_rdzeni = os.cpu_count()  # Zmienna z liczbą rdzeni
    print(f"Zauważ, że liczba rdzeni to: {liczba_rdzeni}")
    
    wynik = [0] * liczba_rdzeni  # Lista do przechowywania wyników
    watki = []
    
    start = time.time()

    # Tworzymy dokładnie tyle wątków, ile mamy rdzeni
    for i in range(liczba_rdzeni):
        t = threading.Thread(target=watek, args=(wynik, i))
        watki.append(t)
        t.start()

    # Czekamy na zakończenie wszystkich wątków
    for t in watki:
        t.join()

    end = time.time()
    print(f"Czas wykonania z optymalną liczbą wątków: {end - start:.4f} sekundy")

if __name__ == "__main__":
    main()
