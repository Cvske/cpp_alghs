#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;


struct node
{
    string zespol;
    int present = 0;
    vector <string> lista;
};
struct node2
{
    string piosenka;
    int present = 0;
    vector <string> lista;
};

class Tree
{
    vector<node*>* tab1;
    vector<node2*>* tab2;
    int cnt;
public:


    Tree(int d)
    {
        cnt = d/2;
        tab1 = new vector<node*>[cnt+1];
        tab2 = new vector<node2*>[cnt+1];
    }
    int hash(string s)
    {

        int sum = 0, index = 0;
        for (string::size_type i = 0; i < s.length(); i++)
            sum += s[i]; 
        index = sum % cnt;
        return index;
    }
    void addL(string zespol, string piosenka)
    {
        int index = hash(zespol);

            bool dec = false;
            node* temp = new node;
            temp->zespol = zespol;
            temp->lista.push_back(piosenka);
            tab1[index].push_back(temp);
 
    }

    void addL2(string zespol, string piosenka)
    {
        int index = hash(piosenka);

            node2* temp = new node2;
            temp->piosenka = piosenka;
            temp->lista.push_back(zespol);
            tab2[index].push_back(temp);
    }


    void findThroughCrew(string zespol)
    {
        int index = hash(zespol);

            for (auto it = tab1[index].begin(); it != tab1[index].end(); it++)
            {
                if((*it)->zespol == zespol)
                {
                    for (int j = 0; j < (*it)->lista.size(); j++)
                        cout << (*it)->lista[j] << endl;
                }
            }
    }
    void findThroughSong(string piosenka)
    {
        int index = hash(piosenka);

            for (auto it = tab2[index].begin(); it != tab2[index].end(); it++)
            {
                if ((*it)->piosenka == piosenka)
                {
                    for (int j = 0; j < (*it)->lista.size(); j++)
                        cout << (*it)->lista[j] << endl;
                }
            }

    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    string crew, title, znak, n;
    string::size_type sz;
    cin.clear();
    cin.sync();
    getline(cin, n);
    int i_n = stoi(n, &sz);

    Tree* tree = new Tree(i_n);


    for (int i = 0; i < i_n; i++)
    {
        cin.clear();
        cin.sync();
        getline(cin, znak);

        if (znak.compare("d") == 0)
        {
            cin.clear();
            cin.sync();
            getline(cin, crew);

            cin.clear();
            cin.sync();
            getline(cin, title);

            tree->addL(crew, title);
            tree->addL2(crew, title);
        }
        else if (znak.compare("w") == 0)
        {
            cin.clear();
            cin.sync();
            getline(cin, crew);

            tree->findThroughCrew(crew);
        }
        else if (znak.compare("z") == 0)
        {
            cin.clear();
            cin.sync();
            getline(cin, title);

            tree->findThroughSong(title);
        }

    }


    delete tree;
    return 0;
}
