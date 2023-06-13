//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

constexpr unsigned int str2int(const char* str, int h = 0){
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

int main(int argc, char *argv[]){
    char *in_filename = argv[1];
    string out_filename = argv[2], line, buf;
    ifstream in_file(in_filename);
    cout<<out_filename<<endl;
    ofstream out_file(out_filename);
    //cerr<<in_filename<<" "<<tag<<endl;

    //Module
    //read
    std::getline(in_file, line);
    if(line.find("module") == string::npos){
        cerr<<"module not found"<<endl;
        return 0;
    }
    buf = line;
    while (line.find(";") == string::npos){
        std::getline(in_file, line);
        buf += line;
    }
    //replace name
    int pos = buf.find("("), cut_pos;
    while(1) {
		pos = buf.find(" ", pos) + 1;
		if(pos == -1){
            cerr<<"file format error"<<endl<<buf<<endl;
            return 0;
        };

		//buf.insert(pos, tag);
        pos = buf.find(",", pos);
		if(pos == -1){
            break;
        };
	}
    out_file<<buf<<endl;
    buf.clear();

    //Input
    //read
    std::getline(in_file, line);
    if(line.find("input") == string::npos){
        cerr<<"input not found"<<endl;
        return 0;
    }
    buf = line;
    while (line.find(";") == string::npos){
        std::getline(in_file, line);
        buf += line;
    }
    //replace name
    pos = buf.find("input");
    while(1) {
		pos = buf.find(" ", pos) + 1;
		if(pos == -1){
            cerr<<"file format error"<<endl<<buf<<endl;
            return 0;
        };

		//buf.insert(pos, tag);
        pos = buf.find(",", pos);
		if(pos == -1){
            break;
        };
	}
    out_file<<buf<<endl;
    buf.clear();

    //Output
    //read
    std::getline(in_file, line);
    if(line.find("output") == string::npos){
        cerr<<"output not found"<<endl;
        return 0;
    }
    buf = line;
    while (line.find(";") == string::npos){
        std::getline(in_file, line);
        buf += line;
    }
    //replace name
    pos = buf.find("output");
    while(1) {
		pos = buf.find(" ", pos) + 1;
		if(pos == -1){
            cerr<<"file format error"<<endl<<buf<<endl;
            return 0;
        };

		//buf.insert(pos, tag);
        pos = buf.find(",", pos);
		if(pos == -1){
            break;
        };
	}
    out_file<<buf<<endl;
    buf.clear();

    //Wire
    //read
    std::getline(in_file, line);
    if(line.find("wire") == string::npos){
        cerr<<"wire not found"<<endl;
        return 0;
    }
    buf = line;
    while (line.find(";") == string::npos){
        std::getline(in_file, line);
        buf += line;
    }
    //replace name
    pos = buf.find("wire");
    while(1) {
		pos = buf.find(" ", pos) + 1;
		if(pos == -1){
            cerr<<"file format error"<<endl<<buf<<endl;
            return 0;
        };

		//buf.insert(pos, tag);
        pos = buf.find(",", pos);
		if(pos == -1){
            break;
        };
	}
    out_file<<buf<<endl;
    buf.clear();

    //Gate
    //read
    while(1){
        std::getline(in_file, buf);
        if(buf.find("endmodule") != string::npos){
            out_file<<"endmodule"<<endl;
            return 0;
        }

        //assign gate including (and, or, nand, nor, not, xor, xnor, buf)
        pos = buf.find_first_not_of(" ");
        string gate_type = buf.substr(pos, (buf.find(" ", pos) - pos)), var1, var2, var3;
        pos = buf.find("(");

        //var1
        pos = buf.find(" ", pos) + 1;
        cut_pos = buf.find_first_of(" ", pos) - pos;
        if(pos == -1){
            cerr<<"var1 format error"<<endl<<buf<<endl;
            return 0;
        };
        var1 = buf.substr(pos, cut_pos);
        //if(var1 != "1'b0" && var1 != "1'b1") var1 = tag + var1;

        //var2
        pos = buf.find(", ", pos) + 2;
        cut_pos = buf.find_first_of(" ", pos) - pos;
        if(pos == -1){
            cerr<<"var2 format error"<<endl<<buf<<endl;
            return 0;
        };
        var2 = buf.substr(pos, cut_pos);
        //if(var2 != "1'b0" && var2 != "1'b1") var2 = tag + var2;

        //var3
        pos = buf.find(", ", pos);
        if(pos != -1){
            pos += 2;
            cut_pos = buf.find_first_of(" ", pos) - pos;
            var3 = buf.substr(pos, cut_pos);
            //if(var3 != "1'b0" && var3 != "1'b1") var3 = tag + var3;
        }

        stringstream ss;
        switch (str2int(gate_type.c_str()))
        {
        case str2int("and"):
            ss<<"assign "<<var1<<" = "<<var2<<" & "<<var3<<";\n";
            break;

        case str2int("or"):
            ss<<"assign "<<var1<<" = "<<var2<<" | "<<var3<<";\n";
            break;

        case str2int("nand"):
            ss<<"assign "<<var1<<" = ~("<<var2<<" & "<<var3<<");\n";
            break;
            
        case str2int("nor"):
            ss<<"assign "<<var1<<" = ~("<<var2<<" | "<<var3<<");\n";
            break;
            
        case str2int("not"):
            ss<<"assign "<<var1<<" = ~"<<var2<<";\n";
            break;
            
        case str2int("xor"):
            ss<<"assign "<<var1<<" = "<<var2<<" ^ "<<var3<<";\n";
            break;
            
        case str2int("xnor"):
            ss<<"assign "<<var1<<" = ~("<<var2<<" ^ "<<var3<<");\n";
            break;
            
        case str2int("buf"):
            ss<<"assign "<<var1<<" = "<<var2<<";\n";
            break;

        default:
            cerr<<"gate type \""<<gate_type<<"\" not found"<<endl;
            return 0;
            break;
        }
        //cerr<<ss.str();
        out_file<<ss.str();
    }
}