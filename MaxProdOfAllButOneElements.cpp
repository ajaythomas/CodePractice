/*
Elements of Programming Interview book
Question 6.11
Find the maximum product that can be created using all elements except one of an array
*/

class Solution {
public:
    int MaxProdOfAllButOneElements(vector<int>& nums) {
        
        int i = 0, negCount = 0, smallestValNegNumber = 0, largestValNegNumber = 0, smallestValNonNegNumber = -1;
        int maxProd = 1;
        
        for(i= 0 ; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                negCount++;
                if(smallestValNegNumber == 0)
                    smallestValNegNumber = nums[i];
                else
                {
                    if(smallestValNegNumber < nums[i])
                        smallestValNegNumber = nums[i];
                }
                
                if(largestValNegNumber == 0)
                    largestValNegNumber = nums[i];
                else
                {
                    if(largestValNegNumber > nums[i])
                        largestValNegNumber = nums[i];
                }
            }
            else
            {
                if(smallestValNonNegNumber == -1)
                    smallestValNonNegNumber = nums[i];
                else
                {
                    if(smallestValNonNegNumber > nums[i])
                        smallestValNonNegNumber = nums[i];
                }
            }
        }
        
        int flag = 0;
        
        switch(negCount)
        {
            
        case 0:
            flag = 0;
            for(i = 0; i < nums.size(); i++)
            {
                //we dont want to drop the same value twice if there are duplicates
                if(flag == 0 && nums[i] == smallestValNonNegNumber)
                {
                    flag = 1;
                    continue;
                }
                maxProd = maxProd * nums[i];
            }
            
            break;
            
        case 1:
            
            for(i = 0; i < nums.size(); i++)
            {
                if(nums[i] < 0)
                    continue;
                    
                maxProd = maxProd * nums[i];
            }
            
            break;
            
        default:
        
            if(negCount%2 != 0)
            {
                flag = 0;
                for(i = 0; i < nums.size(); i++)
                {
                    if(flag == 0 && nums[i] == smallestValNegNumber)
                    {
                        flag = 1;
                        continue;
                    }
                    
                    maxProd = maxProd * nums[i];
                }
                
            }
            else //number of negative numbers is even
            {
                if(smallestValNonNegNumber == -1)
                {
                    cout
                    flag = 0;
                    //all the array elements are negative, maxProd has to be negative
                    //we drop the largest value negative number
                    for(i = 0; i < nums.size(); i++)
                    {
                        if(flag == 0 && nums[i] == largestValNegNumber)
                        {
                            flag = 1;
                            continue;
                        }
                        
                        maxProd = maxProd * nums[i];
                    }
                    
                }
                else
                {
                    flag = 0;
                    for(i = 0; i < nums.size(); i++)
                    {
                        if(flag == 0 && nums[i] == smallestValNonNegNumber)
                        {
                            flag = 1;
                            continue;
                        }
                        
                        maxProd = maxProd * nums[i];
                    }
                }
                
            }
            
            break;
            
        }
        
        return maxProd;
        
        
    }
};
