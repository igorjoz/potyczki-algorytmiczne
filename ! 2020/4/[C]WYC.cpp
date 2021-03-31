// U¿yty materia³:
// Znajdowanie wyjœcia z labiryntu, Data: 25.08.2013, (C)2013 mgr Jerzy Wa³aszek

#include <iostream>
#include <string>

using namespace std;

const int MAXINT = -2147483647;

// Typy dla kolejki
struct slistEl {
    slistEl* next;
    int v;
};

// Definicja typu obiektowego queue
class queue {
private:
    slistEl* head;
    slistEl* tail;

public:
    queue();
    ~queue();
    bool empty(void);
    int  front(void);
    void push(int v);
    void pop(void);
};

//---------------------
// Metody obiektu queue
//---------------------

// Konstruktor - tworzy pust¹ listê
queue::queue() {
    head = tail = NULL;
}

// Destruktor - usuwa listê z pamiêci
queue::~queue() {
    while (head) pop();
}

// Sprawdza, czy kolejka jest pusta
bool queue::empty(void) {
    return !head;
}

// Zwraca pocz¹tek kolejki; Wartoœæ specjalna to -MAXINT
int queue::front(void) {
    if (head) return head->v;
    else return -MAXINT;
}

// Zapisuje do kolejki
void queue::push(int v) {
    slistEl* p = new slistEl;
    p->next = NULL;
    p->v = v;
    if (tail) tail->next = p;
    else head = p;
    tail = p;
}

// Usuwa z kolejki
void queue::pop(void) {
    if (head) {
        slistEl* p = head;
        head = head->next;
        if (!head) tail = NULL;
        delete p;
    }
}


// Rozmiar mapy
int wiersze;
int kolumny;
// Wspó³rzêdne startowe - wiersz, kolumna --> okreœlone po wczytaniu wymiaru mapy
int wst;
int kst;  
// Wspó³rzêdne wyjœcia  - wiersz, kolumna --> lewy górny róg; zawsze 1, bo dodatkowo zostan¹ otoczone œcian¹ (X)
int wwy = 1;
int kwy = 1;

int travellers; // iloœæ podró¿ników
int fastestTraveller;
int totalFastestTravellers = 0;

int up = 0;
int down = 0;

string* L;  // Labirynt


// Odczytuje labirynt; Wyszukuje wierzcho³ki startowy i wyjœciowy
void readL() {
    string temp, s;
    string* T;

    // wczytanie g³ównej czêœci mapy
    for (int i = 1; i < wiersze - 1; i++) {
        cin >> temp;
        s = "X" + temp + "X";
        L[i] = s;
    }

    //górna œciana
    L[0] = "";
    for (int j = 0; j < kolumny; j++) {
        L[0] += "X";
    }

    

    // dolna œciana
    L[wiersze - 1] = "";
    for (int j = 0; j < kolumny; j++) {
        L[wiersze - 1] += "X";
    }

    //cout << endl;
    for (int i = 0; i < wiersze; i++) {
        //cout << L[i] << endl;
    }
}

// Procedura szukania wyjœcia
void SzukajW()
{
    queue Q;
    int w, k; // Wiersz, kolumna bie¿¹cego wierzcho³ka
    int i, j;

    Q.push(wst); // W kolejce umieszczamy wierzcho³ek startowy
    Q.push(kst);

    while (!Q.empty())
    {
        w = Q.front(); Q.pop();  // Pobieramy z kolejki wiersz
        k = Q.front(); Q.pop();  // i kolumnê bie¿¹cego wierzcho³ka

        // Sprawdzamy, czy osi¹gnêliœmy wyjœcie
        if ((w == wwy) && (k == kwy)) break;

        // Przegl¹damy s¹siadów bie¿¹cego wierzcho³ka
        for (i = -1; i <= 1; i++)
            for (j = -1; j <= 1; j++)
                if ((i != j) && (!i || !j)) {
                    if (L[w + i][k + j] == '.') {
                        // W komórce s¹siada zapisujemy, sk¹d przyszliœmy do niej
                        if (i == -1) L[w + i][k + j] = 'd';  // z do³u
                        else if (i == 1) L[w + i][k + j] = 'g';  // z góry
                        else if (j == -1) L[w + i][k + j] = 'p';  // z prawej
                        else L[w + i][k + j] = 'l';  // z lewej

                        Q.push(w + i);  // S¹siad zostaje umieszczony w kolejce
                        Q.push(k + j);
                    }
                }
    }
}

// wypisuje labirynt z ewentualn¹ œcie¿k¹; Zastêpuje znaki kierunków znakiem -.
void PiszL()
{
    int i, j;
    char c;

    i = wwy; j = kwy;

    while ((i != wst) || (j != kst)) {
        c = L[i][j];
        L[i][j] = '+';
        switch (c) {
        case 'd': // dó³
            i++;
            up++;
            break;
        case 'g': // góra
            i--;
            down++;
            break;
        case 'p': // prawo
            j++;
            up++;
            break;
        case 'l': // lewo
            j--;
            down++;
            break;
        }
    }

    L[wwy][kwy] = 'W'; // Odtwarzamy znak wyjœcia

    // Teraz usuwamy znaki kierunku i wypisujemy labirynt
    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < (int)L[i].length(); j++)
            switch (L[i][j])
            {
            case 'g':;
            case 'd':;
            case 'p':;
            case 'l': L[i][j] = ' ';
            }
        //cout << L[i] << endl;
    }
    //cout << endl;
}

struct traveller {
    int upSpeed;
    int downSpeed;
    int totalTime = 0;
};


int main()
{
    cin >> wiersze >> kolumny >> travellers;
    wst = wiersze;
    kst = kolumny;
    traveller* t = new traveller[travellers];

    wiersze += 2; // + 2, aby dobudowaæ œciany
    kolumny += 2;

    L = new string[wiersze];

    readL(); // wczytanie labiryntu

    for (int i = 0; i < travellers; i++) {
        cin >> t[i].upSpeed >> t[i].downSpeed;
    }

    SzukajW();

    //cout << endl;
    PiszL();

    //cout << endl << endl << up << endl << down;

    for (int i = 0; i < travellers; i++) {
        t[i].totalTime += up * t[i].upSpeed;
        t[i].totalTime += down * t[i].downSpeed;
    }

    fastestTraveller = t[0].totalTime;
    for (int i = 1; i < travellers; i++) {
        if (t[i].totalTime < fastestTraveller) {
            fastestTraveller = t[i].totalTime;
        }
    }

    for (int i = 0; i < travellers; i++) {
        if (t[i].totalTime == fastestTraveller) {
            totalFastestTravellers++;
        }
    }

    cout << fastestTraveller << " " << totalFastestTravellers;

    return 0;
}