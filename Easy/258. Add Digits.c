/*Given an integer num, repeatedly add all its digits
until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
*/
int addDigits(int num) {
    int count,digit,sum = 0;
    while(num>=10)//Earlier I took while(count != 0) but gives an error because sum will reset everytime the loop worls
    {
        sum = 0;
        count = 0;
        
        while(num!=0)
        {
            digit = num%10;
            sum+=digit;
            count++;
            num = num/10;
        }
        num = sum;
    }
    return num;/*Earlier I took return sum but forgot that while(num<10) i.e. when num is a
    single digit number, then even the first loop will never run and hence sum will be 0,
    so return sum will give 0 for numbers less than 10.*/
}
