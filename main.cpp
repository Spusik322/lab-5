#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("main.py");
    fout << "print('Use C++ instead :pray')" << endl;
    fout.close();

    ofstream fout2("main.py", ios::app);
    fout2 << "print('or at least Java')" << endl;
    fout2.close();

    
    ifstream fin("main.cpp");
    // ifstream fin("/home/merilian/cpp-university/09.18.2024/main.cpp");
    // ifstream fin("../09.18.2024/main.cpp");
    string line;
    while(getline(fin, line)){
        cout << line << endl;
    }
    fin.close();

    ifstream fin2("out");
    int a, b;
    double c;
    fin2 >> a >> b >> c;
    cout << a << "\t" << b << "\t" << c << "\n";
    fin2.close(); 
}