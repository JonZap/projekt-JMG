import matplotlib.pyplot as plt
import numpy as np

# Symulacja wyników testów wydajności dla różnych podejść

# Dane do wykresów
methods = ['Mutex', 'Zmienne atomowe', 'Brak synchronizacji']
tasks = ['1000 zadań', '10,000 zadań', '100,000 zadań']
execution_times = {
    'Mutex': [15, 140, 1300],  # czas w ms dla różnych liczby zadań
    'Zmienne atomowe': [10, 90, 850],
    'Brak synchronizacji': [8, 70, 650]  # szybko, ale niestabilne i błędne wyniki
}

# Wykresy wyników
x = np.arange(len(tasks))  # lokalizacje dla grup

width = 0.25  # szerokość słupków
plt.figure(figsize=(10, 6))

# Słupki dla każdego podejścia
for i, (method, times) in enumerate(execution_times.items()):
    plt.bar(x + i * width, times, width, label=method)

# Ustawienia wykresu
plt.title("Wyniki testów wydajności dla różnych podejść")
plt.xlabel("Liczba zadań")
plt.ylabel("Czas wykonania (ms)")
plt.xticks(x + width, tasks)
plt.legend()
plt.grid(axis='y')

plt.tight_layout()
plt.savefig("performance_comparison_mutex_atomic.png")
plt.show()

