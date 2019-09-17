//Implementação de Grafo com lista de Adjacência
//Nicolas Fernandes de Lima
//Sarah Silveira

#include <iostream>
#include <list>

using namespace std;

typedef int Vertex;


using namespace std;

// classe No
class No
{
private:
	int v;
	No* prox;
public:
	No(int v) // construtor
	{
		this->v = v;
		this->prox = NULL;
	}

	int obterValor() // obtém o valor
	{
		return v;
	}

	No* obterProx() // obtém o próximo No
	{
		return prox;
	}

	void setProx(No* p) // seta o próximo No
	{
		prox = p;
	}
};

// classe Lista
class Lista
{
private:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento

public:
	Lista()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(int v)
	{
		// se passar elemento, então cria novo No
		cabeca = new No(v);
		cauda = cabeca;
	}

	virtual ~Lista() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da lista
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a lista
			{
				cout << c->obterValor() << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a lista está vazia
	{
		return (cabeca == NULL);
	}

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(int v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->setProx(cabeca);
			cabeca = novo_no;
		}
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(int v)
	{
		No* c = cabeca;
		
		while(c)
		{
			if(c->obterValor() == v)
				return true;
			c = c->obterProx();
		}
		return false;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void remover()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(cabeca->obterProx() == NULL)
				cabeca = NULL;
			else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
				cabeca->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = cabeca;
				No* ant = cabeca->obterProx();
				No* corrente = cabeca->obterProx()->obterProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			}
		}
	}
};


class Graph
{ // Não-direcionado
    Lista *adj;
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
    adj = new Lista[n + 1]; // Vetor usa
    // células de 1..n
}

void Graph::insertEdge(Vertex u, Vertex v)
{    // chave = vértice
    adj[u].inserir_final({v}); // Insere na lista
    adj[v].inserir_final({u}); // Insere na lista
    m++;
}

void Graph::print()
{
    Graph.Lista.mostrar();
};

void Graph::destroy()
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].remover(); // destroi lista
    }
    delete (adj);
    n = m = 0;
}

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