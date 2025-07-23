# map

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  C++ STL 中的關聯式容器 (associative container)，基於**平衡二元搜尋樹 (Balanced Binary Search Tree)**（通常為紅黑樹 Red-Black Tree）實作。  

- **鍵值特性 (Key Properties)**：  
  - Key 唯一且**自動排序**（依 `<` 比較函式）  
  - 支援以 Key 作為索引，快速查找、插入、刪除。  

- **元素排列**：  
  按照 Key 的排序規則有序儲存，遍歷時元素按升序輸出。

---

## 2. 底層實現原理 (Underlying Implementation)
1. **平衡二元搜尋樹**  
   - 使用紅黑樹 (Red-Black Tree) 實作，保證樹高為 O(log n)。  
   - 插入、刪除會維護紅黑樹平衡條件，避免退化成鏈表。  
   
2. **節點結構**  
   - 每個節點儲存 Key、Value、左右子節點指標及顏色資訊。  
   
3. **排序依據**  
   - 預設使用 `std::less<Key>` 比較 Key，也可自訂比較器。  
   
4. **遍歷順序**  
   - 中序遍歷取得升序排列的元素。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)   | 語法 (Syntax)     | 時間複雜度 (Time Complexity) | 備註                      |
|--------------------|-------------------|------------------------------|---------------------------|
| 插入 / 更新        | `m[key] = value;`  | O(log n)                     | 若 key 已存在，更新值       |
| 查找                | `m.find(key)`      | O(log n)                     | 返回 iterator 或 end()      |
| 存取                | `m.at(key)`        | O(log n)                     | 不存在會拋出例外           |
| 刪除                | `m.erase(key)`     | O(log n)                     |                           |
| 元素總數            | `m.size()`         | O(1)                        |                           |
| 遍歷                | `for (auto& e : m)`| O(n)                        | 按 key 有序遍歷            |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構       | 底層實作           | 是否排序 | 查找時間     | 插入刪除時間 | 適用場景                      |
|----------------|--------------------|----------|--------------|--------------|-------------------------------|
| **map**        | 紅黑樹 (平衡 BST)  | 有序     | O(log n)    | O(log n)    | 需要有序輸出、範圍查詢         |
| **unordered_map** | 哈希表           | 無序     | 平均 O(1)   | 平均 O(1)   | 快速查找、不需排序             |
| **set**        | 紅黑樹             | 有序     | O(log n)    | O(log n)    | 唯一鍵且有序集合               |
| **unordered_set** | 哈希表           | 無序     | 平均 O(1)   | 平均 O(1)   | 唯一鍵，快速存在判斷           |

---

## 5. 使用情境 (Usage Scenarios)
- 需要**按鍵排序**的字典結構，例如：  
  - 須按字典序遍歷所有元素  
  - 範圍查詢（例如查找某範圍內的鍵）  

- 需要穩定的 O(log n) 查找、插入和刪除。  

- 無法容忍哈希碰撞導致最壞 O(n) 的場景。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **內存與性能成本**  
   - 紅黑樹節點需額外指標及顏色標記，記憶體成本較哈希表高。  

2. **比較器 (Comparator) 可定制**  
   - 可自定義比較函式以改變排序行為（如降序、自訂 Key 比較邏輯）。  

3. **迭代器穩定性**  
   - 插入不會使已有元素迭代器失效，刪除元素迭代器會失效。  

4. **範圍操作**  
   - 支援 `lower_bound()`, `upper_bound()` 等範圍查詢函式。  
   
5. **中序遍歷保證有序輸出**  
   - 透過中序遍歷紅黑樹，元素依 Key 有序輸出，適合需要排序輸出的需求。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名                   | 重點                             |
|------|------------------------|----------------------------------|
| 208  | Implement Trie (Prefix Tree) | 利用 map 管理子節點          |
| 238  | Product of Array Except Self | 使用 map 儲存中間結果（輔助）  |
| 352  | Data Stream as Disjoint Intervals | 使用 map 管理區間          |
| 315  | Count of Smaller Numbers After Self | 使用平衡樹技巧              |
| 460  | LFU Cache               | 結合 map 與雙向鏈表實作緩存   |

---
