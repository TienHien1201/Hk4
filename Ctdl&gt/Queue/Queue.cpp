#include <iostream>
#include<string>
using namespace std;
const int MaxQueue = 6;
int vitridau = 0;
int vitricuoi = 0;
int sophantutrongQue = 0;
void enqueque(int queque[], int x);
void dequeque(int queque[]);
void quequeRun(int queque[], char charInput);
int main()
{
    int queue[MaxQueue] = { 0 };
    quequeRun(queue, 'E');
    quequeRun(queue, 'A');
    quequeRun(queue, 'S');
    quequeRun(queue, '*');
    quequeRun(queue, 'Y');
    quequeRun(queue, 'Q');
    quequeRun(queue, '*');
    quequeRun(queue, '*');
    quequeRun(queue, '*');
    return 0;
}
void enqueque(int queque[], int x)
{
    if (sophantutrongQue >= MaxQueue)
        cout << "\nhang doi da day";
    else
    {
        if (vitricuoi == vitridau && vitricuoi == 0 && sophantutrongQue == 0)/*trường hợp đầu tiên trong Queue chưa
            có phần tử*/
        {
            queque[vitridau] = x;
            sophantutrongQue++;
        }
        else
        {
            vitricuoi++;
            if (vitricuoi > MaxQueue - 1)//khi viTriCuoi về cuối mảng và vẫn thêm đc
                vitricuoi = 0;
            queque[vitricuoi] = x;
            sophantutrongQue++;
        }
    }
}
void dequeque(int queque[])
{
    if (sophantutrongQue == 0)
        cout << "\nHang doi da het !";
    else
    {
        if (vitridau == vitricuoi && sophantutrongQue == 1)/*Khi trong Queue chỉ có 1 phần tử thì sau khi lấy phần
            tử duy nhất đó ra thì ta reset về 0*/
        {

            cout << "\n" << (char)queque[vitridau];
            vitridau = 0;
            vitricuoi = 0;
            sophantutrongQue = 0;
        }
        else
        {
            cout << "\n" << (char)queque[vitridau];//lấy ra trước =>> xác định lại đầu
            vitridau++;
            if (vitridau > MaxQueue - 1)
                vitridau = 0;
            sophantutrongQue--;
        }
    }
}
void quequeRun(int queque[], char charInput)
{
    if (charInput == 42)
        dequeque(queque);
    else
        enqueque(queque, charInput);
}