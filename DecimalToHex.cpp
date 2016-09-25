class Solution {
public:

    string prepend(string result, string digit)
    {
        if(result == "")
            return digit;
            
        return digit.append(result);
    }
    
    string letter(int rem)
    {
        string digit;
        switch(rem)
        {
            case 10:
                digit = "a";
                break;
                    
            case 11:
                digit = "b";
                break;
                    
            case 12:
                digit = "c";
                break;
                    
            case 13:
                digit = "d";
                break;
                    
            case 14:
                digit = "e";
                break;
                    
            case 15:
                digit = "f";
                break;
                    
            default:
                digit = std::to_string(rem);
                
        }
                
        return digit;
        
    }

    string convertPositive(int num) {
        
        int rem;
        string result = "";
        string digit;
        
        while(num > 0)
        {
            rem = num % 16;
            num = num / 16;
               
            digit = letter(rem);
            
            result = prepend(result,digit);
            
        }
        
        return result;
        
    }
    
    string convertNegative(int num) {
        
        int rem, i;
        string result = "";
        string digit;
        
        num = num * -1;
        
        //convert to binary first
        
        while(num > 0)
        {
            rem = num % 2;
            num = num/2;
            
            digit = std::to_string(rem);
            
            result = prepend(result,digit);
        }
        
        //cout<<result<<endl;
        
        //pad with 0s at the beginning fo the string to make it a 32 bit number
        if(result.length() != 32)
        {
            int zeros = 32 - result.length();
            while(zeros > 0)
            {
                result = prepend(result, "0");
                zeros--;
            }
        }
        
        //cout<<result<<endl;
        
        //take 2s complement
        int j, pos = -1;
        
        for(i = 0; i < result.length(); i++)
        {
            if(result[i] == '0')
                result[i] = '1';
            else
                result[i] = '0';
                
            //get the least significant bit set as 0
            if(result[i] == '0')
                pos = i;
        }
        
        //cout<<result<<endl;
        
        if(pos == -1)
        {
            //it is INT_MIN
            result = "80000000";
            return result;
        }
        else
        {
            result[pos] = '1';
            for(j = pos + 1; j < result.length(); j++)
            {
                result[j] = '0';
            }
        }
        
        //cout<<result<<endl;
        
        //convert to hex
        string res = "";
        
        int number = 0,k = 0;
        string name;
        
        for(i = 0; i < result.length(); i = i + 4)
        {
            number = 0;
            k = 3;
            for(j = i; j < i + 4; j++)
            {
                number = number + ((result[j] == '1' ? 1 : 0) * pow(2,k));
                k--;
            }
            
            name = letter(number);
            res.append(name);
        }
        
        return res;
        
    }


    string toHex(int num) {
        
        if(num > 0)
        {
            return convertPositive(num);
        }
        else if(num == 0)
            return "0";
        else
        {
            //number is negative
            return convertNegative(num);
        }
        
    }
};
