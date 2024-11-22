/*Cấp phát động cho n phần tử, xây dựng hàm
1. Nhập/Xuất mảng
2. Xây dựng hàm thêm số phần tử nhập từ bàn phím
3. xóa 1/2 phần tử trong mảng*/
#include <iostream>
using namespace std;
void inputArray(int* p, int n);
void outputArray(int* p, int n);
void themPhanTu(int*& p, int &n);
void deletePhantu(int*& p, int &n);
void deleteNuaDauPhantu(int*& p, int& n);
int main()
{
	int n;
	cout << "Nhap n so phan tu trong mang: ";
	cin >> n;
	int* p = new int[n];
	inputArray(p, n);
	cout << "\nCac phan tu trong mang sau khi nhap: \n";
	outputArray(p, n);
	themPhanTu(p, n);
	cout << "\nCac phan tu trong mang sau khi them: \n";
	outputArray(p, n);
	deletePhantu(p, n);
	outputArray(p, n);
	deleteNuaDauPhantu(p, n);
	//outputArray(p, n);
}

void inputArray(int *p, int n) {
	
	for (short i = 0; i <n; i++)
	{
		cout << "a[" << i << "] = " ;
			cin >> *(p + i);
	}
}

void outputArray(int *p, int n) {
	for (short i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << *(p+i);
		cout << "\n";
	}
}


void themPhanTu(int * &p, int &n) {
	int soPhanTuThem;
	cout << "\nSo phan tu can them ";
	cin >> soPhanTuThem;
	int kichThuocMoi;
	kichThuocMoi = soPhanTuThem + n;
	int* tam = new int[kichThuocMoi];
	for (short i = 0; i < n; i++)//Gán mảng cũ sang mãng tạm
		*(tam + i) = *(p + i);
	for (short i = n; i < kichThuocMoi; i++) {//Gán các giá trị mới vào mảng tạm
		cout << "a[" << i << "] = ";
		cin >> *(tam + i);
	}
	delete(p);
	p = tam;
	n = kichThuocMoi;

}

void deletePhantu(int * &p , int &n) {
	cout << "\nPhan tu sau khi xoa: \n";
	
	int kichThuocMoi = n/2;
	int* tam = new int[kichThuocMoi];
	for (short i = 0; i < kichThuocMoi; i++)//Gán mảng cũ sang mãng tạm
		*(tam + i) = *(p + i);
	delete(p);
	p = tam;
	n = kichThuocMoi;
}

void deleteNuaDauPhantu(int*& p, int& n) {
	cout << "\nNua dau phan tu sau khi xoa: \n";
	int kichThuocMoi = n/2;
	int* tam = new int[kichThuocMoi];
	for (short i = 0; i < kichThuocMoi; i++)//Gán mảng cũ sang mãng tạm
		*(tam + (kichThuocMoi - 1 - i)) = *(p + (n - 1 - i));
	delete(p);//Giải phóng vùng nhớ p cũ
	p = tam;//trỏ p về vùng nhớ mới => tức cập nhập lại mảng p là mảng tam vì mảng tam là mảng lưu các địa chỉ của phần tử sau khi xóa
	n = kichThuocMoi;//Cập nhật lại kích thước mới 
	for (short i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << *(p + i);
		cout << "\n";
	}
}