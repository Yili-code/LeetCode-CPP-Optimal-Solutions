# unordered_map

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  C++ STL 中基於 **哈希表 (Hash Table)** 的關聯式容器 (associative container)。  
  ** 關聯式容器 (associative container) **: 根據鍵 (key) 來快速查找值 (value) 的容器，而不是透過 index 存取。

- **鍵值特性 (Key Properties)**：  
  - Key 唯一 (unique)  
  - Key 須可被 `std::hash` 雜湊 (hashing)
  ** 雜湊 (hashing) **: 將輸入資料 (key) 經過某種運算轉換成一個固定大小的整數值，稱為 hash 值 (hash value)。
  - 不保證元素有序 (無序)  

- **元素存取方式**：以 Key 為索引存取 Value，平均情況下可在 O(1) 完成查找、插入、刪除。

---

## 2. 底層實現原理 (Underlying Implementation)
1. **雜湊函數 (Hash Function)**  
   - 將 Key 映射為整數 (雜湊值)，用於確定該元素放置於哪個 **桶 (bucket)**。
   - 預設使用 `std::hash<Key>`，可自定義。
   
2. **桶 (Bucket) 與碰撞處理 (Collision Handling)**  
   - `unordered_map` 採用 **鏈地址法 (Separate Chaining)**：  
     - 每個 Bucket 存放一個鏈表或更高效的結構 (部分實作可能用 `std::forward_list`)。  
     - 若多個 Key 雜湊到同一 Bucket，會以鏈結方式儲存。  
   - 另一種處理碰撞的方法: ** Open Addressing（開放定址法）**
     - 衝突時，不開鏈，而是往下找空位存放。
     - 常見策略：線性探查（Linear Probing）、二次探查（Quadratic）、雙重雜湊。
   
3. **負載因子 (Load Factor) 與 Rehash**  
   - **負載因子 (α)** = **元素數量 / 桶數量**。  
   - 當 α 超過最大負載因子 (`max_load_factor()`，預設約 1.0) 時，自動進行 **rehash**：增加桶數並重新分配所有元素位置。
   
4. **平均 vs 最壞情況**  
   - 平均情況下 O(1)，但若碰撞嚴重 (所有元素落在同一桶)，鏈表長度會達 O(n)。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation) | 語法 (Syntax) | 平均時間 (Average) | 最壞時間 (Worst) | 備註 |
|------------------|--------------|--------------------|------------------|------|
| 插入 / 更新 | `m[key] = value;`<br>`m.insert({key, value});` | O(1) | O(n) | `[]` 可更新舊值；`insert` 不覆蓋舊值 |
| 查找 | `m.find(key)` | O(1) | O(n) | 回傳 iterator 或 `end()` |
| 存取 | `m.at(key)` | O(1) | O(n) | 不存在會拋出例外；`[]` 若不存在會自動建立 |
| 刪除 | `m.erase(key)` | O(1) | O(n) | |
| 元素總數 | `m.size()` | O(1) | O(1) | |
| 清空 | `m.clear()` | O(n) | O(n) | |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構 | 底層 | 是否有序 | 平均操作 | 適用場景 |
|----------|------|----------|----------|----------|
| **unordered_map** | 哈希表 | ❌ 無序 | O(1) | 快速查找、計數、配對，如 Two Sum |
| **map** | 紅黑樹 (Red-Black Tree) | ✅ 按 Key 排序 | O(log n) | 需要有序輸出、範圍查詢 |
| **unordered_set** | 哈希表 | ❌ 無序 | O(1) | 只需 Key，不需儲存 Value，如去重 |
| **set** | 紅黑樹 | ✅ 有序 | O(log n) | 去重且需有序輸出 |

---

## 5. 使用情境 (Usage Scenarios)
1. **快速查找配對 (Pair Lookup)**  
   - 例：Two Sum、判斷是否存在補數  

2. **頻率統計 (Frequency Counting)**  
   - 例：字母出現次數、Top K Frequent Elements  

3. **分組 (Grouping)**  
   - 例：Group Anagrams (異位詞分組)  
   
4. **去重 (Deduplication)**  
   - 與 `unordered_set` 搭配使用

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **負載因子調整影響性能**  
   - 透過 `reserve(n)` 或 `rehash(n)` 事先配置足夠桶數，可減少 rehash 次數，大幅提升性能 (尤其在大資料量下)。
   
2. **自定義 Key 類型**  
   - `unordered_map` 支援自定義類型作為 Key，但需提供自定義 `hash` 函數與 `==` 運算子。  
   - 例：以 pair<int,int> 為 Key，需要特別實作。
   
3. **最壞情況退化為 O(n)**  
   - 如果雜湊函數設計不良或遭到惡意輸入攻擊 (Hash DoS)，所有元素落同一 Bucket，性能將嚴重退化。

4. **元素遍歷無固定順序**  
   - 不應假設 `unordered_map` 遍歷順序穩定，若需固定順序請改用 `map` 或另行排序。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名 | 重點 |
|------|------|------|
| 1 | Two Sum | 查找配對，基礎應用 |
| 49 | Group Anagrams | Key 為字母統計後的字串 |
| 347 | Top K Frequent Elements | 頻率表搭配堆 |
| 560 | Subarray Sum Equals K | 前綴和計數 |
| 454 | 4Sum II | 配對兩組和的計數 |

---
