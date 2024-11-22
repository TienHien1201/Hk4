#include <iostream>
using namespace std;

long pN(int x, int n);
long giaiThuaN(int n);
long timUocChungLonNhat(int a,int b);
float Sn(int n);
long SXn(int x, int n);
long SumN(int a[], int n);


int main()
{
	int x, n;
	int	a[] = {1,2,3,4,5 };
	x = 3;
	n = 5;
	//cout << "Gia tri cua pN = " << pN(x, n);
	//cout << giaiThuaN(n);
	//cout << timUocChungLonNhat(x, n);
	//cout << Sn(3);
	//cout << SXn(3, 3);
	cout << SumN(a,n - 1);//Vì mảng khai bao có độ dài là 5 tức là từ 0 đến 4 nên n -1 là vị trí tối đa tức là phần tử cuối cùng của mảng

}


//Bài 1: Tính p(n) = x^n, n nguyên và n >= 1. bài tìm x mũ n

long pN(int x, int n) {

	if (n == 1)
		return x;
	else
		return pN(x, n - 1) * x;
	
}

//Bài 2: tính n! (n nguyên và n >= 0)
long giaiThuaN(int n) {

	if (n == 1)
		return 1;
	else
		return giaiThuaN( n - 1)*n ;
}

//Bài 3: Tìm Ước số chung lớn nhất bằng đệ quy

long timUocChungLonNhat(int a, int b) {
	if (a == b)
		return a;
	else if (a > b)
		return timUocChungLonNhat(a - b, b);
	else
		return timUocChungLonNhat(a, b - a);
}

//Bài 4: Tính S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
float Sn(int n) {

	if (n == 1)
		return (float)1/2;
	else
		return Sn(n - 1) + (float)n / (n + 1);
}

//Bài 5: Tính S(x,n) = x^1 + x^2 + x^3 + ... x^n. 
long SXn(int x, int n) {
	if (n == 1)
		return x;
	else
		return SXn(x, n - 1) + pN(x,n);//pN(x,n) là hàm tính x^n

}

//Bài 6: Tính tổng n phần tử trong mảng số nguyên
long SumN(int a[], int n) {
	if (n == 0)
		return a[0];
	else 
		return SumN(a,n - 1) + a[n];
	
}

//Bài 7: Giải bài toán tháp Hà Nội