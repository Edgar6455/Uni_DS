# Домашнее Задание 2
Правила отправки домашнего задания описаны [тут](./info.md).

## Класс List (1 балл)
Реализовать класс List (Doubly Linked List) с помощью шаблонов.
Если есть вопросы насчет реализации, можно посмотреть описание функций [тут](https://en.cppreference.com/w/cpp/container/list).
Класс должен содержать следующие методы:
```c++
template<typename T>
class List {
  struct Node {
    T data;
    Node *next;
    Node *prev;

    // Functions can be added if necessary
  };

  Node *head;
  Node *tail;
  size_t size_;

public:
  class iterator {
    Node *current;
  public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    iterator();
    iterator(Node *node);
    reference operator*() const;
    pointer operator->() const;
    iterator &operator++();
    iterator &operator++(int);
    iterator &operator--();
    iterator &operator--(int);
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };

  List();
  List(size_t count, const T &value = T());
  List(const List &other);
  List(List &&other);
  List(std::initializer_list<T> ilist);

  ~List();

  List &operator=(const List &other);
  List &operator=(List &&other);
  List &operator=(std::initializer_list<T> ilist);

  // Element access
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;

  // Capacity
  bool empty() const;
  size_t size() const;

  // Modifiers
  iterator insert(iterator pos, const T &value);
  iterator insert(iterator pos, T &&value);
  iterator insert(iterator pos, std::initializer_list<T> ilist);

  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);

  void push_front(const T &value);
  void push_front(T &&value);
  void push_back(const T &value);
  void push_back(T &&value);

  void pop_front();
  void pop_back();

  // Iterators
  iterator begin();
  iterator end();

  // Comparison
  friend bool operator==(const List<T> &lhs, const List<T> &rhs);
};
```

## Задачи с исползованием List (1 балл)

### Задача 1
Написать функцию используя шаблоны, которая получив связанный список и значение **x**,
преобразует его так, чтобы все узлы меньше **x** располагались перед узлами,
большими или равными **x**. Функция должна иметь сложность **O(n)**.

#### Примеры
```
Input:  list = [3, 1, 6, 4, 2, 5], x = 4
Output: list = [3, 1, 2, 4, 6, 5]

Input:  list = [6, -2, 5, 4, 0, 3], x = 4
Output: list = [3, -2, 0, 4, 5, 6]
```

### Задача 2
Написать функцию, которая получает список, содержащий строчные английские буквы от **a** до **z**.
Обработать этот список и заменить любую последовательность соседних одинаковых букв одной заглавной буквой,
представляющей эту последовательность. Функция должна иметь сложность **O(n)**.

#### Примеры
```
Input:  list = [a, a, b, c, c, c]
Output: list = [A, b, C]

Input:  list = [d, f, f, r, r, d]
Output: list = [d, F, R, d]
```

### Задача 3
Написать функцию следующего вида:
```c++
template<typename InputIt, typename T>
bool search(InputIt first, InputIt last, const T &value);
```

Которая получает отсортированный диапазон **[first, last)** и значение **value**,
возвращает **true** если в диапазоне **[first, last)** есть элемент со значением **value**
и **false** в противном случае.

Если **InputIt** имеет тип **input_iterator**, **forward_iterator** или **bidirectional_iterator**, то функция должна иметь сложность **O(n)**.
Если **InputIt** имеет тип **random_access_iterator**, то функция должна иметь сложность **O(log(n))**.

В функции **main** проверить будет ли функция работать по разному для **std::list** и **std::vector**.

Для решения задачи использовать алгоритм [Binary Search](https://www.geeksforgeeks.org/binary-search/).
