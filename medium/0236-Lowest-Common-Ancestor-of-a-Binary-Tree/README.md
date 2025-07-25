## key insight
1. 可能出現 p 或 q 即為 LCA 的情況

2. 配合實際範例

             3  
            / \
           5   1
          / \  / \
         6  2 0  8
        / \
       7   4

p = 6 / q = 4


root -> 3 (return 5)

  [1] left (return 5)
  root -> 5
  
    [2] left (6)
    root -> 6
    root == p return root (return 6)
  
    [2] right (return 4)
    root -> 2

      [3] left (return nullptr)
      root -> 7 

        [4] left (return nullptr)
        root -> nullptr

        [4] right (return nullptr)
        root -> nullptr

      [3] right
      root -> 4 (ruturn 4)

  [1] right (nullptr)
  root -> 1

    [2] left (return nullptr)
    root -> 0

      [3] left (return nullptr)
      root -> nullptr

      [3] right (return nullptr)
      root -> nullptr
    
    [2] right (return nullptr)
    root -> 8

      [3] left (return nullptr)
      root -> nullptr

      [3] right (return nullptr)
      root -> nullptr