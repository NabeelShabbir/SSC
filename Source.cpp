#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "BST.h"
#include "LinkedList.h"

using namespace std;
int Maxi = 0;
int x = 0;

void fillorder(NodeL* ptr, stack<NodeL*>& S, BST& tree, BST& tree2)
{
    if (ptr->visited == false)
    {
        NodeL* temp = ptr;
        ptr->visited = true;

        while (ptr->Next != NULL)
        {
            NodeL* Ind = NULL;
            Ind = tree.FindIndex(tree.getRoot(), ptr->Next->Data);
            if (Ind != NULL)
            {
                fillorder(Ind, S, tree, tree2);
                ptr = ptr->Next;
            }
            else
            {
                fillorder(ptr, S, tree, tree2);
                ptr = ptr->Next;
            }
        }

        NodeL* temp2 = tree2.FindIndex(tree2.getRoot(), temp->Data);
        S.push(temp2);
    }
}



void DFSUTIL(NodeL* ptr, BST& tree)
{
    if (ptr->visited == false)
    {
        NodeL* temp = ptr;
        //cout << ptr->Data << endl;
        ptr->visited = true;
        x++;

        while (ptr->Next != NULL)
        {
            NodeL* Ind = NULL;
            Ind = tree.FindIndex(tree.getRoot(), ptr->Next->Data);
            if (Ind != NULL)
            {
                DFSUTIL(Ind, tree);
                ptr = ptr->Next;
            }
            else
            {
                DFSUTIL(ptr, tree);
                ptr = ptr->Next;
            }
        }
    }
}

int main()
{
    //string filename("web-Google.txt");
    string filename("twitter_combined.txt");
    int n_Head = 0, n_Tail = 0;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    BST BinT;
    LinkedList LL;

    BST BinT_Transpose;
    LinkedList LL_Transpose;
    int c = 0;
    int I = 0;
    while (!input_file.eof())
    {
        input_file >> n_Head >> n_Tail;
        
        c++;
        


        NodeL* Ind = NULL;
        Ind = BinT.FindIndex(BinT.getRoot(), n_Head);
        if (Ind == NULL)
        {
            LL.InsertD(n_Head);
            Ind = LL.getTail();
            if (BinT.Insert1(BinT.getRoot(), n_Head, Ind) == NULL)
            {
                BinT.setRoot(n_Head, Ind);
            }
        }
        LL.InsertN(Ind, n_Tail);

        Ind = NULL;
        Ind = BinT.FindIndex(BinT.getRoot(), n_Tail);
        if (Ind == NULL)
        {
            LL.InsertD(n_Tail);
            Ind = LL.getTail();
            if (BinT.Insert1(BinT.getRoot(), n_Tail, Ind) == NULL)
            {
                BinT.setRoot(n_Tail, Ind);
            }
        }

        NodeL* Ind_T = NULL;
        Ind_T = BinT_Transpose.FindIndex(BinT_Transpose.getRoot(), n_Tail);
        if (Ind_T == NULL)
        {
            LL_Transpose.InsertD(n_Tail);
            Ind_T = LL_Transpose.getTail();
            if (BinT_Transpose.Insert1(BinT_Transpose.getRoot(), n_Tail, Ind_T) == NULL)
            {
                BinT_Transpose.setRoot(n_Tail, Ind_T);
            }
        }
        LL_Transpose.InsertN(Ind_T, n_Head);

        Ind_T = NULL;
        Ind_T = BinT_Transpose.FindIndex(BinT_Transpose.getRoot(), n_Head);
        if (Ind_T == NULL)
        {
            LL_Transpose.InsertD(n_Head);
            Ind_T = LL_Transpose.getTail();
            if (BinT_Transpose.Insert1(BinT_Transpose.getRoot(), n_Head, Ind_T) == NULL)
            {
                BinT_Transpose.setRoot(n_Head, Ind_T);
            }
        }

    }


    cout << endl;
    ////BinT.Display(BinT.getRoot());
    //cout << endl;
    //LL.Display();

    cout << endl;
    ////BinT_Transpose.Display(BinT_Transpose.getRoot());
    //cout << endl;
    //LL_Transpose.Display();
    //cout << endl;


    stack<NodeL*> S;

    NodeL* ptr = LL.getHead();
    while (ptr != NULL)
    {
        if (ptr->visited == false)
        {
            NodeL* temp = ptr;
            fillorder(temp, S, BinT, BinT_Transpose);
        }
        ptr = ptr->Down;
    }
    
    //BinT.deleteBST(BinT.getRoot());



    while (S.empty() == false)
    {
        NodeL* Ptr = S.top();
        S.pop();

        if (Ptr->visited == false)
        {
            DFSUTIL(Ptr, BinT_Transpose);
            if (x > Maxi)
            {
                Maxi = x;
            }
            x = 0;
        }
    }


    cout << "Max: " << Maxi << endl;
    input_file.close();


    return 0;
}