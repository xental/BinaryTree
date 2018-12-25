#include "benchset.h"

int main(){
    std::set<int>* root = new std::set<int>();
    std::set<std::string>* root_str = new std::set<std::string>();
    std::set<double>* root_dbl = new std::set<double >();
    std::string header = "Type,Operation,Elems,Time,Tree,Value";

    std::ofstream out("set_int.csv");
    out<<header<<std::endl;
    generate_int(root, out);
    out.close();

    std::ofstream out_dbl("set_dbl.csv");
    out_dbl<<header<<std::endl;
    generate_double(root_dbl, out_dbl);
    out.close();

    std::ofstream out_str("set_str.csv");
    out_str<<header<<std::endl;
    generate_str(root_str, out_str);
    out_str.close();

    return 0;
}
