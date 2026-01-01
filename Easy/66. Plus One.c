/*You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.


Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].*/

/*Solution by me: -*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
The main logic was to divide the problem into 3 cases: -
1. If the last digit is less than 9, we can simply increment it and return the array.
2. If there are some 9's at the end but there is a non-9 digit before them,
   we can set all the 9's to 0 and increment that non-9 digit by 1.
3. If all the digits are 9's, we need to create a new array with an additional digit at the start 
   and set it to 1(size of new array should be digitsSize + 1), and set all other digits to 0.
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    for(i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]<9)
        {
            digits[i] += 1;
            *returnSize = digitsSize;//(logic if i>=0 or flag == 0)
            return digits;
        }
        digits[i]=0;//Used this for numbers like 899 where after the loop it returned 999
        /*So we introduced this for terms which contained a non nine number but also had 
        9's in them*/
    }
    //if(i=-1)//The loop continued till the end (no need since digit[i] == 9 now)
    /*After this is the case handling for digit[i] == 9 as the digit was never equal to 9
    and hence the loop continued till the very end and didn't returned digits array,
    so the loop got over till i became equal to -1*/
        int* newArray = (int*)malloc((digitsSize + 1) * sizeof(int));
        newArray[0] = 1;
        for (i = 1; i <= digitsSize; i++)
        {
            newArray[i] = 0;
        }
        *returnSize = digitsSize + 1;
        return newArray;
}

