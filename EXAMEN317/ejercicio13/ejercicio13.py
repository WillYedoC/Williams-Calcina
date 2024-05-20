import multiprocessing as mp

def secuencia_fibonacci_rango(ini, fin):
    fibonacci = [0, 1]
    for i in range(2, fin):
        siguiente = fibonacci[-1] + fibonacci[-2]
        fibonacci.append(siguiente)
    return fibonacci[ini:fin]

def fibonacci_paralelo(terminos, procesos):
    grupo = mp.Pool(procesos)
    por_proceso = [terminos // procesos] * procesos

    for i in range(terminos % procesos):
        por_proceso[i] += 1

    resultados = grupo.starmap(secuencia_fibonacci_rango, [(i * (terminos // procesos), (i+1) * (terminos // procesos)) for i in range(procesos)])
    grupo.close()
    grupo.join()

    fibonacci = []
    for resultado in resultados:
        fibonacci.extend(resultado)
    return fibonacci

if __name__ == '__main__':
    terminos = 1000
    procesos = mp.cpu_count()

    fibonacci = fibonacci_paralelo(terminos, procesos)
    print("Secuencia de Fibonacci generada:", fibonacci)
