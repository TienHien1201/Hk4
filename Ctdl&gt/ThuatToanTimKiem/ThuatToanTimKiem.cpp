
#if 1
#include <iostream>
#include<cstdlib>
using namespace std;


void xuatMang(int a[]);
void TimKiemVetCan(int a[]);
void TimKiemLinhCanh(int a[]);
void TimKiemNhiPhan(int a[]);

int main()
{
	int a[100];
	
	//Thuật toán xuất các giá trị random không trùng nhau
	for(short i = 0; i < 5; i++) {
		a[i] = rand() % 5;
	for (short j = 0; j < i; j++) {

		if (a[i] == a[j]) {//Mõi lần phần tử lặp lại 
			j = -1; 
			a[i] = rand() % 5;

		}
	}
	}
	
	


int tam = 0;
	for (short i = 0; i < 5; i++) {
		for (short j = i + 1; j < 5; j++) {
			if (a[i] > a[j])
			{
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
	


	xuatMang(a);
	//TimKiemVetCan(a);
	TimKiemLinhCanh(a);
	//TimKiemNhiPhan(a);
	
}

void xuatMang(int a[]) {
	for (short i = 0; i < 5; i++)
		cout <<"a["<<i<<"] = " << a[i] << " "<<"\n";
}


void TimKiemVetCan(int a[]) {
		int x;
		cout << "\nNhap phan tu can tim: ";
		cin >> x;
		for (short i = 0; i < 100; i++)
		{
			if(a[i] == x) {
				cout << "Tim thay " << x << " tai vi tri " << i<<"\n";
			}
		}
	}

void TimKiemLinhCanh(int a[]) {
	int x;
	cout << "\nNhap phan tu can tim: ";
	cin >> x;

	bool check = false;
	a[5] = x;//Cho thằng cuối mảng để canh
	
	for ( short i = 0 ;  ;i++)
	{
		if(a[i] == x)
		if (i < 5) {

cout << "phan tu " << a[i] << " nam o vi tri " << i << "\n";
check = true;
			break;
		}
		else
		{
			break;
		}
		
	}
	if (check == false)
		cout << "\nKhong tim thay!";

}


void TimKiemNhiPhan(int a[]) {
	
	int x;
	cout << "\nNhap phan tu can tim: ";
	cin >> x;
	int mid = 0, left = 0, right = 0;
	left = 0;
	right = 99;
	bool check = false;
	while(left <= right) {
		
	mid = (left + right) / 2;
	
		if(a[mid] == x) {
			cout << "phan tu " << a[mid] << " nam o vi tri " << mid << "\n";
			check = true;
		break;
		}
		else if(a[mid] < x)
		{
			left = mid + 1;
		}
		else if(a[mid] > x)
		{
			right = mid - 1;
			
		}
	}
	if(check == false)
		{
			cout << "Khong tim thay !";
		}
}

#endif // 0


//####################300 bài code thiếu nhi để luyện thuật toán###############################################

#if 0
//Bài 1: Cho một mảng các số nguyên nums và một số nguyên target, trả về chỉ số của hai số sao cho tổng của chúng bằng target .
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[10];

	for (short i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	int target;
	cin >> target;

	for (short i = 0; i < n - 1; i++) {
		for (short j = i + 1; j < n; j++) {
			if (a[i] + a[j] == target) {
				cout << a[i] << " , " << a[j];
			}
		}
	}
}
#endif // 0

