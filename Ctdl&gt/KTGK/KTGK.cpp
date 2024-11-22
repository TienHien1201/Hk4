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
    for(short i = 0; i < n ; i++) {
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

double giatriPhanSo(phanso ps) {

    return (double)ps.tuso / ps.mauso;
}


void Merge(phanso a[], int left, int mid, int right) {
    int n = right - left + 1;//n là số lượng phần tử trong mảng con cần merge(trộn).
    phanso* tam = new phanso[n];//Khởi tạo một mảng tạm thời có kích thước bằng số lượng phần tử cần merge(trộn)
    
    //Khởi tạo hai chỉ số i và j để duyệt qua hai mảng con được chia từ mảng ban đầu.
    int i = left;
    int j = mid + 1;
    int dem = 0;//Khởi tạo biến đếm để lưu vị trí cần gán phần tử trong mảng tạm thời.

    while (i <= mid && j <= right) {//Bắt đầu vòng lặp để so sánh và gán các phần tử từ hai mảng con vào mảng tạm thời.
        if (giatriPhanSo(a[i]) <= giatriPhanSo(a[j])) {/*Nếu giá trị phân số tại vị trí i trong mảng con bên trái nhỏ hơn hoặc bằng giá trị phân
            số tại vị trí j trong mảng con bên phải.*/
            tam[dem] = a[i];//, thì gán phân số tại vị trí i vào mảng tạm thời 
            i++;//và tăng chỉ số i lên để xét tiếp
        }
        else {/*Ngược lại*/
            tam[dem] = a[j];//, gán phân số tại vị trí j vào mảng tạm thời 
            j++;//và tăng chỉ số j để xét tiếp
        }
        dem++;//Tăng biến đếm dem sau mỗi lần gán.
    }

    while (i <= mid) {//Copy các phần tử còn lại từ mảng con bên trái
        tam[dem] = a[i];
        i++;
        dem++;
    }

    while (j <= right) {// Coppy các phần tử từ mảng con bên phải vào mảng tạm thời.
        tam[dem] = a[j];
        j++;
        dem++;
    }

    for (int k = 0; k < n; k++) {//Copy các phần tử từ mảng tạm thời vào mảng ban đầu, bắt đầu từ vị trí left
        a[left + k] = tam[k];
    }

    delete[] tam;//delete[] tam; Giải phóng bộ nhớ của mảng tạm thời
}

void MergeSort(phanso ps[], int left, int right) {
    if (left < right) {//Kiểm tra nếu chỉ số bên trái nhỏ hơn chỉ số bên phải, tức là mảng con có nhiều hơn một phần tử.
        int mid = (left + right) / 2;//Cho mid là vị trị ở giữa của mảng để chia thành hai mảng con
        MergeSort(ps, left, mid);//Gọi đệ quy hàm MergeSort cho mảng con bên trái của mảng
        MergeSort(ps, mid + 1, right);//Gọi đệ quy hàm MergeSort cho  mảng con bên phải của mảng
        Merge(ps, left, mid, right);//Sau khi hai mảng con đã được sắp xếp, gọi hàm Merge để trộn hai mảng con lại với nhau, thành một mảng con
        //sắp xếp hoàn chỉnh
    }
}

#endif

//Bài 3
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

bool isFibonacci(int x) { /*số Fibonacci là một chuỗi các số trong đó mỗi số là tổng của hai số liền trước nó trong chuỗi 
vd: 0, 1, 1, 2, 3, 5, 8, 13, 21*/ 
    int a = 0, b = 1;/*a là số đầu tiên trong dãy fibonaci, b là số liền kề của a */
  
    while (b < x) {   /*đầu tiên ta khởi tạo a vs b là hai số đầu tiên trong số fibonaci, sau đó dùng while (b < x) xét xem b(b là số đầu tiên trong 
        dãy số fibonaci) có < hơn số mà ta muốn xét(số mà ta muốn xét là x) không đúng thì*/
        
       
        int temp = b; /*thì ta khởi tạo 1 biến tam để lưu giá trị của số kế số đầu tiên trong dãy số của số mà ta đang muốn xét là số fibonaci*/
        b = a + b;/*Sau đó cộng 2 số liền kề trong dãy của số fibonaci lại lưu vào b của lần đầu xét x có phải là số fibonaci không => lúc này
        b đã là số tổng của hai số liền kề trong chuỗi các số của số Fibonaci*/
        a = temp;/*Gán a = lại số liền kề của số vừa đc cộng tổng 2 số liền trước trước lại 
        - vd: ta có số 3 là số fibonaci 
        1) đầu tiên trong dãy 
        fibonaci của số 3 là 0 1 thì a là 0(thì a là số đầu tiên trong dãy fibonaci) b là 1(b là số liền kề vs số đầu tiên trong dãy fibonaci của
        số fibonaci 3) sau đó tạo biến temp để lưu (số liền số đầu tiên(là b nha)) sau đó ta thay đổi giá trị của b là = tổng 2 số liền kề lúc 
        này b = 0 + 1, sau khi cộng 2 số liền kề lại thì ta dùng a để cập nhất lại a là số liền kề của (số tổng 2 số liền kề) bằng cách  gán a 
        = biến temp mà biến temp ban đầu ta gán = b mà b ban đầu = 1 nên a = temp tức a lúc này = 1 
        ####> kết quả của lần chạy đầu tiên khi xét số 3 có phải là số fabonaci này là 0 1(đây là a) 1(đây là b)
        2)  lần tiếp while (b < x) b lúc này = 1 x là số ta muốn xét có phải là số fibonaci hay không tức x = 3 => b < x <=> 1 < 3 
        trong dãy fibonaci của số 3 sau lần chạy đầu tiên thì bay h là 0  1(đây là a) 1(đây là b) ,sau đó tạo biến temp để lưu (số vừa đc cộng ở 
        lần đầu tiên(là b nha) ) sau đó ta thay đổi giá trị của b là = tổng 2 số liền kề của b, lúc 
        này b = 1 liền kề vs b là a là = 1 luôn, sau khi cộng 2 số liền kề lại, thì ta dùng a để cập nhật lại số liền kề của (số vừa đc tính tổng 2 
        số liền kề) bằng cách  gán a = biến temp mà biến temp ban đầu ta gán = b mà b ban đầu = 1 nên a = temp tức a lúc này = 1 
        ####> kết quả của lần chạy lần 2 khi xét số 3 có phải là số fabonaci này là 0 1 1(đây là a) 2(đây là b)
        3) Lần thứ 3 while (b < x) b lúc này = 2 x là số ta muốn xét có phải là số fibonaci hay không tức x = 3 => b < x <=> 2 < 3 
        trong dãy fibonaci của số 3 sau lần chạy thứ 2 thì bay h là 0 1 1(đây là a) 2(đây là b) ,sau đó tạo biến temp để lưu (số vừa đc cộng ở 
        lần thứ 2(là b nha) ) sau đó ta thay đổi giá trị của b là = tổng 2 số liền kề của b, lúc 
        này b = 2 liền kề vs b là a mà a = 1 , sau khi cộng 2 số liền kề lại tức b = b + a <=> b = 2 + 1, cuối cùng ta dùng a để cập nhật lại số 
        liền kề của (số vừa đc tính tổng 2 số liền kề) bằng cách  gán a = biến temp mà biến temp lúc này ta gán = b mà b = 2 nên a = temp tức a 
        lúc này = 2
        ####> kết quả của lần chạy lần 2 khi xét số 3 có phải là số fabonaci này là 0 1 1 2(đây là a) 3(đây là b)
        3) Lần cuối while (b < x) b lúc này = 3 x là số ta muốn xét có phải là số fibonaci hay không tức x = 3 => b < x <=> 3 < 3  là 3 không bé 
        hơn 3 nên dừng while lại xuống chổ return
        */
        
    }
    return (b == x);/*Sau while thì b = 3 và x là số ta đang muốn xét có phải là số fibonaci không tức là x = 3 => b = x <=> 3 = 3 thì đúnhh với
    toán tử so sánh là == nên return về x là số số fibonaci
*/
}
void Fibonacci(phanso ps[], int n) {
    for (int i = 0; i < n; i++) {
        if (isFibonacci(ps[i].tuso) && isFibonacci(ps[i].mauso)) {/*Xét nếu tử và mẫu là số fibonaci bằng hàm kiểm tra số fibonaci thì xuất phân số 
            đó ra*/
            cout << ps[i].tuso << "/" << ps[i].mauso << endl;
        }
    }
}
#endif


#include<iostream>
using namespace std;

void Random(int a[], int n);
void OutPut(int a[], int n);
void Hoan_Vi(int& a, int& b);
void QuickSort(int a[], int left, int right);
int main() {

    int a[200];
    int n;
    cout << "Nhap n phan tu: ";
    cin >> n;
    Random(a, n);
    QuickSort(a, 0, n - 1);
    OutPut(a, n);
}
void Random(int a[], int n) {
    //Thuật toán xuất các giá trị random không trùng nhau
    for (short i = 0; i < n; i++) {
        a[i] = rand() % 199 - 99;
        for (short j = 0; j < i; j++) {
            if (a[i] == a[j]) {//Mõi lần phần tử lặp lại 
                a[i] = rand() % 199 - 99;
                j = -1;/*Mõi lần có số bị trùng ta cần phải set cho j về lại giá trị là 0 bằng cách cho j = -1 vì sau vòng lặp thì j nó tăng lên 1
                đơn vị */

            }
        }
    }
}
void OutPut(int a[], int n) {
    for (short i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = " << a[i]<<"\n";
    }

}
void Hoan_Vi(int& a, int& b) {
    int tam = a;
    a = b;
    b = tam;
}

void QuickSort(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;//duyệt từ bên trái i++
    int j = right;//duyệt từ bên phải j--
    while (i <= j)
    {
        while (a[i] < a[mid])
            i++;
        while (a[j] > a[mid])
            j--;
        if (i <= j)
        {
            Hoan_Vi(a[i], a[j]);
            i++;
            j--;
        }
    }//kết thúc đưa các phần tử về đúng vị trí trái phải
    if (i < right)
        QuickSort(a, i, right);
    if (j > left)
        QuickSort(a, left, j);
}
