#include <stdio.h>


int doesRepeat(char * string, int leftLimit, int rightLimit)
{
    for(int i=leftLimit;i<rightLimit;i++)
    {
        for(int j=leftLimit+1;j<rightLimit;j++)
        {   
            if(i==j)continue;
            if(string[i]==string[j])
            return 0;
        }
    }
    return 1;
}
int lengthOfLongestSubstring(char* s)
{ 
    int len=0,answer=0;
    while((s[++len])!='\0');//length detector
    for(int ptr1=len-1;ptr1>=0;ptr1--)
    {
        for(int ptr2=0;ptr2<ptr1;ptr2++)
        {   
            if(!doesRepeat(s,ptr2,ptr1))
            {
                continue;
            }
            else
            {
                if(((ptr1)-(ptr2))>=answer)
                 answer=(ptr1)-(ptr2);
            }
        }   
    }
   return answer;
}




int main()
{
    char s[] = "jkiksjfd";
    int result = lengthOfLongestSubstring(s);
    printf("\n%d\n", result);
    return 0;
}