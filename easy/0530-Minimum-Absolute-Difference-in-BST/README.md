## 解題思路
1. BST : 
 - 每個節點至多兩個子節點(Left Subtree and Right Subtree)
 
 - 節點排序性質: 對於任意一個節點 N
  - 左子樹所有值 < N
  - 右子樹所有值 > N

 - 對於任意一個節點 N，其左右子樹皆為 BST

2. 利用 BST 特性將節點存入 vector, for loop 逐一比較後更新 result.

3. inorder traversal: left middle right