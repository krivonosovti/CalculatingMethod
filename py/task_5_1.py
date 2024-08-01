import numpy as np 
from scipy import integrate 
import math

def func(x):
#    return (math.log(1.5 + 0.5*x)/(1 + 0.25*(x+1)**2))
    return (x*math.log(1 + x))

def func1(x):
    return (math.log(1 + x)/(1 + (x)**2))

# def func1(x):
#     return (x*math.log(1 + x))

def funcmeller(x):
    return (mnN5(x)/math.sqrt(1-x**2))

def mnN(x, N):
    return x**(2*N-1)-2*x+6

def mnN5(x):
    return x**(5)-2*x+6

def lagrange(x, N):
    if (N == 0):
        return 1
    elif (N == 1):
        return x
    else:
        P0 = 1 
        P1 = x 
        for i in range(2, N + 1): 
            P = ((2 * i - 1) * x * P1 - (i - 1) * P0) / i 
            P0 = P1 
            P1 = P 
        return P

def SepRoot(a, b, N, L):
    h = (b - a)/N
    n1 = a
    n2 = a + h
    mas = []
    while (n2 <= b):
        if (lagrange(n1, L)*lagrange(n2, L)<=0):
            mas.append([n1, n2])
        n1 = n2
        n2 = n1 + h  
    return mas

def SepRoot2(a, b, N, L):
    h = (b - a)/N
    n1 = a
    n2 = a + h
    mas = []
    while (n2 <= b):
        if (Cheb(n1, L)*Cheb(n2, L)<=0):
            mas.append([n1, n2])
        n1 = n2
        n2 = n1 + h  
    return mas

def SecMet(a, b, eps, L):
    n0 = a
    n1 = b
    n2 = n1 - (lagrange(n1, L) * (n1 - n0)) /(lagrange(n1, L) - lagrange(n0, L))
    while(abs(n1-n0) >= eps):
        n2 = n1 - (lagrange(n1, L) * (n1 - n0)) /(lagrange(n1, L) - lagrange(n0, L))
        n0 = n1
        n1 = n2
    return n2

def coef(i, N, z):
    return (2*(1-z[i]**2)/(N**2 * (lagrange(z[i], N-1)**2)))

def vych(N):
    mas = SepRoot(-1, 1, 1000, N)
    z = []
    for i in range(len(mas)):
        z.append(SecMet(mas[i][0], mas[i][1], eps, N))
    lcoef = []
    for i in range(N):
        lcoef.append(coef(i,N,z))
    res = 0
    for i in range(N):
        res = res + lcoef[i]*mnN(z[i], N)
    return res 

def Cheb(x, N):
    if (N == 0):
        return 1
    elif (N == 1):
        return x
    else:
        T0 = 1 
        T1 = x 
        for i in range(2, N + 1): 
            T = 2*x*T1 - T0 
            T0 = T1 
            T1 = T 
        return T

print('Вычисление интегралов при помощи КФ Гаусса')
eps = 10 ** (-12)
h = 1
print('Узлы и Коэффициенты для N узлов (1<=N<=8)')
while (h<9):
    mas = SepRoot(-1, 1, 1000, h)
    z = []
    for i in range(len(mas)):
        z.append(SecMet(mas[i][0], mas[i][1], eps, h))
    print('Узлы:')
    print(z)
    lcoef = []
    for i in range(h):
        lcoef.append(coef(i,h,z))
    print('Коэффициенты:')
    print(lcoef)
    print('\n')
    h+=1

print('Проверка точности для многочленов степени 5,7,9 для N=3,4,5')
for i in range(3,6):
    print(vych(i) - integrate.quad(lambda x: mnN(x,i), -1, 1)[0])

print('Введите с новой строки 3 значения - количество узлов для нахождения по КФ Гаусса: ')
uz = []
for i in range(3):
    uz.append(int(input()))
print(uz)
for i in range(3):
    mas = SepRoot(-1, 1, 1000, uz[i])
    z = []
    for j in range(len(mas)):
        z.append(SecMet(mas[j][0], mas[j][1], eps, uz[i]))
    lcoef = []
    for j in range(uz[i]):
        lcoef.append(coef(j,uz[i],z)*0.5)
    res = 0
    for j in range(uz[i]):
        res = res + lcoef[j]*func(z[j])
    print(f'Вычисленный интеграл для {uz[i]} узлов: {res}')
 
# print(f'Точный интеграл: {integrate.quad(lambda x: func1(x), 0, 1)[0]}')
# print('\n')
# print('\n')
# print('Введите с новой строки 3 значения - количество узлов для нахождения по КФ Меллера: ')
# uz = []
# for i in range(3):
#     uz.append(int(input()))
# print(uz)
# for i in range(3):
#     z = []
#     for j in range(1, uz[i] + 1):
#         print(math.cos(math.pi * (2*j-1)/(2*uz[i])))
#         z.append(math.cos(math.pi * (2*j-1)/(2*uz[i])))
#     res = 0
#     for j in range(uz[i]):
#         res = res + math.cos(z[j])*(math.pi/uz[i])
#     print(f'Вычисленный интеграл для {uz[i]} узлов: {res}')

