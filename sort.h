#ifndef sort
#define sort
#include <string>

using namespace std;


namespace N {

	class our_class {
	public:
		string all_string;
		// в таком порядке строка содержит данные
		int home; // номер дома
		int flat; // номер квартиры
		//int room; количество комнат
		int s; // площадь квартиры
		//int people; // число проживающих людей
		string fio;	// ФИО владельца квартиры
		
		our_class(const string & str); // конструктор для строки
		our_class(); // пустой конструктор
		void set_all(string& str); // принимает строку и устанавливает новые значения
		string showAll(); // выводит всю строку со всеми данными
		string showSorted(); // выводит только те поля, по которым была сортировка

		// перегрузка оператора сравнения БОЛЬШЕ
		friend bool operator>(const our_class& left, const our_class& right);


		// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
		friend bool operator>=(const our_class& left, const our_class& right);


		// перегрузка оператора МЕНЬШЕ
		friend bool operator<(const our_class& left, const our_class& right);


		// перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
		friend bool operator<=(const our_class& left, const our_class& right);


		// перегрузка оператора присваивания
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
