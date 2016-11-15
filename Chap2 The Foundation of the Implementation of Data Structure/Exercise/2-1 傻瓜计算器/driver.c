#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE 20
int main(void)
{
    int number,bit;
    char Operator,temp;
    char input[STR_SIZE];
    int cnt=1;
    int result,i;

    scanf("%s",input);
	result=atoi(&input[0]);
	//printf("%d\n",result);
    for (i=1;(temp=input[i])!='=';i++)
    {
        if (temp>47 && temp<57)
		{
            number=atoi(&input[i]);
			cnt++;
			if ((bit=number/10)>0)
				i+=bit;
		}
        else
            Operator=temp;
        if (cnt==2)
        {
            if (Operator=='+')
                result+=number;
            else if (Operator=='-')
                result-=number;
            else if (Operator=='*')
                result*=number;
            else if (Operator=='/')
                {
                    if (number==0)
					{
						printf("ERROR\n");
						exit(0);
					}
                    else
                        result/=number;
                }
            else
                {
					printf("ERROR\n");
					exit(0);
				}
			cnt=1;
        }
    }
    printf("%d\n",result);

    return 0;
}
