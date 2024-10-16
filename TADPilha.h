#define MAXPILHA 33

struct TpPilhaM3{
    int TOPO[MAXPILHA], BASE[MAXPILHA];
    char PILHA[MAXPILHA];
};
void Inicializar(TpPilhaM3 &PM, int qtdPilhas) {
    int qtdElemen = MAXPILHA / qtdPilhas;
    int BASE[qtdPilhas], TOPO[qtdPilhas];
    
    for (int i = 0; i < qtdPilhas + 1; i++) {
        PM.BASE[i] = i * qtdElemen;
        PM.TOPO[i] = i * qtdElemen - 1;
    }
}

void Push(TpPilhaM3 &PM, int elemento, int NP) {
    PM.PILHA[++PM.TOPO[NP]] = elemento;
}

int Pop(TpPilhaM3 &PM, int NP) {
    return PM.PILHA[PM.TOPO[NP]--];
}

int ElementoTopo(TpPilhaM3 PM, int NP) {
    return PM.PILHA[PM.TOPO[NP]];
}

char PilhaVazia(TpPilhaM3 PM, int NP) {
    return PM.TOPO[NP] < PM.BASE[NP];
}

char PilhaCheia(TpPilhaM3 PM, int NP) {
    return PM.TOPO[NP] + 1 == PM.BASE[NP + 1];
}

void ExibirPilha(TpPilhaM3 PM, int NP) { 
    while(!PilhaVazia(PM, NP)) {
        printf("%c\n", Pop(PM, NP));
    }
}