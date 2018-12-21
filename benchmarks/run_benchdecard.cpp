//
// Created by skulish on 21.12.18.
//

#include "benchdecard.h"
#include <iostream>

int main(){
    DecartTree<int>* root = new DecartTree<int>();
    DecartTree<std::string>* root_str = new DecartTree<std::string>();
    DecartTree<double>* root_dbl = new DecartTree<double >();
    std::string header = "Type,Operation,Elems,Time,Tree,Value";

    std::ofstream out("decart_int.csv");
    out<<header<<std::endl;
    generate_int(root, out);
    out.close();

    std::ofstream out_dbl("decart_dbl.csv");
    out_dbl<<header<<std::endl;
    generate_double(root_dbl, out_dbl);
    out.close();

    std::ofstream out_str("decart_str.csv");
    out_str<<header<<std::endl;
    generate_str(root_str, out_str);
    out_str.close();

    return 0;
}

