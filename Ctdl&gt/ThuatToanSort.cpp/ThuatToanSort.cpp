#include <iostream>
#include<math.h>
using namespace std;

/*Nhập mảng n phần tử, gán giá trị ngẫu nhiên 0 đến n - 1 không lặp lại xây dựng các hàm sắp xếp: 
1. InterChangestion sort Sắp xếp cơ bản
2. Selection soft Sắp xếp chọn
3. bubble sort Sắp xếp nỗi bọt
4. Intertion Sort Sắp xếp chèn
5.Megre Sort: Sắp xếp trộn
6.Quick Sort
7.Radix Sort: Sắp xếp theo hàng đơn vị , hàng chục, hàng trăm , hàng ngàn, ........
8.Hea Sort: Sắp xếp cây nhị phân bằng mảng 1 chiều*/
 
void Random(int a[],int n);
void Xuat_Mang(int a[], int n);
void Hoan_Vi(int& a, int& b);
void InterChanges_sort(int a[], int n);
void Selection_soft(int a[], int n);
void Bubble_sort(int a[], int n);
void  Intertion_Sort(int a[], int n);
void MergeSort(int a[], int left, int right);
void Merge(int a[], int left, int mid, int right);
void QuickSort(int a[], int left, int right);
void Hoan_Vi(int &a, int &b) {
	int tam = a;
	a = b;
	b = tam;
}

/******************************************************************************
InterChanges Sort: Sắp xếp đổi vị trí
Seleect Sort: Sắp xếp chọn
BubBle Sort: Sắp xếp nỗi bọt
Intertion sort: Sắp xếp chèn
*******************************************************************************/
#if 0


int main()
{
	int a[10];
	int n;
	cout << "Nhap n so phan tu random: ";
	cin >> n;

	//Random(a,n);	
	for (short i = 0; i < n; i++)
	{
		cout  << "a[ " << i << " ] =";
		cin >> a[i];
	}
	//InterChanges_sort(a, n);
	//Selection_soft(a, n);
	//Bubble_sort(a, n);
	//Insertion_Sort(a, n);
	MergeSort(a, 0, n - 1);

	Xuat_Mang(a, n);

}



void Random(int a[], int n) {
	//Thuật toán xuất các giá trị random không trùng nhau
	for (short i = 0; i < n; i++) {
		a[i] = rand() % n;
		for (short j = 0; j < i; j++) {
			if (a[i] == a[j]) {//Mõi lần phần tử lặp lại 
				a[i] = rand() % n;
				j = -1;/*Mõi lần có số bị trùng ta cần phải set cho j về lại giá trị là 0 bằng cách cho j = -1 vì sau vòng lặp thì j nó tăng lên 1
				đơn vị */

			}
		}
	}
}

void Xuat_Mang(int a[], int n) {
	for (short i = 0; i < n; i++)
	{
		cout << "a[ " << i << "] = "<<a[i] <<"\n";
	}
}


void InterChanges_sort(int a[], int n) {
	
			for (short i = 0; i < n - 1; i++)
				for (short j = i + 1; j < n; j++)
					if (a[i] > a[j])
						Hoan_Vi(a[i], a[j]);
	
}

void Selection_soft(int a[], int n) {
	for (short i = 0; i < n - 1; i++){
		int min = i;
		for (short j = i + 1; j < n ; j++){
			if (a[min] > a[j])
			{
				min = j;

				
			}
		}
		Hoan_Vi(a[i],a[min]);
	}
}

