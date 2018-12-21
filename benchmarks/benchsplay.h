#include "../include/SplayTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

void generate_int(SplayTree<int>* tree, std::ofstream& steam);
void generate_double(SplayTree<double>* tree, std::ofstream& steam);
void generate_str(SplayTree<std::string>* tree, std::ofstream& steam);
