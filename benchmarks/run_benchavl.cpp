//
// Created by skulish on 21.12.18.
//

#include "benchavl.h"
#include <iostream>

int main(){
    AVLTree<int>* root = new AVLTree<int>();
    AVLTree<std::string>* root_str = new AVLTree<std::string>();
    AVLTree<double >* root_dbl = new AVLTree<double >();
    std::string header = "Type,Operation,Elems,Time,Tree,Value";

    std::ofstream out("avl_int.csv");
    out<<header<<std::endl;
    generate_int(root, out);
    out.close();

    std::ofstream out_dbl("avl_dbl.csv");
    out_dbl<<header<<std::endl;
    generate_double(root_dbl, out_dbl);
    out.close();

    std::ofstream out_str("avl_str.csv");
    out_str<<header<<std::endl;
    generate_str(root_str, out_str);
    out_str.close();

    return 0;
}

