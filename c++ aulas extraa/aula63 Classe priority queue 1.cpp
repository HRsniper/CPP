/*  queue - FIFO = fist in , first out
    priority queue = fila de prioridade
 */
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
	priority_queue<int> pqueue;
	// priority_queue<int, vector<int>, greater<int> > pqueue; // inverte a prioridade

	pqueue.push(20);
	pqueue.push(15);
	pqueue.push(50);

	cout << "Elemento do topo: " << pqueue.top() << endl;

	if(pqueue.empty()) {
		cout << "\nFila vazia!!\n";
    } else {
		cout << "\nFila NAO vazia!!\n";
    }

	cout << "\nTamanho da fila: " << pqueue.size() << endl;

	cout << "\nMostrando os elementos: ";
	while(!pqueue.empty()) {
		cout << pqueue.top() << " ";
		pqueue.pop();
	}

	cout << endl;

	return 0;
}
