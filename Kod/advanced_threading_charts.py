import matplotlib.pyplot as plt
import numpy as np

# Dane do wykresów zaawansowanych analiz
threads_adv = np.array([1, 2, 4, 8, 16, 32])
response_time = np.array([200, 120, 80, 60, 70, 100])  # Czas odpowiedzi w ms
throughput = np.array([50, 90, 150, 200, 180, 160])  # Przepustowość (zadania na sekundę)
efficiency = throughput / threads_adv  # Efektywność wątków (hipotetyczna wartość)
scalability = np.array([1, 1.8, 3.5, 6.5, 5.8, 4.0])  # Skalowalność w wielokrotności bazowej wartości

# Wykres 7: Liczba wątków vs. czas odpowiedzi
plt.figure(figsize=(15, 10))

plt.subplot(2, 2, 1)
plt.plot(threads_adv, response_time, marker='o', linestyle='-', color='b', label='Czas odpowiedzi')
plt.title("Liczba wątków vs. czas odpowiedzi")
plt.xlabel("Liczba wątków")
plt.ylabel("Czas odpowiedzi (ms)")
plt.grid(True)
plt.legend()

# Wykres 8: Liczba wątków vs. efektywność
plt.subplot(2, 2, 2)
plt.plot(threads_adv, efficiency, marker='s', linestyle='--', color='r', label='Efektywność wątków')
plt.title("Liczba wątków vs. efektywność")
plt.xlabel("Liczba wątków")
plt.ylabel("Efektywność (zadania/wątek)")
plt.grid(True)
plt.legend()

# Wykres 9: Liczba wątków vs. skalowalność
plt.subplot(2, 2, 3)
plt.bar(threads_adv, scalability, color='g', alpha=0.7, label='Skalowalność')
plt.title("Liczba wątków vs. skalowalność")
plt.xlabel("Liczba wątków")
plt.ylabel("Skalowalność (wielokrotność bazowa)")
plt.grid(axis='y')
plt.legend()

# Wykres 10: Porównanie czasu odpowiedzi i przepustowości
plt.subplot(2, 2, 4)
plt.plot(threads_adv, response_time, marker='o', linestyle='-', color='b', label='Czas odpowiedzi')
plt.plot(threads_adv, throughput, marker='d', linestyle='--', color='m', label='Przepustowość')
plt.title("Czas odpowiedzi vs. przepustowość")
plt.xlabel("Liczba wątków")
plt.ylabel("Wartości (ms lub zadania/s)")
plt.grid(True)
plt.legend()

plt.tight_layout()

# Zapisz wykresy do pliku
plt.savefig("advanced_threading_charts.png")

# Pokaż wykresy
plt.show()
