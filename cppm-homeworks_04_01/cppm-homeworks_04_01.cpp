// cppm-homeworks_04_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
class Adress {
private:
    std::string city;
    std::string street;
    std::string homeNumb;
    std::string apartment;
 public:
    
    //cеттеры
    void set_city(std::string city) { //устанавливает город в экземпляр класса
        this->city = city;
    }
    void set_street(std::string street) { //устанавливает улицу
        this->street = street;
    }
    void set_homeNumb(std::string homeNumb) { //устанавливает номер дома
        this->homeNumb = homeNumb;
    }
    void set_apartment(std::string apartment) { //устанавливает номер квартиры
        this->apartment = apartment;
    }
    //геттеры
    std::string get_city() { return city; }
    std::string get_street() { return street; }
    std::string get_hoomeNumb() { return homeNumb; }
    std::string get_apartment() { return apartment; }

    //склеивает одну строку из строки полей 
    std::string make_Adress_in_one_string() {
        std::string buffer;
        buffer = city + ", " + street + ", " + homeNumb + ", " + apartment + "\n";
        return buffer;
    }
};

//возвращает считанный из файла элемент
std::string return_from_reader(std::ifstream& reader) {
    std::string buff;
    reader >> buff;
    return buff;

}



int main()
{
    std::ifstream reader("in.txt");
    if (!reader.is_open()) {
        std::cout << "Unable to open input file!" << std::endl;
        return 1;
    }
    int N; //для записи количества адресов
    reader >> N;
    Adress* arr_adress = new Adress[N];
    for (int i = 0; i < N; i++) {
        arr_adress[i].set_city(return_from_reader(reader));
        arr_adress[i].set_street(return_from_reader(reader));
        arr_adress[i].set_homeNumb(return_from_reader(reader));
        arr_adress[i].set_apartment(return_from_reader(reader));
    }
    reader.close();
    std::ofstream writer("out.txt");
    if (!writer.is_open()) {
        std::cout << "Unable to open output file!" << std::endl;
        return 2;
    }
    //записываем количество адресов
    writer << N << std::endl;
    for (int i = 0; i < N; i++) {
        writer << arr_adress[i].make_Adress_in_one_string();
    }
    writer.close();
    delete[] arr_adress;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
