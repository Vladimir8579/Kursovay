#pragma warning(default:4716)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int sizes = 4000;
char prodoljenie;
int setlast = 3999;
int timecast = 0;
int tablecast = 0;
unsigned short int maximum = -1;
int ramzes;
bool f = false;
bool grow;
string swaper;

struct database // Структура для базы данных
{
    char FioEmployee[32] = { 0 };
    unsigned short int DepartmentNumber;
    char Position[22] = { 0 };
    char DateOfBirth[8] = { 0 };
} *stacks;

struct lister // Список
{
    lister* next;
    database* data;
} *head, * tail;

struct queue
{
    lister* head;
    lister* tail;
};

struct tree // Дерево
{
    database* data;
    int TreeBalancing;
    tree* left;
    tree* right;
}; tree* root;


void Indexing(database* record[], lister* head);
int ConclusionByTwenty(database* record[]);
int Search(database* record[], int key);
bool Compare(int str1, int str2, std::string str3, std::string str4);
int Delimiter(lister*& head, lister*& a, lister*& b, int& n);
int MergeSort(lister*& head);
int LR(tree* p);
void LL(tree*& p);
void LRtoAVL(tree*& p);
void RR(tree*& p);
void RL(tree*& p);
void AVL(database* D, tree*& p);
void Print(lister* head);
void Menu(void);
void Create(void);
void Queue(lister*& head, lister*& tail, database* Array);



int main(void)
{
    char key{};
    database* record[4000];
    head = NULL;
    tree* root = NULL;
    Create();
    while (key != 'q')
    {
        system("cls");
        Menu();
        std::cin >> key;
        switch (key)
        {
        case '1':
            Print(head);
            break;
        case '2':
        {
            MergeSort(head);
            Indexing(record, head);
            ConclusionByTwenty(record);            
            int f = Search(record, 240);
            ramzes = f;
            std::cout << f + 1 << "-" << setlast + 1 << " - wave of tree to create.\n";
            for (f; f <= setlast; f++)
                AVL(record[f], root);
            std::cout << "Representing of tree (->):\n";
            LR(root);
            system("pause>>void");
            ramzes = 0;
        }
        break;
        case '3':
            exit(1);
            break;
        }
    }
    return 0;
}

void Menu(void)
{
    setlocale(LC_ALL, "866");
    std::cout << "Локаль: " << setlocale(LC_ALL,NULL) << std::endl;
    printf( "апровл\n");
    std::cout << "2. Create and show the AVL tree.\n";
    std::cout << "3. Quite.\n";
    std::cout << "вапрвапр: ";
}

void Create(void)
{
    std::fstream file("BASE2.dat", std::ios::binary | std::ios::in);
    for (int i = 0; i < sizes; i++)
    {
        stacks = new database;
        file.seekp(64 *i, std::ios::beg);
        file.read((char*)stacks, sizeof(database));
        Queue(head, tail, stacks);
    }
    file.close();
}

int ConclusionByTwenty(database* record[])
{
    system("cls");
    bool boolean = 0;
    std::string swp;
    int o4erednoi_nenujnii_c4et4ik = 0;
    for (int i = 0; i < 4000; i++)
    {
        if (boolean == 0)
        {
            std::cout << "+";
            for (int x = 0; x < 118; x++)
                std::cout << "-";            
            std::cout << "\n| Number\t| FioEmployee\t\t\t\t | Department \t| Post\t\t\t     | Date\t\t|\n+";
            for (int x = 0; x < 118; x++)
                std::cout << "-";
            std::cout << "\n";
            boolean = 1;
        }
        std::cout << "| " << i + 1 << "\t\t| ";
        swp = { record[i]->FioEmployee };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << record[i]->DepartmentNumber << "\t\t| ";
        maximum = std::max(record[i + 1]->DepartmentNumber, record[i]->DepartmentNumber);
        swp = { record[i]->Position };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { record[i]->DateOfBirth };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        o4erednoi_nenujnii_c4et4ik++;
        if (o4erednoi_nenujnii_c4et4ik == 50)
        {
            
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
            std::cout << "\nPress [1] to continue / To abort, press another key:";
            std::cin >> prodoljenie;
            if (prodoljenie == '1')
            {
                o4erednoi_nenujnii_c4et4ik = 0;
                system("cls");
                boolean = 0;
            }
            else
            {
                system("cls");
                break;
            }
        }
    }

}


