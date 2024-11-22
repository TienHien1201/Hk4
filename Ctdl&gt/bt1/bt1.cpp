#include <iostream>
#include<math.h>
#include<cstdlib>
#include<iostream>

using namespace std;

//bt1
#if 0
int main()
{
    int a, b, c;
    cout << "Nhap vao 3 gia tri a, b va c: ";
    cin >> a >> b >> c;

    float delta, x1, x2, x;
    

    if (a == 0) {
        if(b == 0) {
        cout << "Phuong trinh co mot nghiem !";
        }
        if (c == 0) {
        cout << "Chuong trinh vo so nghiem !";
        }
        else
        {
            cout << "Phuong trinh vo nghiem !";
        }
    }
   else {
        delta = b * b - 4 * a * c;
        if(delta > 0) {
            x1 = (-b + sqrt(delta)) / 2 * a;
            x2 = (-b - sqrt(delta)) / 2 * a;
            cout << "Phuong trinh co hai nghiem phan biet la: " << x1 << " ;" << x2;
            
        }
        else if(delta == 0)
        {
            x = -b / (2* a);
            cout << "Phuong trinh co nghiem kep: " << x;
        }
        else
        {
            cout << "Phuong trinh vo nghiem !";
        }
        }
}
#endif

#if 0
int main() {
    int n = 1000000;
    int* a = new int[n]; // Cấp phát bộ nhớ động
    int sum = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        sum += a[i];
    
    }

    cout << "Trung binh: " << static_cast<double>(sum) / n;

	//--------------------------------
	int m = 0;
	int* b = new int[n];
	b[m] = a[0]; // phần tử đầu tiên của mảng a chính là phần tử phân biệt
	m++; // số lượng phần tử mảng b tăng lên 1 đơn vị

	// vòng lặp duyệt từng phần tử của mảng a
	for (int i = 1; i < n; i++)
	{
		// duyệt từng phần tử của mảng a, duyệt từ vị trí i - 1 đến 0
		// <=> duyệt từ vị trí i-1 về đầu mảng, để tìm xem a[i] trước đó có tồn tại hay chưa
		// nếu a[i] mà duyệt về trước đó mà chưa có tồn tại thì a[i] chính là phần tử phân biệt
		bool Kiem_Tra = true; // giả sử a[i] sẽ là phần tử phân biệt
		for (int j = i - 1; j >= 0; j--)
		{
			// nếu a[i] bằng a[j] <=> a[i] đã có tồn tại trước đó 
			if (a[i] == a[j])
			{
				Kiem_Tra = false; // cập nhật lại a[i] không phải là phần tử phân biệt
				break; // dừng việc kiểm tra
			}
		}
		if (Kiem_Tra == true)
		{
			b[m] = a[i]; // đưa phần tử phân biệt vào mảng b
			m++; // số lượng phần tử mảng b tăng lên 1 đơn vị
		}
	}

	// BƯỚC 2: ĐI TÌM SỐ LẦN XUẤT HIỆN CỦA TỪNG PHẦN TỬ PHÂN BIỆT TRONG MẢNG A
	// vòng lặp lấy từng phần tử của mảng b- mảng chứa phần tử phân biệt
	// để duyệt với toàn bộ mảng a <=> duyệt với vòng lặp for bên trong
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		// duyệt từng phần tử của mảng b với toàn bộ mảng a để tìm số lần xuất hiện
		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j])
			{
				dem++; // số lần xuất hiện của phần tử b[i] tăng lên 1 
			}
		}
		cout << "\nPhan tu " << b[i] << " xuat hien: " << dem << " lan";
	}
	//--------------------------------

	
    delete[] a; // Đừng quên giải phóng bộ nhớ đã cấp phát
	delete[] b;
    return 0;
}
#endif // 0


