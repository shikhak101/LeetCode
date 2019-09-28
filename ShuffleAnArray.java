class Solution {
    int[] array;
    int[] original;
    Random rand = new Random();

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        array = original;
        original = original.clone();
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    
    public int[] shuffle() {
        for(int i=0; i<array.length; i++){
            int idx = rand.nextInt(array.length-i)+i;
            int temp = array[idx];
            array[idx] = array[i];
            array[i] = temp;
        }
        return array;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */