#include <iostream>
#include <vector>
using namespace std;


struct uczestnik
{
    int index;
    //bool sciezka;
};

struct danie
{
    int index, val;
};

class Graph
{
private:
    int n, m, l, cnt;
    char** arr;
    char** krawedzie;
    vector <uczestnik> member;
    vector <danie> dish;
public:
    Graph(int n, int m, int l)
    {
        this->n = n;
        this->m = m;
        this->l = l;
        this->cnt = 0;

        arr = new char* [n];
        krawedzie = new char* [n];
        for (int i = 0; i < n; i++)  arr[i] = new char[m];
        for (int i = 0; i < n; i++)  krawedzie[i] = new char[m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                krawedzie[i][j] = 'W';
            }
                
    }
    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
            delete[] krawedzie[i];
        }
        delete[] arr;
        delete[] krawedzie;
    }
    void createMember(int i)
    {
        member.push_back(uczestnik());
        member[i].index = i;
    }
    void createDish(int i)
    {
        dish.push_back(danie());
        dish[i].val = l;
        dish[i].index = i;
    }
    void main()
    {
        int i = 0, jTemp = 0, dec = 0, iTemp = 0;
        cnt = 0;
        while (i < n)
        {
            dec = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 'x' && krawedzie[i][j]=='W')
                {
                    if (dec == 0)
                    {
                        jTemp = j;
                        dec = 1;
                    }
                    if (dish[j].val > 0)
                    {
                        jTemp = j;
                        j = m + 1;
                    }

                }
            }


            if (dec == 1)
            {
                if (dish[jTemp].val > 0)
                {
                    cnt++;
                    dish[jTemp].val--;
                    krawedzie[i][jTemp] = 'S';
                }
                else //all dishes are 0
                {
    
                    for (int k = 0; k < n; k++)
                    {
                        if (arr[k][jTemp] == 'x' && krawedzie[k][jTemp]=='S')
                        {

                            for (int j = 0; j < m; j++)
                            {
                                if (arr[k][j] == 'x' && krawedzie[k][j] == 'W' && dish[j].val>0)
                                {
                                    krawedzie[i][jTemp] = 'S';
                                    krawedzie[k][jTemp] = 'W';
                                    krawedzie[k][j] = 'S';
                                    cnt++;
                                    dish[j].val--;
                                    j = m + 1;
                                    k = n + 1;
                                }
                            }

                        }
                    }
                }
            }

            dec = 0;
            jTemp = 0;
            i++;
        }
    }
    int getCnt()
    {
        return cnt;
    }

};



int main()
{

    int n, m, l;
    cin >> n >> m >> l; //arr[n][m]
    Graph* g = new Graph(n, m, l);
    for (int i = 0; i < n; i++) g->createMember(i);
    for (int i = 0; i < m; i++) g->createDish(i);
    g->main();
    int wynik = g->getCnt();
    cout << wynik;


    delete g;
    return 0;
}
