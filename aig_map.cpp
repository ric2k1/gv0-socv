//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

struct aig_map{
    int var;
    string name;
};

void mapping(char *in_filename, ofstream& out_file){
    vector<aig_map> input, output;
    string line, buf;
    stringstream ss;
    ifstream in_file(in_filename);

    //get num_PI num_PO
    int nPI, nPO;
    getline(in_file, line);
    ss<<line; ss>>buf;
    ss<<line; ss>>buf;
    ss<<line; ss>>buf;
    //cout<<buf<<endl;
    nPI = stoi(buf);
    ss<<line; ss>>buf;
    ss<<line; ss>>buf;
    //cout<<buf<<endl;
    nPO = stoi(buf);

    //get PI_var
    for(int i = 0; i < nPI; i++){
        getline(in_file, line);
        aig_map temp;
        //cout<<"PI "<<i<<" "<<line<<endl;
        temp.var = stoi(line);
        input.push_back(temp);
    }

    //get PO_var
    for(int i = 0; i < nPO; i++){
        getline(in_file, line);
        aig_map temp;
        //cout<<"PO "<<i<<" "<<line<<endl;
        temp.var = stoi(line);
        output.push_back(temp);
    }

    while(line.find("i") == string::npos){
        getline(in_file, line);
    }

    line = line.substr(line.find(" ")+1);
    input[0].name = line;
    for(int i = 1; i < nPI; i++){
        getline(in_file, line);
        line = line.substr(line.find(" ")+1);
        input[i].name = line;
    }

    for(int i =0; i < nPO; i++){
        getline(in_file, line);
        line = line.substr(line.find(" ")+1);
        output[i].name = line;
    }

    for(int i = 0; i < nPI; i++){
        out_file<<in_filename[strlen(in_filename)-5]<<" input "<<input[i].name<<" "<<input[i].var<<endl;
    }
    for(int i = 0; i < nPO; i++){
        out_file<<in_filename[strlen(in_filename)-5]<<" output "<<output[i].name<<" "<<output[i].var<<endl;
    }
    in_file.close();
}

int main(int argc, char *argv[]){
    char *in_filename1 = argv[1], *in_filename2 = argv[2], *out_filename = argv[3];
    ofstream out_file(out_filename);
    mapping(in_filename1, out_file);
    mapping(in_filename2, out_file);
    out_file.close();
}