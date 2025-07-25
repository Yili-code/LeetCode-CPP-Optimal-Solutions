## key insight
考慮到 BST 以及空間複雜度，不使用 vector 將 BST 加入統計，而是直接在 traverse node->val 變化時將總量小於最大量的數字刪除

## time and space complexity
1. 時間複雜度: O(n)

2. 空間複雜度: (額外空間為主) -> O(1)、嚴格計算(包含呼叫堆疊) -> O(1 + h) -> o(h)
 - 額外空間: O(1) 只使用常數變數
 - 呼叫堆疊: O(h) h 為樹高 (平衡 BST 約 log n，退化成鏈表最差 n)

## 額外補充
1. 為什麼 In-order traversal 需要 push to call stack 
  void inOrder(TreeNode* node) {
    if (!node) return;

    inOrder(node->left);       // (1)
    cout << node->val << " ";  // (2)
    inOrder(node->right);      // (3)
  } 

  當呼叫 inOrder(node->left) 時，函式還沒結束，系統要暫存當前的執行狀態 (例如：當前 node, 下一步該執行哪一行)，
  所以會把它壓入系統呼叫堆疊 (Push to Call Stack)。當左子樹遍歷結束後，系統會彈出 (Pop) 返回上一層，繼續執行 (2) 和 (3)。