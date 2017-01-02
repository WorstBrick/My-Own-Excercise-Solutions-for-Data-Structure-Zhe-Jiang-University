#include "Interface.h"

int MaxIndex=-1,MaxTimes=0,Quant=0;
//采用折叠法,电话号码最高位1舍弃,剩下的10位组成两个5位数的和作为Hash地址.
//则Hash地址的值域为0~199998,而最大输入为2*(10^5)=200000,将其除以以Load Factor=0.7,再取素数得到TableSize
//按理来说应该是够的了,可是在PTA上,当数据量最大时老说我超时
Position Hash(ElementType Number,HashTable H)
{
    int i,j,D;
    Position Address=0;

    for (i=1;Number[i]!='\0';i+=5)
        for (D=10000,j=0;j<5;j++,D/=10)
            Address+=(Number[i+j]-'0')*D;

    return (Address%(H->TableSize));
}

//这是老师的版本,只取最低的5位
/*Position Hash(ElementType Number,HashTable H)
{
    Position Address=atoi(Number+6);
    return Address%(H->TableSize);
}*/
int NextPrime(int N)
{
    int Prime=(N%2==0? N+1:N);
    int i;

    while (1)
    {
        for (i=(int)sqrt(Prime);i>2 && Prime%i!=0;i--)
            continue;
        if (i==2)
            break;
        else
            Prime+=2;
    }

    return Prime;
}

HashTable InitHashTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(*H));
    H->TableSize=NextPrime(TableSize);

    int i;
    H->TheCells=(KeysAddress)malloc((H->TableSize)*sizeof(struct KNode));
    for (i=0;i<H->TableSize;i++)
    {
        H->TheCells[i].CallTimes=0;
        H->TheCells[i].Flag=Empty;
        H->TheCells[i].Number=(char *)malloc(12*sizeof(char));
        H->TheCells[i].Number[0]='\0';
    }

    return H;
}

Position Find(ElementType Key,HashTable H)
{
    Position Primary=Hash(Key,H);
    Position Current=Primary;
    int D=0;

    while (H->TheCells[Current].Flag!=Empty && strcmp(Key,H->TheCells[Current].Number)!=0)
    {
        D++;
        if (D%2!=0)
            Current=(Primary+D*D)%H->TableSize;
        else
        {
            Current=Primary-(D*D)/4;
            while (Current<0)
                Current+=H->TableSize;
        }
    }

    return Current;
}

void Insert(ElementType Key,HashTable H)
{
    Position Location=Find(Key,H);

    if (H->TheCells[Location].Flag==Empty)
    {
        (H->TheCells[Location].CallTimes)++;
        H->TheCells[Location].Flag=IsUsed;
        strcpy(H->TheCells[Location].Number,Key);
    }
    else
        (H->TheCells[Location].CallTimes)++;

    if (H->TheCells[Location].CallTimes>MaxTimes)
    {
        MaxIndex=Location;
        MaxTimes=H->TheCells[Location].CallTimes;
        Quant=1;
    }
    else if (H->TheCells[Location].CallTimes==MaxTimes)
    {
        Quant++;
        if (strcmp(H->TheCells[Location].Number,H->TheCells[MaxIndex].Number)<0)
            MaxIndex=Location;
    }
}

void BuildHashTable(int N,HashTable H)
{
    ElementType Number=(ElementType)malloc(12*sizeof(char));
    int i;

    for (i=0;i<N;i++)
    {
        getchar();
        fgets(Number,12,stdin);
        Insert(Number,H);
        getchar();
        fgets(Number,12,stdin);
        Insert(Number,H);
    }
}

void ShowMax(HashTable H)
{
    printf("%s %d",H->TheCells[MaxIndex].Number,MaxTimes);
    if (Quant>1)
        printf(" %d",Quant);
}
