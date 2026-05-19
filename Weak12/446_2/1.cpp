#include <iostream>
#include <string>
#include <ctime>
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

    virtual void draw() {
        cout << icon << "(" << x << "," << y << ") ";
    }
};

// ================= Zombie =================
class Zombie : public Monster {
public:
    Zombie(string n="좀비", string i="Z",
        int x=0, int y=0)
        : Monster(n, i, x, y) {}

    ~Zombie() {
        cout << " Zombie";
    }
};

// ================= Vampire =================
class Vampire : public Monster {
public:
    Vampire(string n="뱀파이어", string i="V",
        int x=0, int y=0)
        : Monster(n, i, x, y) {}

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
    KGhost(string n="처녀귀신", string i="G",
        int x=0, int y=0)
        : Monster(n, i, x, y) {}

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
        : Monster(n, i, x, y), bHori(bH) {}

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
        : Monster(n, i, x, y) {}

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

// ================= Siangshi =================
class Siangshi : public Jiangshi {
    int count;

public:
    Siangshi(string n="슈퍼강시", string i="@",
        int x=0, int y=0, bool bH=true)
        : Jiangshi(n, i, x, y, bH), count(0) {}

    void move(int maxx, int maxy) {

        count++;

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
        : Monster(n, i, x, y) {}

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

// ================= main =================
int main() {

    srand((unsigned int)time(NULL));

    const int MAX = 7;

    Monster* m[MAX];

    m[0] = new Zombie();
    m[1] = new Vampire();
    m[2] = new KGhost();
    m[3] = new Jiangshi();
    m[4] = new Smombi();
    m[5] = new Siangshi();
    m[6] = new FireMonster();

    for (int turn = 0; turn < 10; turn++) {

        cout << "\n[턴 " << turn + 1 << "]\n";

        for (int i = 0; i < MAX; i++) {
            m[i]->move(20, 10);
            m[i]->draw();
            cout << endl;
        }
    }

    for (int i = 0; i < MAX; i++)
        delete m[i];

    return 0;
}