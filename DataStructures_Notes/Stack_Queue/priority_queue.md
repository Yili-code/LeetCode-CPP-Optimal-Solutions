# priority_queue

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  優先佇列（Priority Queue）是一種特殊的隊列，元素出隊順序依**優先權（priority）**決定，而非單純 FIFO 或 LIFO。  

- **元素特性**：  
  - 每個元素有對應的優先權，通常預設為最大值優先（max-heap）。  
  - 出隊時取出當前優先權最高的元素。  

- **用途**：  
  用於需按優先級別處理任務的場景，如排程、演算法中最短路徑、事件驅動模擬。

---

## 2. 底層實現原理 (Underlying Implementation)
- **二元堆（Binary Heap）**實作最常見，具備完全二元樹結構，通常以陣列形式存放。  

- **最大堆（Max-Heap）**：父節點值 ≥ 子節點值，堆頂為最大元素。  

- **最小堆（Min-Heap）**：父節點值 ≤ 子節點值，堆頂為最小元素（可透過比較器自訂）。  

- 堆操作包含插入、彈出頂端元素時會維護堆結構。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)          | 語法 (Syntax)           | 時間複雜度 (Time Complexity) | 備註                        |
|---------------------------|-------------------------|------------------------------|-----------------------------|
| 插入元素 (Push)           | `pq.push(val);`          | O(log n)                     | 將元素放入堆中，維護堆序     |
| 讀取頂端元素 (Top)        | `pq.top();`              | O(1)                        | 取最大/最小元素              |
| 彈出頂端元素 (Pop)        | `pq.pop();`              | O(log n)                     | 移除最大/最小元素，維護堆序 |
| 判空                     | `pq.empty();`            | O(1)                        |                             |
| 取得大小                 | `pq.size();`             | O(1)                        |                             |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構           | 優先順序     | 插入時間     | 取最大/最小時間 | 適用場景                       |
|--------------------|--------------|--------------|----------------|-------------------------------|
| **priority_queue** | 優先級決定   | O(log n)     | O(1)           | 排程、Dijkstra、事件模擬       |
| **queue**          | 先進先出     | O(1)         | O(1) (頭部)    | 排隊系統、BFS                  |
| **stack**          | 後進先出     | O(1)         | O(1) (頂部)    | 遞迴、括號匹配、DFS            |
| **set / map**      | 有序元素     | O(log n)     | O(log n)       | 需排序且能快速查找的場景       |

---

## 5. 使用情境 (Usage Scenarios)
- **演算法優化**：Dijkstra 最短路徑、Prim 最小生成樹等需頻繁找最大/最小元素。  

- **任務排程**：需優先處理重要任務。  

- **事件驅動模擬**：依事件時間或優先級觸發處理。  

- **資料流中維持前 k 大（或小）元素**。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **自訂比較器 (Custom Comparator)**  
   - 可透過模板參數定義自訂排序，如變成最小堆或依自訂規則排序。  

2. **底層容器彈性**  
   - `std::priority_queue` 預設底層為 `vector`，可替換為其他序列容器。  

3. **無法遍歷全部元素**  
   - priority_queue 不支援迭代器，無法直接遍歷所有元素。  

4. **更新元素優先權較複雜**  
   - 不支援隨機存取更新元素優先權，需刪除後重插或使用特殊資料結構（如堆疊疊堆）。  
   
5. **內存與性能考量**  
   - 堆結構操作需多次交換元素，插入和刪除的常數因子比 queue 或 stack 高。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名                           | 重點                              |
|------|--------------------------------|-----------------------------------|
| 23   | Merge k Sorted Lists            | 利用 priority_queue 合併多鏈表      |
| 215  | Kth Largest Element in an Array | 用最大堆或最小堆求第 k 大元素        |
| 347  | Top K Frequent Elements         | 用 priority_queue 取前 k 高頻率元素  |
| 373  | Find K Pairs with Smallest Sums | 雙指針配合 priority_queue         |
| 778  | Swim in Rising Water            | Dijkstra + priority_queue          |

---
