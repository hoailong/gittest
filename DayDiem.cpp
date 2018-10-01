/*
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;

class Diem {
	friend class DayDiem;
	double x;
	double y;
	string m;
public:
	friend istream& operator>>(istream &in,Diem &d);
	friend ostream& operator<<(ostream &out,Diem d);
	double khoangCachDenO() {
		return sqrt(x*x+y*y);
	}
	double khoangCach2Diem(Diem d2) {
		return sqrt((d2.x-this->x)*(d2.x-this->x)+(d2.y-this->y)*(d2.y-this->y));
	}
	
};
istream& operator>>(istream &in,Diem &d){
	cout << "Hoanh do: ";in >>d.x;
	cout << "Tung do: ";in >>d.y;
	do {
		cout << "Ma mau (DO , VANG , XANH) :";
		in.ignore()	;
		in >> d.m;
	} while (d.m.compare("DO") !=0 && d.m.compare("VANG") !=0 && d.m.compare("XANH") !=0);
	return in;
}

ostream& operator<<(ostream &out,Diem d){
	out << "(" << d.x << "," << d.y << ") " << "\tMau: " << d.m;
	return out; 
}

class DayDiem {
	int n;
	Diem *d;
public:
	void nhap();
	void xuat(); 
	double duongGapKhuc();
	double khoangCachMax();
	double tongDoDaiDiemXanh();
	int soDiemTheoMau(string mau);
	string mauNhieuDiemNhat();
};

void DayDiem::nhap() {
	do {
		cout << "Nhap so diem: ";cin >> n;
	} while (n <= 0);
	d = new Diem[n+1];
	for (int i = 0; i < n; i++) {
		cout << "\nNhap toa do diem thu " << i+1 << " : " << endl;
		cin >> d[i];
	}
}

void DayDiem::xuat() {
	for (int i = 0; i < n; i++) {
		cout << "\nToa do diem thu " << i+1 << " : " <<d[i];
	}
}

double DayDiem::duongGapKhuc() {
	double s = 0;
	for (int i = 0; i < n-1; i++) {
		s+= d[i].khoangCach2Diem(d[i+1]);
	}
	return s;
}

double DayDiem::khoangCachMax() {
	double max = d[0].khoangCachDenO();
	for (int i = 1; i < n; i++) {
		double kc = d[i].khoangCachDenO();
		max = max > kc ? max : kc;
	}
	return max;
}

double DayDiem::tongDoDaiDiemXanh() {
	double sx = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].m.compare("XANH") == 0) {
			sx+= abs(d[i].y);
		}
	}
	return sx;
}

int DayDiem::soDiemTheoMau(string mau) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].m.compare(mau) == 0) dem++;
	}	
	return dem;
}

string DayDiem::mauNhieuDiemNhat() {
	string s = "";
	int a = soDiemTheoMau("DO");
	int b = soDiemTheoMau("XANH");
	int c = soDiemTheoMau("VANG");
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	if (max == a) s+=" DO";
	if (max == b) s+=" XANH";
	if (max == c) s+=" VANG";
	return s;
}

int main() {
	DayDiem dd;
	dd.nhap();
	dd.xuat();
	cout << "\n\nD dai duong gap khuc : " << dd.duongGapKhuc();
	cout << "\nKhoang cach Max cua cac diem toi tam O : " << dd.khoangCachMax();
	cout << "\nTong do dai cac khonag cach tu cac diem Xanh toi truc 0X : " << dd.tongDoDaiDiemXanh();
	cout << "\nSo diem co mau DO: " << dd.soDiemTheoMau("DO");
	cout << "\nSo diem co mau VANG: " << dd.soDiemTheoMau("VANG");
	cout << "\nSo diem co mau XANH: " << dd.soDiemTheoMau("XANH");
	cout << "\nMau co nhieu diem nhat :" << dd.mauNhieuDiemNhat();
	return 0;
}

