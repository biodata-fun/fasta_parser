#include <iostream>
#include "fastaf.h"
#include <filesystem>
#include <map>

using namespace std;

int usage() {
    std::cerr << "Usage: ./getseq <input.fa> <seq_id>" << std::endl;
    return 1;
}

int main(int argc, char* argv[]){
    // Create object
    if(argc == 3) {
        string path = argv[1];
        string id = argv[2];
        string index_f = path+".fai";
        fastaf f1(path);
        map<string, int> index; 
        index=f1.read_index(index_f);
        f1.get_seq(index, id);
    } else {
        return usage();
    }
    return 0;
}