#include <stdio.h>

/*
【問題】
先ほどのnewとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください。
*/

class Array
{
public:
    Array() {}

    void Create(int num)
    {
        newArray = new int[num];
        Size = num;
    }

    void Set(int num, int value)
    {
        if (num >= 0 && num < Size)
        {
            newArray[num] = value;
        }
        else
        {
            printf("配列外を参照しようとしています。\n");
        }
    }

    int Get(int num)
    {
        if (num >= 0 && num < Size)
        {
            return newArray[num];
        }
        else
        {
            printf("配列外を参照しようとしています。\n");
        }
    }

    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;
    }

private:
    int* newArray = nullptr;
    int Size;
};

int main()
{
    Array array;

    array.Create(1000);


    for (int i = 0; i < 1000; ++i)
    {
        array.Set(i, i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        printf("num = %d\n", array.Get(i));
    }

    // 配列外参照しようとした際を確認
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}