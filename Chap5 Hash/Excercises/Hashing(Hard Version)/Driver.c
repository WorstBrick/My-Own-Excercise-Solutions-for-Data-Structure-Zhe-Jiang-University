#include "Interface.h"

int main(void)
{
    int TableSize;
    scanf("%d",&TableSize);
    int UnShiftLimit=0,ShiftLimit=TableSize-1;
    ElementType Buffer[TableSize];

    BuildWorkSpace(Buffer,TableSize,&UnShiftLimit,&ShiftLimit);
    ReversedHash(Buffer,TableSize,UnShiftLimit,ShiftLimit);
    free(Buffer);

    return 0;
}
