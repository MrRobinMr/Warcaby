
//klasa kontrolująca plansze gry
#include <pole.cpp>
#include <iostream>
#include <ruch.cpp>

class Plansza{
    private:
        Pole* tab;
        int a;
        //zmienne zliczajace iczb pionow pozostalych na planszy
        int biale = 1;
        int czarne = 1;
    public:
        Plansza(int a){
            //tworzenie planszy o boku a
            this->a=a;
            this->tab = new Pole[(a*a)];
            for(int i=1;i<this->a+1;i++){
                for(int j=1;j<this->a+1;j++){
                    if(i<(this->a/2)){ //piony czarne
                        if(i%2==1 && j%2==0){
                            this->tab[this->convertXY(i,j)].set(i,j,'c');
                        }else if(i%2==0 && j%2==1){
                            this->tab[this->convertXY(i,j)].set(i,j,'c');
                        }else{
                            this->tab[this->convertXY(i,j)].set(i,j,'p');
                        }
                    }else if(i>(this->a/2+1)){ //pola białe
                        if(i%2==1 && j%2==0){
                            this->tab[this->convertXY(i,j)].set(i,j,'b');
                        }else if(i%2==0 && j%2==1){
                            this->tab[this->convertXY(i,j)].set(i,j,'b');
                        }else{
                            this->tab[this->convertXY(i,j)].set(i,j,'p');
                        }
                    }else{
                        this->tab[this->convertXY(i,j)].set(i,j,'p');
                    }
                }
            }
        }
        void wyczysc(){
            delete this->tab;
        }
        int convertXY(int x, int y){ //zamiana współrzędnych xy na numer obiektu w tablicy
            return (x*this->a+y);
        }
        Pole* getTab(){
            return this->tab;
        }
        void wypisz(){ //wypisywanie planszy
            for(int i=1;i<this->a+1;i++){
                for(int j=1;j<this->a+1;j++){
                    std::cout<<this->tab[this->convertXY(i,j)].getPion();
                    if(tab[this->convertXY(i,j)].getPion()=='b' || tab[this->convertXY(i,j)].getPion()=='B'){
                        this->biale = +1;
                    }
                    if(tab[this->convertXY(i,j)].getPion()=='c' || tab[this->convertXY(i,j)].getPion()=='C'){
                        this->czarne = +1;
                    }
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
        void zamien(int p1, int p2){
            char a = this->tab[p1].getPion();
            this->tab[p1].zamien('p');
            this->tab[p2].zamien(a);

        }
        bool spr(Ruch a){
            char znak = tab[convertXY(a.wypiszX1(),a.wypiszY1())].getPion();
            char znak2 = tab[convertXY(a.wypiszX2(),a.wypiszY2())].getPion();
            if(znak != a.wypiszk()){
                std::cout<<"Wbrano zly pionek wybierz ponownie"<<std::endl;
                return false;
            }else{
                if(znak2 == a.wypiszk()){
                    std::cout<<"nie mozesz sie tam ruszyc z"<<std::endl;
                    return false;
                }
                if(a.wypiszk()=='b'){
                    if(a.wypiszX1()<=a.wypiszX2()){
                        std::cout<<"nie mozesz sie tam ruszyc x"<<std::endl;
                        return false;
                    }
                    if(abs(a.wypiszY1()-a.wypiszY2())!=1){
                        std::cout<<"nie mozesz sie tam ruszyc y"<<std::endl;
                        return false;
                    }
                }
                if(a.wypiszk()=='c'){
                    if(a.wypiszX1()>=a.wypiszX2()){
                        std::cout<<"nie mozesz sie tam ruszyc x"<<std::endl;
                        return false;
                    }
                    if(abs(a.wypiszY1()-a.wypiszY2())!=1){
                        std::cout<<"nie mozesz sie tam ruszyc y"<<std::endl;
                        return false;
                    }
                }
            }
            return true;
        }
        bool sprBicie(int x, int y){
            int pole = this->convertXY(x,y);
            if(this->tab[pole].getPion()=='b'){
                if(this->tab[this->convertXY(x-1,y-1)].getPion()!='c' || this->tab[this->convertXY(x-1,y+1)].getPion()!='c'){
                    return false;
                }else{
                    if(this->tab[this->convertXY(x-2,y-2)].getPion()!='p' || this->tab[this->convertXY(x-2,y+2)].getPion()!='p'){
                        return false;
                    }
                }
            }
            if(this->tab[pole].getPion()=='c'){
                if(this->tab[this->convertXY(x+1,y-1)].getPion()!='b' || this->tab[this->convertXY(x+1,y+1)].getPion()!='b'){
                    return false;
                }else{
                    if(this->tab[this->convertXY(x+2,y-2)].getPion()!='p' || this->tab[this->convertXY(x+2,y+2)].getPion()!='p'){
                        return false;
                    }
                }
            }
            return false;
        }
        bool petlaBicia(char a){
            for(int i=1;i<this->a+1;i++){
                for(int j=1;j<this->a+1;j++){
                    if(this->tab[this->convertXY(i,j)].getPion()==a){
                        if(this->sprBicie(i,j)==true){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        Pole getPole(int x, int y){
            return this->tab[this->convertXY(x,y)];
        }
        int getBiale(){
            return this->biale;
        }
        int getCzarne(){
            return this->czarne;
        }
        void ruch(char k){
            if(k == 'b'){
                std::cout<<"ruch bialych"<<std::endl;
            }
            if(k == 'c'){
                std::cout<<"ruch czarnych"<<std::endl;
            }
            Ruch a = Ruch(k);
            do{
            a.podajX1();
            a.podajY1();
            a.podajX2();
            a.podajY2();
            }while(spr(a)==false);
            zamien(convertXY(a.wypiszX1(),a.wypiszY1()),convertXY(a.wypiszX2(),a.wypiszY2()));
        }

};
