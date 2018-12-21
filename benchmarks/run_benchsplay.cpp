//
// Created by skulish on 21.12.18.
//

#include "benchsplay.h"
#include <iostream>

int main(){
    SplayTree<int>* root = new SplayTree<int>();
    SplayTree<std::string>* root_str = new SplayTree<std::string>();
    SplayTree<double>* root_dbl = new SplayTree<double >();
    std::string header = "Type,Operation,Elems,Time,Tree,Value";

    std::ofstream out("splay_int.csv");
    out<<header<<std::endl;
    generate_int(root, out);
    out.close();

    std::ofstream out_dbl("splay_dbl.csv");
    out_dbl<<header<<std::endl;
    generate_double(root_dbl, out_dbl);
    out.close();

    std::ofstream out_str("splay_str.csv");
    out_str<<header<<std::endl;
    generate_str(root_str, out_str);
    out_str.close();

    return 0;
}