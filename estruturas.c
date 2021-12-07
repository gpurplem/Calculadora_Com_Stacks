struct elpilha {
	float valor;
	struct elpilha* ant;
};

typedef struct elpilha elpilha;

struct lista_de_pilhas {
	int id;
	elpilha* pilha;
	struct lista_de_pilhas* prox;
};

typedef struct lista_de_pilhas lista_de_pilhas;

/*struct vetorDinamicoInt {
	int valor;
	struct vetorDinamicoInt* prox;
};

typedef struct vetorDinamicoInt vetorDinamicoInt;*/