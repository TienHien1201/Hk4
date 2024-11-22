//Bài 1
#if 0

#include <iostream>
using namespace std;

struct phanso
{
    int tuso;
    int mauso;
};
void nhapPhanSo(phanso ps[], int n);
void XuatPhanSo(phanso ps[], int n);
int main()
{
    phanso ps[200];
    int n;
    cout << "Nhap n phan so: ";
    cin >> n;
    nhapPhanSo(ps, n);
    cout << "Cac phan so vua nhap: \n";
    XuatPhanSo(ps, n);

}

void nhapPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        ps[i].tuso = (rand() % 199) - 99; /* Vì từ - 99 đến 99 là 198 số thì nó sẽ rand ra rố từ 0 đến 198 thì muốn phạm vi từ - 99 đến 99 ta chỉ cần
        lấy giá trị vừa đc random ra trừ cho 99 là ra đc số từ -99 đến 99 vd: random ra số 1 ta lấy 1 - 99 = -98 , vd random ra số 198 ta trừ đi
        99 = 99 */
        ps[i].mauso = (rand() % 199) - 99; // Random từ -99 đến 99

        /* Kiểm tra và chỉnh lại giá trị nếu mẫu số bằng 0 khi mẫu mà bằng 0 thì ta dùng vòng lặp while để xét và cho random ra số mới phải khác
        0*/
        while (ps[i].mauso == 0) {

            ps[i].mauso = (rand() % 199) - 99; // Random lại mẫu số
        }
    }
}


void XuatPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        cout << ps[i].tuso << "/" << ps[i].mauso << "\n";

    }
}
#endif // 0

//Bài 2
#if 0
#include <iostream>
using namespace std;

struct phanso
{
    int tuso;
    int mauso;
};
void nhapPhanSo(phanso ps[], int n);
void XuatPhanSo(phanso ps[], int n);
void Merge(phanso a[], int left, int mid, int right);
void MergeSort(phanso ps[], int left, int right);
double giatriPhanSo(phanso ps);
int main()
{
    phanso ps[200];
    int n;
    cout << "Nhap n phan so: ";
    cin >> n;
    nhapPhanSo(ps, n);
    cout << "Cac phan so vua nhap: \n";
    XuatPhanSo(ps, n);
    MergeSort(ps, n - n, n - 1);
    cout << "Cac phan so vua sap xep: \n";
    XuatPhanSo(ps, n);

}

void nhapPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        ps[i].tuso = (rand() % 199) - 99; 
        ps[i].mauso = (rand() % 199) - 99; 
        while (ps[i].mauso == 0) {

            ps[i].mauso = (rand() % 199) - 99;
        }
    }
}


void XuatPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        cout << ps[i].tuso << "/" << ps[i].mauso << "\n";

    }
}

double giatriPhanSo(phanso ps) {

    return (double)ps.tuso / ps.mauso;
}


void Merge(phanso a[], int left, int mid, int right) {
    int n = right - left + 1;
    phanso* tam = new phanso[n];


    int i = left;
    int j = mid + 1;
    int dem = 0;

    while (i <= mid && j <= right) {
        if (giatriPhanSo(a[i]) <= giatriPhanSo(a[j])) {
            tam[dem] = a[i];
            i++;
        }
        else {/*Ngược lại*/
            tam[dem] = a[j];
            j++;
        }
        dem++;
    }

    while (i <= mid) {
        tam[dem] = a[i];
        i++;
        dem++;
    }

    while (j <= right) {
        tam[dem] = a[j];
        j++;
        dem++;
    }

    for (int k = 0; k < n; k++) {
        a[left + k] = tam[k];
    }

    delete[] tam;
}

void MergeSort(phanso ps[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(ps, left, mid);
        MergeSort(ps, mid + 1, right);
        Merge(ps, left, mid, right);
    }
}

#endif

//Bài 3
#if 1
#include <iostream>
using namespace std;

struct phanso
{
    int tuso;
    int mauso;
};
void nhapPhanSo(phanso ps[], int n);
void XuatPhanSo(phanso ps[], int n);
void Merge(phanso a[], int left, int mid, int right);
void MergeSort(phanso ps[], int left, int right);
double giatriPhanSo(phanso ps);
bool isFibonacci(int x);
void Fibonacci(phanso a[], int n);
int main()
{
    phanso ps[1000];
    int n;
    cout << "Nhap n phan so: ";
    cin >> n;
    nhapPhanSo(ps, n);
    cout << "Cac phan so vua nhap: \n";
    XuatPhanSo(ps, n);
    MergeSort(ps, n - n, n - 1);
    cout << "Cac phan so vua sap xep: \n";
    XuatPhanSo(ps, n);
    cout << "Cac phan so la so finaboci: \n";
    Fibonacci(ps, n);


}

void nhapPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        ps[i].tuso = (rand() % 199) - 99; 
        ps[i].mauso = (rand() % 199) - 99; 

        while (ps[i].mauso == 0) {

            ps[i].mauso = (rand() % 199) - 99; 
        }
    }
}


void XuatPhanSo(phanso ps[], int n) {
    for (short i = 0; i < n; i++) {
        cout << ps[i].tuso << "/" << ps[i].mauso << "\n";

    }
}

double giatriPhanSo(phanso ps) {

    return (double)ps.tuso / ps.mauso;
}


void Merge(phanso a[], int left, int mid, int right) {
    int n = right - left + 1;
    phanso* tam = new phanso[n];
    int i = left;
    int j = mid + 1;
    int dem = 0;

    while (i <= mid && j <= right) {
        if (giatriPhanSo(a[i]) <= giatriPhanSo(a[j])) {
            tam[dem] = a[i];
            i++;
        }
        else {
            tam[dem] = a[j];
            j++;
        }
        dem++;
    }

    while (i <= mid) {
        tam[dem] = a[i];
        i++;
        dem++;
    }

    while (j <= right) {
        tam[dem] = a[j];
        j++;
        dem++;
    }

    for (int k = 0; k < n; k++) {
        a[left + k] = tam[k];
    }

    delete[] tam;
}

void MergeSort(phanso ps[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(ps, left, mid);
        MergeSort(ps, mid + 1, right);
        Merge(ps, left, mid, right);
    }
}

bool isFibonacci(int x) { 
    int a = 0, b = 1;

    while (b < x) {  


        int temp = b;
        b = a + b;
        a = temp;

    }
    return (b == x);

}
void Fibonacci(phanso ps[], int n) {
    for (int i = 0; i < n; i++) {
        if (isFibonacci(ps[i].tuso) && isFibonacci(ps[i].mauso)) {
            cout << ps[i].tuso << "/" << ps[i].mauso << endl;
        }
    }
}
#endif
