// ���� ������ �������� � ��������� �����, ������� ����� ��������� � ���� ��������� �������� ������ ������, �������� ��� ����� ����������.

#include <iostream>
using namespace std;

// ����� "�����"
class Point {

	// �����������
	int X;
	int Y;
public:

	//�����������
	Point() {
		X = Y = 0;
	}

	//��������� ���������
	void SetPoint(int iX, int iY) {
		X = iX;
		Y = iY;
	}

	//������������ ���������
	void Show() {
		cout << "----------------------------\n\n";
		cout << X << "\t" << Y << "\n\n";
		cout << "----------------------------\n\n";
	}
};
//����� ������
class Figura {

	// ��������� �����
	// (���������� �����)
	Point* obj;

	// ���������� �����
	int count;
	// ���� ������
	int color;

public:

	//�����������
	Figura() {
		count = color = 0;
		obj = NULL;
	}

	// �������� ������
	void CreateFigura(int cr, int ct) {
		// ���� ����� ������ ���� - ��� �� ������
		if (ct < 3) exit(0);
		//������������� ����� � ���������� �����
		count = ct;
		color = cr;
		// ���������� ������ ��� ������ �����
		obj = new Point[count];
		if (!obj) exit(0);

		//��������� ��������� �����
		int tempX, tempY;
		for (int i = 0; i < count; i++) {
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}

	//����� ������
	void ShowFigura() {
		cout << "----------------------------\n\n";
		cout << "Color" << color << "\n\nPoints - " << count << "\n\n";
		for (int i = 0; i < count; i++) {
			obj[i].Show();
		}
	}

	//���� ������ ���� �������� ������
	~Figura() {
		if (obj != NULL) delete[]obj;
	}


};

class Composition
{
	Figura* obj;
	int count;
public:
	Composition()
	{
		obj = NULL;
		count = 0;
	}
	~Composition()
	{
		if (obj)
			delete [] obj;
	}
	void addFigura(int c)
	{
		count = c;
		obj = new Figura[count];
		for (int i=0; i<count; i++)
		{
			int col, num;
			cout << "enter color of figure on number of points to create it -> " << endl;
			cin >> col >> num;
			(obj+i)->CreateFigura(col, num);
		}
	}
	void showComposition() const
	{
		for (int i=0; i<count; i++)
			(obj+i)->ShowFigura();
	}
};

void main() {

	//Figura f;
	//f.CreateFigura(255, 3);
	//f.ShowFigura();
	Composition c;
	c.addFigura(3);
	c.showComposition();

}


