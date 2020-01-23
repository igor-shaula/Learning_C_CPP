#include <iostream>
#include <forward_list>
#include <cstdio>

using namespace std;

class Node {
    Node *next_ = nullptr;
    char value_ = -1;
public:
    Node *getNext() const { return next_; }
    char getValue() const { return value_; }
    void setValue(char const c) { value_ = c; }
    void addNewNode(Node *newNode) { // object of newNode must be created in dynamic memory before this
        next_ = newNode;
    }
    bool hasNext() const { return next_ != nullptr; };
    void gotoNext(Node const *nextNode) {
        next_ = nextNode->next_;
        value_ = nextNode->value_;
    }
    int getSize() {
        int size = 0;
        while (this->hasNext()) {
            ++size;
            gotoNext(this->getNext());
        }
        return size;
    }
};

int getSize(forward_list<Node> const &list) {
    int size = 0;
    auto it = list.begin();
    while (it != list.end()) {
        ++size;
        advance(it, 1);
    }
    return size;
}

void print(forward_list<Node> const &list) {
    cout << "print()" << endl;
//    auto it = list.begin();
//    while (it != list.end()) {
//        cout << it.operator*().getValue() << endl;
//        advance(it, 1);
//    }
    for (Node node : list)
        cout << node.getValue();
    cout << endl;
}

void prepareForwardList(forward_list<Node> &list) {
    cout << "prepareForwardList()" << endl;
    int size = 0;
    char c;
    while ((cin >> c) && c != '\n' && c != '`') {
        Node *currentNode = new Node();
        currentNode->setValue(c);
        currentNode->addNewNode(new Node());
        putchar(currentNode->getValue());
//        list.emplace_front(*currentNode);
        list.push_front(*currentNode);
        ++size;
    }
    putchar('\n');
    cout << size << endl;
    cout << "list size in the end of preparation: " << getSize(list) << endl;
}

void reverseForwardList(forward_list<Node> &initialList) {
//    initialList.reverse();
    int length = getSize(initialList);
    // we need temporary array for reordering:
    // array of nodes is meant for use in reverse
    struct Node *ptrArray[length + 1];
    for (int i = 0; i < length - 2; ++i)
        ptrArray[i]->addNewNode(ptrArray[i + 1]);
    ptrArray[length - 1]->addNewNode(ptrArray[0]);
    // reversing itself:
    for (int i = 0; i < length; ++i)
        initialList.push_front(*ptrArray[i]);
//    for (int i = length - 1; i > 0; --i) {
//        ptrArray[i]->nextNodePtr = ptrArray[i - 1];
//    }
}

int main() {
    forward_list<Node> list;
    prepareForwardList(list);
    print(list);
    reverseForwardList(list);
    print(list);
    return 0;
}