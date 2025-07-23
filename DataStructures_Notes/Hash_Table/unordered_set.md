# unordered_set

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  C++ STL 中基於 **哈希表 (Hash Table)** 的關聯式容器 (associative container)。  
  ** 關聯式容器 (associative container) **: 根據鍵 (key) 來快速查找值 (value) 的容器，而不是透過 index 存取。

- **元素特性 (Element Properties)**：  
  - 僅儲存 **唯一 (unique)** 元素，無 Key-Value 配對。  
  - 元素必須可被 `std::hash` 雜湊。  
  - 不保證有序 (元素排列順序不固定)。  

- **主要用途**：快速判斷元素是否存在、集合操作（交集、差集、去重）。

---

## 2. 底層實現原理 (Underlying Implementation)
1. **雜湊函數 (Hash Function)**  
   - 將元素映射到桶 (bucket) 的索引，預設使用 `std::hash<T>`，可自定義。

2. **桶 (Bucket) 與碰撞處理 (Collision Handling)**  
   - 採用 **鏈地址法 (Separate Chaining)**：  
     - 若多個元素雜湊至同一桶，會以鏈結結構（通常為 `std::forward_list`）存放。  

3. **負載因子 (Load Factor) 與 Rehash**  
   - **負載因子 (α)** = **元素數量 / 桶數**。  
   - 當 α 超過 `max_load_factor()` (預設約 1.0) 時，自動執行 **rehash**：增加桶數並重新分配元素。

4. **平均 vs 最壞情況**  
   - **平均**：插入、查找、刪除 O(1)  
   - **最壞**：當碰撞嚴重時退化為 O(n)

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation) | 語法 (Syntax) | 平均時間 (Average) | 最壞時間 (Worst) | 備註 |
|------------------|--------------|--------------------|------------------|------|
| 插入 | `s.insert(value);` | O(1) | O(n) | 插入已存在元素不會報錯，但無效果 |
| 查找 | `s.find(value)` | O(1) | O(n) | 回傳 iterator 或 `end()` |
| 判斷存在 | `s.count(value)` | O(1) | O(n) | 返回 0 或 1 |
| 刪除 | `s.erase(value)` | O(1) | O(n) | |
| 元素總數 | `s.size()` | O(1) | O(1) | |
| 清空 | `s.clear()` | O(n) | O(n) | |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構 | 底層 | 是否有序 | 平均操作 | 適用場景 |
|----------|------|----------|----------|----------|
| **unordered_set** | 哈希表 | ❌ 無序 | O(1) | 去重、快速存在判斷 |
| **set** | 紅黑樹 (Red-Black Tree) | ✅ 有序 | O(log n) | 去重且需要排序輸出 |
| **unordered_map** | 哈希表 | ❌ 無序 | O(1) | Key-Value 映射 |
| **map** | 紅黑樹 | ✅ 有序 | O(log n) | Key-Value 映射且需排序 |

---

## 5. 使用情境 (Usage Scenarios)
1. **快速存在性判斷 (Existence Check)**  
   - 例：判斷某元素是否出現過 (如檢查重複)。  

2. **去重 (Deduplication)**  
   - 例：輸入一串數字，快速獲得唯一元素集合。  

3. **集合操作 (Set Operations)**  
   - 可用於交集、聯集、差集操作（需手動實作）。  
   
4. **過濾器實現**  
   - 例：簡單黑名單、白名單過濾。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **`reserve()` / `rehash()` 性能優化**  
   - 若已知元素數量，提前 `reserve(n)` 可減少多次 rehash，性能顯著提升。
   
2. **遍歷無固定順序**  
   - 不可依賴元素的遍歷順序，若需要排序結果，應將元素轉為 `vector` 再 `sort()`。
   
3. **Key 自定義型別支持**  
   - 自定義結構作為元素時，必須提供自定義 `hash` 與 `==`。  
   - 例：`unordered_set<pair<int,int>>` 需自定義 `struct hash_pair`。

4. **空間換時間特性**  
   - 為了達到 O(1) 平均時間，`unordered_set` 的空間消耗通常比 `set` 大。

5. **最壞情況性能退化**  
   - 若雜湊函數不均勻或惡意輸入導致碰撞，操作會退化至 O(n)。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名 | 重點 |
|------|------|------|
| 217 | Contains Duplicate | 判斷是否有重複元素 |
| 136 | Single Number | 利用集合性質去重 |
| 349 | Intersection of Two Arrays | 快速交集 |
| 202 | Happy Number | 判斷循環，檢查是否出現過 |
| 575 | Distribute Candies | 快速去重計算種類數 |

---
