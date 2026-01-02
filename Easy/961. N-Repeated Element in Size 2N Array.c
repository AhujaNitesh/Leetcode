/*You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

Example 1:
Input: nums = [1,2,3,3]
Output: 3

Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
 

Constraints:

2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
nums contains n + 1 unique elements and one of them is repeated exactly n times.*/
/*
The main logic was that it contains n+1 unique elements, and one element repeats more than once,
i.e. n times
eg. an array contains 4 elements so its length is 6 (2*n thus n = 3)
and now n+1 unqiue elements are present including the one which is repeated and the repeated element appears n times.
This means n (unique excluding the repeating number) + n (times the number is repeated counting the 1 we excluded in the first n) = 2n
*/

/*Pigeonhole Principle (Learnt today)

"If you put more items than containers, at least one container must contain more than one item."

Because the repeated element appears so frequently, it is guaranteed to appear
either adjacent to itself or with at most one element in between.
This allows us to detect it by checking nums[i] with nums[i+1] and nums[i+2]*/
int repeatedNTimes(int* nums, int numsSize) {
    int i,ans;
    ans = nums[0];
    for(i=0;i<numsSize-2;i++)
    {
        if(nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
        {
            ans = nums[i];
            return ans;
        }
    }
    return nums[numsSize-1];/*I added this as a fall back return to check if last 2 elements are same
    if after running the entire loop, no answer returns in a 4 element array e.g. 2,3,9,9
    as the loop tills third last element only so i+1 and i+2 i.e last and 2nd last elements are not checked
    and 4 element array contains 2 repeated numbers*/
}