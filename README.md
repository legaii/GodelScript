## Как запустить?
* ```mkdir build && cd build```
* ```cmake ..```
* ```cmake --build .```
* ```sudo cmake --install .```
* Теперь на Вашем устройстве установлена команда ```godel```

## Запуск тестов
* ```mkdir build && cd build```
* ```cmake .. -DCMAKE_BUILD_TYPE=Debug```
* ```make test```
* Примечание: тесты (особенно isPrime) могут работать долго.

## Определение общерекурсивной функции
В GödelScript общерекурсивная функция определяется так же, как и на [Википедии](https://en.wikipedia.org/wiki/General_recursive_function).

## Синтаксис
#### Элементарные сущности
В GödelScript есть 2 элементарные сущности: операторы и именные функции. Имя сущности - это набор символов из таблицы ASCII с десятичными номерами от 33 до 122 включительно, кроме символов ```(```, ```)```, ```=``` и ```#```.
#### Комментарии
Комментарий - это префикс строки программы, который начинается с символа ```#``` (из всех таких выбирается самый длинный). Комментарии полностью игнорируются интерпретатором, поэтому далее мы **будем считать, что комментариев не существует**.
#### Строка программы
Непустая строка корректной программы имеет вид ```name = function```, где ```name``` - имя новой именной функции, а ```function``` - функция.
#### Функция
Функция - это:
1. Именная функция.
2. ```(Op f1 ... fn)```, где ```Op``` - это ```n```-арный оператор, а ```f1```, ..., ```fn``` - ```n``` функций.

## Типизация
Аргументы и возвращаемое значение функции - это натуральные числа (начиная с 0), поэтому тип функции представляется как натуральное число, равное арности этой функции.

Аргументы и возвращаемое значение оператора - это функции, поэтому тип ```n```-арного оператора представляется как строка ```(t1, ..., tn) -> m```, где ```t1, ..., tn``` - типы принимаемых функций, а ```m``` - тип возвращаемой функции.

Одному имени может соответствовать множество операторов с попарно различными типами принимаемых функций. Интерпретатор автоматически выбирает, какой оператор вызвать, исходя из типов принимаемых функций.

## Операторы
Доступно 3 множества операторов (пользовательские операторы не поддерживаются):
* ```Compose``` - операторы суперпозиции. ```m+1```-арный оператор ```Compose``` имеет тип ```(m, n, ..., n) -> n```, при этом ```m>0```. ```Compose h g1 ... gm``` возвращает ```n```-арную функцию ```f```, такую что ```f(x1, ..., xn) == h(g1(x1, ..., xn), ..., gm(x1, ..., xn))```.
* ```Recur``` - операторы примитивной рекурсии. ```Recur``` имеет тип ```(n, n+2) -> n+1```. ```Recur g h``` возвращает ```n+1```-арную функцию ```f```, такую что:
  * ```f(0, x1, ..., xn) == g(x1, ..., xn)```.
  * ```f(y + 1, x1, ..., xn) == h(f(y, x1, ..., xn), y, x1, ..., xn)```.
* ```Min``` - операторы минимизации аргумента. ```Min``` имеет тип ```(n+1) -> n```. ```Min g``` возвращает ```n```-арную функцию ```f``` (где ```g``` - ```n+1```-арная функция), такую что:
  * Если ```g(y, x1, ..., xn) != 0``` (для любого ```y```), то ```f(x1, ..., xn)``` не определена.
  * Иначе ```f(x1, ..., xn) == y```, где ```y``` - наименьшее число, такое что ```g(y, x1, ..., xn) == 0```.

## Функции
По умолчанию определены следующие именные функции:
* ```0_0, 0_1, ..., 1_0, 1_1, ..., 2_0, 2_1, ..., ...``` - константы (первый индекс означает возвращаемое значение, второй индекс означает арность).
* ```succ``` - функция арности 1, такая что ```succ(x) == x+1```.
* ```id1_1, id1_2, ..., id2_2, id2_3, ..., ...``` - проекторы (первый индекс означает номер переменной, второй индекс означает арность).

Когда программа запускается, то выполняется именная функция ```main``` (если она не определена, то возникает сообщение об ошибке).
