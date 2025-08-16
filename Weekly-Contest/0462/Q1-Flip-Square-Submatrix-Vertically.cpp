class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
      if (grid.size() == 0) return {};
      
      if (k % 2 == 1) {
        int mid = (k + 1) / 2 + x - 1;
        int top = mid - 1;
        int bottom = mid + 1;
        
        while (top >= x) {
          for (int i = y; i < y + k; ++i) {
            swap(grid[top][i], grid[bottom][i]); 
          }

          --top;
          ++bottom;
        }

      } else {
        int mid_top = k / 2 + x - 1;
        int mid_bot = mid_top + 1;

        while (mid_top >= x) {
          for (int i = y; i < y + k; ++i) {
            swap(grid[mid_top][i], grid[mid_bot][i]);  
          }

          --mid_top;
          ++mid_bot;
        }
      }

      return grid;
    }
};