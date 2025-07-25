# hash_collision_handling

## 1. 基本定義 (Basic Definition)
- **資料結構背景**：  
  哈希表 (Hash Table) 是一種基於「鍵 (Key) → 雜湊函數 (Hash Function) → 桶 (Bucket)」映射的資料結構。

- **碰撞 (Collision)**：  
  當兩個不同的鍵經過雜湊函數後得到相同的桶索引，即發生碰撞。  

- **碰撞處理**是哈希表維持高效操作的核心技術，決定元素在桶內的存放與查找策略。

---

## 2. 底層實現原理 (Underlying Implementation)

### 2.1 碰撞處理策略 (Collision Resolution Strategies)

#### (1) 鏈地址法 (Separate Chaining)
- 每個桶實際上是一個**鏈結串列**（或其他容器如樹、向量等）。  

- 碰撞的元素被存放在該桶的鏈結串列中。  

- 查找時：先定位桶，然後在鏈結串列中線性搜尋。  

- C++ `unordered_map` 和 `unordered_set` 多數實作使用此法。  

- **優點**：實作簡單，動態可伸縮，理論和實務表現都好。  

- **缺點**：若負載過高，鏈表過長，查找性能下降。

#### (2) 開放定址法 (Open Addressing)
- 當碰撞發生時，透過探查（Probe）找尋下一個空桶。  

- 常見探查策略：線性探查、二次探查、雙重雜湊等。  

- C++ 標準 `unordered_map` 不常使用此法，但部分語言或庫使用。  

- **優點**：不需額外指標空間，空間利用率高。  

- **缺點**：插入/刪除較複雜，容易聚集（Clustering）導致性能下降。

---

### 2.2 負載因子 (Load Factor)
- 定義：**負載因子 α = 元素數量 / 桶數量**。  

- 負載因子越大，桶中鏈表長度越長，碰撞越多，查找效率下降。  

- 一般設置最大負載因子限制（例如 1.0 或 0.75），超過時會執行 **rehash**。  

- **rehash**：  
  - 增加桶數量（通常倍增）  
  - 重新計算每個元素的桶索引並移動  
  - 負載因子下降，性能恢復

---

## 3. 常見操作影響 (Effects on Operations)

| 操作 | 理想時間複雜度 | 負載因子影響 | 碰撞影響 |
|------|-----------------|--------------|----------|
| 插入 | O(1)           | 負載因子越高，鏈表越長，插入成本增高 | 多碰撞需線性探查或鏈表掃描 |
| 查找 | O(1)           | 負載因子越高，鏈表越長，查找成本增高 | 相同桶中線性掃描 |
| 刪除 | O(1)           | 同插入與查找影響 | 需定位元素後刪除鏈結 |

---

## 4. 與相近資料結構比較 (Comparison with Other Collision Handling)

| 特性           | Separate Chaining           | Open Addressing               |
|----------------|----------------------------|------------------------------|
| 空間需求       | 需指標與鏈表空間           | 只用陣列空間                 |
| 插入速度       | 穩定                       | 快（探查時可能較慢）          |
| 刪除方便度     | 容易（直接移除鏈表節點）   | 較難（需標記刪除狀態）        |
| 實作難度       | 較簡單                     | 較複雜                       |
| 空間利用率     | 較低，因鏈結開銷           | 較高                         |
| 性能退化風險   | 高負載時退化為 O(n)        | 聚集效應導致退化             |

---

## 5. 較少人思考的點 (Less-Discussed Points)

1. **rehash 頻率與成本權衡**  
   - rehash 是昂貴操作，但避免頻繁執行是性能關鍵。  
   - 預估容量與合理設定最大負載因子能降低 rehash 次數。

2. **非均勻雜湊函數導致性能瓶頸**  
   - 不良雜湊函數會使大量元素集中同一桶，造成鏈長增長。  
   - 自訂雜湊函數時應避免簡單線性映射。

3. **多線程環境下的哈希表**  
   - 多線程插入/查找時碰撞處理的同步機制設計複雜。  
   - 多數 STL 容器非線程安全，需額外鎖或使用並行容器。

4. **散列桶內資料結構優化**  
   - 部分高效實作會將桶內鏈結改為平衡樹 (如 Java HashMap 在長鏈時轉成紅黑樹)，提升最壞情況查找效率。

---

## 6. 使用情境 (Usage Scenarios)

- 哈希表中 **碰撞處理** 是性能優劣的關鍵。  

- **鏈地址法** 適合 STL 容器，簡單且擴展性佳。  

- **開放定址法** 適合內存受限且需緊湊陣列的場景。  

- 選擇合適碰撞處理方式須視具體應用需求、記憶體限制與預期資料量而定。

---
