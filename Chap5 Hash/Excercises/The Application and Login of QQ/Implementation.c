#include "Interface.h"

int Hash(ElementType Key,HashTable H)
{
    return (int)(Key%H->TableSize);
}

int NextPrime(int TableSize)
{
    if (TableSize%2==0)
        TableSize++;
    int i;

    while (1)
    {
        for (i=sqrt(TableSize);i>2 && i%TableSize;i--)
            continue;
        if (i==2)
            break;
        else
            TableSize+=2;
    }

    return TableSize;
}

HashTable InitHashTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(*H));
    H->TableSize=NextPrime((int)(TableSize/0.7));

    H->AllKeys=(Cells)malloc((H->TableSize)*sizeof(struct KNode));

    int i;
    for (i=0;i<H->TableSize;i++)
        H->AllKeys[i].Next=NULL;

    return H;

}

Position Find(ElementType Key,HashTable H)
{
    Position Tmp=H->AllKeys[Hash(Key,H)].Next;

    while (Tmp!=NULL && Tmp->Key!=Key)
        Tmp=Tmp->Next;

    return Tmp;
}

bool Insert(ElementType Key,char PassWord[],HashTable H)
{
    Position Tmp=Find(Key,H);

    if (Tmp==NULL)
    {
        int Address=Hash(Key,H);
        Tmp=(PtrToKode)malloc(sizeof(struct KNode));
        Tmp->Key=Key;
        Tmp->PassWord=(char *)malloc(DIGITS*sizeof(char));
        strcpy(Tmp->PassWord,PassWord);
        Tmp->Next=H->AllKeys[Address].Next;
        H->AllKeys[Address].Next=Tmp;
        return true;
    }

    else
        return false;
}

ElementType MakeKey(char RawKey[])
{
    int i;

    for (i=0;i<11 && RawKey[i]=='0';i++)
        continue;

    return (ElementType)(atol(&RawKey[i]));
}

static void Myfgets(char Buf[],int Limit)
{
    char ch;
    int cnt;

    for (cnt=0;cnt<Limit-1 && (ch=getchar())!='\n' && ch!=' ';cnt++)
        Buf[cnt]=ch;
    Buf[cnt]='\0';
    if (cnt==Limit-1)
        getchar();
}
void AppAndLog(int N,HashTable H)
{
    int i;
    char Command;
    char Number[11];
    char PassWord[17];
    ElementType Key;
    Position Tmp;

    getchar();
    for (i=0;i<N;i++)
    {
        Command=getchar();
        getchar();
        Myfgets(Number,11);
        //getchar();
        Myfgets(PassWord,17);
        Key=MakeKey(Number);
        switch (Command)
        {
            case 'L':
                if ((Tmp=Find(Key,H))==NULL)
                    puts("ERROR: Not Exist");
                else
                {
                    if (strcmp(Tmp->PassWord,PassWord)==0)
                        puts("Login: OK");
                    else
                        puts("ERROR: Wrong PW");
                }
                break;
            case 'N':
                if (Insert(Key,PassWord,H))
                    puts("New: OK");
                else
                    puts("ERROR: Exist");
                break;
            default:
                break;
        }
    }
}