//Bt2
#if 1
int main() {
	int n = 1000;
	int* a = new int[n];
	int sum = 0;
	int dem = 0;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		sum += a[i];

	}

	cout << "Trung binh cua cac so random la: " << static_cast<double>(sum) / n;

	int m = 0;
	int* b = new int[n];
	b[m] = a[0]; 
	m++; 

	for (int i = 1; i < n; i++)
	{
		bool Kiem_Tra = true; 
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				Kiem_Tra = false;
				break;
			}
		}
		if (Kiem_Tra == true)
		{
			b[m] = a[i]; 
			m++;
		}
	}

	//Sắp xếp các phần tử random tu 0 đến 99 theo thứ tự từ bé đến lớn
	short tam = 0;
	for (short i = 0; i < m; i++)
	{
		for(short j = i + 1; j<m;j++) {
			if(b[i] > b[j]) {
				tam = b[i];
				b[i] = b[j];
				b[j] = tam;
			}
		}
	}


	cout << "\n\nXuat cac phan tu random phan biet sap xep theo thu tu tu be den lon: \n";
	for (short i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}


	cout << "\n\nDem so lan xuat hien cua cac phan tu random: ";
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j])
			{
				dem++;
			}
		}
		cout << "\nPhan tu " << b[i] << " xuat hien: " << dem << " lan";
	}


	
	cout << "\n\nDo thi bieu dien toa do so lan xuat hien cua cac so random: \n";
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j])
			{
				dem++;
				cout << " * ";
				
				
			}
			
		}
		cout << "\n";
	}

	delete[] a;
	delete[] b;
	return 0;
}
#endif // 0

#if 0
//Đếm số lần phần tử xuất hiện trong mảng
#define MAX 100

// hàm nhập mảng
void Nhap_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap gia tri a[" << i << "] = ";
		cin >> a[i];
	}
}

// hàm xuất mảng
void Xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

// hàm đi tìm phần tử phân biệt
void Tim_Phan_Tu_Phan_Biet(int a[], int b[], int n, int& m)
{
	m = 0;
	b[m] = a[0]; // phần tử đầu tiên của mảng a chính là phần tử phân biệt
	m++; // số lượng phần tử mảng b tăng lên 1 đơn vị

	// vòng lặp duyệt từng phần tử của mảng a
	for (int i = 1; i < n; i++)
	{
		// duyệt từng phần tử của mảng a, duyệt từ vị trí i - 1 đến 0
		// <=> duyệt từ vị trí i-1 về đầu mảng, để tìm xem a[i] trước đó có tồn tại hay chưa
		// nếu a[i] mà duyệt về trước đó mà chưa có tồn tại thì a[i] chính là phần tử phân biệt
		bool Kiem_Tra = true; // giả sử a[i] sẽ là phần tử phân biệt
		for (int j = i - 1; j >= 0; j--)
		{
			// nếu a[i] bằng a[j] <=> a[i] đã có tồn tại trước đó 
			if (a[i] == a[j])
			{
				Kiem_Tra = false; // cập nhật lại a[i] không phải là phần tử phân biệt
				break; // dừng việc kiểm tra
			}
		}
		if (Kiem_Tra == true)
		{
			b[m] = a[i]; // đưa phần tử phân biệt vào mảng b
			m++; // số lượng phần tử mảng b tăng lên 1 đơn vị
		}
	}
}

// hàm đếm số lần xuất hiện của từng phần tử phân biệt
void Xu_Li(int a[], int b[], int n, int& m)
{
	// BƯỚC 1: ĐI TÌM PHẦN TỬ PHÂN BIỆT
	Tim_Phan_Tu_Phan_Biet(a, b, n, m);

	// BƯỚC 2: ĐI TÌM SỐ LẦN XUẤT HIỆN CỦA TỪNG PHẦN TỬ PHÂN BIỆT TRONG MẢNG A
	// vòng lặp lấy từng phần tử của mảng b- mảng chứa phần tử phân biệt
	// để duyệt với toàn bộ mảng a <=> duyệt với vòng lặp for bên trong
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		// duyệt từng phần tử của mảng b với toàn bộ mảng a để tìm số lần xuất hiện
		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j])
			{
				dem++; // số lần xuất hiện của phần tử b[i] tăng lên 1 
			}
		}
		cout << "\nPhan tu " << b[i] << " xuat hien: " << dem << " lan";
	}
}

int main()
{
	int n; // số lượng phần tử mảng a
	int m;// số lượng phần tử mảng b
	int a[MAX];
	int b[MAX];// mảng b chính là mảng phụ chứa các phần tử phân biệt của mảng a

	cout << "\nNhap so luong phan tu mang: ";
	cin >> n;
	cout << "\n\tNHAP MANG A\n";
	Nhap_Mang(a, n);
	cout << "\n\tXUAT MANG A\n";
	Xuat_Mang(a, n);

	// gọi lại hàm xử lí - để đếm số lần xuất hiện của từng phần tử phân biệt

	Xu_Li(a, b, n, m);



	system("pause");
	return 0;
}

#endif // 0





