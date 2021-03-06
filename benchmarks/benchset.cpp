#include "benchset.h"

using namespace std::chrono;

void generate_int(std::set<int>* tree, std::ofstream& steam){
    int num = 5000000;
    for (int i = 0; i<num; i++){
        auto start = high_resolution_clock::now();

        //tree.Insert(i);
        tree->insert(i);


        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        steam<<"int,"<<"add,"<<i<<","<<duration.count()<<",Set,"<<i<<std::endl;
        auto tstart = high_resolution_clock::now();

        //tree.Find(tree.GetRoot(), i);
        tree->find(i);

        auto tstop = high_resolution_clock::now();
        auto tduration = duration_cast<nanoseconds>(tstop - tstart);
        steam<<"int,"<<"find,"<<i<<","<<tduration.count()<<",Set,"<<i<<std::endl;
    }

    for (int i = 0; i<num; i++){
        auto start = high_resolution_clock::now();

        //tree.Insert(i);
        //tree->deleteRecord(i);
        tree->erase(i);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        steam<<"int,"<<"delete,"<<i<<","<<duration.count()<<",Set,"<<i<<std::endl;
    }
}


void generate_double(std::set<double>* tree, std::ofstream& steam){
    int num = 5000000;
    double val = 0.0;
    for (int i = 0; i<num; i++){
        auto start = high_resolution_clock::now();
        //tree->insertRecord(val);
        tree->insert(val);
        //tree.Insert(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        steam<<"double,"<<"add,"<<i<<","<<duration.count()<<",Set,"<<val<<std::endl;
        start = high_resolution_clock::now();
        //tree->findRecord(val);

        //tree.Find(tree.GetRoot(), i);
        tree->find(val);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        steam<<"double,"<<"find,"<<i<<","<<duration.count()<<",Set,"<<val<<std::endl;
        val+=0.0555123;
    }
    val = 0.0;
    for (int i = 0; i<num; i++){
        auto start = high_resolution_clock::now();
        //tree->deleteRecord(val);
        tree->erase(val);
        //tree.Insert(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        steam<<"double,"<<"delete,"<<i<<","<<duration.count()<<",Set,"<<val<<std::endl;
        val+=0.0555123;
    }
}

void generate_str(std::set<std::string>* tree, std::ofstream& steam){
    int count = 0;
    std::string* letter_arr = new std::string[10]{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i =0; i<10; i++){
        for (int j =0; j<10; j++){
            for (int k =0; k<10; k++){
                for (int l =0; l<10; l++){
                    for (int m =0; m<10; m++){
                        for (int n=0; n<10; n++){
                            for (int z=0; z<5; z++) {
                                std::string final_str =
                                        letter_arr[i] + letter_arr[j] + letter_arr[k] + letter_arr[l] +
                                        letter_arr[m] + letter_arr[n] + letter_arr[z];

                                auto start = high_resolution_clock::now();
                                //tree->insertRecord(final_str);
                                tree->insert(final_str);
                                auto stop = high_resolution_clock::now();
                                auto duration = duration_cast<nanoseconds>(stop - start);
                                steam << "string," << "add," << count << "," << duration.count() << ",Set,"
                                      << final_str
                                      << std::endl;
                                start = high_resolution_clock::now();

                                //tree->findRecord(final_str);
                                tree->find(final_str);
                                //tree.Find(tree.GetRoot(), final_str);
                                stop = high_resolution_clock::now();
                                duration = duration_cast<nanoseconds>(stop - start);
                                steam << "string," << "find," << count << "," << duration.count() << ",Set,"
                                      << final_str << std::endl;
                                count++;

                            }
                        }
                    }
                }
            }
        }
    }

    count = 0;
    for (int i =0; i<10; i++){
        for (int j =0; j<10; j++){
            for (int k =0; k<10; k++){
                for (int l =0; l<10; l++){
                    for (int m =0; m<10; m++){
                        for (int n=0; n<10; n++){
                            for (int z=0; z<5; z++) {
                                std::string final_str =
                                        letter_arr[i] + letter_arr[j] + letter_arr[k] + letter_arr[l] +
                                        letter_arr[m] + letter_arr[n] + letter_arr[z];

                                auto start = high_resolution_clock::now();
                                tree->erase(final_str);
                                auto stop = high_resolution_clock::now();
                                auto duration = duration_cast<nanoseconds>(stop - start);
                                steam << "string," << "delete," << count << "," << duration.count() << ",Set,"
                                      << final_str
                                      << std::endl;
                                count++;

                            }
                        }
                    }
                }
            }
        }
    }
}