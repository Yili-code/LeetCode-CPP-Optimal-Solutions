# multimap

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  C++ STL 中基於 **平衡二元搜尋樹 (Balanced Binary Search Tree)** 實作的關聯式容器，類似 `map`，但允許**多個元素擁有相同的 Key**。 

- **鍵值特性 (Key Properties)**：  
  - Key 可重複（多對一關係）。  
  - Key 依預設比較函式 (`std::less<Key>`) 有序排列。  

- **元素排列**：  
  按照 Key 排序，插入時會將相同 Key 的元素插入對應位置。

---

## 2. 底層實現原理 (Underlying Implementation)
- 採用紅黑樹（Red-Black Tree）或其他自平衡二元搜尋樹。 

- 節點儲存 Key-Value，並依 Key 有序排列。  

- 支援多個節點擁有相同 Key，且遍歷時這些節點會連續出現。  

- 插入時不覆蓋已有 Key，保持多重對應。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)        | 語法 (Syntax)             | 時間複雜度 (Time Complexity) | 備註                          |
|-------------------------|---------------------------|------------------------------|-------------------------------|
| 插入                    | `mm.insert({key, value});` | O(log n)                     | 不會覆蓋已有 Key               |
| 查找（單一）            | `mm.find(key)`             | O(log n)                     | 返回第一個匹配 Key 的 iterator |
| 查找（範圍）            | `mm.equal_range(key)`      | O(log n)                     | 返回該 Key 範圍的迭代器 pair   |
| 刪除                    | `mm.erase(key)`            | O(log n) + 刪除元素數量       | 刪除所有該 Key 的元素           |
| 刪除特定元素            | `mm.erase(iterator)`       | O(1)                         | 根據 iterator 刪除特定節點     |
| 遍歷                    | `for (auto& e : mm)`       | O(n)                        | 按 Key 排序，包含重複 Key       |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構       | 允許重複 Key | 是否排序 | 查找時間     | 插入刪除時間 | 適用場景                     |
|----------------|--------------|----------|--------------|--------------|------------------------------|
| **multimap**   | 是           | 有序     | O(log n)    | O(log n)    | 需存多對多關係、保有 Key 順序 |
| **map**        | 否           | 有序     | O(log n)    | O(log n)    | 唯一 Key 的 Key-Value 儲存    |
| **unordered_multimap** | 是    | 無序     | 平均 O(1)   | 平均 O(1)   | 多對多映射，非排序需求        |
| **unordered_map** | 否         | 無序     | 平均 O(1)   | 平均 O(1)   | 唯一 Key，快速查找            |

---

## 5. 使用情境 (Usage Scenarios)
- 需要在同一 Key 下存多筆資料的字典結構。  

- 需保留 Key 順序且 Key 可能重複。  

- 例如多對一、多對多關係管理，如學生選多門課、事件多重標籤等。  

- 需要快速範圍查詢重複 Key 的所有元素。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **equal_range 與範圍查詢**  
   - `equal_range(key)` 同時返回包含所有該 Key 的元素區間迭代器，方便遍歷。 

2. **插入不會覆蓋已有元素**  
   - 插入後不會取代先前的元素，與 `map` 差異大，須注意使用情境。  

3. **迭代器穩定性**  
   - 插入不使已有迭代器失效，刪除元素使該迭代器失效。  
   
4. **自訂比較器**  
   - 可改變 Key 的排序行為，例如降序或自定義排序條件。  
   
5. **內存使用**  
   - 相較於 `map`，`multimap` 節點數更多，內存開銷相對較大。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名                     | 重點                               |
|------|--------------------------|------------------------------------|
| 350  | Intersection of Two Arrays II | 使用 multimap 或 unordered_multimap 管理重複元素 |
| 241  | Different Ways to Add Parentheses | 用 multimap 存多種拆分結果         |
| 49   | Group Anagrams           | 用 multimap 存多個同 Key 的字串群組   |
| 451  | Sort Characters By Frequency | 使用 multimap 管理頻率排序          |
| 349  | Intersection of Two Arrays | 用 multimap 支援重複元素的集合操作    |

---
