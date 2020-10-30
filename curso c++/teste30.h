#ifndef TESTE30_H_INCLUDED
#define TESTE30_H_INCLUDED

class Armas{
    public:
        std::string tipo;
        int capmax;
        Armas(int initp);
        void impr();

    private:
        /* codico */
};

//1= AR, 2= SR, 3= pistol
Armas::Armas(int initp){// metodo construtor
    if (initp==1){
        capmax= 30;
        tipo= "AR";
    }else if(initp==2){
        capmax= 5;
        tipo= "SR";
    }else if(initp==3){
        capmax= 15;
        tipo= "Pistol";
    }else if(initp>=4){
        std::cout << "Nao tem esse tipo associado no codico" << "\n";
    }
}

void Armas::impr(){
    std::cout << "Tipo da arma......: " << tipo << "\n";
    std::cout << "capacidade da arma: " << capmax << "\n";
    std::cout << std::endl;
}

#endif // TESTE30_H_INCLUDED
