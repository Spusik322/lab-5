#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool letters(string& str){
    for (char ch : str) {
        if (!isalpha(ch)){
            return false;
        }
    }
    return true;
}
bool digits(string& str){
    for (char ch : str){
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;
}
void raspred (istream &in, fstream &out1, fstream &out2){
    string stroka;
    while(getline(in, stroka)){
        if (letters(stroka)){
            out2 << stroka << endl;
        }
        if (digits(stroka)){
            out1 << stroka << endl;
        }
    }
}
void pr(istream &file){
    string stroka;
    file.seekg(0, ios::beg);
    while(getline(file, stroka)){
        cout << stroka << endl;
    }
}
int main(){
    auto &in_fname = "files/INPUT.txt";
    ifstream in;
    fstream out1("files/out1.txt", ios::trunc | ios_base::in | ios_base::out);
    fstream out2("files/out2.txt", ios::trunc | ios_base::in | ios_base::out);
    int b;
    cout << "Введите 1 если хотите увидеть входной файл, 0 если нет " << endl;
    cin >> b;
    if (b == 1){
        in.open(in_fname);
        pr(in);
        in.close();
    }
    in.open(in_fname);
    raspred (in, out1, out2);
    in.close();
    cout << "Введите 0 если хотите увидеть выходной файл со словами, 1 если с цифрами и 3 если не хотите видеть, 4 если оба ";
    cin >> b;
    if (b == 0){
        pr(out2);
    }if (b == 1){
        pr(out1);
    }if (b == 4){
        pr(out2);
        pr(out1);
    }
    out1.close();
    out2.close();
}