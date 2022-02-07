#pragma warning(default:4716)

#include <iostream>
#include <locale>
#include <map>
#include <list>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <string.h>

int sizes = 4000;
char prodoljenie;

struct database // ya4eika dlya bazi
{
    char name[32] = { 0 };
    unsigned short int number;
    char post[22] = { 0 };
    char date[8] = { 0 };
} *stacks;

struct lister // spisok
{
    lister* next;
    database* data;
} *head, * tail;

struct queue
{
    lister* head;
    lister* tail;
};

struct tree // derevo
{
    database* data;
    int balance;
    tree* left;
    tree* right;
}; tree* root;

std::string swaper;
bool sorted = false;
int setfirst;
int setlast = 3999;
int timecast = 0;
int tablecast = 0;
unsigned short int maximum = -1;
int ramzes;
bool foundb = false;
bool f = false;
bool wlyapa = false;
int numeric = 1;
bool creature = false;
bool grow;
bool tryt = false;

void index_cast(database* record[], lister* head);
int searching(database* record[]);
int o4erednoi_nenujnii_vivod(database* record[]);
int quick_search(database* record[], int key);
bool Comparator(int str1, int str2, std::string str3, std::string str4);
int Separation(lister*& head, lister*& a, lister*& b, int& n);
int MergeSort(lister*& head);
int L_R(tree* p);
void LL(tree*& p);
void LR(tree*& p);
void RR(tree*& p);
void RL(tree*& p);
void avl(database* D, tree*& p);
void print_spis(lister* head);
void menu(void);
void create_base(void);
void add_queue(lister*& head, lister*& tail, database* Array);
int diff(const database& a, const database& b);
void qSort(database* array[], int L, int R);

int main(void)
{
    char key{};
    database* record[4000];
    head = NULL;
    tree* root = NULL;
    create_base();
    while (key != 'q')
    {
        system("cls");
        menu();
        std::cin >> key;
        switch (key)
        {
        case '1':
            print_spis(head);
            break;
        case '2':
        {
            MergeSort(head);
            index_cast(record, head);
            o4erednoi_nenujnii_vivod(record);
            // rabotaet do suda
            int f = quick_search(record, 240);
            ramzes = f;
            std::cout << f + 1 << "-" << setlast + 1 << " - wave of tree to create.\n";
            for (f; f <= setlast; f++)
                avl(record[f], root);
            std::cout << "Representing of tree (->):\n";
            L_R(root);
            system("pause>>void");
            ramzes = 0;
        }
        break;
        case 'q':
            exit(1);
            break;
        }
    }
    return 0;
}

void menu(void)
{
    std::cout << "1. Unsorted database.\n";
    std::cout << "2. Create the AVL tree.\n";
    std::cout << "q. Quite the program running .\n";
    std::cout << "Choose action: ";
}

void create_base(void)
{
    std::fstream file("BASE2.dat", std::ios::binary | std::ios::in);
    for (int i = 0; i < sizes; i++)
    {
        stacks = new database;
        file.seekp(64 * i, std::ios::beg);
        file.read((char*)stacks, sizeof(database));
        add_queue(head, tail, stacks);
    }
    file.close();
}

