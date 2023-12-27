# Домашнее Задание 5
Правила отправки домашнего задания описаны [тут](./info.md).

## Класс PriorityQueue (2 балла)
Реализовать класс **PriorityQueue** (т.е. **Max-Heap**), который хранит полное бинарное дерево используя вектор.
Данная структура должна работать для любого типа **T**, для которого определен оператор меньше.
Если есть вопросы насчет структуры, можно посмотреть описание функций [тут](https://en.cppreference.com/w/cpp/container/priority_queue).
Класс должен содержать следующие методы:
```c++
#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue {
private:
  std::vector<T> heap;

  // Functions can be added if necessary

public:
  template<typename InputIt>
  PriorityQueue(InputIt first, InputIt last); // O(N)

  bool empty() const; // O(1)

  size_t size() const; // O(1)

  void push(const T &value); // O(log(N))

  void pop(); // O(log(N))

  const T &top() const; // O(1)
};
```

## Задачи с исползованием PriorityQueue (Max-Heap) (2 балла)
Все задачи должны быть решены с использованием вами написанного **PriorityQueue**.

### Задача 1
Вам дан целочисленный массив `piles`, где `piles[i]` представляет количество камней в **i**-ой стопке, и целое число **k**.
Вам следует применить следующую операцию ровно **k** раз:

* Выберите любой `piles[i]` и удалите из нее `floor(piles[i]/2)` камней. где `floor(x)` - округляет **х** вниз.

Обратите внимание,
что вы можете применить операцию к одной и той же стопке более одного раза.

Верните минимально возможное общее количество камней, оставшихся после выполнения **k** операций.

### Примеры
```
Input: piles = [5,4,9], k = 2
Output: 12

Input: piles = [4,3,6,7], k = 3
Output: 12
```

### Задача 2
Дан массив точек `Points` размера **n**, где `Points[i] = [xi, yi]` представляет точку на плоскости **XY**
и целое число **k**, верните **k** ближайших точек к началу координат **(0, 0)**.

Расстояние между двумя точками на плоскости **XY** — это евклидово расстояние.

Вы можете вернуть ответ в любом порядке.

Решить задачу за **O(n * log(k))**.

Для решения можно использовать данную структуру:
```c++
#include <cmath>

struct Point {
  int x{};
  int y{};

  double dist() const {
    return std::sqrt(x * x + y * y);
  }

  friend bool operator<(const Point &lhs, const Point &rhs) {
    // Complete...
  }
};
```
### Пример
```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
```

### Задача 3
Вам дан целочисленный массив `heights`, представляющий высоту зданий,
два целых числа `bricks` и `ladders`.

Вы начинаете свое путешествие со здания 0 и переходите к следующему зданию, возможно, используя кирпичи или лестницы.

При переходе из здания **i** в здание **i+1**,

* Если высота текущего здания больше или равна высоте следующего здания,
вам не нужна лестница или кирпичи.

* Если высота текущего здания меньше высоты следующего здания,
вы можете использовать одну лестницу или `h[i+1] - h[i]` кирпичей.

Верните самый дальний индекс здания, которого вы можете достичь, если оптимально используете данные лестницы и кирпичи.

### Примеры
```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.

Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7

Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

### Задача 4
Вам дан массив из **k** связанных списков,
каждый связанный список отсортирован в порядке возрастания.

Объедините все связанные списки в один
отсортированный связанный список и верните его.

```c++
std::list<int> mergeKLists(const std::vector<std::list<int>>& lists);
```

### Пример
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```
