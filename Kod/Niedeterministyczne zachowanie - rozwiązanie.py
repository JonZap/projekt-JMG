import threading

licznik = 0  # Zmienna globalna
lock = threading.Lock()  # Tworzymy zamek

def zwiekszLicznik():
    global licznik
    for _ in range(100000):
        with lock:  # Zabezpieczamy sekcję krytyczną za pomocą zamka
            licznik += 1

# Tworzymy dwa wątki
t1 = threading.Thread(target=zwiekszLicznik)
t2 = threading.Thread(target=zwiekszLicznik)

t1.start()
t2.start()

t1.join()
t2.join()

print(f"Koncowy licznik (z synchronizacją): {licznik}")
