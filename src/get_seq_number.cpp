#include <iostream>
#include "fastaf.h"

using namespace std;

int usage() {
    std::cerr << "Usage: ./getseqno <input.fa>" << std::endl;
    return 1;
}

int main(int argc, char* argv[]){
    if(argc == 2) {
        string path = argv[1];
        fastaf f1(path);
        int number=f1.get_number_seqs();
        cout << number << endl;
    } else {
        return usage();
    }
    return 0;
}