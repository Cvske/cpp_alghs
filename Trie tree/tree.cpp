#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct node
{
    string zespol;
    node* down, * up, * left, * right;
    vector <string> lista;
};

struct node2
{
    string piosenka;
    node2* down, * up, * left, * right;
    vector <string> lista;
};

class Tree
{
    node* root;
    node2* root2;
public:
    Tree()
    {
        node* temp = new node;
        temp->zespol = "zzzzzzzzzzzzzzzzzzz";
        temp->down = nullptr;
        temp->up = nullptr;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->lista.push_back("ZZZZZZZZZZZ");

        node2* temp2 = new node2;
        temp2->piosenka = "zzzzzzzzzzzzzzzzzzz";
        temp2->down = nullptr;
        temp2->up = nullptr;
        temp2->left = nullptr;
        temp2->right = nullptr;
        temp2->lista.push_back("ZZZZZZZZZZZ");


        root = temp;
        root2 = temp2;
    }
    node* getRoot()
    {
        return root;
    }
    void add(string zespol, string piosenka)
    {
        if (root->down == nullptr)
        {
            node* temp = new node;
            temp->zespol = zespol;
            temp->down = nullptr;
            temp->up = root;
            temp->left = nullptr;
            temp->right = nullptr;
            root->down = temp;
            temp->lista.push_back(piosenka);

        }
        else if (root->down->zespol[0] > zespol[0])
        {
            node* temp = new node;
            temp->zespol = zespol;
            temp->down = nullptr;
            temp->left = nullptr;
            temp->right = root->down;
            root->down->left = temp;
            root->down = temp;
            temp->up = root;
            temp->lista.push_back(piosenka);

        }
        else
        {
            bool loop = false;
            node* temp = root->down;
            node* tempB;
            int iTemp = 0, i, len = 0;
            while (zespol.length() > len)
            { 
                if (zespol[0] > temp->zespol[0] )
                    {
                    if (temp->right == nullptr)
                    {
                        node* tempO = new node;
                        tempO->zespol = zespol;
                        tempO->down = nullptr;
                        tempO->lista.push_back(piosenka);
                        tempO->up = temp->up;

                        tempO->left = temp;
                        temp->right = tempO;

                        tempO->right = nullptr;


                        len = zespol.length() + 3;
                        break;
                    }
                    else if (zespol[0] < temp->right->zespol[0])
                    {
                        node* tempO = new node;
                        tempO->lista.push_back(piosenka);
                        tempO->zespol = zespol;
                        tempO->down = nullptr;
                        tempO->up = temp->up;
                        tempO->left = temp;
                        tempO->right = temp->right;

                        temp->right->left = tempO;
                        temp->right = tempO;
                                        

                        len = zespol.length() + 3;
                        break;
                    }
                    else temp = temp->right;
                    }
                else if (zespol[0] < temp->zespol[0])
                {
                        node* tempO = new node;
                        tempO->lista.push_back(piosenka);
                        tempO->zespol = zespol;
                        tempO->down = nullptr;
                        tempO->up = temp->up;
                        temp->up->down = tempO;
                        tempO->left = nullptr;


                        tempO->right = temp;
                        temp->left = tempO;

                        len = zespol.length() + 3;
                        break;
                }
                else if (temp->zespol[0] == zespol[0])               
                {      
                    if (temp->zespol.length() < zespol.length())
                    {
                        bool dec = false;
                        /*cout << "TEMP: " << temp->zespol << " " << "ZESPOL: " << zespol << endl << endl;*/

                        for (i = 0; i < temp->zespol.length(); i++)
                        {
                            if (zespol[i] != temp->zespol[i])
                            {
                                dec = true;
                                iTemp = i;
                                string newString = "", oldString = "";
                                for (int j = 0; j < iTemp; j++) newString += zespol[j];
                                for (int j = iTemp; j < temp->zespol.length(); j++) oldString += temp->zespol[j];


                                string zespolT = "";
                                for (int j = iTemp; j < zespol.length(); j++) zespolT += zespol[j];
                                zespol = zespolT;


                                temp->zespol = newString; //sie

                                node* tempO = new node; //m
                                tempO->zespol = oldString;

                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempO->lista.push_back(temp->lista[j]);
                                temp->lista.clear();

                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempO->down = temp->down;
                                    temp->down->up = tempO;
                                    temp->down = tempO;
                                }
                                else temp->down = tempO;


                                node* tempN = new node; //kiera
                                tempN->lista.push_back(piosenka);
                                tempN->zespol = zespol;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (tempN->zespol > tempO->zespol)
                                {
                                    temp->down = tempO;
                                    tempN->left = tempO;
                                    tempO->right = tempN;
                                }
                                else if (tempN->zespol < tempO->zespol)
                                {
                                    temp->down = tempN;
                                    tempN->right = tempO;
                                    tempO->left = tempN;
                                }

                                len = zespol.length() + 3;
                                break;
                            }
                            else iTemp = i;                    
                        }
                        string zespolT = "";
                        
                        if (dec == false)
                        {
                            for (int j = iTemp + 1; j < zespol.length(); j++) zespolT += zespol[j];
                            zespol = zespolT;

                            if (temp->down == nullptr)
                            {
                                node* tempO = new node;
                                tempO->zespol = zespol;
                                temp->down = tempO;
                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;
                                tempO->lista.push_back(piosenka);

                                len = zespol.length() + 3;
                                break;
                            }
                            else temp = temp->down;
                        }
                        /*cout << "TEMP: " << temp->zespol << " " << "ZESPOL: " << zespol << endl << endl;*/
                        cout << zespol[0] << endl;
                    }
                    else if (temp->zespol.length() >= zespol.length()) //wprowadzany mniejszy/rowny
                    {                
                        bool dec = false;
                        for (i = 0; i < zespol.length(); i++)
                        {
                            if (zespol[i] != temp->zespol[i])//czaj 0 1 2 3
                            {







                                dec = true;
                                iTemp = i; //3
                                string newString = "", oldString = "";
                                for (int j = 0; j < iTemp; j++) newString += zespol[j]; //cza
                                for (int j = iTemp; j < temp->zespol.length(); j++) 
                                    oldString += temp->zespol[j]; //oldString = jnik
                                


                                string zespolT = "";
                                for (int j = iTemp; j < zespol.length(); j++) 
                                    zespolT += zespol[j];   //isz                  

                                zespol = zespolT;
                               
                                temp->zespol = newString; // cza

                                node* tempO = new node; //reszta stringa z temp 

                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempO->lista.push_back(temp->lista[j]);

                                temp->lista.clear();


                                tempO->zespol = oldString; //jnik
                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempO->down = temp->down;
                                    temp->down->up = tempO;
                                    temp->down = tempO;
                                }
                                else temp->down = tempO;


                                node* tempN = new node; //reszta stringa z nowego zespolu -> //isz
                                tempN->lista.push_back(piosenka);
                                tempN->zespol = zespol;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (tempN->zespol > tempO->zespol)
                                {
                                    temp->down = tempO;
                                    tempN->left = tempO;
                                    tempO->right = tempN;
                                }
                                else if (tempN->zespol < tempO->zespol)
                                {
                                    temp->down = tempN;
                                    tempN->right = tempO;
                                    tempO->left = tempN;
                                }

                                i = zespol.length() + 3;
                                len = zespol.length() + 3;
                               
                                break;
                            }
                        }
                        if (dec == false)
                        {
                            
                            if (zespol.length() == temp->zespol.length())
                            {
                                bool d = true;
                                for (int j = 0; j < temp->lista.size(); j++)
                                {
                                    if (temp->lista[j] == piosenka)
                                    {
                                        j = temp->lista.size() + 3;
                                        d = false;
                                    }

                                }
                                if (d == true)
                                    temp->lista.push_back(piosenka);

                            }
                            else
                            {
                                int l = zespol.length();
                                string newString = "", oldString = "";
                                for (int j = l; j < temp->zespol.length(); j++) newString += temp->zespol[j];
                                for (int j = 0; j < l; j++) oldString += temp->zespol[j];

                                temp->zespol = oldString;

                                node* tempN = new node; //reszta stringa z nowego zespolu -> //isz
                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempN->lista.push_back(temp->lista[j]);
                                temp->lista.clear();
                                temp->lista.push_back(piosenka);
                                tempN->zespol = newString;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempN->down = temp->down;
                                    temp->down->up = tempN;
                                    temp->down = tempN;
                                }
                                else temp->down = tempN;
                                break;
                            }
                            break;
                        }
                    }
                }
                node* tempCur = temp;

