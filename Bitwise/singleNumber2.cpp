int singleNumber(vector<int>& nums) {
    vector<int> store(32, 0);

    for (int num : nums) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                store[i]++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (store[i] % 3 != 0) {
            result |= (1 << i);
        }
    }

    return result;
}
