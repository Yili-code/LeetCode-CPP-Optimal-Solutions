class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int totalTank = 0; // Total gas gain across the whole circuit
    int currTank = 0;  // Current gas tank when starting from `start`
    int start = 0;     // Candidate starting station

    for (int i = 0; i < gas.size(); ++i) {
      int gain = gas[i] - cost[i];
      totalTank += gain;
      currTank += gain;

      // If we run out of gas at station i, we cannot start from any station before or at i
      if (currTank < 0) {
        start = i + 1;
        currTank = 0;
      }
    }

    // If the total gas is less than the total cost, we cannot complete the circuit 
    return totalTank < 0 ? -1 : start;
  }
};
