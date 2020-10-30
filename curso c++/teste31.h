#ifndef TESTE30_H_INCLUDED
#define TESTE30_H_INCLUDED

class carros{
    public:
        carros(int initp);
       // void impr();
        int getvelmax();// sem get e set nao precisa so colocar velmax normal
        bool getvendido();
        void setvendido(int v);

    private:
        std::string nome;
        void setvelmax(int vel);
        std::string tipo;
        int velmax;
        bool vendido;
};

bool carros::getvendido(){
    return vendido;
}
void carros::setvendido(int v){
    if(v==1){
        vendido=true;
    }else if(v==0){
        vendido=false;
    }
}

int carros::getvelmax(){// metodo direto nao usa get
    return velmax;
}
void carros::setvelmax(int vel){// metodo direto nao usa set
    velmax=vel;
}

//1= AR, 2= SR, 3= pistol
carros::carros(int initp){// metodo construtor
    if (initp==1){
        //velmax= 300;
        setvelmax(300);
        tipo= "carro1";
    }else if(initp==2){
        //velmax= 150;
        setvelmax(150);
        tipo= "carro2";
    }else if(initp==3){
        //velmax= 15;
        setvelmax(15);
        tipo= "carro3";
    }/*else if(initp>=4){
        std::cout << "Nao tem esse tipo associado no codico" << "\n";
    }*/
}

/*void carros::impr(){
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "velmax: " << velmax << "\n";//velmax normal sem set e get funcional do mesmo jeito
    std::cout << std::endl;
}*/

#endif // TESTE30_H_INCLUDED
