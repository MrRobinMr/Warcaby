#include <iostream>

class Ruch{ //klasa odpowiadająca za kontrole pól i pionów w czasie ruchu
private:
    char k;
    int x1; //1 odpowiada za adres z wybranego pola a 2 odpowiada za adres gdzie ma być wykonany ruch
    int y1;
    int x2;
    int y2;
public:
    Ruch(char k){
        this->k=k;
    }
    void podajX1(){
        char X=0;
        std::cout<<"Podaj numer wiersza:\n";
        std::cin>>X;
        this->x1=int(X-'0');
    }
    void podajY1(){
        char Y=0;
        std::cout<<"Podaj numer kolumny:\n";
        std::cin>>Y;
        this->y1=int(Y-'0');
    }
    void podajX2(){
        char X=0;
        std::cout<<"Podaj numer wiersza 2:\n";
        std::cin>>X;
        this->x2=int(X-'0');
    }
    void podajY2(){
        char Y=0;
        std::cout<<"Podaj numer kolumny 2:\n";
        std::cin>>Y;
        this->y2=int(Y-'0');
    }
    int wypiszX1(){
        return this->x1;
    }
    int wypiszX2(){
        return this->x2;
    }
    int wypiszY1(){
        return this->y1;
    }
    int wypiszY2(){
        return this->y2;
    }
    char wypiszk(){
        return this->k;
    }
};
