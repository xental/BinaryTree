#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <set>


void generate_int(std::set<int>* tree, std::ofstream& steam);
void generate_double(std::set<double>* tree, std::ofstream& steam);
void generate_str(std::set<std::string>* tree, std::ofstream& steam);
