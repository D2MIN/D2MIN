#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Функция возвращает длину линии по формуле нахождения длины линии sqrt( (a1-a2)^2 + (b1-b2)^2 )
double length(pair <double, double> cord_one, pair <double, double> cord_two) {
	return sqrt(pow(abs(cord_one.first - cord_two.first), 2) + pow(abs(cord_one.second - cord_two.second), 2));
}

//Функция считающая длины сторон треугольника образованого прямой и точкой
double min_lenght_triangle(pair <double, double >& point, pair <double, double> cord_line_one, pair <double, double > cord_line_two) {
	double line_1, line_2, line_3;
	line_1 = length(point, cord_line_one); // 1 сторона
	line_2 = length(point, cord_line_two); // 2 сторона
	line_3 = length(cord_line_one, cord_line_two); // основание треугольника
	double s_pr = (line_1 + line_2 + line_3) / 2; // Полупериметр треугольника
	double s = sqrt(s_pr * (s_pr - line_1) * (s_pr - line_2) * (s_pr - line_3)); // Площадь треугольника
	double h = (2 * s) / line_3; // Высота треугольника
	return h;
}

//Функция считающая длину от точки до прямой если они на одной оси x
double min_lenght_x(pair <double, double >& point, pair <double, double> cord_line_one, pair <double, double > cord_line_two){
	if (point.first > cord_line_one.first && point.first > cord_line_two.first) //Проверяю ниже точка или выше прямой
		return abs(max(cord_line_one.first, cord_line_two.first) - point.first);
	else
		return abs(min(cord_line_one.first, cord_line_two.first) - point.first);
}

//Функция считающая длину от точки до прямой если они на одной оси y
double min_lenght_y(pair <double, double >& point, pair <double, double> cord_line_one, pair <double, double > cord_line_two){
	if (point.second > cord_line_one.second && point.second > cord_line_two.second) // Проверяю правее точка или левее прямой
		return abs(max(cord_line_one.second, cord_line_two.second) - point.second);
	else
		return abs(min(cord_line_one.second, cord_line_two.second) - point.second);
}

int main() {
	pair <double, double > point; 
	pair <double, double > cord_line_one; 
	pair <double, double > cord_line_two;

	cin >> cord_line_one.first >> cord_line_one.second; //Первая кордината линии
	cin >> cord_line_two.first >> cord_line_two.second; //Вторая корда линии

	ifstream file("points.txt");
	if (!file.is_open()) { // проверка, успешно ли открыт файл
		cout << "Ошибка открытия файла!";
		return 1;
	}
	
	double min;
	int flag = 0;
	pair <int, int> min_point;
	//Считываем с файла
	while (!file.eof() && file >> point.first, file >> point.second) {
		//Если они на оси x
		if (point.first == cord_line_one.first && point.first == cord_line_two.first) {
			if (flag == 1 && min > min_lenght_y(point, cord_line_one, cord_line_two)) {
				min = min_lenght_y(point, cord_line_one, cord_line_two); //Переприсваеваем минимальную длину
				min_point = point; // Переприсваеваем точку
			}
			if (flag == 0){
				min = min_lenght_y(point, cord_line_one, cord_line_two);
				min_point = point;
				flag = 1;
			}
		}
		//Если они на оси y
		if (point.second == cord_line_one.second && point.second == cord_line_two.second) {
			if (flag == 1 && min > min_lenght_x(point, cord_line_one, cord_line_two)) {
				min = min_lenght_x(point, cord_line_one, cord_line_two);
				min_point = point;
			}
			if (flag == 0){
				min = min_lenght_x(point, cord_line_one, cord_line_two);
				min_point = point;
				flag = 1;
			}
		}
		// Иначе
		if (point.first != cord_line_one.first && point.first != cord_line_two.first && point.second != cord_line_one.second && point.second != cord_line_two.second) {
			if (flag == 1 && min > min_lenght_triangle(point, cord_line_one, cord_line_two)) {
				min = min_lenght_triangle(point, cord_line_one, cord_line_two);
				min_point = point;
			}
			if (flag == 0) {
				min = min_lenght_triangle(point, cord_line_one, cord_line_two);
				min_point = point;
				flag = 1;
			}
		}
	}
	cout << min_point.first << " " << min_point.second;
}