//klasa pola składająca się z współrzędnych x i y oraz pola z nazwą piona
class Pole{
    private:
    //numer wiersza
        int x;
    //numer koluny
        int y;
        char pion;
//b-biały pion, c-czarny pion, B-biała dama, C-czarna dama, p-puste pole
    public:
        Pole(){
            this->x=0;
            this->y=0;
            this->pion=' ';
        }
        void set(int x, int y, char pion){ //funkcja ustawiania danych w obiekcie w trakcie tworzenia planszy do gry
            this->x=x;
            this->y=y;
            this->pion=pion;
        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
        char getPion(){
            return this->pion;
        }
        void zamien(char a){
            this->pion = a;
        }
};
