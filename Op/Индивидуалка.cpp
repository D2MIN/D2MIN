#include <iostream>
using namespace std;

//1 2 3 4 5 6 0
//2 4 6 8 0
//1 3 5 7 9 0

struct List {
	int data;
	List* next;
};

void create_list(List* p, List* r, int x) {
	while (x) {
		r->data = x;
		p->next = r;
		p = r;
		r = new List;
		cin >> x;
	}
	p->next = NULL;
	delete r;
}

void delete_list(List* head) {
	if (head != NULL) {
		delete_list(head->next);
		delete head;
	}
}

void print_list(List* p) {
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

int point_a(List* p_1, List* p_2) {
	int count = 0;
	List* head = p_1;
	while (p_1 != NULL) {
		while (p_2 != NULL) {
			if (p_1->data == p_2->data) {
				count++;
			}
			if (count > 1) {
				return 1;
			}
			p_2 = p_2->next;
		}
		p_2 = head;
		count = 0;
		p_1 = p_1->next;
	}
	return 0;
}

void point_b(List* p_1, List* p_2, List* point, int n) {
	while (p_1 != NULL) {
		if (p_1->data == n) {
			point = p_1->next;
			while (p_2 != NULL) {
				List* r = new List;
				r->data = p_2->data;
				p_1->next = r;
				p_1 = r;
				p_2 = p_2->next;
			}
			p_1->next = point;
			p_1 = point;
		}
		else {
			p_1 = p_1->next;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	List* head_1 = new List;
	List* head_2 = new List;
	List* head_3 = new List;
	List* r_1 = new List, * p_1;
	List* r_2 = new List, * p_2;
	List* r_3 = new List, * p_3;

	cout << "Введите список 1: " << endl;
	int x; cin >> x;
	head_1->data = x;
	cin >> x;
	create_list(head_1, r_1, x);

	cout << "Введите список 2: " << endl;
	cin >> x;
	head_2->data = x;
	cin >> x;
	create_list(head_2, r_2, x);

	cout << "Введите список 3: " << endl;
	cin >> x;
	head_3->data = x;
	cin >> x;
	create_list(head_3, r_3, x);

	cout << "Сделайте правильный выбор." << endl;
	cout << "1 - Проверит 1 список на присутствие одинаковых элементов" << endl;
	cout << "2 - добавим в список 2 после заданого элемента список 3" << endl;
	cout << ":  ";
	int flag;
	cin >> flag;
	if (flag == 1) {
		if (point_a(head_1, head_1)) {
			cout << "Присутствуют";
		}
		else cout << "Отсутствуют";
	}
	if (flag == 2) {
		cout << "Тогда введите число после которого мы вставим элемент: ";
		int n; cin >> n;
		point_b(head_2, head_3, r_3, n);
		print_list(head_2);
	}
	if (flag != 1 && flag != 2) {
		cerr << "Вы выбрали не верный вариант";
	}

	delete_list(head_1);
	delete_list(head_2);
	delete_list(head_3);
}
