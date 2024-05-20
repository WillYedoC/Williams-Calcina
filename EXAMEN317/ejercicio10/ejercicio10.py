import multiprocessing as mp

def generar_serie(inicio, N, paso, cola):
    serie = [inicio + j * paso for j in range(N)]
    cola.put(serie)

def main():
    M = int(input("Ingrese el numero de vectores (M): "))
    N = int(input("Ingrese el numero de terminos (N): "))

    paso = 2
    colas = [mp.Queue() for _ in range(M)]
    procesos = []

    for i in range(M):
        inicio = (i * N + 1) * paso
        p = mp.Process(target=generar_serie, args=(inicio, N, paso, colas[i]))
        procesos.append(p)
        p.start()

    for p in procesos:
        p.join()

    series = [cola.get() for cola in colas]

    print("Serie generada:")
    for i in range(M):
        print(f"Vector {i + 1}: {' '.join(map(str, series[i]))}")

if __name__ == "__main__":
    main()
