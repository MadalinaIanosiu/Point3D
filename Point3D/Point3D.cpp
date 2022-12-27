#include "Point3D.h"
#include "PointType.h"

Point3D::Point3D(std::string name, float x, float y, float z, PointType type) : //constr cu parametrii
	m_name{ name }, m_x{ x }, m_y{ y }, m_z{ z }, m_type{ type }
{}

Point3D::Point3D(const Point3D& pct) : //constr de copiere
	m_name{ pct.m_name }, m_x{ pct.m_x }, m_y{ pct.m_y }, m_z{ pct.m_z }, m_type{ pct.m_type }
{}

void Point3D::setType(PointType type)
{
	m_type = type;
}

void Point3D::translatie(float x, float y)
{
	m_x += x;
	m_y += y;
}

std::pair<float, float>Point3D::conversie(const Point3D& pct)
{
	int P = 500;
	float x_2D = pct.m_x * (P / P - pct.m_z);
	float y_2D = pct.m_y * (P / P - pct.m_z);
	return { x_2D, y_2D };
}

std::string Point3D::GetName() const
{
	return m_name;
}

float Point3D::GetY() const
{
	return m_y;
}

float Point3D::GetX() const
{
	return m_x;
}

float Point3D::GetZ() const
{
	return m_z;
}

PointType Point3D::GetType() const
{
	return m_type;
}

float Point3D::valoareMediePuncte(const std::vector<Point3D> points)
{
	float avg = 0.0f;
	for (const auto& point : points)
	{
		avg += point.m_x + point.m_y + point.m_z;
	}
	avg /= (points.size() * 3);
	return avg;
}

std::ostream& operator<<(std::ostream& out, const Point3D& pct)
{
	out << pct.m_name << " " << pct.m_x << " " << pct.m_y << " " << pct.m_z << " " <<
		pointTypeToString(pct.m_type);
	return out;
}

std::istream& operator>>(std::istream& in, Point3D& pct)
{
	std::string s;
	in >> pct.m_name >> pct.m_x >> pct.m_y >> pct.m_z >> s;
	pct.m_type = convertStrToType(s);
	return in;
}

float Point3D::distance(const Point3D& first, const Point3D& second)
{
	return sqrt(pow(second.m_x - first.m_x, 2) +
		pow(second.m_y - first.m_y, 2));
}
