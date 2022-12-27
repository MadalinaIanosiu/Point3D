#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"PointType.h"

class Point3D
{
private:
	float m_x, m_y, m_z;
	std::string m_name;
	PointType m_type;
public:
	Point3D() = default;
	Point3D(std::string name, float x, float y, float z, PointType type);
	Point3D(const Point3D& pct);
	void translatie(float x, float y); //translatie
	void setType(PointType type); //setter
	std::pair<float, float> conversie(const Point3D& pct); // conversie
	friend std::ostream& operator<<(std::ostream& out, const Point3D& pct);
	friend std::istream& operator>>(std::istream& in, Point3D& pct);
	std::string GetName() const;
	float GetY() const;
	float GetX() const;
	float GetZ() const;
	PointType GetType() const;
	static float valoareMediePuncte(const std::vector<Point3D> vec);
	static float distance(const Point3D& first, const Point3D& second);
};



