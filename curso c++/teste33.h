#ifndef TESTE30_H_INCLUDED
#define TESTE30_H_INCLUDED

class Base1{
public:
    void impb1();
private:
};
//construtor
void Base1::impb1(){
     std::cout << "Base1" << std::endl;
}

class Base2{
public:
    void impb2();
private:
};
//construtor
void Base2::impb2(){
    std::cout << "Base2" << std::endl;
}

class Base3{
public:
    void impb3();
private:
};
//construtor
void Base3::impb3(){
    std::cout << "Base3" << std::endl;
}

class Classe4:public Base1,public Base2,public Base3{
public:

private:
};

#endif // TESTE30_H_INCLUDED