int o4erednoi_nenujnii_vivod(database* record[])
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
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+";
            std::cout << "\n| Number\t| Person\t\t\t\t | State\t| Post\t      \t\t      | Date\t\t|\n+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
            boolean = 1;
        }
        std::cout << "| " << i + 1 << "\t\t| ";
        swp = { record[i]->name };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << record[i]->number << "\t\t| ";
        maximum = std::max(record[i + 1]->number, record[i]->number);
        swp = { record[i]->post };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { record[i]->date };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        o4erednoi_nenujnii_c4et4ik++;
        if (o4erednoi_nenujnii_c4et4ik == 20)
        {
            std::cout << "+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
            std::cout << "\nPress [1] to continue / Anything else for break:";
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

void add_queue(lister*& head, lister*& tail, database* info)
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

void print_spis(lister* head)
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
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+";
            std::cout << "\n| Number\t| Person\t\t\t\t | State\t| Post\t      \t\t     | Date\t\t|\n+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
            table = true;
        }

        std::cout << "| " << i << "\t\t| ";
        swp = { p->data->name };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << p->data->number << "\t\t| ";
        swp = { p->data->post };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { p->data->date };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        i++;
        n++;
        if (n == 20)
        {
            n = 0;
            std::cout << "+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
            std::cout << "\nPress [1] to continue / Anything else for break:";
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

bool Comparator(int str1, int str2, std::string str3, std::string str4)
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

int Separation(lister*& head, lister*& a, lister*& b, int& n)
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
    Separation(head, a, b, n);
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
                int str1 = a->data->number;
                std::string str3 = a->data->name;
                int  str2 = b->data->number;
                std::string str4 = b->data->name;
                if (Comparator(str1, str2, str3, str4))
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

void index_cast(database* record[], lister* head)
{
    lister* p = head;
    for (int i = 0; i < sizes; i++)
    {
        record[i] = p->data;
        p = p->next;
    }
}

int quick_search(database* Index[], int key)
{
    int l = 0;
    int r = 3999;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (Index[m]->number < key)
            l = m + 1;
        else
            r = m;
    }
    if (Index[r]->number == key)
    {
        return r;
    }
    return -1;
}
std::string swp;
int counter = 0;
int L_R(tree* p)
{
    if (p != NULL)
    {
        L_R(p->left);
        //timecast++;
        if (tablecast == 0)
        {
            std::cout << "+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+";
            std::cout << "\n| Number\t| Person\t\t\t\t | State\t| Post\t      \t\t     | Date\t\t|\n+";
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";
        }
        counter++;
        std::cout << "| " << ramzes + 1 << "\t\t| ";
        swp = { p->data->name };
        std::cout << swp.substr(0, 32) << "\t | ";
        std::cout << p->data->number << "\t\t| ";
        swp = { p->data->post };
        std::cout << swp.substr(0, 22) << "\t     | ";
        swp = { p->data->date };
        std::cout << swp.substr(0, 8) << "\t\t|\n";
        ramzes++;
        tablecast++;
        timecast++;
        L_R(p->right);
        if (ramzes == 3999)
        {
            for (int x = 0; x < 119; x++)
                std::cout << "-";
            std::cout << "+\n";

        }
        //if(counter == 20)
        //{
        //    if(getch() == '1')
        //        counter
        //}
    }
}

void LL(tree*& p)
{
    tree* q;
    q = p->left;
    q->balance = 0;
    p->balance = 0;
    p->left = q->right;
    q->right = p;
    p = q;
}

void LR(tree*& p)
{
    tree* q, * r;
    q = p->left;
    r = q->right;
    if (r->balance < 0)
        p->balance = 1;
    else
        p->balance = 0;
    if (r->balance > 0)
        q->balance = -1;
    else
        q->balance = 0;
    r->balance = 0;
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
    q->balance = 0;
    p->balance = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}

void RL(tree*& p)
{
    tree* r, * q;
    q = p->right;
    r = q->left;
    if (r->balance > 0)
        p->balance = -1;
    else p->balance = 0;
    if (r->balance < 0)
        q->balance = 1;
    else q->balance = 0;
    r->balance = 0;
    q->left = r->right;
    p->right = r->left;
    r->right = q;
    r->left = p;
    p = r;
}

void avl(database* D, tree*& p)
{
    if (p == NULL)
    {
        p = new tree;
        p->data = D;
        p->left = NULL;
        p->right = NULL;
        p->balance = 0;
        grow = true;
    }
    else
        // > != >=
        if (strcmp(p->data->name, D->name) > 0)
        {
            avl(D, p->left);
            if (grow == true)
            {
                if (p->balance > 0)
                {
                    p->balance = 0;
                    grow = 0;
                }
                else
                    if (p->balance == 0)
                    {
                        p->balance = -1;
                        grow = false;
                    }
                    else
                        if (p->left->balance < 0)
                        {
                            LL(p);
                            grow = false;
                        }
                        else
                        {
                            LR(p);
                            grow = false;
                        }
            }
        }
        else
            if (strcmp(p->data->name, D->name) <= 0)
            {
                avl(D, p->right);
                if (grow == true)
                {
                    if (p->balance < 0)
                    {
                        p->balance = 0;
                        grow = false;
                    }
                    else
                        if (p->balance == 0)
                        {
                            p->balance = 1;
                        }
                        else
                            if (p->right->balance > 0)
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