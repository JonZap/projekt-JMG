import matplotlib.pyplot as plt
import numpy as np

# Dane do wykresów
num_threads = np.array([1, 2, 4, 8, 16])
execution_time = np.array([100, 60, 40, 35, 50])  # w ms, hipotetyczny czas wykonania
cpu_usage = np.array([20, 35, 50, 70, 95])  # w %, zużycie CPU

# Wykres 1: Liczba wątków vs. czas wykonania
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.plot(num_threads, execution_time, marker='o', linestyle='-', color='b', label='Czas wykonania')
plt.title("Liczba wątków vs. czas wykonania")
plt.xlabel("Liczba wątków")
plt.ylabel("Czas wykonania (ms)")
plt.grid(True)
plt.legend()

# Wykres 2: Liczba wątków vs. zużycie CPU
plt.subplot(1, 2, 2)
plt.plot(num_threads, cpu_usage, marker='s', linestyle='--', color='r', label='Zużycie CPU')
plt.title("Liczba wątków vs. zużycie CPU")
plt.xlabel("Liczba wątków")
plt.ylabel("Zużycie CPU (%)")
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.savefig("thread_performance_analysis.png")
plt.show()
