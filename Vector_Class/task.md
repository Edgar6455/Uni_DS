# Домашнее Задание 1
Зарание посмотрите правила отправки домашнего задания, которое описано [тут](./info.md).

## Класс Vector (1 балл)
Реализовать класс Vector с помощью шаблонов.
Если есть вопросы насчет реализации, можно посмотреть описание функций [тут](https://en.cppreference.com/w/cpp/container/vector).
Класс должен содержать следующие методы:
```c++
template <typename T>
class Vector {
  Vector();
  Vector(size_t arr_size);
  Vector(size_t arr_size, T elem);

  Vector(const Vector<T> &other);
  Vector(Vector<T> &&other);
  
  ~Vector();

  Vector<T> &operator=(const Vector<T> &other);
  Vector<T> &operator=(Vector<T> &&other);
  
  size_t size() const;
  size_t capacity() const;

  bool empty() const;

  const T &operator[](size_t index) const;
  T &operator[](size_t index);

  const T &at(size_t index) const;
  T &at(size_t index);

  void push_back(const T &x);
  void push_back(T &&x);
  
  void pop_back();

  void clear();
};
```

## Задачи с исползованием Vector (1 балл)
Все задачи должны быть решены с использованием вами написанного вектора.

### Задача 1
Дан целочисленный массив `nums`, напишите такую функцию, которая возвращает массив `result`, такой, что `result[i]` равен произведению всех элементов `nums`, кроме `nums[i]`.

Произведение любого префикса или суффикса чисел гарантированно вписывается в 32-битное целое число.
Вы должны написать алгоритм, который работает за время **O(n)** и не использует операцию деления.
#### Примеры

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

### Задача 2
Дана матрица n x m различных целых чисел, напишите такую функцию, которая возвращает все счастливые числа в матрице в любом порядке.

Счастливое число — это такой элемент матрицы, который является минимальным элементом в своей строке и максимальным в своем столбце.

```
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]

Input: matrix = [[7,8],[1,2]]
Output: [7]
```
