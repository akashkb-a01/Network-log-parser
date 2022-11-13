#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ifstream inFile("./test.txt");
    ofstream outFile("./out.csv");
    string line;
    outFile << "PktNumber,Appearance,Direction,Type,Component,Edge,Filter,OriginalSize,LoggedSize" << '\n';
    // char delim[] = ", ";
    string m[] = {"PktNumber","Appearance","Direction","Type","Component","Edge","Filter","OriginalSize","LoggedSize"};
    while (inFile)
    {
       string token;// = strtok(line, delim);
       string t = "";
       int pos = 0;
       while(getline(inFile, line)){
        pos = 0;
        t = "";
        // cout << token << endl;
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
        // token = strtok(NULL, delim);
       }

    //    outFile << line << endl;
    }

    outFile.close();
    inFile.close();

    return 0;
} 