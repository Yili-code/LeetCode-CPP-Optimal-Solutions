# queue

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  隊列（Queue）是一種**先進先出（FIFO, First In First Out）**的線性資料結構。  

- **操作特性**：  
  - 元素只能從尾端（rear/back）插入（enqueue）。  
  - 元素只能從頭端（front）刪除（dequeue）。  

- **主要用途**：  
  排隊系統、廣度優先搜尋（BFS）、資源調度等。

---

## 2. 底層實現原理 (Underlying Implementation)
- **陣列環狀緩衝區 (Circular Array)**  
  - 使用固定大小陣列，利用 modulo 運算實現頭尾指標環繞。  

- **鏈結串列 (Linked List)**  
  - 使用節點指標串連，動態大小，避免空間浪費。  

- C++ STL `std::queue` 是容器適配器，底層通常以 `deque` 實作。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)       | 語法 (Syntax)      | 時間複雜度 (Time Complexity) | 備註                       |
|------------------------|--------------------|------------------------------|----------------------------|
| 插入元素（入隊）        | `q.push(val);`      | O(1)                        | 在尾端插入                 |
| 刪除元素（出隊）        | `q.pop();`          | O(1)                        | 移除頭端元素               |
| 讀取隊頭元素            | `q.front();`        | O(1)                        |                           |
| 讀取隊尾元素            | `q.back();`         | O(1)                        |                           |
| 判空                   | `q.empty();`        | O(1)                        |                           |
| 取得大小               | `q.size();`         | O(1)                        |                           |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構       | 存取規則       | 插入位置  | 刪除位置  | 時間複雜度 (插入/刪除) | 適用場景                      |
|----------------|----------------|-----------|-----------|------------------------|-------------------------------|
| **queue**      | FIFO           | 尾端      | 頭端      | O(1)                   | 排隊系統、BFS、工作排程       |
| **stack**      | LIFO           | 頂端      | 頂端      | O(1)                   | 遞迴、括號匹配、深度優先搜尋  |
| **deque**      | 雙端可操作     | 頭尾均可  | 頭尾均可  | O(1)                   | 雙端操作需求，隨機存取         |
| **priority_queue** | 優先級隊列  | 按優先級插入 | 按優先級刪除 | O(log n)              | 需要依優先順序處理的資料       |

---

## 5. 使用情境 (Usage Scenarios)
- 模擬排隊機制，如列隊購票、列印任務排程。  

- **廣度優先搜尋 (BFS)**，例如圖或樹的層序遍歷。  

- 非同步事件處理與訊息緩衝。  

- 資源池的公平分配。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **空間管理**  
   - 使用環狀陣列避免頻繁移動元素，提高空間利用率。  
   
2. **多線程安全**  
   - 標準 queue 非線程安全，需額外鎖或使用並行結構。  

3. **迭代器缺失**  
   - `std::queue` 無迭代器，無法直接遍歷內容。 

4. **底層容器差異**  
   - 可指定底層容器（`deque`、`list`），影響性能特性。  
   
5. **實務中 queue 可能被封裝為消息隊列或事件隊列**  
   - 用於跨執行緒通訊或非同步處理。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名                      | 重點                            |
|------|---------------------------|---------------------------------|
| 102  | Binary Tree Level Order Traversal | BFS 使用 queue 層序遍歷       |
| 200  | Number of Islands         | BFS 用 queue 搜尋連通區塊      |
| 933  | Recent Counter            | 使用 queue 儲存時間戳，維護窗口|
| 225  | Implement Stack using Queues | 利用兩個 queue 實作 stack      |
| 622  | Design Circular Queue     | 環狀 queue 實作                 |

---
