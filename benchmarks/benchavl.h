#include "../include/AVLTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

void generate_int(AVLTree<int>* tree, std::ofstream& steam);
void generate_double(AVLTree<double>* tree, std::ofstream& steam);
void generate_str(AVLTree<std::string>* tree, std::ofstream& steam);
