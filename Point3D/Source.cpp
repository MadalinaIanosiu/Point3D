#include "Point3D.h"
#include <fstream>
#include<algorithm>

bool comparator(const Point3D& pct1, const Point3D& pct2)
{
	return pct1.GetZ() < pct2.GetZ();
}
int main()
{
	std::vector<Point3D> points; {
		float x, y, z;
		std::string name;
		for (std::ifstream fin("input.txt"); !fin.eof();) {
			std::string s;
			fin >> name >> x >> y >> z >> s;
			PointType type = convertStrToType(s);
			points.emplace_back(name, x, y, z, type);
		}
	}
	/*Testare de afisare a continutului din fisier*/
	for (const auto& x : points) {
		std::cout << x << "\n";
	}
	/*Se sortează punctele după valoarea coordonatei Z și se afișează în fișierul output.txt,
fiecare punct pe o linie separată.*/
	std::ofstream fout("output.txt");
	std::sort(points.begin(), points.end(), comparator);
	for (const auto& x : points) {
		fout << x << "\n";
	}
	std::cout << "\n";
	/*Se calculează și se afișează pe ecran valoarea medie a tuturor punctelor, folosind o funcție
 membră statică a clasei Point3D.*/
	std::cout << "Average of all points: " << Point3D::valoareMediePuncte(points) << '\n';
	/*Se citesc de la tastatura mai multe puncte 3D, fiecare punct cu toate atributele lui. Să se
 creeze o colecție cu punctele 2D obtinute prin transformarea acelor puncte de frontiera și
 să se afișeze perechea de puncte 2D cu cea mai mică distanță.*/
	Point3D point;
	std::vector <Point3D> points2D;
	while (std::cin >> point)
	{
		if (point.GetZ() == 0)
			break;
		if (pointTypeToString(point.GetType()) == "PunctFrontiera")
		{
			point.conversie(point);
			points2D.emplace_back(point);
		}
	}
	if (points2D.size() < 2) throw std::exception();

	float min = INT_MAX;
	Point3D minPointFirst, minPointSecond;
	for (const auto& point2DFirst : points2D)
	{
		for (const auto& point2DSecond : points2D)
		{
			float distance = Point3D::distance(point2DFirst, point2DSecond);
			if (distance < min && distance != 0)
			{
				min = distance;
				minPointFirst = point2DFirst;
				minPointSecond = point2DSecond;
			}
		}
	}
	std::cout << minPointFirst << minPointSecond;
	return 0;
}
