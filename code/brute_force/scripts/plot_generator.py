import matplotlib.pyplot as plt

def plot_time(input_path, output_path):
    sizes, times = [], []

    with open(input_path) as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 2:
                sizes.append(int(parts[0]))
                times.append(float(parts[1]))

    plt.figure()
    plt.plot(sizes, times, marker='o')
    plt.xlabel("Tamaño total (s + t)")
    plt.ylabel("Tiempo (ms)")
    plt.title("Tiempo vs Tamaño")
    plt.grid(True)
    plt.savefig(output_path)
    plt.close()

def plot_memory(input_path, output_path):
    sizes, memories = [], []

    with open(input_path) as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 3:
                sizes.append(int(parts[0]))
                memories.append(float(parts[2]))

    plt.figure()
    plt.plot(sizes, memories, marker='s', color='green')
    plt.xlabel("Tamaño total (s + t)")
    plt.ylabel("Memoria estimada (KB)")
    plt.title("Memoria vs Tamaño")
    plt.grid(True)
    plt.savefig(output_path)
    plt.close()

if __name__ == "__main__":
    input_path = "data/measurements/a.txt"
    plot_time(input_path, "data/plots/tiempo_vs_tamanoBF.png")
    plot_memory(input_path, "data/plots/memoria_vs_tamanoBF.png")
