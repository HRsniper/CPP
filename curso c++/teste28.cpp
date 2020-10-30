#include <iostream>

using namespace std;

class Armas{
    public:
        string tipo;
        int capmax;
        void tparma(int initp);

    private:
        /* codico */
};

//1= AR, 2= SR, 3= pistol
void Armas::tparma(int initp){
    if (initp==1){
        this-> capmax= 30;
        this-> tipo= "AR";
    }else if(initp==2){
        this-> capmax= 5;
        this-> tipo= "SR";
    }else if(initp==3){
        this-> capmax= 15;
        this-> tipo= "Pistol";
    }else if(initp>=4){
        cout << "Nao tem esse tipo associado no codico" << "\n";
    }
}


int main(){
    int i;

    Armas *arm1=new Armas();

    cout << "selecione [1]AR, [2]SR, [3]Pistol, [4 ou +]Nao tem" << endl;
    cout << "digite: ";
    cin >> i;

    arm1-> tparma(i);

    cout << "Tipo da arma......: " << arm1-> tipo << "\n";
    cout << "capacidade da arma: " << arm1-> capmax << "\n";

	system("pause");
	return 0;
}
