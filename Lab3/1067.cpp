#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
int n, num, pos;
string str, name, space[100];

struct Node {
    string name;
    struct Node *next;
    struct Node *child;
};

Node* root;
Node* curNode;
string extractName();
void solve();
void addName(string);
void PrintResult(int, Node*);
void addChild(Node, string);
void addNext(Node, string);
void insertNext(Node, string);

int main(int argc, char** argv) {
        space[0] = "";
    for (int i = 1; i <= 90; i++) {
        space[i] = space[i - 1];
        space[i] += " ";
    }
    cin >> n;
    root = new Node();
    root->child = NULL;
    root->next = NULL;
    string curName;
    num = 0;

    for (int i = 1; i <= n; i++) {
        cin >> str;
        curNode = root;
        while (str.length() != 0) {
            curName = extractName();
            addName(curName);
        }
    }
    PrintResult(0, root);
}

void PrintResult(int depth, Node* cur) {
    Node* node = cur->child;
    while (node != NULL) {
        num--;
        if (num > 0) {
            cout << space[depth] << node->name<< endl;
        } else cout << space[depth] << node->name;
        PrintResult(depth + 1, node);
        node = node->next;
    }
}

void addChild(Node* &node, string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->child = NULL;
    newNode->next = NULL;
    node->child = newNode;
}

void addNext(Node* &node, string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->child = NULL;
    newNode->next = NULL;
    node->next = newNode;
}

void insertNext(Node* &node, string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->child = NULL;
    newNode->next = node->next;
    node->next = newNode;
}

void insertChildAtHead(Node* &node, string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->child = NULL;
    newNode->next = node->child;
    node->child = newNode;
}

void addName(string curName) {
    num++;
    if (curNode->child == NULL) {
        addChild(curNode, curName);
        curNode = curNode->child;
    } else {
        if (curNode->child->name.compare(curName) > 0) {
            insertChildAtHead(curNode, curName);
            curNode = curNode->child;
            return;
        }
        
        if (curNode->child->name.compare(curName) == 0) {
            num--;
            curNode = curNode->child;
            return;
        }
        curNode = curNode->child;
        while ((curNode->next != NULL)
                && (curNode->next->name.compare(curName) < 0)) {
            curNode = curNode->next;
        }
        if (curNode->next == NULL) {
            addNext(curNode, curName);
            curNode = curNode->next;
            return;
        }
        if (curNode->next->name.compare(curName) == 0) {
            curNode = curNode->next;
            num--;
            return;
        }
        insertNext(curNode, curName);
        curNode = curNode->next;
    }
}

string extractName() {
    int pos = str.find("\\");
    string name;
    if (pos != -1) {
        name = str.substr(0, pos);
        str.erase(0, pos + 1);
    } else {
        name = str;
        str.erase(0, str.length());
    }
    return name;
}
