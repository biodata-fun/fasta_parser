#include "fastaf.h"
#include<iostream>
#include <fstream>
#include <map>
#include <sstream>

/*
* Constructor
* Parameter
* ---------
* p : str
*     Path to Fasta file
*/
fastaf::fastaf(string p){
    path = p;
}
 
// Destructor
fastaf::~fastaf(){
}

map<string, int> fastaf::read_index(string indexf)
{
    /*
    Function to read in the index file

    Parameters
    ----------
    indexf : string
             Path to file with index
    Returns
    -------
    map<string, int>
    */
    fstream fio; 
    fio.open(indexf, ios::in);
    string str;
    map<string, int> m; 
    if (fio.is_open())
    { 
        while (getline(fio, str))
        {
            if (str.empty())
            {
                continue;
            }
            else
            {
                stringstream s(str);
                int pos;
                string id;
                s >> id >> pos;
                m.insert(make_pair(id, pos));
            }
        }
        fio.close();
    }
    else
        cout<< "Error opening the file:"<< indexf << endl;  
    return m;
}

void fastaf::make_index(string indexf)
{
    /*
    Function to generate the index for sequences
    in the file

    Parameters
    ----------
    indexf : string
             Name of the index
    */
    fstream fio; 
    string line; 
    fio.open(path, ios::in);

    fstream ix_f;
    ix_f.open(indexf, ios::out);
    if (fio.is_open())
    { 
        // Execute a loop If file successfully Opened 
        while (fio) { 
            // Read line by line 
            getline(fio, line);
            if( line[0]=='>')
            {
                line.erase(0, 1);
                int position=fio.tellg();
                ix_f<<line<<" "<<position<<endl;
                continue;
            }
        }
        fio.close();
    } else
        cout<< "Error opening the file:"<< indexf << endl;
}

void fastaf::get_seq(map<string, int> ix, string id)
{
    /*
    Function to get a certain sequence from the Fasta file

    Parameters
    ----------
    ix : map<string, int> with index
    id : id of sequence to fetch
    */
    int pos = ix[id];

    fstream fin;
    fin.open(path, ios::in);

    cout << ">" << id << endl;
    if (fin.is_open())
    {   
        // move the pointer to 6th position from begginning
        fin.seekg(pos, ios::beg);
        while (fin) {
            string line;
            getline(fin, line);
            if (line[0]=='>')
            {
                break;
            } else {
                cout << line << endl;
            }
        }
    }
    else
        cout<< "Error opening the file:"<< path << endl;
}