                while (loop==false)
                {
                    if (tempCur->zespol[0] == zespol[0])
                    {
                        temp = tempCur;
                        loop = true;
                    }
                    if (tempCur->right == nullptr)
                        loop = true;
                    else tempCur = tempCur->right;
                }
                loop = false;
                
            }

        }
    }
    void findThroughCrew(string zespol)
    {
        node* temp = root->down;
        string lookFor = "";
        bool dec = true;
        string zespolP = zespol;
        while (dec == true)
        {           
            if (zespol[0] == temp->zespol[0])
            {
                int len = temp->zespol.length();
                string zespolT = "";
                for (int j = len; j < zespol.length(); j++) zespolT += zespol[j];
                zespol = zespolT;
                lookFor += temp->zespol;

                if (lookFor == zespolP)
                {
                    for (int j = 0; j < temp->lista.size(); j++)
                        cout << temp->lista[j] << endl;
                    dec = false;
                }
                else if (temp->down == nullptr) break;
                else
                {
                    temp = temp->down;
                    while (temp->left != nullptr) temp = temp->left;
                }
            }
            else
            {

                if (temp->right == nullptr)
                {
                    dec = false;
                    break;
                }
                else temp = temp->right;
            }
        }
        /*cout << root->down->zespol << endl;*/
    }


    node2* getRoot2()
    {
        return root2;
    }
    void add2(string zespol, string piosenka)
    {
        if (root2->down == nullptr)
        {
            node2* temp = new node2;
            temp->piosenka = piosenka;
            temp->down = nullptr;
            temp->up = root2;
            temp->left = nullptr;
            temp->right = nullptr;
            root2->down = temp;
            temp->lista.push_back(zespol);
        }
        else if (root2->down->piosenka[0] > piosenka[0])
        {
            node2* temp = new node2;
            temp->piosenka = piosenka;
            temp->down = nullptr;
            temp->left = nullptr;
            temp->right = root2->down;
            root2->down->left = temp;
            root2->down = temp;
            temp->up = root2;
            temp->lista.push_back(zespol);
        }
        else
        {
            bool loop = false;
            node2* temp = root2->down;
            node2* tempB;
            int iTemp = 0, i, len = 0;
            while (piosenka.length() > len)
            {
      
                if (piosenka[0] > temp->piosenka[0])
                {
                    if (temp->right == nullptr)
                    {
                        node2* tempO = new node2;
                        tempO->piosenka = piosenka;
                        tempO->down = nullptr;
                        tempO->lista.push_back(zespol);
                        tempO->up = temp->up;

                        tempO->left = temp;
                        temp->right = tempO;

                        tempO->right = nullptr;


                        len = zespol.length() + 3;
                        break;
                    }
                    else if (piosenka[0] < temp->right->piosenka[0])
                    {
                        node2* tempO = new node2;
                        tempO->lista.push_back(zespol);
                        tempO->piosenka = piosenka;
                        tempO->down = nullptr;
                        tempO->up = temp->up;
                        tempO->left = temp;
                        tempO->right = temp->right;

                        temp->right->left = tempO;
                        temp->right = tempO;


                        len = zespol.length() + 3;
                        break;
                    }
                    else temp = temp->right;
                }
                else if (piosenka[0] < temp->piosenka[0])
                    {
                        node2* tempO = new node2;
                        tempO->lista.push_back(zespol);
                        tempO->piosenka = piosenka;
                        tempO->down = nullptr;
                        tempO->up = temp->up;
                        temp->up->down = tempO;
                        tempO->left = nullptr;


                        tempO->right = temp;
                        temp->left = tempO;

                        len = piosenka.length() + 3;
                        break;
                    }
                else if (temp->piosenka[0] == piosenka[0])
                {
                    bool dec = false;
                    if (temp->piosenka.length() < piosenka.length())
                    {
                        for (i = 0; i < temp->piosenka.length(); i++)
                        {
                            if (piosenka[i] != temp->piosenka[i])
                            {
                                dec = true;
                                iTemp = i;
                                string newString = "", oldString = "";
                                for (int j = 0; j < iTemp; j++) newString += piosenka[j];
                                for (int j = iTemp; j < temp->piosenka.length(); j++) oldString += temp->piosenka[j];


                                string zespolT = "";
                                for (int j = iTemp; j < piosenka.length(); j++) zespolT += piosenka[j];
                                piosenka = zespolT;


                                temp->piosenka = newString; //sie

                                node2* tempO = new node2; //m
                                tempO->piosenka = oldString;

                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempO->lista.push_back(temp->lista[j]);
                                temp->lista.clear();

                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempO->down = temp->down;
                                    temp->down->up = tempO;
                                    temp->down = tempO;
                                }
                                else temp->down = tempO;


                                node2* tempN = new node2; //kiera
                                tempN->lista.push_back(zespol);
                                tempN->piosenka = piosenka;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (tempN->piosenka > tempO->piosenka)
                                {
                                    temp->down = tempO;
                                    tempN->left = tempO;
                                    tempO->right = tempN;
                                }
                                else if (tempN->piosenka < tempO->piosenka)
                                {
                                    temp->down = tempN;
                                    tempN->right = tempO;
                                    tempO->left = tempN;
                                }

                                len = piosenka.length() + 3;
                                break;
                            }
                            else iTemp = i;
                        }

                        if (dec == false)
                        {
                            string zespolT = "";
                            for (int j = iTemp + 1; j < piosenka.length(); j++) zespolT += piosenka[j];
                            piosenka = zespolT;

                            if (temp->down == nullptr)
                            {
                                node2* tempO = new node2;
                                tempO->piosenka = piosenka;
                                temp->down = tempO;
                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;
                                tempO->lista.push_back(zespol);

                                len = piosenka.length() + 3;
                                break;
                            }
                            else temp = temp->down;
                        }
                        
                    }
                    else if (temp->piosenka.length() >= piosenka.length()) //piosenka mniejsza/rowna
                    {
                        bool dec = false;
                        for (i = 0; i < piosenka.length(); i++)
                        {
                            if (piosenka[i] != temp->piosenka[i])
                            {
                                dec = true;
                                iTemp = i;
                                string newString = "", oldString = "";
                                for (int j = 0; j < iTemp; j++) newString += piosenka[j];
                                for (int j = iTemp; j < temp->piosenka.length(); j++) oldString += temp->piosenka[j];


                                string zespolT = "";
                                for (int j = iTemp; j < piosenka.length(); j++) zespolT += piosenka[j];
                                piosenka = zespolT;


                                temp->piosenka = newString; //sie

                                node2* tempO = new node2; //reszta stringa z temp
                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempO->lista.push_back(temp->lista[j]);
                                temp->lista.clear();
                                tempO->piosenka = oldString;
                                tempO->up = temp;
                                tempO->down = nullptr;
                                tempO->left = nullptr;
                                tempO->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempO->down = temp->down;
                                    temp->down->up = tempO;
                                    temp->down = tempO;
                                }
                                else temp->down = tempO;


                                node2* tempN = new node2; //reszta stringa z nowego zespolu
                                tempN->lista.push_back(zespol);
                                tempN->piosenka = piosenka;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (tempN->piosenka > tempO->piosenka)
                                {
                                    temp->down = tempO;
                                    tempN->left = tempO;
                                    tempO->right = tempN;
                                }
                                else if (tempN->piosenka < tempO->piosenka)
                                {
                                    temp->down = tempN;
                                    tempN->right = tempO;
                                    tempO->left = tempN;
                                }

                                len = piosenka.length() + 3;
                                break;
                            }
                        }
                        if (dec == false)
                        {
                            if (piosenka.length() == temp->piosenka.length())
                            {
                                bool d = true;
                                for (int j = 0; j < temp->lista.size(); j++)
                                {
                                    if (temp->lista[j] == zespol)
                                    {
                                        j = temp->lista.size() + 3;
                                        d = false;
                                    }
                                }
                                if (d == true)
                                    temp->lista.push_back(zespol);
                                
                            }
                            else
                            {
                                int l = piosenka.length();
                                string newString = "", oldString = "";
                                for (int j = l; j < temp->piosenka.length(); j++) newString += temp->piosenka[j];
                                for (int j = 0; j < l; j++) oldString += temp->piosenka[j];

                                temp->piosenka = oldString;

                                node2* tempN = new node2; //reszta stringa z nowego zespolu -> //isz
                                for (int j = 0; j < temp->lista.size(); j++)
                                    tempN->lista.push_back(temp->lista[j]);
                                temp->lista.clear();
                                temp->lista.push_back(zespol);
                                tempN->piosenka = newString;
                                tempN->up = temp;
                                tempN->down = nullptr;
                                tempN->left = nullptr;
                                tempN->right = nullptr;

                                if (temp->down != nullptr)
                                {
                                    tempN->down = temp->down;
                                    temp->down->up = tempN;
                                    temp->down = tempN;
                                }
                                else temp->down = tempN;
                                break;
                            }
                            break;
                        }
                    }

                }
                if (temp->right != nullptr) temp = temp->right;

                node2* tempCur = temp;
                while (loop == false)
                {
                    if (tempCur->piosenka[0] == piosenka[0])
                    {
                        temp = tempCur;
                        loop = true;
                    }
                    if (tempCur->right == nullptr)
                        loop = true;
                    else tempCur = tempCur->right;
                }
                loop = false;
            }

        }
    }
    void findThroughSong(string piosenka)
    {
        node2* temp = root2->down;
        string lookFor = "";
        bool dec = true;
        string piosenkaP = piosenka;
        while (dec == true)
        {

            if (piosenka[0] == temp->piosenka[0])
            {
                int len = temp->piosenka.length();
                string zespolT = "";
                for (int j = len; j < piosenka.length(); j++) zespolT += piosenka[j];
                piosenka = zespolT;
                lookFor += temp->piosenka;
                if (lookFor == piosenkaP)
                {
                    for (int j = 0; j < temp->lista.size(); j++)
                        cout << temp->lista[j] << endl;
                    dec = false;
                }


                else if (temp->down == nullptr) break;
                else
                {
                    temp = temp->down;
                    while (temp->left != nullptr) temp = temp->left;
                }
            }
            else
            {
                if (temp->right == nullptr)
                {
                    dec = false;
                    break;
                }
                else temp = temp->right;
            }
        }

        
    }


    void display()
    {
        node* main = root->down;
        while (main != root)
        {
            while (main->down != nullptr)
            {
                cout << main->zespol << endl;
                main = main->down;
            }
            cout << main->zespol << endl;


            while (main->right == nullptr && main != root)
                main = main->up;

            if (main->right != nullptr)
                main = main->right;

        }
    }
    void displayPreorder(node* root)
    {
        if (root == NULL)
            return;

        while (root)
        {

            cout << root->zespol << "" << endl;
            for (int i = 0; i < root->lista.size(); i++) cout <<root->zespol<<": "<< root->lista[i] << endl;
            if (root->down)
                displayPreorder(root->down);
            root = root->right;
        }
    }
    void displayPreorder2(node2* root)
    {
        if (root == NULL)
            return;

        while (root)
        {

            cout << root->piosenka << "" << endl;
            for (int i = 0; i < root->lista.size(); i++) cout << root->piosenka << ": " << root->lista[i] << endl;
            if (root->down)
                displayPreorder2(root->down);
            root = root->right;
        }
    }
};




