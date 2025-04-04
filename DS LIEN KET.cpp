#include <iostream>
using namespace std;
typedef struct node
{
	DataType info;
	struct node* next;
}Node;
Node* pHead = NULL;

// Kiểm tra danh sách rỗng 
bool IsEmpty(Node* pHead)
{
	return (pHead == NULL);
}
//Khởi tạo danh sách liên kết
void Init(Node*& pHead)
{
	pHead == NULL;
}
Node* CreateNode(int X)
{
	Node* p = new Node;
	p->info = X;
	p->next = NULL;
	return p;
}
// Duyệt 1 danh sách liên kết
void ShowList(Node* pHead) // trỏ đến node đầu tiên của danh sách liên kết 
{
	Node* p = pHead; // Gán con trỏ p bằng pHead để duyệt ds mà không làm mất vị trí gốc
	if (p == NULL)
		cout << "Danh sach rong";
	else
		while (p != NULL) // duyệt qua từng phần tử
		{
			cout << p->info;
			p = p->next; // di chuyển con trỏ p sang node tiếp theo
		}
}
// Tìm kiếm một phần tử 
Node* Find(Node* pHead, int x)
{
	// x là nội dung cần tìm
	bool found = false;
	Node* p = pHead;
	while ((p != NULL) && (!found))
	{
		if (p->info == x)
			found = true;
		else
			p = p->next;
	}
	if (!found)
		p = NULL;
	return p;
}
// Tìm kiếm trong ds đã có thứ tự
Node* FindOrder(Node* pHead, int x)
{
	// Tìm x trong danh sách đã có thứ tự 
	bool found = false;
	Node* p = pHead;
	while ((p != NULL) && (!found))
	{
		if (p->info == x)
			found = true;
		else if (p->info < x)
			p = p->next;
		else
			p = NULL;
	}
	if (!found)
		p = NULL;
	return p;
}
// Thêm vào đầu danh sách
void InsertFirst(Node*& pHead, int x)
{
	Node* p = CreateNode(x);
	p->next = pHead;
	pHead = p;
}
// Thêm một phần tử vào sau một nút 
void InsertAfter(Node* p, int x)
{
	if (p != NULL)
	{
		// Thêm vào ngay sau item 
		Node* q = CreateNode(x);
		q->next = p->next;
		p->next = q;
	}
}
// Thêm vào danh sách có thứ tự 
void InsertOrder(Node*& pHead, int x)
{
	// Thêm x vào danh sách có thứ tự tăng dần
	Node* tp;
	Node* p = pHead;
	bool cont = true;
	while ((p != NULL) && cont)
		if (p->info < x)
		{
			tp = p;
			p = p->next;
		}
		else cont = false;
	// Xen nút q vào giữa p và nút tp
	if (p == pHead)
		InsertFirst(pHead, x);
	else
		InsertAfter(pHead, x);
}
//Loại bỏ một phần tử ở đầu danh sách
void Deletefirst(Node*& pHead)
{
	if (IsEmpty(pHead))
		cout << "Danh sach rong!";
	else
	{
		Node* p = pHead;
		pHead = pHead->next;
		delete p;
	}
}
// Loại bỏ một phần tử sau 
void DeleteAfter(Node* p)
{
	//Thêm x vào danh sách có thứ tự tăng dần
	if (p == NULL || p->next == NULL)
	{
		// kiểm tra nút sau p có tồn tại không 
		cout << "Khong the xoa nut nay!";
	}
	else
	{
		Node* q = p->next;
		p->next = q->next;
		delete q;
	}
}
// Loại bỏ một phần tử có nội dung x
Node* Remove(Node*& pHead, int x)
// Tìm và bỏ x trong danh sách first chưa có thứ tự
{
	Node* tp;
	Node* p = pHead;
	bool found = false;
	while ((p != NULL) && !found) 
	{
		if (p->info != x)
		{
			tp = p;
			p = p->next;
		}
		else
			found = true;
	}
	if (found)
	{
		if (p == pHead) // Loại bỏ phần tử đầu tiên
			pHead = p->next;
		else
			tp->next = p->next;
		delete p;
	}
}
Node* Remove(Node*& pHead, int x)
// Tìm và bỏ x trong danh sách first chưa có thứ tự
{
	Node* tp;
	Node* p = pHead;
	bool found = false;
	while ((p != NULL) && !found)
	{
		if (p->info != x)
		{
			tp = p;
			p = p->next;
		}
		else
			found = true;
	}
	if (found)
	{
		if (p == pHead) // Loại bỏ phần tử đầu tiên
			pHead = p->next;
		else
			tp->next = p->next;
		delete p;
	}
}
	Node* RemoveOrder(Node * &pHead, int x)
	{
		// Tìm và bỏ x trong danh sách first đã có thứ tự
		Node* tp;
		Node* p = pHead;
		bool found = false;
		while ((p != NULL) && !found) 
		{
			if (p->info < x)
			{
				tp = p;
				p = p->next;
			}
			else if (p->info == x) found = true;
			else p = NULL;
		}
		if (found)
		{
			if (p == pHead) // Loại bỏ phần tử đầu tiên
				pHead = p->next;
			else
				tp->next = p->next;
			delete p;
		}
	}
	void ClearList(Node*& pHead)
		// Xóa toàn bộ danh sách
	{
		Node* p;
		while (pHead != NULL) 
		{
			p = pHead;
			pHead = p->next;
			delete p;
		} // hết while
	} // hết ClearList
// Sắp xếp danh sách dùng Selection Sort
	void SelectionSort(Node*& pHead)
		// Sắp xếp danh sách tăng dần
	{
		Node* p, * q, pmin;
		int vmin;
		for (p = pHead; p->next != NULL; p = p->next) {
			vmin = p->info;
			pmin = p;
			for (q = p->next; q != NULL; q = q->next) {
				if (q->info < min) {
					vmin = q->info;
					pmin = q;
				} // hết if
			} // hết for q
			pmin->info = p->info;
			p->info = vmin;
		} // hết for p
	} // hết Sort