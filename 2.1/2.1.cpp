#include <iostream>
// 7) добавлено ненужное объявление using namespace std; и дальше все равно используется полный путь к пространству std::

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y; // 4) y заменил на m_y
	}
}; // 1) добавил ;

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main() // 2) Main изменил на main
{
	// 5) int i; удалил, и перенес тип <int> в for()
	for (int i = 0; i < 5; i++){ // 6) удалил ; после закрывающей скобки ')' оказалась самой сложной ошибкой для обнаружения =)
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

// 3) удалил дубликат print_point