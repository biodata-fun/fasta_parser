#include <iostream>
#include "fastaf.h"
#include <filesystem>

using namespace std;

int usage() {
    std::cerr << "Usage: ./makeix <input.fa>" << std::endl;
    return 1;
}

int main(int argc, char* argv[]){
    // Create object
    if(argc == 2) {
        string path = argv[1];
        filesystem::path p(path);
        string filename = p.filename();
        string index_f = filename+".fai";
        fastaf f1(path);
        f1.make_index(index_f);
    } else {
        return usage();
    }
    return 0;
}