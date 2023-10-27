"""
mod

Ф-ции:
rand_range - возвращает случайное число от -82 до -51 с шагом в 2
randrange(a, b, c) - случайное число от a до b с шагом в c. a, b, c - целые числа

rand_ceil - возвращает округленное в большую сторону число, полученное путем умножения случайного числа от 0 до 1 на случайное целое число от -93 до -44
ceil(a) - возвращает число, округленное в большую сторону
random() - возвращает случайное дробное число от 0 до 1
randint(a, b) - возвращает случайное число в интервале от a до b. a, b - целые числа

"""

from random import random, randrange, randint
from math import ceil

def rand_range():
    return randrange(-82, -51, 2) 

def rand_ceil():
    return ceil(random()*randint(-93, -44))