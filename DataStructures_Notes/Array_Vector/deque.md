# deque

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  雙端隊列（Double-Ended Queue），允許在兩端進行高效插入與刪除的序列容器。  
- **元素特性 (Element Properties)**：  
  - 支援從頭尾兩端快速（常數時間）插入與刪除。  
  - 支援隨機存取（O(1) 時間）。  
  - 在 C++ STL 中 `std::deque` 不是單純的連續陣列，而是由多個固定大小的緩衝區組成。

---

## 2. 底層實現原理 (Underlying Implementation)
- `std::deque` 實作通常採用**分段陣列 (Segmented Array)**，包含多個小陣列（block/chunk）。  
- 這些小陣列透過一個陣列（map）管理指標，支援在兩端靈活增減小陣列。  
- 隨機存取時，先定位哪個 block，再定位 block 內的元素。  
- 插入刪除操作在兩端是 O(1)，中間則為 O(n)。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)      | 語法 (Syntax)        | 時間複雜度 (Time Complexity) | 備註                       |
|---------------- ------|---------------------|-----------------------------|----------------------------|
| 插入尾端              | `d.push_back(val)`   | O(1) 均攤                   |                            |
| 插入頭端              | `d.push_front(val)`  | O(1) 均攤                   |                            |
| 刪除尾端              | `d.pop_back()`       | O(1)                        |                            |
| 刪除頭端              | `d.pop_front()`      | O(1)                        |                            |
| 隨機存取              | `d[i]`               | O(1)                        |                            |
| 插入/刪除中間元素      | `insert` / `erase`   | O(n)                        | 需搬移元素                  |
| 大小                  | `d.size()`           | O(1)                        |                            |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構    | 底層實作                   | 頭尾插入刪除     | 隨機存取  | 適用場景                     |
|------------|---------------------------|-----------------|----------|------------------------------|
| **deque**  | 分段陣列 (Segmented Array) | O(1)            | O(1)     | 頭尾操作頻繁，需隨機存取     |
| **vector** | 連續陣列                   | O(n) 頭部插入    | O(1)     | 尾端插入刪除頻繁，隨機存取   |
| **list**   | 雙向鏈結串列                | O(1)           | O(n)     | 頻繁中間插入刪除，非隨機存取 |

---

## 5. 使用情境 (Usage Scenarios)
- 需要在**兩端快速插入與刪除**的場景（如滑動視窗、雙端隊列緩衝）。  
- 需**隨機存取元素**，但又要避免 vector 在頭部插入造成效能問題。  
- FIFO 與 LIFO 混合使用情況。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **內存碎片化與分配**  
   - 由多個小陣列組成，可能比 vector 佔用更多內存碎片。  
   
2. **迭代器失效規則**  
   - 插入或刪除元素時，部分迭代器可能失效，需小心使用。  

3. **容量與擴容策略**  
   - 分段陣列內部管理，擴容較 vector 複雜，不一定有連續空間。 

4. **與 vector 的效能比較**  
   - vector 適合尾端大量操作，deque 頭尾均衡操作時更佳。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名               | 重點                           |
|------|--------------------|--------------------------------|
| 239  | Sliding Window Maximum | 利用 deque 做單調隊列解題     |
| 862  | Shortest Subarray with Sum at Least K | 使用 deque 優化前綴和解法 |
| 321  | Create Maximum Number | 雙端操作策略                  |
| 155  | Min Stack          | 利用 deque 實作堆疊            |
| 641  | Design Circular Deque | 模擬雙端隊列                  |

---
