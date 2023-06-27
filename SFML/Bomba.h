
class bomb {
private:
    int posX;
    int posY;
    int time;
    int cant;
    int longitud;
public:
    bomb(int x, int y, int t) : posX(x), posY(y), time(t) {
    }
    void actualizar() {
        time--;
    }
    bool explosion() {
        if (time == 0) {
            return true;
        }
    }
    int getposX() {
        return posX;
    }int getposY() {
        return posY;
    }
};
