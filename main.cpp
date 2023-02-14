#include <QCoreApplication>
#include <iostream>
#include <math.h>




class Vector{
public:

    virtual double vectorLengths(){std::cout<<"virtual";}
};


class Vector1:public Vector{
    double x1;

public:
    Vector1(double x1){
        this->x1 = x1;
    }
    double vectorLengths(){
        return fabs(x1);
    }

};


class Vector2:public Vector{
    double x1;
    double x2;
public:
    Vector2(double x1,double x2){
        this->x1 = x1;
        this->x2 = x2;
    }

    double vectorLengths(){
        return sqrt(x2*x2 + x1*x1);
    }

};


struct Element{
    Vector vector;
    Element *next;
};



class VectList{
Element *head = NULL;

public:
    void addElement(Vector* vector){
        Element *newElement = new Element();

        newElement->vector = *vector;
        newElement->next = NULL;

        if(head == NULL){
            head = newElement;
        }else{
            Element *current = head;
            while(current->next!=NULL){
                current = current->next;
            }
            current->next = newElement;
        }
    }

    void printLength(){
        Element *current = head;
        while(current->next!=NULL){
            std::cout << current->vector.vectorLengths()<<std::endl;
            current = current->next;
        }
    }
};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vector1 v1(3.42);
    Vector2 v2(3.42,80.23);
    Vector1 v3(783.0);
    Vector2 v4(123.19,43.23);
    Vector1 v5(9.23);

    VectList list;

    list.addElement(&v1);
    list.addElement(&v2);
    list.addElement(&v3);
    list.addElement(&v4);
    list.addElement(&v5);

    list.printLength();

    return a.exec();
}
