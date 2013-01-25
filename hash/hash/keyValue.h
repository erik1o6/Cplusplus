// KeyValuePair.h- header file
// Written by: Erik Arfvidson

#pragma once

//struct for key
template<typename KeyType, typename ValueType>
struct KeyValuePair
{
	KeyType Key;
	ValueType Value;


};
//print keys
template <typename KeyType, typename ValueType>
//ostream

static std::ostream& operator << (std::ostream& out, KeyValuePair<KeyType,ValueType>& pair)
{
	out << "(" << pair.Key << ", " << pair.Value << ")";
	return out;
}