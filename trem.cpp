#include "trem.h"
#include <QtCore>

static QMutex mutex[7];

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 40;
    this->incremento = 5;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            this->incremento = 5;
            if(x == 300 && y == 30) {
                if(mutex[1].tryLock()) {
                    if(!mutex[0].tryLock()) {
                        this->incremento = 0;
                        mutex[1].unlock();
                    }
                } else {
                    this->incremento = 0;
                }
            }
            else if(x == 310 && y == 150) {
                mutex[0].unlock();
            }
            else if(x == 175 && y == 150) {
                mutex[1].unlock();
            }
            if (y == 30 && x < 330) {
                x+=this->incremento;
            }
            else if (x == 330 && y < 150) {
                y+=this->incremento;
            }
            else if (x > 60 && y == 150)
                x-=this->incremento;
            else
                y-=this->incremento;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            this->incremento = 5;
            if(x == 570 && y == 30) {
                mutex[3].lock();
            }
            else if(x == 600 && y == 130) {
                mutex[4].lock();
            }
            else if(x == 580 && y == 150) {
                mutex[3].unlock();
            }
            else if(x == 445 && y == 150) {
                mutex[4].unlock();
            }
            else if(x == 485 && y == 150) {
                mutex[2].lock();
            }
            else if(x == 350 && y == 150) {
                mutex[0].lock();
            }
            else if(x == 330 && y == 130) {
                mutex[2].unlock();
            }
            else if(x == 350 && y == 30) {
                mutex[0].unlock();
            }
            if (y == 30 && x <600)
                x+=this->incremento;
            else if (x == 600 && y < 150)
                y+=this->incremento;
            else if (x > 330 && y == 150)
                x-=this->incremento;
            else
                y-=this->incremento;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            this->incremento = 5;
            if(x == 755 && y == 150) {
                if(mutex[5].tryLock()) {
                    if(!mutex[3].tryLock()) {
                        this->incremento = 0;
                        mutex[5].unlock();
                    }
                } else {
                    this->incremento = 0;
                }
            }
            else if(x == 600 && y == 130) {
                mutex[5].unlock();
            }
            else if(x == 620 && y == 30) {
                mutex[3].unlock();
            }

            if(y  == 30 && x < 870) {
                x+=this->incremento;
            }
            else if(x == 870 && y < 150) {
                y+=this->incremento;
            }
            else if(x > 600 && y == 150 ) {
                x-=this->incremento;
            } else {
                y-=this->incremento;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:
            this->incremento = 5;
            if(x == 195 && y == 170) {
                if(!mutex[1].tryLock()) {
                    this->incremento = 0;
                }
            } else if(x == 300 && y == 150) {
                if(mutex[6].tryLock()) {
                    if(!mutex[2].tryLock()) {
                        this->incremento = 0;
                        mutex[6].unlock();
                    }
                } else {
                    this->incremento = 0;
                }
            }
            else if(x == 350 && y == 150 ) {
                mutex[1].unlock();
            }
            else if(x == 440 && y == 270) {
                mutex[6].unlock();
            }
            else if(x == 465 && y == 170) {
                mutex[2].unlock();
            }
            if(y == 150 && x < 465)
                x+=this->incremento;
            else if(x == 465 && y < 270)
                y+=this->incremento;
            else if(x > 195 && y == 270)
                x-=this->incremento;
            else
                y-=this->incremento;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:
            this->incremento = 5;
            if(x == 490 && y == 270) {
                if(mutex[4].tryLock()) {
                    if(!mutex[6].tryLock()) {
                        this->incremento = 0;
                        mutex[4].unlock();
                    }
                } else {
                    this->incremento = 0;
                }
            } else if(x == 570 && y == 150) {
                if(!mutex[5].tryLock()) {
                    this->incremento = 0;
                }
            }
            else if(x == 620 && y == 150 ) {
                mutex[4].unlock();
            }
            else if(x == 735 && y == 170) {
                mutex[5].unlock();
            }
            else if(x == 485 && y == 150) {
                mutex[6].unlock();
            }

            if(y == 150 && x < 735) {
                x+=this->incremento;
            } else if(x == 735 && y < 270) {
                y+=this->incremento;
            } else if(x > 465 && y == 270) {
                x-=this->incremento;
            } else {
                y-=this->incremento;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}
