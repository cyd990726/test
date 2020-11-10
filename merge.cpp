#include<iostream>
#include<fstream>
#include<vector>
typedef int elem;
//最low的冒泡排序
void bubble_sort(std::vector<elem>&arr,int p,int r)
{
    for(int j=r;j>p;j--)
    {
        for(int i=p;i<j;i++)
        {
            if(arr[i]>arr[i+1])
            {
                elem temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}
//完美版本的归并排序

void merge(std::vector<elem>&arr,int p,int q,int r)
{
    const int lengthA=q-p+1;
    const int lengthB=r-q;
    elem A[lengthA],B[lengthB];
    for(int i=0;i<lengthA;i++)
    {
        A[i]=arr[p+i];
    }
    for(int j=0;j<lengthB;j++)
    {
        B[j]=arr[q+j+1];
    }
    int i=0,j=0,t=0;
    while(i<lengthA&&j<lengthB)
    {
        if(A[i]<B[j])
        {
            arr[t+p]=A[i];
            i++;
        }
        else
        {
            arr[t+p]=B[j];
            j++;
        }
        t++;
    }
    while(j<lengthB)
    {
        arr[t+p]=B[j];
        j++;
        t++;
    }
    while(i<lengthA)
    {
        arr[t+p]=A[i];
        i++;
        t++;
    }
    
}
void merge_sort(std::vector<elem>&arr,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }

}
//插入排序
void insert(std::vector<elem>&A,const int &p,const int &r)
{
    for(int i=p+1;i<=r;i++)
    {
        auto key=A[i];
        int j=i;
        while(A[j-1]>key&&j>p)
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=key;
    }
}
//最强大的快速排序
int search_medium(std::vector<elem>&arr,const int&p,const int&r)
{
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            elem temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    elem temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1;
}
void quick_sort(std::vector<elem>&arr,const int&p,const int&r)
{
    if(p<r)
    {
        int q=search_medium(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}
void out_rand(int n)
{
    std::ofstream fout("data.txt");
    srand(0);
    for(int i=0;i<n;i++)
    {
        fout<<rand()<<std::endl;
    }
    fout.close();
}
int main()
{
    int n;
    std::cout<<"please enter the number of data:";
    std::cin>>n;
    out_rand(n);
    std::fstream fin("data.txt");
    std::vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        elem temp;
        fin>>temp;
        arr[i]=temp;
    }
    fin.close();
    bubble_sort(arr,0,n-1);
    //merge_sort(arr,0,n-1);
    //insert(arr,0,n-1);
    //quick_sort(arr,0,n-1);
    for(auto i:arr)
    {
        std::cout<<i<<"\t";
    }
    return 0;
}