#include "../include/DecartTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

void generate_int(DecartTree<int>* tree, std::ofstream& steam);
void generate_double(DecartTree<double>* tree, std::ofstream& steam);
void generate_str(DecartTree<std::string>* tree, std::ofstream& steam);
