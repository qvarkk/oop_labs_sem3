from math import remainder
from time import perf_counter
from itertools import filterfalse

import mod
# help(mod)

# Обработчик 
def processing(inp): 
  if inp == '': 
    return 0 

  # проверяется с 1 индекса потому что на 0 может 
  # стоять "-", который с isdigit возвращает false 

  if inp[1:].isdigit(): 
    if int(inp) < 0: 
      return int(inp) 
    else: 
      print(f'Wrong number: {inp}') 
      return 0 
  else: 
    # если буква подходит, то добавляем ее в список 
    # в конце объединяем строку в одну 

    res = [] 

    for i in inp: 
      if i in 'БВГДЖЗЙКЛМНПРСТФХЦЧШЩ': 
        res.append(i) 
    if ''.join(res) == '': 
      print(f'Wrong word: {inp}') 
      return 0 
    else: 
      return ''.join(res) 


# Модификатор 
def modifier(func): 
  def wrapper(inp): 
    # в последствии func будет calculate и поэтому 
    # result будет результатом вычислений 

    # сохраняем время начала работы функции
    start_time = perf_counter()

    maxValue, latestLetter = func(inp) 

    # фиксируем время конца работы функции, чтобы потом вычислить сколько она выполнялась
    end_time = perf_counter()

    oddN = 0 
    res = [] 

    for i in inp: 
      if type(i) is int and remainder(i, 2) != 0: 
        oddN += 1 
      elif type(i) is not int: 
        res.append(i.lower()) 

    print(f'Decorator:\n1) Number of odd numbers: {oddN}\n2) Changed register: ', end = '') 
    print(*res) 
    # вычисляем время работы функции и выводим его :)
    print(f":Function execution time: {end_time - start_time} seconds") 
    print(f'Calculator: \n1) Biggest number: {maxValue}\n2) Lattest letter in alphabet: {latestLetter}') 
    return maxValue, latestLetter 

  return wrapper 

#Вычислятор (с модификатором) 
@modifier 
def calculate(inp): 
  # по дефолту значения 0 и '', которые  
  # впоследствии заменяются на максимов (max) 

  maxValue = 0 
  latestLetter = '' 

  for i in inp: 
    if type(i) is int: 
      if maxValue != 0: 
        maxValue = max(i, maxValue) 
      else: 
        maxValue = i 
    else: 
      # для каждой буквы проверяет больше ли она 
      # нынешнего максима, тк чем ближе буква к 
      # концу алфавита тем больше ее значение 

      for j in i: 
        if latestLetter != '': 
          latestLetter = max(j, latestLetter) 
        else: 
          latestLetter = j 

  return maxValue, latestLetter 

# генерим рандомные значения
random_range = [mod.rand_range() for i in range(10)] 
random_ceil = [mod.rand_ceil() for i in range(10)] 
print(f"Random values returned by rand_range function: {random_range}") 
print(f"Random values returned by rand_ceil function: {random_ceil}") 

# обрабатываем рандомные значения 
res_1 = [processing(str(i)) for i in random_range] 
res_2 = [processing(str(i)) for i in random_ceil] 
print(f"rand_range values after processing: {res_1}") 
print(f"rand_ceil values after processing: {res_2}\n") 

values = [] 

while True: 
  print('Input a value: ', end='') 
  inp = input() 

  if inp == 'end': 
    break 

  # чтобы можно было вводить значения через пробел 

  lastInp = inp.split() 

  for i in lastInp: 
    res = processing(i) 

    # добавляет только валидные значения, тк 
    # ф-ция возвращает 0 при невалидных 

    if res != 0: 
      values.append(res) 

calculate(values) 