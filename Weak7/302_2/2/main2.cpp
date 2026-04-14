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
    WordPair words[MAXWORDS]; // 저장된 단어 배열
    int nWords;               // 현재 등록된 단어 수

public:
    MyDic() { nWords = 0; }

    // 하나의 단어 추가
    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords++] = WordPair(eng, kor);
        }
    }

    // 파일에서 단어 읽기
    inline void load(string filename) {
        ifstream fin(filename);
        string eng, kor;

        while (fin >> eng >> kor) {
            add(eng, kor);
        }

        fin.close();
    }

    // 파일에 저장
    inline void store(string filename) {
        ofstream fout(filename);

        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    // 화면 출력
    inline void print() {
        for (int i = 0; i < nWords; i++) {
            cout << i << ": " << words[i].eng
                 << " - " << words[i].kor << endl;
        }
    }

    // 영어 반환
    inline string getEng(int id) {
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    // 한글 반환
    inline string getKor(int id) {
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }
};