#include <iostream>
using namespace std;

template<typename T>
class List
{

    struct Node
    {
        T value;
        Node* next;
        Node() :value(0), next(nullptr) {}
        Node(T value, Node* next) :value(value), next(next) {}
    };

    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value) // []<-[]<-[]
    {
        Node* newNode = new Node(value, head);
        /*newNode->value = value;
        newNode->next = head;*/
        head = newNode;
    }
    void Print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << " " << current->value;
            current = current->next;
        }
        cout << endl;
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void DeleteFromTail()
    {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void DeleteFromHead()
    {
        if (head == nullptr)return;
        Node* current = head;
        head = head->next;
        delete current;
    }

    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
};



class Point
{
    int x;
    int y;
public:
    Point() :x(0), y(0) {}
    Point(int x, int y) :x(x), y(y) {}
    int GetX()const { return x; }
    int GetY()const { return y; }
};

ostream& operator <<(ostream& out, const Point& point)
{
    out << point.GetX() << " " << point.GetY() << endl;
    return out;
}

class Vector
{
    List<Point> list;
    int size;

public:
    Vector() :size(0){}
    void AddPointToHead(Point p)
    {
        list.AddToHead(p);
        size++;
    }
    void AddPointToTail(Point p)
    {
        list.AddToTail(p);
        size++;
    }
    void DeletePointFromHead()
    {
        list.DeleteFromHead();
        size--;
    }
    void DeletePointFromTail()
    {
        list.DeleteFromTail();
        size--;
    }
    void Print()
    {
        cout << "List size is " << size << endl;
        list.Print();
    }
};
int main()
{
    //List l;

    //l.AddToTail(100);
    //l.AddToTail(200);
    //l.AddToTail(300);
    //l.Print();
    ////l.DeleteFromTail();
    ////l.Print();
    ////l.DeleteFromTail();
    ////l.Print();
    //l.DeleteFromHead();
    //l.Print();
    //l.DeleteFromHead();
    //l.Print();
    //l.DeleteFromHead();
    //l.Print();

    Vector vector;
    vector.AddPointToHead({1,2});
    vector.AddPointToHead({2,3});
    vector.AddPointToHead({4,5});
    vector.AddPointToHead({6,4});
    vector.Print();
    vector.DeletePointFromTail();
    vector.Print();
    vector.DeletePointFromHead();
    vector.Print();
}