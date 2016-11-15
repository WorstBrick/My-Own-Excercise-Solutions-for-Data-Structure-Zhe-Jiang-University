static int BiSearch(int *List,int n,int x)
{
    int i,start=0,end=n-1;
    int mid;

    while (start-end!=0)
    {
        mid=(start+end)/2;
        if (List[mid]==x)
            return mid;
        else if (x<List[mid])
            end=mid;
        else
            start=mid;
    }
    return start;
}


voif insert(int *List,int n,int x)
{
    int position=BiSearch(List,n,x);
    List[position]=x;
}
