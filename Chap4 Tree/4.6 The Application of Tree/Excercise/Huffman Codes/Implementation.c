#include "Interface.h"

int CharFre[SIZE];
int OptFreSum;
int FreSum;

Tree NewNode(void)
{
    Tree T=(Tree)malloc(sizeof(*T));
    T->Data=NOINFO;
    T->Left=T->Right=NULL;

    return T;
}


void ReadFre(int N)
{
    int i;
    char ch;

    fflush(stdin);
    for (i=0;i<N;i++)
    {
        scanf("%c %d",&ch,&CharFre[i]);
        getchar();
    }
}

void CalFre(int N)
{
    extern int FreSum;
    double digit=(log(N+1)/log(2));
    int i;

    FreSum=0;
    for (i=0;i<N;i++)
        FreSum+=(int)(digit*CharFre[i]);
}

bool JudgeHuff(int N)
{
    Tree root=NewNode();
    Tree Tmp;
    int i,cnt;
    ElementType Data,Code;
    bool flag=false;
    extern int FreSum;
    extern int OptFreSum;
    extern int CharFre[SIZE];

    OptFreSum=0;
    for (i=0;i<N;i++)
    {
        Tmp=root;
        fflush(stdin);
        scanf("%c ",&Data);
        cnt=0;
        while ((Code=getchar())!='\n')
        {
            cnt++;
            switch (Code)
            {
                case '0':
                    if (!(Tmp->Left))
                        Tmp->Left=NewNode();
                    Tmp=Tmp->Left;
                    if (Tmp->Data!=NOINFO)
                        flag=true;
                    break;
                case '1':
                    if (!(Tmp->Right))
                        Tmp->Right=NewNode();
                    Tmp=Tmp->Right;
                    if (Tmp->Data!=NOINFO)
                        flag=true;
                    break;
                default:
                    break;
            }
        }
        if (Tmp->Left || Tmp->Right)
            flag=true;
        Tmp->Data=Data;
        OptFreSum+=cnt*CharFre[i];
    }

    if (flag)
        return false;
    return (OptFreSum<FreSum);
}
