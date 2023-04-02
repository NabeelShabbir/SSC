#ifndef BIST_H
#define BIST_H
#include <iostream>
#include "LinkedList.h"
using namespace std;



struct Node {
    int Data;
    //int Index;
    NodeL* Index;
    Node* Left, * Right;
    Node(int D)
    {
        Data = D;
        Index = NULL;
        Left = NULL;
        Right = NULL;
    }

    Node(int D, NodeL* I)
    {
        Data = D;
        Index = I;
        Left = NULL;
        Right = NULL;
    }
};

class BST
{
private:
    Node* root;
public:
    BST()
    {
        root = NULL;
    }

    Node* getRoot()
    {
        return root;
    }
    void setRoot(int D, NodeL* I)
    {
        root = new Node(D, I);
    }

    NodeL* FindIndex(Node* Parent, int& Val)
    {
        if (Parent == NULL)
        {
            return NULL;
        }
        if (Val == Parent->Data)
        {
            return Parent->Index;
        }

        if (Val > Parent->Data)
        {
            FindIndex(Parent->Right, Val);
        }
        else if (Val < Parent->Data)
        {
            FindIndex(Parent->Left, Val);
        }
    }

    Node* Insert1(Node* Parent, int val, NodeL* Index)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            Insert2(root, val, Index);
        }
    }

    Node* Insert2(Node* Parent, int val, NodeL* Index)
    {
        if (Parent == NULL)
        {
            return new Node(val, Index);
        }
        else
        {
            Node* cur;
            if (val < Parent->Data)
            {
                cur = Insert2(Parent->Left, val, Index);
                Parent->Left = cur;
            }
            else if (val > Parent->Data)
            {
                cur = Insert2(Parent->Right, val, Index);
                Parent->Right = cur;
            }
            return Parent;
        }

    }

    void Display(Node* p)
    {
        if (p != NULL)
        {
            cout << p->Data << " "/* << p->Index*/ << " " << endl;
            Display(p->Left);
            Display(p->Right);
        }
    };

    ~BST()
    {
        deleteBST(root);
    }

    void deleteBST(Node* p)
    {
        if (p != NULL)
        {
            deleteBST(p->Left);
            deleteBST(p->Right);
            delete p;
        }
    }
};

#endif