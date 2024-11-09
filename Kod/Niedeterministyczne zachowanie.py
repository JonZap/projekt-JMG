import threading

licznik = 0  # Zmienna globalna

def zwiekszLicznik():
    global licznik
    for _ in range(100000):
        licznik += 1  # Brak synchronizacji, możliwość wystąpienia warunku wyścigu

# Tworzymy dwa wątki
t1 = threading.Thread(target=zwiekszLicznik)
t2 = threading.Thread(target=zwiekszLicznik)

t1.start()
t2.start()

t1.join()
t2.join()

print(f"Koncowy licznik (bez synchronizacji): {licznik}")
