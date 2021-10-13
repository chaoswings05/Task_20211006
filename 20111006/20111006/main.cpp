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
    }

    void Set(int num, int value)
    {
        newArray[num] = value;
    }

    int Get(int num)
    {
        return newArray[num];
    }

    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;
    }
private:
    int* newArray = new int[0];
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