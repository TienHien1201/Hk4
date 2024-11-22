/*Bài 1: Xây dựng hàm nhập mảng phân số có n phần, với n nhập từ bàn phím, gắn ngẫu nhiên
các giá trị tử số, mẫu số từ 1 - 99, xuất ra màn hình những phân số có mẫu số chia hết cho tử số
*/
#if 0
#include <iostream>
#include<math.h>
using namespace std;

struct phanso {
    int tuso;
    int mauso;
};

void nhap(phanso a[], int n);
void xuat(phanso a[], int n);
int main() {
    phanso ps[100];
    int n;
    cout << "Ban muon nhap bao nhieu phan so ngau nhien: ";
    cin >> n;
    nhap(ps, n); 
    xuat(ps, n);
    

    
    
}

void nhap(phanso ps[], int n) {
    for (int i = 0; i < n; i++) {
        ps[i].tuso = rand() % 99 + 1;
        ps[i].mauso = rand() % 99 + 1;
    }
}

void xuat(phanso ps[], int n) {
    cout << "Cac phan so vua nhap:\n";
    for (int i = 0; i < n; i++) {
        if (ps[i].mauso %  ps[i].tuso == 0)
        {
cout << "Phan so thu " << i + 1 << ": " << ps[i].tuso << "/" << ps[i].mauso << "\n";
        }
        
    }
}

#endif

#if 0

#endif // 0

/*Bài 2 dựa trên mảng phân số đã nhập ngẫu nhiên ở câu 1, xây dựng hàm sắp xếp nhanh quicksort
cho mảng phân số*/
#include <iostream>
#include<math.h>
using namespace std;

struct phanso {
    int tuso;
    int mauso;
};

void nhap(phanso a[], int n);
void xuat(phanso a[], int n);
double GiaTriCuaPhanSo(phanso ps);
void  QuickSort(phanso ps[], int l, int r);
int main() {
    phanso ps[100];
    int n;
    cout << "Ban muon nhap bao nhieu phan so ngau nhien: ";
    cin >> n;
    nhap(ps, n);
    cout << "Cac phan so vua nhap:\n";
    xuat(ps, n);
    cout << "Cac phan so sau khi duoc sap xep:\n";
    QuickSort(ps, n - n, n - 1 );
    xuat(ps, n);

}

void nhap(phanso ps[], int n) {
    for (int i = 0; i < n; i++) {
        ps[i].tuso = rand() % 99 + 1;
        ps[i].mauso = rand() % 99 + 1;
    }
}

void xuat(phanso ps[], int n) {
   
    for (int i = 0; i < n; i++) {
        if (ps[i].mauso % ps[i].tuso == 0)
        {
            cout << "Phan so thu " << i + 1 << ": " << ps[i].tuso << "/" << ps[i].mauso << "\n";
        }

    }
}

void HoanVi(phanso &x, phanso &y ) {
    
    phanso tam = x;
    x = y;
    y = tam;


}

double GiaTriCuaPhanSo(phanso ps) {

    return (double)ps.tuso / ps.mauso;
}


void QuickSort(phanso ps[], int l, int r)
{
    int i = l;
    int j = r;
    phanso mid = ps[(l + r) / 2];
    while (i <= j)
    {
        while (GiaTriCuaPhanSo(ps[i]) < GiaTriCuaPhanSo(mid))
        {
            i++;
        }
        while (GiaTriCuaPhanSo(ps[j]) > GiaTriCuaPhanSo(mid))
        {
            j--;
        }
        if (i <= j)
        {
            HoanVi(ps[i], ps[j]);
            i++;
            j--;
        }
    }
    if (l < j)
    {
        QuickSort(ps, l, j);
    }
    if (i < r)
    {
        QuickSort(ps, i, r);
    }
}



/*Bài 3: từ mảng phần tử đã sắp xếp ở câu 2, xuất ra màn hình chỉ những phân số là 
có tử số và mẫu số đều là số nguyên tố*/
#if 0
#include <iostream>
#include<math.h>
using namespace std;

struct phanso {
    int tuso;
    int mauso;
};

void nhap(phanso a[], int n);
void xuat(phanso a[], int n);
bool checkIsPrimary(int x);
void checkPhanSoIsSoNguyenTo(phanso ps[], int n);
int main() {
    phanso ps[100];
    int n;
    cout << "Ban muon nhap bao nhieu phan so ngau nhien: ";
    cin >> n;
    nhap(ps, n);
    xuat(ps, n);
    cout << " Cac so phan so la so nguyen to :\n";
    checkPhanSoIsSoNguyenTo(ps, n);



}

void nhap(phanso ps[], int n) {
    for (int i = 0; i < n; i++) {
        ps[i].tuso = rand() % 99 + 1;
        ps[i].mauso = rand() % 99 + 1;
    }
}

void xuat(phanso ps[], int n) {
    cout << "Cac phan so vua nhap:\n";
    for (int i = 0; i < n; i++) {
            cout << "Phan so thu " << i + 1 << ": " << ps[i].tuso << "/" << ps[i].mauso << "\n";
    }
}

bool checkIsPrimary(int x) {
    if (x <= 1)
        return false;
    for (short i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;

    }
    return true;
}

void checkPhanSoIsSoNguyenTo(phanso ps[], int n) {
    for (short i = 0; i < n; i++)
    {
        if ( checkIsPrimary(ps[i].tuso) && checkIsPrimary(ps[i].mauso))
            cout << ps[i].tuso << "/" << ps[i].mauso << "\n";
    }


}
#endif