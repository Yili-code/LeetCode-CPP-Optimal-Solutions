# stack

## 1. 基本定義 (Basic Definition)
- **資料結構 (Data Structure)**：  
  棧（Stack）是一種**後進先出（LIFO, Last In First Out）**的線性資料結構。  

- **操作特性**：  
  - 只允許在頂端（top）進行插入（push）和刪除（pop）。  
  - 只能存取頂端元素（top）。  

- **主要用途**：  
  用於暫存資料、遞迴展開、語法解析、深度優先搜尋等。

---

## 2. 底層實現原理 (Underlying Implementation)
- **陣列實作 (Array-based)**：  
  以動態陣列（如 `std::vector`）或固定大小陣列存放元素，頂端為陣列尾部。 

- **鏈結串列實作 (Linked List-based)**：  
  利用單向鏈結串列，將新節點插入頭部作為頂端。  

- C++ STL 中的 `std::stack` 是**容器適配器 (container adaptor)**，預設底層容器為 `deque`，也可以用 `vector` 或 `list`。

---

## 3. 常見操作與時間複雜度 (Common Operations & Complexity)

| 操作 (Operation)   | 語法 (Syntax)       | 時間複雜度 (Time Complexity) | 備註                      |
|--------------------|---------------------|------------------------------|---------------------------|
| 壓入元素 (Push)     | `s.push(val);`       | O(1)                        |                           |
| 彈出元素 (Pop)      | `s.pop();`           | O(1)                        | 不返回值                   |
| 讀取頂端元素 (Top)  | `s.top();`           | O(1)                        |                           |
| 判空               | `s.empty();`         | O(1)                        |                           |
| 取得大小           | `s.size();`          | O(1)                        |                           |

---

## 4. 與相近資料結構比較 (Comparison with Similar Data Structures)

| 資料結構       | 存取規則       | 插入/刪除位置 | 時間複雜度 (插入/刪除) | 適用場景                     |
|----------------|----------------|---------------|------------------------|------------------------------|
| **stack**      | LIFO           | 頂端          | O(1)                   | 遞迴、語法分析、回溯、DFS    |
| **queue**      | FIFO           | 頭尾          | O(1)                   | 排隊、廣度優先搜尋 (BFS)     |
| **deque**      | 雙端可插入刪除 | 頭尾          | O(1)                   | 頭尾操作均衡需求             |
| **vector**     | 隨機存取       | 尾端          | 均攤 O(1)              | 動態陣列，隨機存取需求       |

---

## 5. 使用情境 (Usage Scenarios)
- **函式呼叫堆疊（Call Stack）**：管理遞迴調用和返回。  

- **括號匹配**：判斷程式碼或表達式括號是否匹配。  

- **中序轉後序或前序遍歷**：語法分析、表達式計算。  

- **深度優先搜尋 (DFS)**：樹或圖遍歷。  

- **Undo 功能**：追蹤操作記錄。

---

## 6. 較少人思考的點 (Less-Discussed Points)
1. **容器適配器限制**  
   - `std::stack` 不直接提供迭代器，無法遍歷內容，只能操作頂端。  

2. **底層容器影響性能**  
   - 使用 `deque` 作底層通常最通用，`vector` 底層可優化尾端操作，但不支援頭部操作。  

3. **空間效率與記憶體分配**  
   - 基於陣列的實作可能需要重新分配空間，鏈結串列則需額外指標空間。 
    
4. **多線程安全**  
   - STL stack 非線程安全，須額外同步控制。  
   
5. **泛型與自訂類型支援**  
   - stack 支援任意類型，但需類型有可拷貝或移動建構子。

---

## 7. LeetCode 經典題目 (Classic Problems)

| 題號 | 題名                   | 重點                           |
|------|------------------------|--------------------------------|
| 20   | Valid Parentheses       | 利用 stack 判斷括號匹配         |
| 150  | Evaluate Reverse Polish Notation | 使用 stack 計算後序表達式    |
| 71   | Simplify Path           | 用 stack 處理路徑解析           |
| 155  | Min Stack               | 結合 stack 實作帶最小值功能的堆疊 |
| 232  | Implement Queue using Stacks | 雙 stack 實現 queue 功能      |

---
