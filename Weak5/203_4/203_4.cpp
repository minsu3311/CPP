#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

struct Move {
    char dir;
};

class Puzzle {
private:
    int size;
    vector<vector<int>> board;
    vector<Move> moves;
    vector<vector<int>> initialBoard;

public:
    Puzzle(int n) : size(n) {
        board.resize(size, vector<int>(size));
        init();
    }

    void init() {
        int num = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = num++;
            }
        }
        board[size-1][size-1] = 0;

        shuffle();
        initialBoard = board;
    }

    void shuffle() {
        srand(time(0));
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        int x = size-1, y = size-1;
        for (int i = 0; i < 1000; i++) {
            int r = rand() % 4;
            int nx = x + dx[r];
            int ny = y + dy[r];

            if (nx>=0 && ny>=0 && nx<size && ny<size) {
                swap(board[x][y], board[nx][ny]);
                x = nx; y = ny;
            }
        }
    }

    void print() {
        for (auto &row : board) {
            for (auto &v : row) {
                if (v == 0) cout << " ";
                else cout << v << "\t";
            }
            cout << endl;
        }
    }

    bool move(char dir) {
        int x, y;
        for (int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j]==0){
                    x=i; y=j;
                }
            }
        }

        int nx = x, ny = y;
        if (dir=='w') nx++;
        else if (dir=='s') nx--;
        else if (dir=='a') ny++;
        else if (dir=='d') ny--;

        if (nx>=0 && ny>=0 && nx<size && ny<size) {
            swap(board[x][y], board[nx][ny]);
            moves.push_back({dir});
            return true;
        }
        return false;
    }

    bool isSolved() {
        int num = 1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==size-1 && j==size-1) return board[i][j]==0;
                if(board[i][j]!=num++) return false;
            }
        }
        return true;
    }

    // 저장 기능
    void save(string filename) {
        ofstream file(filename, ios::binary);
        file.write((char*)&size, sizeof(size));

        for (auto &row : board)
            file.write((char*)row.data(), sizeof(int)*size);

        int msize = moves.size();
        file.write((char*)&msize, sizeof(msize));
        file.write((char*)moves.data(), sizeof(Move)*msize);

        file.close();
    }

    // 불러오기
    void load(string filename) {
        ifstream file(filename, ios::binary);
        file.read((char*)&size, sizeof(size));

        board.resize(size, vector<int>(size));
        for (auto &row : board)
            file.read((char*)row.data(), sizeof(int)*size);

        int msize;
        file.read((char*)&msize, sizeof(msize));
        moves.resize(msize);
        file.read((char*)moves.data(), sizeof(Move)*msize);

        file.close();
    }

    // 리플레이
    void replay() {
        board = initialBoard;
        print();
        cout << "=== Replay Start ===\n";

        for (auto &m : moves) {
            move(m.dir);
            print();
            cout << "-------------\n";
        }
    }
};

int main() {
    int size;
    cout << "퍼즐 크기 선택 (3 / 4 / 5): ";
    cin >> size;

    Puzzle game(size);

    while (true) {
        game.print();

        if (game.isSolved()) {
            cout << "완성!\n";
            break;
        }

        cout << "이동 (w/a/s/d), 저장(sv), 불러오기(ld), 리플레이(rp): ";
        string cmd;
        cin >> cmd;

        if (cmd == "sv") {
            game.save("save.dat");
            cout << "저장됨\n";
        }
        else if (cmd == "ld") {
            game.load("save.dat");
            cout << "불러오기 완료\n";
        }
        else if (cmd == "rp") {
            game.replay();
        }
        else {
            game.move(cmd[0]);
        }
    }

    return 0;
}
