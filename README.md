# C++ tasks

Пояснение: в директории `tasks/taskN` (где N - номер задачи) находятся все необходимые файлы. В текстовых файлах `inputK.txt` содержатся входные тестовые данные, а в `outputK.txt` - соответствующие выходные данные (ответы). Файл `taskN.cpp` трогать нельзя.

0. Графовые алгоритмы (в git не загружаем)

Создать класс граф. Реализовать алгоритмы:

* поиск в глубину и ширину (+ поиск компонент связности и поиск кратчайших расстояний);
* алгоритм Дейкстры и алгоритм Флойда-Уоршелла;
* алгоритм Прима и алгоритм Крускала (Краскала).

1. Задача про максимальное значение

Даны массив вещественных чисел и 4 вида операций: +, -, *, /.
Какое максимальное значение можно получить, используя эти операции? Вычисления осуществляются последовательно (без учета приоритетности).

Примеры:

```
[1, 2, 3, 4]
1 + 2 * 3 * 4 = 36

[3, -3, 0.2, -6]
3 * (-3) / 0.2 * (-6) = 270
```

2. Решето Эратосфена

`n => {p | p - простое <= n}`

* 2.1. Модификация решета Эратосфена (в git не загружаем)

Уменьшите количество используемой памяти (`O(n)`).

3. Решето Сундарама

`n => {p | p - простое <= n}`

4. Задача про нахождение помещения с наибольшим объемом

Имеется склад длиной `a`, шириной `b` и высотой `c`.
Необходимо найти помещение с наибольшим объемом. Это помещение формируется следующим образом.
Его ширина фиксирована и равна `b`.

Есть массив из `n` целых чисел, характеризующий высоты колонн,
которые могут быть использованы при строительстве.

Пример такого массива представлен на рисунке ниже:
![Массив колонн](./assets/bars.png)

Двигать колонны нельзя, а высота помещения ограничивается минимальной высотой из 2 рассматриваемых колонн, длина определяется расстоянием между колоннами.

Пусть `a = b = c = 10`. Если мы возьмем 1ую и 6ую коллонны, то объем помещения равен `10 * (6 - 1) * 4 = 200`.

5. Корректность скобочного выражения

Написать программу, определяющую корректность скобочного выражения, состоящего из скобок 4 типов: `(), [], {}, <>`. В общем случае выражение может содержать произвольные символы.

6. Вычисление арифметического выражения в форме обратной польской записи

Реализовать алгоритм вычисления арифметического выражения в форме обратной польской записи.

7. Стековый калькулятор

Написать стековый калькулятор, который вычисляет значение арифметического выражения, состоящего из констант (вещественных чисел, разделитель целой и дробной части - точка), знаков арифметических операций и круглых скобок и не содержащего переменных. На вход подается строка, представляющая собой арифметическое выражение. Его корректность не гарантируется, поэтому перед вычислением необходимо проверить его на корректность. В случае, если оно некорректно, выдать соответствующее сообщение, в противном случае - вычисленное значение. Обозначения операций: сложение/вычитание (+, -), умножение/деление (*, /), применение унарного минуса (-), возведение в степень (^). Круглые скобки используются для задания приоритета.

8. Поиск подстроки в строке. [Алгоритм Кнута-Морриса-Пратта](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9A%D0%BD%D1%83%D1%82%D0%B0-%D0%9C%D0%BE%D1%80%D1%80%D0%B8%D1%81%D0%B0-%D0%9F%D1%80%D0%B0%D1%82%D1%82%D0%B0)

9. Сжатие (компрессия). [Код Хаффмана](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%A5%D0%B0%D1%84%D1%84%D0%BC%D0%B0%D0%BD%D0%B0)

Примеры:

```
Оригинальный текст: ab
Закодированный текст: 01
Раскодированный текст: ab
Коды символов:
a : 0
b : 1

Оригинальный текст: ba
Закодированный текст: 10
Раскодированный текст: ba
Коды символов:
a : 0
b : 1

Оригинальный текст: abc
Закодированный текст: 10110
Раскодированный текст: abc
Коды символов:
a : 10
b : 11
c : 0

Оригинальный текст: cba
Закодированный текст: 01110
Раскодированный текст: cba
Коды символов:
a : 10
b : 11
c : 0

Оригинальный текст: aaabbc
Закодированный текст: 000111110
Раскодированный текст: aaabbc
Коды символов:
a : 0
b : 11
c : 10
```

10. Сжатие (компрессия). [Алгоритм LZW](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_LZW)

Первоначальное состояние словаря кодирования формируется на основе символов с кодами `0-255`.
Для словаря декодирования ключи и значения меняются местами.


```bash
git remote add REMOTE_NAME REMOTE_REPO_URL_1
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_1
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_2
...
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_N

or

git remote add REMOTE_NAME REMOTE_REPO_URL_1
for (( i=1; i<=N; i++ ))
do
  git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_I
done
```
