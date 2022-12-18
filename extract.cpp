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
    outFile << "PktNumber,Appearance,Direction,Type,Component,Edge,Filter,OriginalSize,LoggedSize,Source,Destination" << '\n';
    string m[] = {"PktNumber","Appearance","Direction","Type","Component","Edge","Filter","OriginalSize","LoggedSize","Source","Destination"};
    while (inFile)
    {
       string type;
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
                if(i == 3)
                    type = line.substr(fou + m[i].length() + 1, pos - (fou + m[i].length() + 2 ));
                t += line.substr(fou + m[i].length() + 1, pos - (fou + m[i].length() + 1));
            }
            t += ",";
        }
        if(t != ",,, 0,,,,,," && t != ",,,,,,,,,"){
            if(type == "IP"){
                int pos, fou;
                getline(inFile, line);
                fou = line.find("ip: ", 0);
                pos = fou + 3;
                fou = line.find(">", pos);
                t += (line.substr(pos + 1, fou - pos - 2) + ",");
                pos = fou + 1;
                fou = line.find(": ", pos);
                t += line.substr(pos + 1, fou - pos - 1);
            }
            else if(type == "Ethernet"){
                int pos, fou;
                getline(inFile, line);
                fou = line.find(": ", 0);
                pos = fou + 1;
                fou = line.find(">", pos);
                t += (line.substr(pos + 1, fou - pos - 2) + ",");
                pos = fou + 1;
                fou = line.find(": ", pos);
                t += line.substr(pos + 1, fou - pos - 1);
            }

            else if(type == "WiFi"){
                int pos, fou;
                getline(inFile, line);
                fou = line.find("SA:", 0);
                pos = fou + 2;
                fou = line.find(" ", pos);
                t += (line.substr(pos + 1, fou - pos - 1) + ",");
                fou = line.find("DA:", 0);
                pos = fou + 2;
                fou = line.find(" ", pos);
                t += line.substr(pos + 1, fou - pos - 1);
            }
            else 
            t += ",";
            outFile << t << endl;
        }
       }
    }

    outFile.close();
    inFile.close();

    return 0;
} 
