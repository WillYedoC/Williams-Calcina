import random
import multiprocessing as mp

def monte_carlo_pi(n):
    dcc = 0
    for _ in range(n):
        x = random.random()
        y = random.random()
        if x**2 + y**2 <= 1:
            dcc += 1
    return dcc

def estimar_pi(mss, prc):
    grp = mp.Pool(prc)
    mss_pr_prc = [mss // prc] * prc
    for i in range(mss % prc):
        mss_pr_prc[i] += 1

    resultados = grp.map(monte_carlo_pi, mss_pr_prc)
    ttl_dentro = sum(resultados)
    ttl_mss = sum(mss_pr_prc)

    estimacion_pi = 4 * (ttl_dentro / ttl_mss)
    return estimacion_pi

if __name__ == '__main__':
    mss = 10000000
    prc = mp.cpu_count()

    pi_estimado = estimar_pi(mss, prc)
    print("Estimación de Pi:", pi_estimado)
