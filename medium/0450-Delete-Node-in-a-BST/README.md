## 解題思路
1. 總共有五種情況，刪除節點為
  - 葉節點 (左右皆空)
  - 左為空、右不為空
  - 右為空、左不為空
  - 左不空、右不空
  - 根節點

2. 當左右皆為空
  - 找右子樹最小值 (successor) 或左子樹最大值 (predecessor) 取代原本的值 (取代 value)
  - 取代後再進行一次 deleteNode (此時 deleteNode 會變成刪除 leaf note)

3. 為了保留當 (root->val == key && root->left && root->right) 時 root 的位置
因此在 private 建立 findMin function，而不是直接在原地 find the seccessor's value
