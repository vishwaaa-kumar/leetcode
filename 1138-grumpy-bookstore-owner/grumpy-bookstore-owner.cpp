class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int notGrumpy = 0;
         // initial satisfied customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                notGrumpy += customers[i];
        }
        int specialPower = 0;
        // initial additional customers if we use the grumpy technique
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1)
                specialPower += customers[i];
        }
        int maxSpecialPower = specialPower;
        // Sliding window to maximize additional customers we can gain
        for (int i = minutes; i < n; i++) {
            if (grumpy[i-minutes] == 1) // Remove if grumpy at 'i - minutes'
                specialPower -= customers[i-minutes];
            if (grumpy[i] == 1) // Add if grumoy at 'i'
                specialPower += customers[i];
            maxSpecialPower = max(maxSpecialPower, specialPower);
        }
        return notGrumpy + maxSpecialPower;
    }
};