//Cách 1: Dùng đk j < n - i - 1
void Bubble_sort(int a[], int n) {
	for (short i = 0; i < n; i++)
		for (short j = 0; j < n - i - 1; j++)/*Đối với sắp xếp tăng dần thì j < n - i - 1 mõi lần so sánh thì phần từ lớn nhất sẽ đc đưa về cuối mảng 
			nên lần so sánh tiếp theo ta không cần phải so sánh thằng đầu mảng với thằng vừa đc đưa về cuối mảng nữa cứ như vậy thằng lớn nhì sẽ 
			đc đưa về gần cuối mảng và phần tử đầu mảng không cần so sánh với thằng lớn nhất và lớn nhì mảng và mõi lần có phần tử lớn nhất nhì... thì
			lần lượt sẽ đc đưa về cuối ,gần cuối mảng, gần gần cuối mảng.... nên ta sẽ có đk dừng j < n - i - 1*/
			if (a[j] > a[j + 1])
				Hoan_Vi(a[j], a[j + 1]);
}
//Cách 2:
#if 0
void Bubble_sort(int a[], int n) {
	for (short i = n - 1; i > 0; i--)
		for (short j = 0; j < n; j++)
			if (a[j] > a[j + 1])
				Hoan_Vi(a[j], a[j + 1]);
}
#endif // 0



//Cách 1: 
#if 0
void  Insertion_Sort(int a[], int n) {
	for (short i = 1; i < n ; i++)
	{
		int vt = i - 1, x = a[i];
		while(vt >= 0 && a[vt] > x) {
			a[vt + 1] = a[vt];

			--vt;
		}
		a[vt + 1] = x;
	}

}
#endif // 0
//Cách 2: Cách thầy chỉ
void  Insertion_Sort(int a[], int n) {
	for (short i = 1; i < n ; i++)
	{
		int tam = a[i];
		short j;
		for (j = i - 1; j >= 0; j--){
			if (a[j] > tam)
				a[j + 1] = a[j];
			else
				break;
        }
		a[j + 1] = tam;
			
				
	}

}

#endif

/******************************************************************************
merge sort
*******************************************************************************/
#if 1
int main()
{
	//int a[] = { 8,7,5,12,3,9,6,17 };
	int a[] = { 9,1,8,2 };
	int n = 4;
	MergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)//xuất mảng
		cout << "\na[" << i << "]=" << a[i];
	return 0;
}

void MergeSort(int a[], int left, int right) {
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
#endif
void Merge(int a[], int left, int mid, int right) {
	int n = right - left + 1;//số phần tử cần trộn lại
	int* tam = new int[n];
	int i = left;//duyệt mảng bên trái
	int j = mid + 1;//duyệt mảng bên phải
	int dem = 0;//vị trí phần tử ở mảng tạm cần trộn/chèn vào
	while (dem <= n)
	{
		if (i > mid)//chèn hết bên trái, tức đây các ptu đã đc sắp xếp 
		{
			tam[dem] = a[j];//Các phần tử ở mảng con bên phải đc sắp xếp và đưa vào mảng tam
			j++;
			dem++;
		}
		else if (j > right)//chèn hết bên phải, tức đây các ptu đã đc sắp xếp 
		{
			tam[dem] = a[i];//Các phần tử ở mảng con bên trái đc sắp xếp và đưa vào mảng tam
			i++;
			dem++;
		}
		else//Ngược lại nếu ở trên sắp xếp mà còn có ptu chưa đc sắp xếp
		{
			if (a[i] < a[j])/*Mảng con bên trái còn phần tử chưa đc sắp xếp thì đk này đc thực thi để sắp xếp hết các phần tử chưa 
				đc sắp xếp ở mảng con bên trái*/
			{
				tam[dem] = a[i];
				i++;
				dem++;
			}
			if (a[j] < a[i])/*Mảng con bên phải còn phần tử chưa đc sắp xếp thì đk này đc thực thi để sắp xếp hết các phần tử chưa 
				đc sắp xếp ở mảng con bên phải*/
			{
				tam[dem] = a[j];
				j++;
				dem++;
			}
		}
	}//kết thúc trộn/chèn
	for (int i = 0; i < n; i++)
		a[left + i] = tam[i];
}
//#endif



/******************************************************************************
QuickSort
*******************************************************************************/
#if 0
int main()
{
	int a[] = {15,2,8,7,3,9,6,17 };
	int n = 8;
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)//xuất mảng
		cout << "\na[" << i << "]=" << a[i];
}