int CompareStr(char* s1, char* s2, int len)
{
    int i = 0;
    int m = 0;
    while (i < len && m == 0) {
        if (s1[i] < s2[i])
            m = -1;
        else if (s1[i] > s2[i])
            m = 1;
        i++;
    }
    return m;
}



void Queue(lister*& head, lister*& tail, database* info)
{
    lister* p = new lister;
    p->data = info;
    p->next = NULL;
    if (head == NULL)
    {
        head = tail = p;
        head->next = NULL;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

void Print(lister* head)
{
    short int n = 0;
    short int i = 1;
    lister* p;
    bool boolean = 0;
    bool table = false;
    std::string swp;
    system("cls");
    for (p = head; p; p = p->next)
    {
        if (table == false)
        {
            std::cout << "+";
            for (int x = 0; x < 118; x++)
                std::cout << "-";
            
            std::cout << "\n| Number\t| FioEmployee\t\t\t\t | Department\t| Post\t\t\t     | Date\t\t|\n+";
            for (int x = 0; x < 118; x++)
                std::cout << "-";
            std::cout << "\n";
            table = true;
        }

        std::cout << "| " << i << "\t\t| ";
        swp = { p->data->FioEmployee };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << p->data->DepartmentNumber << "\t\t| ";
        swp = { p->data->Position };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { p->data->DateOfBirth };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        i++;
        n++;
        if (n == 50)
        {
            n = 0;
            std::cout << "+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "\n";
            std::cout << "\nPress [1] to continue / To abort, press another key:";
            std::cin >> prodoljenie;
            if (prodoljenie == '1')
            {
                std::cout << std::endl;
                if (i == 4000)
                {
                    system("cls");
                    main();
                }
                system("cls");
                table = false;
                boolean = 0;
                continue;
            }
            else
            {
                system("cls");
                main();
                break;
            }
        }
    }
    if (p->next == NULL)
        std::cout << "\n";
}

bool Compare(int str1, int str2, std::string str3, std::string str4)
{
    if ((str1 < str2) and (str3 < str4))
    {
        return true;
    }
    else if ((str1 <= str2) and (str3 < str4))
    {
        return true;
    }
    else if (str1 < str2)
    {
        return true;
    }
    return false;
}

int Delimiter(lister*& head, lister*& a, lister*& b, int& n)
{
    lister* p, * q;
    a = head;
    b = head->next;
    n = 1;
    p = a;
    q = b;
    while (q)
    {
        n++;
        p->next = q->next;
        p = q;
        q = q->next;
    }
}

int MergeSort(lister*& head)
{
    int m, n, i;
    lister* a, * b;
    queue c[2];
    int p = 1, q, r;
    if (head == NULL)
        return 0;
    Delimiter(head, a, b, n);
    while (p < n)
    {
        c[0].tail = (lister*)&(c[0].head);
        c[1].tail = (lister*)&(c[1].head);
        i = 0;
        m = n;
        while (m > 0)
        {
            if (m >= p)
                q = p;
            else q = m;
            m -= q;

            if (m >= p)
                r = p;
            else
                r = m;
            m -= r;
            while ((q > 0) && (r > 0))
            {
                int str1 = a->data->DepartmentNumber;
                std::string str3 = a->data->FioEmployee;
                int  str2 = b->data->DepartmentNumber;
                std::string str4 = b->data->FioEmployee;
                if (Compare(str1, str2, str3, str4))
                {
                    c[i].tail->next = a;
                    c[i].tail = a;
                    a = a->next;
                    q--;
                }
                else
                {
                    c[i].tail->next = b;
                    c[i].tail = b;
                    b = b->next;
                    r--;
                }
            }
            while (q > 0)
            {
                c[i].tail->next = a;
                c[i].tail = a;
                a = a->next;
                q--;
            }

            while (r > 0)
            {
                c[i].tail->next = b;
                c[i].tail = b;
                b = b->next;
                r--;
            }
            i = 1 - i;
        }
        a = c[0].head;
        b = c[1].head;
        p *= 2;
    }
    c[0].tail->next = 0;
    head = c[0].head;
    return 0;
}

void Indexing(database* record[], lister* head)
{
    lister* p = head;
    for (int i = 0; i < sizes; i++)
    {
        record[i] = p->data;
        p = p->next;
    }
}

int Search(database* Index[], int key)
{
    int l = 0;
    int r = 3999;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (Index[m]->DepartmentNumber < key)
            l = m + 1;
        else
            r = m;
    }
    if (Index[r]->DepartmentNumber == key)
    {
        return r;
    }
    return -1;
}
std::string swp;
int counter = 0;
int LR(tree* p)
{
    if (p != NULL)
    {
        LR(p->left);
        
        if (tablecast == 0)
        {
            std::cout << "+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+";
            std::cout << "\n| Number\t| FioEmployee\t\t\t\t | DepartmentNumber Number\t| Post\t\t\t| Date\t\t|\n+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
        }
        counter++;
        std::cout << "| " << ramzes + 1 << "\t\t| ";
        swp = { p->data->FioEmployee };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << p->data->DepartmentNumber << "\t\t| ";
        swp = { p->data->Position };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { p->data->DateOfBirth };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        ramzes++;
        tablecast++;
        timecast++;
        LR(p->right);
        if (ramzes == 3999)
        {
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";

        }
    }
}

void LL(tree*& p)
{
    tree* q;
    q = p->left;
    q->TreeBalancing = 0;
    p->TreeBalancing = 0;
    p->left = q->right;
    q->right = p;
    p = q;
}

void LRtoAVL(tree*& p)
{
    tree* q, * r;
    q = p->left;
    r = q->right;
    if (r->TreeBalancing < 0)
        p->TreeBalancing = 1;
    else
        p->TreeBalancing = 0;
    if (r->TreeBalancing > 0)
        q->TreeBalancing = -1;
    else
        q->TreeBalancing = 0;
    r->TreeBalancing = 0;
    q->right = r->left;
    p->left = r->right;
    r->left = q;
    r->right = p;
    p = r;
}


void RR(tree*& p)
{
    tree* q;
    q = p->right;
    q->TreeBalancing = 0;
    p->TreeBalancing = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}

void RL(tree*& p)
{
    tree* r, * q;
    q = p->right;
    r = q->left;
    if (r->TreeBalancing > 0)
        p->TreeBalancing = -1;
    else p->TreeBalancing = 0;
    if (r->TreeBalancing < 0)
        q->TreeBalancing = 1;
    else q->TreeBalancing = 0;
    r->TreeBalancing = 0;
    q->left = r->right;
    p->right = r->left;
    r->right = q;
    r->left = p;
    p = r;
}

void AVL(database* D, tree*& p)
{
    if (p == NULL)
    {
        p = new tree;
        p->data = D;
        p->left = NULL;
        p->right = NULL;
        p->TreeBalancing = 0;
        grow = true;
    }
    else
        // > != >=
        if (strcmp(p->data->FioEmployee, D->FioEmployee) > 0)
        {
            AVL(D, p->left);
            if (grow == true)
            {
                if (p->TreeBalancing > 0)
                {
                    p->TreeBalancing = 0;
                    grow = 0;
                }
                else
                    if (p->TreeBalancing == 0)
                    {
                        p->TreeBalancing = -1;
                        grow = false;
                    }
                    else
                        if (p->left->TreeBalancing < 0)
                        {
                            LL(p);
                            grow = false;
                        }
                        else
                        {
                            LRtoAVL(p);
                            grow = false;
                        }
            }
        }
        else
            if (strcmp(p->data->FioEmployee, D->FioEmployee) <= 0)
            {
                AVL(D, p->right);
                if (grow == true)
                {
                    if (p->TreeBalancing < 0)
                    {
                        p->TreeBalancing = 0;
                        grow = false;
                    }
                    else
                        if (p->TreeBalancing == 0)
                        {
                            p->TreeBalancing = 1;
                        }
                        else
                            if (p->right->TreeBalancing > 0)
                            {
                                RR(p);
                                grow = false;
                            }
                            else
                            {
                                RL(p);
                                grow = false;
                            }
                }
            }
}