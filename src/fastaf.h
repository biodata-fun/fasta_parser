#ifndef FASTAF_H
#define FASTAF_H

#include<iostream>
#include <map>

using namespace std;

class fastaf{
    private:
        string path;
    public: 
        fastaf(string p);
        ~fastaf();
        void make_index(string indexf);
        map<string, int> read_index(string indexf);
        void get_seq(map<string, int> m, string id);
};
#endif