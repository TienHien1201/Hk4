#include <iostream>
#include<string>//Dùng library String để xử lí chuỗi ký tự
using namespace std;
const int maxStack = 5;
int vitridinh = -1;
void push(int stack[], int x);
void pop(int stack[]);
void runStack(int stack[], string StringInput);
void hauTo(int stack[], string StringInput);
void tinhkq(int stack[], string BieuThucHauTo);

int main()
{
	int stack[maxStack] = { 0 };
	//runStack(stack, "EAS*Y**QUE***ST***I*ON");
	//hauTo(stack, "(4-5)*(6+3)");
	tinhkq(stack, "45-63+*");
}
void push(int stack[], int x) {
	if (vitridinh > maxStack - 1)
		cout << "\nStack day !";
	else {
		vitridinh++;
		stack[vitridinh] = x;
	}
}
void pop(int stack[]) {
	if (vitridinh < 0)
		cout << "\nStack rong !";
	else
	{
		cout << char(stack[vitridinh]);
		vitridinh--;
	}
}

/*Bài 1: Thêm vào lấy lần lượt chuỗi EAS*Y**QUE***ST***I*ON và stack và Xuất ra chuỗi SYAEUQTSEI */
void runStack(int stack[], string StringInput) {
	for (short i = 0; i < StringInput.length(); i++)//StringInput.length() đếm xem chuỗi có bao nhiêu ký tự
	{
		if(StringInput[i] == 42)//Xét xem ký tự lưu trong chuỗi stringInput kiểu string có phải là dấu * không 
			pop(stack);
		else//Nếu không phải là dấu * thì đưa vào stack
			push(stack, StringInput[i]);
	}
}

/*Bài 2: Chuyển đổi biểu thức trung tố (4-5)*(6 + 3) sang hậu tố 45-63+* */
void hauTo(int stack[], string StringInput) {
	for (short i = 0; i < StringInput.length(); i++) {//StringInput.length() đếm xem chuỗi có bao nhiêu ký tự
		if (StringInput[i] == '(')
			push(stack, '(');
		else if (StringInput[i] == ')') {
			while (stack[vitridinh] != '(')
				pop(stack);
			vitridinh--; // Đưa ra ngoài khỏi dấu ngoặc đóng
			
		}
		else {
			if (StringInput[i] >= 42 && StringInput[i] <= 47) {//Khi gặp toán tử + - * chia tức mã ascll 
				if ((StringInput[i] == '+' || StringInput[i] == '-') &&
					(stack[vitridinh] == '*' || stack[vitridinh] == '/')) {/*Dấu nào có bậc ưu tiên cao hơn sẽ
					đc lấy ra trước*/
					pop(stack);
					push(stack, StringInput[i]);
				}
				else
					push(stack, StringInput[i]);
			}
			else
				cout << StringInput[i];
		}
	}
	// Sau khi duyệt xong chuỗi, cần pop những phần tử còn lại trong stack
	while (vitridinh >= 0) {
		pop(stack);
	}
}
//Tính kết quả của hậu tố
void tinhkq(int stack[], string BieuThucHauTo) {
	for (short i = 0; i < BieuThucHauTo.length(); i++) {//StringInput.length() đếm xem chuỗi có bao nhiêu ký tự
		if (BieuThucHauTo[i] >= 48 && BieuThucHauTo[i] <= 57)//Nếu là số nguyên tức mã ascll
			push(stack, BieuThucHauTo[i]);
		else
		{
			int tam;
			if (BieuThucHauTo[i] == '+')
				 tam = (stack[vitridinh - 1]- 48) + (stack[vitridinh] - 48);/*Vì số nguyên ta là Mã ascll nên
			số 0 có mã asccl là 48 => 48 - 48 = 0... Tương tự các số nguyên khác số 1 mã ascll là 49 => 49 - 48
			ra số 1.....*/
			else if (BieuThucHauTo[i] == '-')
				 tam = (stack[vitridinh - 1] - 48) - (stack[vitridinh] - 48);
			else if (BieuThucHauTo[i] == '*')
				 tam = (stack[vitridinh - 1] - 48) * (stack[vitridinh]- 48);
			else
				tam = (stack[vitridinh - 1] - 48) / (stack[vitridinh]-48);
			vitridinh= vitridinh - 2;
			push(stack, tam);
		}
		cout << stack;
	}
	}
