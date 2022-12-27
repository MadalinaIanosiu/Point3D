#pragma once
#include<string>
#include<cstdint>

enum class PointType : uint8_t {
	PunctFrontiera,
	PunctIntern,
	PunctExtern,
	None
};
PointType convertStrToType(const std::string& str);
std::string pointTypeToString(const PointType& type);