/*Tư tưởng thuật toán QuickSort là: 
* 
*/
void QuickSort(int a[], int left, int right) {
	int mid = (left + right) / 2;
	int i = left;//Duyệt từ trái và i++
	int j = right;//Duyệt từ phải và j--
	while(i< j)//Diều kiện duyệt i và j
	{

		while (a[i] < a[mid])
			i++;
		while (a[j] > a[mid])
			j--;
		if (i<= j)
		{
			Hoan_Vi(a[i],a[ j]);
			i++;
			j--;
		}

	}//Kết thúc đưa các phần tử về đúng vị trí
	if (i < right)//Kiểm tra sắp xếp mảng bên phải 
	{
		QuickSort(a, i, right);
	}
	else if( j > left)//Kiểm tra sắp xếp mảng bên trái
	{
		QuickSort(a, j, left);
	}
}
#endif

/******************************************************************************
radix: 
Sắp xếp theo hàng đơn vị chục trăm ngàn..... Đây là sắp xếp nhanh nhất
*******************************************************************************/
void radix(int a[], int n, int soBac);
void RadixSort(int a[], int n);
#if 0
int main()
{
	int a[] = { 213,33,2,22,224,111,4,32,44 };
	int n = 9;

	RadixSort(a, n);
	for (int i = 0; i < n; i++)//xuất mảng
		cout << "\na[" << i << "]=" << a[i];
}


void radix(int a[], int n, int soBac) {
	int * tam = new int[n];
	int soLanXuatHienCacSo[10] = { 0 };
	int soLanDaChen[10] = { 0 };
	int donvi, vitri;
	for (int i = 0; i < n; i++)//Đếm tổng số lần xuất hiện các số
	{
		int temp1 = pow(10, soBac);
		int temp2 = pow(10, soBac - 1);
		donvi = a[i] % temp1 / temp2;
		soLanXuatHienCacSo[donvi]++;
	}
	for (int i = 0; i < n; i++)//Chèn số a[i] vào vị trí thích hợp trong mảng tam
	{
		int temp1 = pow(10, soBac);
		int temp2 = pow(10, soBac - 1);
		donvi = a[i] % temp1 / temp2 ;
		int dem = 0;
		for (int j = 0; j < donvi; j++)
		{
			dem = dem + soLanXuatHienCacSo[j];
		}
			vitri = dem + soLanDaChen[donvi];
			tam[vitri] = a[i];
			soLanDaChen[donvi]++;
	}//Chèn xong
	for (int i = 0; i < n; i++)//Gán lại mảng a
			a[i] = tam[i];
}

void RadixSort(int a[], int n) {
	int SoBac = 0;
	int max = a[0];
for (short i = 0; i < n; i++) 
	if (a[i] > max)
		max = a[0];
while(max > 0) {
	max /= 10;
	++SoBac;
}
for (short i = 1; i <= SoBac; i++)
{
	radix(a, n, i);
}
}
#endif

/******************************************************************************
Heap Sort: Sắp xếp theo cây nhị phân của mảng 1 chiều
*******************************************************************************/
#if 0
void heapModify(int a[], int i)
{
	for (int j = i / 2 - 1; j >= 0; j--)
	{
		int root = j;
		int left = 2 * j + 1;
		int right = 2 * j + 2;

		if (left < i && a[root] < a[left])
			root = left;
		if (right < i && a[root] < a[right])
			root = right;

		if (root != j)
			swap(a[root], a[j]);
	}
}

void heap_sort(int a[], int n)
{
	for (int i = n; i > 1; i--)
	{
		heapModify(a, i);
		swap(a[i - 1], a[0]);
	}
}
#endif // 0

