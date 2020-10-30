#include <iostream>

using namespace std;

int main(){

    enum armas{ARscarh=30, SRchaytec=5, SG12=7, SMGmp5=25};
	armas selecaoarmas0;
	armas selecaoarmas1;
	armas selecaoarmas2;
	armas selecaoarmas3;

	selecaoarmas0=ARscarh;
	selecaoarmas1=SRchaytec;
	selecaoarmas2=SG12;
	selecaoarmas3=SMGmp5;

	cout << "quantidade de municao Scar-H: " << selecaoarmas0 << "\n";
	cout << "quantidade de municao ChayTec: " << selecaoarmas1 << "\n";
	cout << "quantidade de municao 12: " << selecaoarmas2 << "\n";
	cout << "quantidade de municao Mp5: " << selecaoarmas3 << "\n";

	system("pause");return 0;
}
