#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

class WordPair {
public:
    string eng;
    string kor;

    WordPair() {}
    WordPair(string e, string k) {
        eng = e;
        kor = k;
    }
};

class MyDic {
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() { nWords = 0; }

    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS)
            words[nWords++] = WordPair(eng, kor);
    }

    inline void load(string filename) {
        ifstream fin(filename);
        string eng, kor;
        while (fin >> eng >> kor)
            add(eng, kor);
        fin.close();
    }

    inline void store(string filename) {
        ofstream fout(filename);
        for (int i = 0; i < nWords; i++)
            fout << words[i].eng << " " << words[i].kor << endl;
        fout.close();
    }

    inline void print() {
        for (int i = 0; i < nWords; i++)
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
    }

    inline string getEng(int id) {
        return (id >= 0 && id < nWords) ? words[id].eng : "";
    }

    inline string getKor(int id) {
        return (id >= 0 && id < nWords) ? words[id].kor : "";
    }
};

int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");

    dic.print();

    dic.store("dic.txt");

    MyDic dic2;
    dic2.load("dic.txt");

    dic2.print();

    return 0;
}