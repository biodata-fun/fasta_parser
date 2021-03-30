#include "fastaf.h"
#include<iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>


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
                // get the identifier only and ignore optional description
                stringstream s(line);
                string id;
                s >> id;
                long long int position;
                position=fio.tellg();
                position= position-(line.length()+2);
                ix_f<<id<<" "<<position<<endl;
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
    int pos;
    if(ix.find(id)==ix.end()) {
        cout<< "I could not find an entry with id " << id << " in the index"<<endl;
        exit(EXIT_FAILURE);
    } else {
        pos=ix[id];
    }
    
    fstream fin;
    fin.open(path, ios::in);

    if (fin.is_open())
    {   
        // move the pointer to the right position from begginning
        fin.seekg(pos, ios::beg);
        bool is_seen=false;
        while (fin) {
            string line;
            getline(fin, line);
            if (line[0]=='>' && is_seen==false)
            {
                cout << line << endl;
                is_seen=true;
            } else if (line[0]=='>' && is_seen==true) {
                break;
            } else {
                cout << line << endl;
            }
        }
    }
    else
        cout<< "Error opening the file:"<< path << endl;
}

int fastaf::get_number_seqs()
{
    /*
    Function to get the number of seqs in a Fasta file

    Returns
    -------
    int : Number of seqs
    */
    fstream fin;
    fin.open(path, ios::in);
    string line; 

    int seq_count=0;
    if (fin.is_open())
    {
        while ( getline (fin, line) )
        {
            if (line[0]=='>')
                seq_count++;
        }
        fin.close();
    } else
        cout<< "Error opening the file:"<< path << endl;
    
    return seq_count;
}

void fastaf::get_seq_ids()
{
    /*
    Function to get the ids in a Fasta file
    */
    fstream fin;
    fin.open(path, ios::in);
    string line; 

    if (fin.is_open())
    {
        while ( getline (fin, line) )
        {
            if (line[0]=='>')
                cout<< line <<endl;
        }
        fin.close();
    } else
        cout<< "Error opening the file:"<< path << endl;   
}


