## key insight
1. BST : 
 - 每個節點至多兩個子節點(Left Subtree and Right Subtree)
 
 - 節點排序性質: 對於任意一個節點 N
  - 左子樹所有值 < N
  - 右子樹所有值 > N

 - 對於任意一個節點 N，其左右子樹皆為 BST

2. 利用 BST 特性將節點存入 vector, for loop 逐一比較後更新 result.

3. inorder traversal: left middle right

## time and space complxity
1. 時間複雜度: O(n) <- O(n) + o(n)
 - In-order Traversal: O(n)
 - compare in vector: O(n)

2. 空間複雜度: O(n) <- max(O(n), O(h))
 - vector<int>: O(n)
 - recursion call stack: O(h)
  - balanced BST: h -> log n
  - worst case: h -> n

 - 總空間 = max(存陣列的空間, 遞迴堆疊空間) = max(O(n), O(h))

## 優化
1. 中序遍歷邊比較相鄰節點值，不再儲存所有節點，只記錄：
 - prevVal：前一個節點值

 - minDiff：目前最小絕對差

2. 額外空間只用到 2 個整數 → O(1)（不計遞迴堆疊）

class Solution {
private:
    int prevVal = -1;     // 記錄前一個節點值 (-1 表示還沒初始化)
    int minDiff = INT_MAX; // 目前最小差值

    void inOrder(TreeNode* node) {
        if (!node) return;

        inOrder(node->left);

        if (prevVal != -1) { // 從第二個節點開始才能比較
            minDiff = min(minDiff, node->val - prevVal);
        }
        prevVal = node->val;

        inOrder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};