#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

#define MAX_X 80
#define MAX_Y 40

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

// 최대 크기로 선언 (일부만 사용)
static int MineMapMask[MAX_Y][MAX_X];
static int MineMapLabel[MAX_Y][MAX_X];

static int nx, ny;
static int nBomb;

// 접근 함수
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }

inline bool isValid(int x, int y) {
    return (x >= 0 && x < nx && y >= 0 && y < ny);
}

inline bool isBomb(int x, int y) {
    return isValid(x,y) && label(x,y) == Bomb;
}

inline bool isEmpty(int x, int y) {
    return isValid(x,y) && label(x,y) == Empty;
}

// 주변 지뢰 수
int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx,yy) && label(xx,yy) == Bomb)
                count++;
    return count;
}

// 초기화
void init(int total) {
    srand((unsigned int)time(NULL));

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            mask(x,y) = Hide;
            label(x,y) = Empty;
        }

    nBomb = total;

    // 지뢰 배치
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(x,y) != Empty);

        label(x,y) = Bomb;
    }

    // 숫자 채우기
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x,y) == Empty)
                label(x,y) = countNbrBombs(x,y);
}

// 출력
void print() {
    system("cls"); // (리눅스면 "clear")

    cout << "발견: " << " / 전체: " << nBomb << endl;

    // 열 번호
    cout << "   ";
    for (int x = 0; x < nx; x++)
        printf("%2d", x);
    cout << endl;

    for (int y = 0; y < ny; y++) {
        printf("%2d ", y);

        for (int x = 0; x < nx; x++) {
            if (mask(x,y) == Hide)
                cout << "□";
            else if (mask(x,y) == Flag)
                cout << "★";
            else {
                if (isBomb(x,y))
                    cout << "*";
                else if (isEmpty(x,y))
                    cout << " ";
                else
                    cout << label(x,y);
            }
        }
        cout << endl;
    }
}

// 깃발 표시
void mark(int x, int y) {
    if (isValid(x,y) && mask(x,y) == Hide)
        mask(x,y) = Flag;
}

// 파기 (재귀)
void dig(int x, int y) {
    if (!isValid(x,y) || mask(x,y) != Hide) return;

    mask(x,y) = Open;

    if (label(x,y) == 0) {
        for (int yy = y - 1; yy <= y + 1; yy++)
            for (int xx = x - 1; xx <= x + 1; xx++)
                dig(xx, yy);
    }
}

// 게임 종료 체크
int checkDone() {
    int count = 0;

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            if (mask(x,y) != Open) count++;
            if (mask(x,y) == Open && isBomb(x,y))
                return -1; // 실패
        }

    return (count == nBomb) ? 1 : 0;
}

// 입력
bool getPos(int &x, int &y) {
    char cmd;
    cout << "\n좌표 입력 (형식: x y / f x y = 깃발): ";
    cin >> cmd;

    if (cmd == 'f') {
        cin >> x >> y;
        return true; // flag
    } else {
        x = cmd - '0';
        cin >> y;
        return false; // dig
    }
}

// 메인 게임
void playMineSweeper(int total) {
    init(total);

    int x, y, status;

    do {
        print();

        bool isFlag = getPos(x, y);

        if (isFlag)
            mark(x,y);
        else
            dig(x,y);

        status = checkDone();

    } while (status == 0);

    print();

    if (status < 0)
        cout << "\n실패: 지뢰 폭발!!!\n";
    else
        cout << "\n성공: 탐색 성공!!!\n";
}

// main
int main() {
    int total;

    cout << "<< Mine Sweeper >>\n";

    cout << "맵 크기 입력 (가로 세로): ";
    cin >> nx >> ny;

    if (nx > MAX_X) nx = MAX_X;
    if (ny > MAX_Y) ny = MAX_Y;

    cout << "지뢰 개수 입력: ";
    cin >> total;

    playMineSweeper(total);

    return 0;
}