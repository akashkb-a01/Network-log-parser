#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 3)
        cout << "Error: Too few arguments. Pass input and output file..." << endl ;
    string inpfile = argv[1];
    string outpfile = argv[2];
    ifstream inFile(inpfile);
    ofstream outFile(outpfile);
    string line;
    outFile << "PktNumber,Appearance,Direction,Type,Component,Edge,Filter,OriginalSize,LoggedSize" << '\n';

    string m[] = {"PktNumber","Appearance","Direction","Type","Component","Edge","Filter","OriginalSize","LoggedSize"};
    while (inFile)
    {
       string token;
       string t = "";
       int pos = 0;
       while(getline(inFile, line)){
        pos = 0;
        t = "";
        for(int i=0; i<9; i++){
            size_t fou = line.find(m[i], pos);
            if(fou != string::npos){
                pos = fou;
                pos = line.find(", ", pos);
                t += line.substr(fou + m[i].length() + 1, pos - (fou + m[i].length() + 1));
            }
            if(i!=8)
                t += ",";
        }
        if(t != ",,, 0,,,,," && t != ",,,,,,,,")
            outFile << t << endl;
       }
    }

    outFile.close();
    inFile.close();

    return 0;
} 
