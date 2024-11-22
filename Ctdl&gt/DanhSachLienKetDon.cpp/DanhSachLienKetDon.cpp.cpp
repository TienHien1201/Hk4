#include <iostream>
using namespace std;
/*

*/

struct node
{
    node* pNext;
    int data;
};

void adHead(node*& pHead, int data);
void getList(node* pHead);
void adLast(node*& pHead, int data);
void adNodePsauNodeQ(node*& pHead, int x, int data);
void deleleFirt(node*& pHeah, int data);
void deleteLast(node*& pHead, int data);
void delete_nodeX(node* &pHead,int x);
int main()
{
    node* pHead = NULL;
    node* Q = NULL;

    adHead(pHead, 1);
    adHead(pHead, 2);
    adHead(pHead, 3);
    adLast(pHead, 4);
    adLast(pHead, 5);
    adLast(pHead, 6);
    getList(pHead);
    adNodePsauNodeQ(pHead, 6, 4);
    deleleFirt(pHead, 3);
    cout << "\nDanh sach sau khi xoa node dau :\n";
    getList(pHead);
    deleteLast(pHead, 4);
    cout << "\nDanh sach sau khi xoa node cuoi :\n";
    getList(pHead);


    delete_nodeX(pHead, 2);
    cout << "\nDanh sach sau khi xoa node " << "\n";
    getList(pHead);
    
    
    
}

void adHead(node* &pHead, int data) {

    node* tam = NULL;//tạo 1 cái node cho danh sách đơn
    tam = new node;//Cấp phát vùng nhớ lưu giá trị cho node tạm
    tam->data = data;
    tam->pNext = NULL;
    
    if (pHead == NULL)
        pHead = tam;
    else
    {
        tam->pNext = pHead;
        pHead = tam;
    }
}

//hàm lấy các node xuất ra màn hình
void getList(node * pHead) {
    while(pHead != NULL) {

        cout << pHead->data << " ";
        pHead = pHead->pNext;
    }
}

void adLast(node*& pHead, int data) {//Thêm cuối
    node* tam = new node; // Tạo một nút mới
    tam->data = data;
    tam->pNext = NULL;

    if (pHead == NULL) // Nếu danh sách rỗng, nút mới là nút đầu
        pHead = tam;
    else {
        /*Tạo 1 node p thế chổ chổ cho node đầu trong danh sách để lấy p duyệt danh sách liên kết đơn tìm node kế cuối, 
        để không làm mất liên kết từ node pHead(node đầu) đến node gần cuối trong danh sách liên kết đơn chứ k nếu ta dùng trực tiếp node
        đầu duyệt và cập nhật lại node kế mõi lần duyệt là node pHead thì nó sẽ mất liên kết với những node đầu vì ta câp nhật trực 
        tiếp node pHead là node của mõi lần duyệt kế tiếp nên dẫn đến mất liên kết với các node đầu vì vậy cần tạo 1 node thế pHead tìm
        ra node kết cuối để liên kết với node thêm vào cuối*/
        node* p = pHead;
        while (p->pNext != NULL) { // Di chuyển đến phần tử cuối cùng của danh sách
             p = p->pNext;
         
        }
        // Nối nút mới vào cuối danh sách
        p->pNext = tam;
      
    }
}
void adNodePsauNodeQ(node*& pHead, int x, int data) {
    // Tạo nút mới cần thêm vào danh sách
    node* tam = new node;
    tam->data = data;
    tam->pNext = NULL;

    // Kiểm tra danh sách có rỗng không
    if (pHead == NULL) {
        cout << "Danh sach rong!";
        return;
    }

   
    node* Q = pHead;
    while (Q->pNext != NULL && Q->data != x) {
        Q = Q->pNext;
    }

    if (Q->data != x) {
        cout << "\nKhong ton tai node " << x << endl;
        delete tam; // Xóa nút mới
        return;
    }

    // Chèn nút mới vào sau nút Q
    cout << "\ndanh sach sau khi them node " <<tam->data  << " vao sau node " << x <<"\n";
    tam->pNext = Q->pNext;
    Q->pNext = tam;
    getList(pHead);
}

void deleleFirt(node* &pHeah, int data) {
    if (pHeah == NULL)
        cout << "danh sach rong !";
    else
    {
        node* tam = pHeah;
        pHeah = pHeah->pNext;
        delete(tam);

    }
}

void deleteLast(node * &pHead, int data) {
    if (pHead == NULL)
        cout << "Danh sach rong !";
    else {
        node* p = pHead;
        while(p->pNext->pNext != NULL) {
           p = p->pNext;

        }
        p->pNext = NULL;
    }

}

//tự làm
//void delete_nodeX(node* &pHead, int x) {//x là p, Q là data
//   
//    if (pHead == NULL)
//        cout << "Danh sach rong !";
//    else
//    {
//        node* Q = pHead;
//        while (Q->pNext != NULL && Q->pNext->data != x) {
//            Q = Q->pNext;
//        }
//
//        if (Q->data != x)
//        {
//            cout << "Khong ton tai node " << x;
//            return;
//        }
//      
//        Q->pNext = Q->pNext->pNext;
//        node* tam = pHead->pNext;
//        pHead = pHead->pNext->pNext;
//        delete(tam);
//        cout << "\nDanh sach sau khi xoa node " << x<<"\n";
//        getList(pHead);
//        
//    }
//}


//Thầy sửa
bool FindX(node* & pHead, int x) {
    while(pHead != NULL) {
        if (pHead->data == x)
        {
            break;
        }
        else
            pHead = pHead->pNext;
        if (pHead == NULL)
            return false;
        else
            return true;
    }
}
void delete_nodeX(node* &pHead, int x) {
    if (FindX(pHead, x))
    {
        node* pHeadTam = pHead;
        while (pHead->pNext->data != x)
        {
            pHead = pHead->pNext;
        }
        node* tam = pHead->pNext;
        pHead->pNext = pHead->pNext->pNext;
        delete (tam);
        pHead = pHeadTam;
    }
    else
    {
        cout << "\nkhong co node x";
    }    
}

void remove_All
















