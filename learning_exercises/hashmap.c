// solution 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    typedef struct {
        int index;
        int value;
    } Pair;
    Pair pairs[numsSize];
    for(int i = 0; i < numsSize; i++){
        pairs[i].index = i;
        pairs[i].value = nums[i];
    }
    *returnSize = 2; // as defined by the 'two-sum' problem - TODO make this dynamic
    int* solution = malloc(*returnSize * sizeof(int));
    for(int j = 0; j < numsSize; j++){
        for(int k = 0; k < numsSize; k++){
            if((pairs[j].value + pairs[k].value == target) && pairs[j].index != pairs[k].index){
                solution[0] = pairs[j].index;
                solution[1] = pairs[k].index;
            }
        }
    }
    return solution;
}



// solution 2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; // as defined by the 'two-sum' problem - TODO make this dynamic
    int* solution = malloc(*returnSize * sizeof(int));
    for(int j = 0; j < numsSize; j++){
        for(int k = 0; k < numsSize; k++){
            if((nums[j] + nums[k] == target) && j != k){
                solution[0] = j;
                solution[1] = k;
                return solution;
            }
        }
    }
    return solution;
}



// solution 3
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
// TODO implement a hashmap
}