int main()
{
    ios_base::sync_with_stdio(false);
    Tree* tree = new Tree();

    string crew, title, znak, n;

    string::size_type sz;
    cin.clear();
    cin.sync();
    getline(cin, n);
    int i_n = stoi(n, &sz);
    for (int i = 0; i < i_n; i++)
    {

        cin.clear();
        cin.sync();
        getline(cin, znak);

        if (znak.find("d") != string::npos)
        {
            cin.clear();
            cin.sync();
            getline(cin, crew);
            cin.clear();
            cin.sync();
            getline(cin, title);


            tree->add(crew, title);
            tree->add2(crew, title);

        }
        else if (znak.find("w") != string::npos)
        {
            cin.clear();
            cin.sync();
            getline(cin, crew);
            tree->findThroughCrew(crew);
        }
        else if (znak.find("z") != string::npos)
        {
            cin.clear();
            cin.sync();
            getline(cin, title);
            tree->findThroughSong(title);
        }

    }



    //cout << endl << endl << "TREE" << endl << endl;
    //node* root = tree->getRoot();
    //tree->displayPreorder(root);
    //cout << endl<<"OTHER" << endl;
    ///*delete tree;*/
    //node2* root2 = tree->getRoot2();
    //tree->displayPreorder2(root2);
    return 0;
}
