#ifndef sort
#define sort
#include <string>

using namespace std;


namespace N {

	class our_class {
	public:
		string all_string;
		// � ����� ������� ������ �������� ������
		int home; // ����� ���� 
		int flat; // ����� ��������
		//int room; ���������� ������
		int s; // ������� ��������
		//int people; // ����� ����������� �����
		string fio;	// ��� ��������� ��������
		
		our_class(const string & str); // ����������� ��� ������
		our_class(); // ������ �����������
		void set_all(string& str); // ��������� ������ � ������������� ����� ��������
		string showAll(); // ������� ��� ������ �� ����� �������
		string showSorted(); // ������� ������ �� ����, �� ������� ���� ����������

		// ���������� ��������� ��������� ������ 
		friend bool operator>(const our_class& left, const our_class& right);


		// ���������� ��������� ��������� ������ ��� �����
		friend bool operator>=(const our_class& left, const our_class& right);


		// ���������� ��������� ������
		friend bool operator<(const our_class& left, const our_class& right);


		//���������� ��������� ������ ��� �����
		friend bool operator<=(const our_class& left, const our_class& right);


		// ���������� ��������� ������������
		our_class& operator=(const our_class& other) {
			home = other.home;
			flat = other.flat;
			s = other.s;
			fio = other.fio;
			all_string = other.all_string;
			return *this;
		}


	};

	
}




#endif
