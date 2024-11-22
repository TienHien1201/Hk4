/*pre oder => duyệt trước => gốc trái phải 

35,18,8,20,40,37,36,50,45,55,65 
*/

/*inOder => duyệt trước => trái gốc phải
8,18,20,35,36,40, 45,50,55,65

*/

/*PostOder => duyệt trước => trái phải gốc
8,20,18,36,37,45,65,55,50,35,40
*/
#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree* pleft;
    tree* pright;
};

tree *newTree(int x) {
  
    tree* p = new tree();
    p->data = x;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}

void themvaocay(tree*&t, int x) {
    if (t == NULL)
    {
        t = newTree(x);
    }
    else
    {
        if (x < t->data)
            themvaocay(t->pleft, x);
       
        else
            themvaocay(t->pright, x);
       
    }

}
void pre_oder(tree*  t) {//Xuất LNR

    if (t != NULL)
    { 
        cout << t->data<<" ";
        pre_oder(t->pleft);
      
        pre_oder(t->pright);
    }

}
void in_Oder(tree* t) {//Xuất LNR

    if (t != NULL)
    {

        pre_oder(t->pleft); 
        cout << t->data << " ";
        pre_oder(t->pright);
     
    }

}

void Post_Oder(tree* t) {//Xuất LRN

    if (t != NULL)
    {
        
        Post_Oder(t->pleft);
        Post_Oder(t->pright);
        cout << t->data << " ";
    }

}

void DiTimNodeTheMang(tree*& x, tree*& y) {

    if (y->pleft != NULL) {
        DiTimNodeTheMang(x, y->pleft);
    }
  
    else 

    {
        x->data = y->data;
        x = y;
        y = y->pright;
    }
}

void XoaNode(tree*& t, int data) {
   
    if (t == NULL)
    {
        return;
    }
    else
    {
      
        if (data < t->data)
        {
            XoaNode(t->pleft, data);
        }
    
        else if (data > t->data)
        {
            XoaNode(t->pright, data);
        }
        else
        {
            tree* x = t;

            if (t->pleft == NULL)
            {
                t = t->pright;
            }
            else if (t->pright == NULL)
            {
                t = t->pleft;
            }
            else { 
                DiTimNodeTheMang(x, t->pright);

                
            }
            delete x;
        }
    }
}
void pre_oder(tree* t);//Xuất NLR
void in_Oder(tree* t);//Xuất LNR
void Post_Oder(tree* t);//Xuất LRN
void themvaocay(tree*& t, int x);
void DiTimNodeTheMang(tree*& x, tree*& y);
void XoaNode(tree*& t, int data);

int main()
{
    tree *t = NULL;
    themvaocay(t, 8);
    themvaocay(t, 1);
    themvaocay(t, 9);
    themvaocay(t, 7);
    themvaocay(t, 5);
    themvaocay(t, 6);
    themvaocay(t, 4);
    themvaocay(t, 3);
    themvaocay(t, 2);
    themvaocay(t, 0);
    pre_oder(t);
    cout << "\n";
    in_Oder(t);
    cout << "\n";
    Post_Oder(t);
    int x;
    cout << "\nNhap node can xoa: ";
    cin >> x;
    XoaNode(t, x);
    pre_oder(t);
    cout << "\n";
    in_Oder(t);
    cout << "\n";
    Post_Oder(t);
}


