//Implementação de Grafo com lista de Adjacência
//Nicolas Fernandes de Lima
//Sarah Silveira

#include <iostream>
#include <list>

using namespace std;

typedef int Vertex;


template <typename Tipo>
class No{
private:
	Tipo item;
	No<Tipo> *prox;
public:
	No(){
		prox = NULL;
	}
	No(Tipo){
		this->item = item;
	}
	No<Tipo>* getProx(){
		return prox;
	}
	void setProx(No<Tipo>* prox){
		this->prox = prox;
	}
	Tipo getItem(){
		return item;
	}
	void setItem(Tipo item){
		this->item=item;
	}

};

template <typename Tipo>
class Lista{
private:
	No<Tipo>* prim;
	No<Tipo>* ult;
	bool vazia();
public:
	Lista(){
		cria();
	};
	
	void cria();
	void insereObj(Tipo);
	void removePrim();
	void imprime();
	No<Tipo>* busca(Lista l, char c);
	No<Tipo>* buscaObj(string);
	void imprimeObj();
};

template <typename Tipo>
void Lista<Tipo>::cria(){
	prim = new No<Tipo>;
	prim->setProx(NULL);
	prim->setL(NULL);
	ult = prim;
}
template <typename Tipo>
bool Lista<Tipo>::vazia(){
	return prim == ult;
}

template <typename Tipo>
void Lista<Tipo>::insereObj(Tipo i){
	ult->setProx(new No<Tipo>());
	ult = ult->getProx();
	ult->setProx(NULL);
	ult->setItem(i);
}

template <typename Tipo>
void Lista<Tipo>::imprime(){
	No<Tipo> *p = prim->getProx();
	while(p != NULL){
		cout << p->getL().getLetra();
		p = p->getProx();
	}
	cout << endl;
}

template <typename Tipo>
void Lista<Tipo>::imprimeObj(){
	No<Tipo> *p = prim->prox;
	while(p != NULL){
		cout << "(" << p->item.codigo << "," << p->item.letra <<")";
		p = p->prox;
		cout << endl;
	}
}


class Graph
{ // Não-direcionado
    Lista<Vertex> *adj;
    int n, m; // ordem e tamanho
    void destroy();

public:
    Graph(int); // construtor
    void initialize(int);
    void insertEdge(Vertex, Vertex);
    void print();
    // métodos get/set para n, m e adj.
};

Graph::Graph(int n)
{
    initialize(n);
}

void Graph::initialize(int n)
{
    if (this->n != 0)
        destroy();
    this->n = n;
    adj = new Lista<Vertex>[n + 1]; // Vetor usa
    // células de 1..n
}

void Graph::insertEdge(Vertex u, Vertex v)
{    // chave = vértice
    adj[u].insereObj({v}); // Insere na lista
    adj[v].insereObj({u}); // Insere na lista
    m++;
}

void Graph::print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "v[" << i << "] = ";
        adj[i].imprimeObj();
    }
};

// void Graph::destroy()
// {
//     for (int i = 0; i <= n; i++)
//     {
//         adj[i].destroy(); // destroi lista
//     }
//     delete (adj);
//     n = m = 0;
// }

// Função auxiliar
void testaGrafo(Graph &g)
{
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    g.insertEdge(4, 5);
    g.insertEdge(5, 1);
    g.insertEdge(5, 2);
    g.insertEdge(2, 4);
    g.print();
}

int main(int argc, const char *argv[])
{
    int n, m;
    cout << "ordem: ";
    cin >> n;
    Graph g(n);
    testaGrafo(g);

    return 0;
}