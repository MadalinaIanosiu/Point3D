#include "PointType.h"

PointType convertStrToType(const std::string& str)
{
	if (str == "PunctFrontiera") {
		return PointType::PunctFrontiera;
	}
	else if (str == "PunctIntern")
	{
		return PointType::PunctIntern;
	}
	else if (str == "PunctExtern") {
		return  PointType::PunctExtern;
	}
	throw std::exception{ "UNKNOWN TYPE" };
}
std::string pointTypeToString(const PointType& type)
{
	switch (type)
	{
	case  PointType::PunctFrontiera:
		return "PunctFrontiera";
	case PointType::PunctIntern:
		return  "PunctIntern";
	case PointType::PunctExtern:
		return "PunctExtern";
	default:
		break;
	}
}
