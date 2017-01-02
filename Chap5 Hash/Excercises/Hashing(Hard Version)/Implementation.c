#include "Interface.h"

bool Switch=true;
Position Hash(Key Data,int TableSize)
{
    return (Data%TableSize);
}

int comp(const void*a,const void*b)
{
    return (*(ElementType *)a)->Data-(*(ElementType *)b)->Data;
}

void BuildWorkSpace(ElementType Buffer[],int TableSize,int * UnShiftLimit,int * ShiftLimit)
{
    Position Current;
    Key Data;
    ElementType Tmp;

    for (Current=0;Current<TableSize;Current++)
    {
        scanf("%d",&Data);
        if (Data!=-1)
        {
            Tmp=(ElementType)malloc(sizeof(struct KNode));
            Tmp->Data=Data;
            Tmp->CurrentSite=Current;
            Tmp->PrimarySite=Hash(Data,TableSize);
            if (Current==Tmp->PrimarySite)
            {
                Tmp->D=0;
                Buffer[(*UnShiftLimit)]=Tmp;
                (*UnShiftLimit)++;
                continue;
            }
            else if (Current<Tmp->PrimarySite)
                Tmp->D=TableSize-Tmp->PrimarySite+Current;
            else
                Tmp->D=Current-Tmp->PrimarySite;
            Buffer[(*ShiftLimit)]=Tmp;
            (*ShiftLimit)--;
        }
    }

    qsort(Buffer,(*UnShiftLimit),sizeof(ElementType),comp);
}

void UpDateD(ElementType Buffer[],Position InfluencePoint,Position j,int ShiftLimit)
{
    for (;j>ShiftLimit;j--)
    {
        if (Buffer[j]->PrimarySite<Buffer[j]->CurrentSite)
        {
            if (InfluencePoint>=Buffer[j]->PrimarySite && InfluencePoint<Buffer[j]->CurrentSite)
                (Buffer[j]->D)--;
        }
        else
        {
            if (InfluencePoint<Buffer[j]->CurrentSite || InfluencePoint>=Buffer[j]->PrimarySite)
                (Buffer[j]->D)--;
        }
    }
}

static void ShowKey(Key Data)
{
    if (Switch)
    {
        printf("%d",Data);
        Switch=false;
    }
    else
        printf(" %d",Data);
}
void ReversedHash(ElementType Buffer[],int TableSize,int UnShiftLimit,int ShiftLimit)
{
    Position i=0,j=TableSize-1;

    while(i<UnShiftLimit && j>ShiftLimit)
    {
        if (Buffer[i]->Data>Buffer[j]->Data && Buffer[j]->D==0)
        {
            ShowKey(Buffer[j]->Data);
            UpDateD(Buffer,Buffer[j]->CurrentSite,j-1,ShiftLimit);
            //free(Buffer[j]);
            j--;
        }
        else
        {
            ShowKey(Buffer[i]->Data);
            UpDateD(Buffer,Buffer[i]->CurrentSite,j,ShiftLimit);
            //free(Buffer[i]);
            i++;
        }
    }

    while (i<UnShiftLimit)
    {
        ShowKey(Buffer[i]->Data);
        //free(Buffer[i]);
        i++;
    }

    while (j>ShiftLimit)
    {
        ShowKey(Buffer[j]->Data);
        //free(Buffer[j]);
        j--;
    }
}
