#include <stdio.h>

/*
�y���z
��قǂ�new��delete�Ŕz����m�ۂ��鏈�����A
�N���X�ɂ��ăf�X�g���N�^�Ŏ�����delete���Ă΂��悤�ɂ��Ă��������B
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
            printf("�z��O���Q�Ƃ��悤�Ƃ��Ă��܂��B\n");
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
            printf("�z��O���Q�Ƃ��悤�Ƃ��Ă��܂��B\n");
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

    // �z��O�Q�Ƃ��悤�Ƃ����ۂ��m�F
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}