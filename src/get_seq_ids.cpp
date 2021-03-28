#include <iostream>
#include "fastaf.h"

using namespace std;

int usage() {
    std::cerr << "Usage: ./getids <input.fa>" << std::endl;
    return 1;
}

int main(int argc, char* argv[]){
    if(argc == 2) {
        string path = argv[1];
        fastaf f1(path);
        f1.get_seq_ids();
    } else {
        return usage();
    }
    return 0;
}