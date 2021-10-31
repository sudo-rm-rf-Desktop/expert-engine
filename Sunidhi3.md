class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0,num1=0,num2=0;  // Xor of entire array, the two numbers
        for(int x: nums) xr^=x;   // XOR of two num
        int setBit = 1;   // Let us begin with the first num
        for(int i = 1;i<=31;i++){
            if(xr & setBit) break;    //This is the rightmost set bit   
            setBit<<=1;
        }
		
        for(int x: nums){
            if((x&setBit) == setBit) num1 ^= x;   // this is group A
            else num2 ^= x;   // This is group B
        }
        return {num1,num2};
    } 
    
};
