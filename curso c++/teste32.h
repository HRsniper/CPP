#ifndef TESTE30_H_INCLUDED
#define TESTE30_H_INCLUDED

class Veiculo{
public:
    int vel;
    int sa;//santo antonio
    int rodas;
    void settipo(int tp);
    void setvelmax(int vm);
    void setnitro(bool nt);
    int gettipo();
    void imp();
private:
    int tipo;
    int velmax;
    bool nitro;
};

//opter private tipo por set
int Veiculo::gettipo(){
    return tipo;
}
//manipular private tipo
void Veiculo::settipo(int tp){
    tipo=tp;
}
//manipular private velmax
void Veiculo::setvelmax(int vm){
    velmax=vm;
}
//manipular private nitro
void Veiculo::setnitro(bool nt){
    nitro=nt;
}

// herdou de veiculo os public
class Carro:public Veiculo{
public:
    Carro();
private:
};
//construtor
Carro::Carro(){
    vel=0;
    sa=0;
    rodas=4;
    settipo(1);
    setvelmax(150);
    setnitro(true);
}
// herdou de veiculo os public
class Moto:public Veiculo{
public:
    Moto();
private:
};
//construtor
Moto::Moto(){
    vel=0;
    sa=0;
    rodas=2;
    settipo(2);
    setvelmax(125);
    setnitro(false);
}

// herdou de veiculo os public
class Carrosa:public Veiculo{
public:
    Carrosa();
private:
};
//construtor
Carrosa::Carrosa(){
    vel=0;
    sa=1;
    rodas=6;
    settipo(3);
    setvelmax(200);
    setnitro(true);
}

// imp esta dentro da classe entao nao precisa usa metodo set
void Veiculo::imp(){
    std::cout << "tipo: " << tipo << "\n";
    std::cout << "velmax: " << velmax << "\n";
    std::cout << "nitro: " << nitro << "\n";
    std::cout << "vel: " << vel << "\n";
    std::cout << "sa: " << sa << "\n";
    std::cout << "rodas: " << rodas << "\n";
    std::cout << "**********" << "\n";
}

#endif // TESTE30_H_INCLUDED
