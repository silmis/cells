#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

class Grid;

typedef std::string string;
typedef std::vector<string> strVector;
typedef std::unordered_map<string, string> rulemap;
typedef std::unique_ptr<Grid> gridPointer;
typedef std::vector<gridPointer> lifetime;

#endif
