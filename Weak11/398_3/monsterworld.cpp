#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
using namespace std;

#define MAXMONS 8

// ======================================================
// Canvas 클래스
// ======================================================
class Canvas {
    int width, height;
    char display[30][30];

public:
    Canvas(int w = 20, int h = 10) {
        width = w;
        height = h;
        clear();
    }

    void clear(char ch = '.') {
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                display[y][x] = ch;
    }

    void draw(int x, int y, char ch) {
        display[y][x] = ch;
    }

    void print(const char* title = "") {
        system("cls");

        cout << title << endl;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                cout << display[y][x] << ' ';
            cout << endl;
        }
    }
};

// ======================================================
// (1) Monster 클래스에 에너지 속성 추가
// (2) getEnergy() 함수 추가
// (4) 정적 멤버 변수 추가
// ======================================================
class Monster {
protected:
    string name;
    char shape;
    int x, y;

    // (1) 에너지 변수 추가
    int nEnergy;

    // (4) 전체 몬스터 수 저장
    static int count;

public:
    Monster(
        string n = "몬스터",
        char s = '@',
        int px = 0,
        int py = 0,
        int energy = 100
    ) {
        name = n;
        shape = s;
        x = px;
        y = py;

        // (1)
        nEnergy = energy;

        // (4)
        count++;
    }

    virtual ~Monster() {

        // (4)
        count--;
    }

    // (4)
    static void printCount() {
        cout << "전체 몬스터 수 = "
             << count << endl;
    }

    // (2) getEnergy() 함수
    int getEnergy() {
        return nEnergy;
    }

    virtual void move(int maxx, int maxy) {

        int dx = (rand() % 3) - 1;
        int dy = (rand() % 3) - 1;

        x += dx;
        y += dy;

        if (x < 0) x = 0;
        if (y < 0) y = 0;

        if (x >= maxx) x = maxx - 1;
        if (y >= maxy) y = maxy - 1;

        // (1) 이동 시 에너지 감소
        nEnergy--;
    }

    virtual void draw(Canvas& canvas) {
        canvas.draw(x, y, shape);
    }

    virtual void print() {
        cout << name
             << "\tX:" << x
             << "\tY:" << y
             << "\tE:" << nEnergy
             << endl;
    }
};

// (4) 정적 변수 초기화
int Monster::count = 0;

// ======================================================
// MonsterWorld 클래스
// ======================================================
class MonsterWorld {

    int xMax, yMax;

    int nMon;
    int nMove;

    Monster* pMon[MAXMONS];

    Canvas canvas;

public:
    MonsterWorld(int w, int h)
        : canvas(w, h)
    {
        xMax = w;
        yMax = h;

        nMon = 0;
        nMove = 0;
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    void add(Monster* m) {

        if (nMon < MAXMONS)
            pMon[nMon++] = m;
    }

    // ======================================================
    // (3) checkStarvation() 함수 추가
    // ======================================================
    void checkStarvation() {

        for (int i = 0; i < nMon; i++) {

            // 에너지가 0 이하이면 삭제
            if (pMon[i]->getEnergy() <= 0) {

                cout << "\nMonster 하나가 굶어 죽었습니다.\n";

                delete pMon[i];

                // 마지막 몬스터를 앞으로 이동
                pMon[i] = pMon[nMon - 1];

                nMon--;

                i--;
            }
        }
    }

    void print() {

        canvas.clear('.');

        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);

        canvas.print("[ Monster World (Dynamic World) ]");

        cout << endl;

        cout << "전체 이동 횟수 = "
             << nMove << endl;

        // (4)
        Monster::printCount();

        cout << endl;

        for (int i = 0; i < nMon; i++)
            pMon[i]->print();
    }

    void play(int maxwalk, int wait) {

        print();

        for (int i = 0; i < maxwalk; i++) {

            for (int k = 0; k < nMon; k++)
                pMon[k]->move(xMax, yMax);

            nMove++;

            // (3)
            checkStarvation();

            print();

            if (nMon == 0) {
                cout << "\n모든 몬스터가 죽었습니다.\n";
                break;
            }

            this_thread::sleep_for(chrono::milliseconds(wait));
        }
    }
};

// ======================================================
// (5) main 함수
// ======================================================
int main() {

    srand((unsigned int)time(NULL));

    int w = 16;
    int h = 8;

    MonsterWorld game(w, h);

    game.add(
        new Monster(
            "몬스터",
            '*',
            rand() % w,
            rand() % h,
            30
        )
    );

    game.add(
        new Monster(
            "도깨비",
            '&',
            rand() % w,
            rand() % h,
            20
        )
    );

    game.add(
        new Monster(
            "불그대",
            '#',
            rand() % w,
            rand() % h,
            50
        )
    );

    game.add(
        new Monster(
            "고스트",
            '@',
            rand() % w,
            rand() % h,
            10
        )
    );

    game.play(500, 100);

    cout << "\n------ 게임 종료 ------\n";

    return 0;
}