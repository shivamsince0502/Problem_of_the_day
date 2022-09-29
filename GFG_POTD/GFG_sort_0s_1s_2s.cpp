class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int z = 0, o = 0, t = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0) z++;
            else if(a[i] == 1) o++;
            else t++;
        }
        int i = 0;
        while(i < z)a[i++] = 0;
        while(i < z+o)a[i++] = 1;
        while(i < z+o+t)a[i++] = 2;
    }
    
};
