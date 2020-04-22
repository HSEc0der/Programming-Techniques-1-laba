#ifndef Header
#define Header
#include <string>

namespace N {
	class our_class {
		private:
			std::string all_string; // вся строка, которая подается на вход
			// в таком порядке строка содержит данные
			int home;
			int flat;
			//int room;
			int s;
			//int people
			std::string fio;
		public:
			// конструктор
			our_class(const std::string& str);
			
			//пустой конструктор
			our_class();
			
			//возвращает номер дома
			int Home();
			
			//возвращает номер квартиры
			int Flat();

			//возвращает площадь
			int S();

			//возврашает ФИО
			std::string Fio();

			//возвращает всю строку
			std::string AllString();
			
			//возвращает только те поля, по которым была сортировка
			std::string showSorted();
}

			//работает также, как и конструктор
			void set_all(const std::string & str);

			// перегрузка оператора сравнения БОЛЬШЕ 
			friend bool operator>(const our_class& left, const our_class& right);


			// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
			friend bool operator>=(const our_class& left, const our_class& right);


			// перегрузка оператора МЕНЬШЕ
			friend bool operator<(const our_class& left, const our_class& right);


			//перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
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
	}; // end our_class
} // end namespace N
#endif
