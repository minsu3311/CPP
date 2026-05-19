// ===============================
// Monster World Game (수정 버전)
// windows.h 제거 완료
// ===============================

#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// ================= Monster =================
class Monster {
protected:
    string name, icon;
    int x, y;

public:
    Monster(string n = "몬스터", string i = "M",
        int xx = 0, int yy = 0)
        : name(n), icon(i), x(xx), y(yy) {
    }

    virtual ~Monster() {}

    virtual void move(int maxx, int maxy) {
        int dir = rand() % 4;

        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;

        clip(maxx, maxy);
    }

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        if (x >= maxx) x = maxx - 1;
        if (y >= maxy) y = maxy - 1;
    }

    virtual void draw(char map[][20]) {
        map[y][x] = icon[0];
    }
};

// ================= Zombie =================
class Zombie : public Monster {
public:
    Zombie(string n="좀비", string i="Z",
        int x=0, int y=0)
        : Monster(n, i, x, y) {
    }

    void move(int maxx, int maxy) {
        Monster::move(maxx, maxy);
    }
};

// ================= Vampire =================
class Vampire : public Monster {
public:
    Vampire(string n="뱀파이어", string i="V",
        int x=0, int y=0)
        : Monster(n, i, x, y) {
    }

    void move(int maxx, int maxy) {

        int dir = rand() % 4;

        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;

        clip(maxx, maxy);
    }
};

// ================= Ghost =================
class KGhost : public Monster {
public:
    KGhost(string n="귀신", string i="G",
        int x=0, int y=0)
        : Monster(n, i, x, y) {
    }

    void move(int maxx, int maxy) {

        x = rand() % maxx;
        y = rand() % maxy;

        clip(maxx, maxy);
    }
};

// ================= Jiangshi =================
class Jiangshi : public Monster {
protected:
    bool bHori;

public:
    Jiangshi(string n="강시", string i="J",
        int x=0, int y=0, bool bH=true)
        : Monster(n, i, x, y), bHori(bH) {
    }

    void move(int maxx, int maxy) {

        int dir = rand() % 2;
        int jump = rand() % 2 + 1;

        if (bHori)
            x += ((dir == 0) ? -jump : jump);
        else
            y += ((dir == 0) ? -jump : jump);

        clip(maxx, maxy);
    }
};

// ================= Smombi =================
class Smombi : public Monster {
public:
    Smombi(string n="스몸비", string i="S",
        int x=0, int y=0)
        : Monster(n, i, x, y) {
    }

    void move(int maxx, int maxy) {

        int dir = rand() % 4;

        if (dir == 0) {
            x--;
            y--;
        }
        else if (dir == 1) {
            x++;
            y--;
        }
        else if (dir == 2) {
            x--;
            y++;
        }
        else {
            x++;
            y++;
        }

        clip(maxx, maxy);
    }
};

// ================= Super Jiangshi =================
class Siangshi : public Jiangshi {
    int count;

public:
    Siangshi(string n="슈퍼강시", string i="@",
        int x=0, int y=0, bool bH=true)
        : Jiangshi(n, i, x, y, bH), count(0) {
    }

    void move(int maxx, int maxy) {

        count++;

        // 3턴마다 방향 변경
        if (count % 3 == 0)
            bHori = !bHori;

        int dir = rand() % 2;
        int jump = rand() % 2 + 1;

        if (bHori)
            x += ((dir == 0) ? -jump : jump);
        else
            y += ((dir == 0) ? -jump : jump);

        clip(maxx, maxy);
    }
};

// ================= FireMonster =================
class FireMonster : public Monster {
public:
    FireMonster(string n="불꽃몬스터", string i="F",
        int x=0, int y=0)
        : Monster(n, i, x, y) {
    }

    void move(int maxx, int maxy) {

        int dir = rand() % 4;
        int speed = rand() % 3 + 1;

        if (dir == 0)
            x -= speed;
        else if (dir == 1)
            x += speed;
        else if (dir == 2)
            y -= speed;
        else
            y += speed;

        clip(maxx, maxy);
    }
};

// ================= MonsterWorld =================
class MonsterWorld {

    int width, height;

    Monster* monsters[20];

    int count;

    char map[20][20];

public:

    MonsterWorld(int w, int h) {
        width = w;
        height = h;
        count = 0;
    }

    void add(Monster* m) {
        monsters[count++] = m;
    }

    void clearMap() {

        for (int y = 0; y < height; y++) {

            for (int x = 0; x < width; x++) {

                map[y][x] = '.';
            }
        }
    }

    void drawMap() {

        for (int i = 0; i < count; i++) {

            monsters[i]->draw(map);
        }

        for (int y = 0; y < height; y++) {

            for (int x = 0; x < width; x++) {

                cout << map[y][x] << ' ';
            }

            cout << endl;
        }
    }

    void play(int turn) {

        for (int t = 0; t < turn; t++) {

            // 화면 정리용 줄바꿈
            cout << string(30, '\n');

            clearMap();

            // 몬스터 이동
            for (int i = 0; i < count; i++) {

                monsters[i]->move(width, height);
            }

            cout << "========== TURN "
                 << t + 1
                 << " ==========" << endl;

            drawMap();

            cout << endl;

            cout << "Z : Zombie" << endl;
            cout << "V : Vampire" << endl;
            cout << "G : Ghost" << endl;
            cout << "J : Jiangshi" << endl;
            cout << "S : Smombi" << endl;
            cout << "@ : Siangshi" << endl;
            cout << "F : FireMonster" << endl;

            // 0.5초 대기
            this_thread::sleep_for(
                chrono::milliseconds(500)
            );
        }
    }
};

// ================= main =================
int main() {

    srand((unsigned int)time(NULL));

    MonsterWorld game(20, 10);

    game.add(new Zombie(
        "허접좀비", "Z",
        rand()%20, rand()%10));

    game.add(new Vampire(
        "뱀파이어", "V",
        rand()%20, rand()%10));

    game.add(new KGhost(
        "처녀귀신", "G",
        rand()%20, rand()%10));

    game.add(new Jiangshi(
        "강시", "J",
        rand()%20, rand()%10, true));

    game.add(new Smombi(
        "스몸비", "S",
        rand()%20, rand()%10));

    game.add(new Siangshi(
        "슈퍼강시", "@",
        rand()%20, rand()%10, true));

    game.add(new FireMonster(
        "불꽃몬스터", "F",
        rand()%20, rand()%10));

    game.play(100);

    return 0;
}