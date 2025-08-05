## problem description
people in format: (h, k)
  - h = height of the person
  - k = number of people in front who are taller of equal height

Example:
people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}

step 1: sort the people
  - by height decreasing (taller people first)
  - if same height, by `k` increasing (fewer people in front first)
  - sorted result: {{7,0}, {7,1}, {6,1}, {5,0}, {5,2}, {4,4}}

step 2: insert one by one into result
  - insert {7,0} at index 0
  [] → [{7,0}]
  
  - inset {7,1} at index 1
  [{7,0}] → [{7,0}, {7,1}]
  
  - insert {6,1} at index 1
  [{7,0}, {7,1}] → [{7,0}, {6,1}, {7,1}]
  
  - insert {5,0} at index 0
  [{7,0}, {6,1}, {7,1}] → [{5,0}, {7,0}, {6,1}, {7,1}]
  
  - insert {5,2} at index 2
  [{5,0}, {7,0}, {6,1}, {7,1}] → [{5,0}, {7,0}, {5,2}, {6,1}, {7,1}]
  
  - insert {4,4} at index 4
  [{5,0}, {7,0}, {5,2}, {6,1}, {7,1}] → [{5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1}]

## Why this work?
1. Taller people are placed first.

2. Their position is not affected by shorter people added after.

3. Each person is inserted at the position that satisfies their k (how many taller people are before them).

## classification: greedy

## key insight

1. Sort people in descending height, and for the same height, ascending `k`;

```cpp
bool compare(const vector<int> &a, const vector<int> &b) {
  if (a[0] != b[0]) return a[0] > b[0];

  return a[1] < b[1];
}

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), compare);

    ...
  }
}
```

2. Then, insert each person into the result list at index `k`. 

```cpp
result.insert(result.begin() + person[1], person);
```

## syntax breakdown
```cpp
result.insert(result.begin() + person[1], person);

result.begin() : iterator pointing to the start of the vector

result.begin() + person[1] : moves the iterator `k` steps forward

insert(...) : inserts the `person` at that exact position
```