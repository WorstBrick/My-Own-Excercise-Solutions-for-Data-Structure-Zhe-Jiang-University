#include "Interface.h"

int DIGITQ;

UserList InitUserList(int MaxNum)
{
    UserList U=(UserList)malloc(MaxNum*sizeof(struct UNode));
    int i;

    for (i=0;i<MaxNum;i++)
    {
        U[i].AllTopicsMarks=NULL;
        U[i].FullMarkQuant=0;
        U[i].TotalMarks=0;
    }
    return U;
}

int GetID(char Buf[])
{
    int i;
    int tmp;
    int ID=0,Mul=1;

    for (i=1;Buf[5-i]=='0';i++)
        Mul*=10;

    for (;i<=5 && Buf[5-i]!='0';i++)
    {
        tmp=(int)Buf[5-i]-48;
        ID+=tmp*Mul;
        Mul*=10;
    }

    return ID;
}
static Topics InitTopics(int K)
{
    Topics T=(Topics)malloc(K*sizeof(int));
    int i;

    for (i=0;i<K;i++)
        T[i]=NOSOLUTION;

    return T;
}
void BuildUserList(UserList U,int * FullMark,int M,int K)
{
    int i;
    char Buf[6];
    int UID,EID,Mark;

    getchar();
    for (i=0;i<M;i++)
    {
        fgets(Buf,6,stdin);
        UID=GetID(Buf);
        UID--;
        scanf("%d %d",&EID,&Mark);
        getchar();
        if (U[UID].AllTopicsMarks==NULL)
            U[UID].AllTopicsMarks=InitTopics(K);
        if (U[UID].AllTopicsMarks[EID-1]<Mark)
        {
            if (Mark<=0)
                U[UID].AllTopicsMarks[EID-1]=0;
            else
            {
                if (U[UID].AllTopicsMarks[EID-1]>0)
                    U[UID].TotalMarks-=U[UID].AllTopicsMarks[EID-1];
                U[UID].TotalMarks+=Mark;
                U[UID].AllTopicsMarks[EID-1]=Mark;
            }
        }

        if (Mark==FullMark[EID-1])
            (U[UID].FullMarkQuant)++;
    }
}


Table InitTable(int MaxNum)
{
    Table T=(Table)malloc(MaxNum*sizeof(int));
    int i;

    for (i=0;i<MaxNum;i++)
        T[i]=i;

    return T;
}

Bucket InitBucket(int MaxNum)
{
    Bucket B=(Bucket)malloc(MaxNum*sizeof(struct BNode));
    int i;

    for (i=0;i<MaxNum;i++)
    {
        B[i].Head=B[i].Tail=NULL;
    }

    return B;
}

void FullMarkQuantBucketSort(Table T,UserList U,Bucket B,int N,int K)
{
    EleList Tmp,List;
    int i,j,FullMarkQuant;

    for (i=0;i<N;i++)
    {
        Tmp=(EleList)malloc(sizeof(struct EleNode));
        Tmp->Ele=T[i];
        FullMarkQuant=U[T[i]].FullMarkQuant;
        Tmp->Next=NULL;
        if (B[FullMarkQuant].Head==NULL)
            B[FullMarkQuant].Head=B[FullMarkQuant].Tail=Tmp;
        else
        {
            B[FullMarkQuant].Tail->Next=Tmp;
            B[FullMarkQuant].Tail=Tmp;
        }
    }

    for (i=K,j=0;i>=0;i--)
    {
        if (B[i].Head!=NULL)
        {
            List=B[i].Head;
            while (List && j<N)
            {
                Tmp=List->Next;
                T[j++]=List->Ele;
                free(List);
                List=Tmp;
            }
            B[i].Head=B[i].Tail=NULL;
        }
    }
}

int GetDigit(int Num,int D)
{
    int i;

    for (i=1;i<D;i++)
        Num/=RADIX;

    return (Num%RADIX);
}

void TotalMarkRadixSort(Table T,UserList U,Bucket B,int N)
{
    EleList Tmp,List;
    int i,D,Di;

    List=NULL;
    for (i=0;i<N;i++)
    {
        Tmp=(EleList)malloc(sizeof(struct EleNode));
        Tmp->Ele=T[i];
        Tmp->Next=List;
        List=Tmp;
    }

    for (D=1;D<=DIGITQ;D++)
    {
        while (List)
        {
            Di=GetDigit(U[List->Ele].TotalMarks,D);
            Tmp=List->Next;
            List->Next=NULL;
            if (B[Di].Head==NULL)
                B[Di].Head=B[Di].Tail=List;
            else
            {
                B[Di].Tail->Next=List;
                B[Di].Tail=List;
            }
            List=Tmp;
        }

        for (i=RADIX-1;i>=0;i--)
        {
            if (B[i].Head!=NULL)
            {
                B[i].Tail->Next=List;
                List=B[i].Head;
                B[i].Head=B[i].Tail=NULL;
            }
        }
    }

    for (i=N-1;i>=0;i--)
    {
        Tmp=List->Next;
        T[i]=List->Ele;
        free(List);
        List=Tmp;
    }
}

static void ShowDetailedMark(int UID,UserList U,int K)
{
    int i;

    for (i=0;i<K;i++)
    {
        if (U[UID].AllTopicsMarks[i]==NOSOLUTION)
            printf(" -");
        else
            printf(" %d",U[UID].AllTopicsMarks[i]);
    }
    putchar('\n');

}
void ShowRank(Table T,UserList U,int N,int K)
{
    int Rank=1,TotalMarks;
    int i;

    for (i=0;i<N && U[T[i]].TotalMarks==0;i++);

    if (i==N)
        return;
    TotalMarks=U[T[i]].TotalMarks;
    printf("%d %05d %d",Rank,T[i]+1,TotalMarks);
    ShowDetailedMark(T[i],U,K);

    for (i++;i<N;i++)
    {
        if (U[T[i]].TotalMarks==0)
            continue;
        if (U[T[i]].TotalMarks<TotalMarks)
        {
            Rank++;
            TotalMarks=U[T[i]].TotalMarks;
        }
        printf("%d %05d %d",Rank,T[i]+1,U[T[i]].TotalMarks);
        ShowDetailedMark(T[i],U,K);
    }
}
