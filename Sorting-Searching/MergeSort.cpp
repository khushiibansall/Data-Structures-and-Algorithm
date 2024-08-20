class Solution {
public:
        
        void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1; // Size of left subarray
        int n2 = right - mid;    // Size of right subarray

        // Create temporary vectors
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        // Copy data to temporary vectors
        for (int i = 0; i < n1; i++)
            leftArr[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = nums[mid + 1 + j];

        // Merge the temporary vectors back into nums[left..right]
        int i = 0; // Initial index of leftArr
        int j = 0; // Initial index of rightArr
        int k = left; // Initial index of merged subarray

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }

        // Copy remaining elements of leftArr[], if any
        while (i < n1) {
            nums[k++] = leftArr[i++];
        }

        // Copy remaining elements of rightArr[], if any
        while (j < n2) {
            nums[k++] = rightArr[j++];
        }
    }

    // MergeSort function to sort the array
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = left + (right - left) / 2;

            // Recursively sort the first and second halves
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);

            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }

    // Function to sort the array and return it
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
