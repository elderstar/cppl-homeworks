#include <iostream>
#include "cube.h"

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = x; // семантическая ошибка, логика нарушена
	}
};

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}


int main()
{
	std::cout << cube(3);

	for (int i = 0; i < 5; i++) { 
		//point my_pоint{ i, 2 * i }; // синтаксические ошибки
		//print_point(my_point);
	}
	return 0;
}