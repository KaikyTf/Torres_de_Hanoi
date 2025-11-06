# 🗼 Torres de Hanói (Implementação em C++)

Este projeto consiste na implementação do clássico jogo **Torres de Hanói**, desenvolvido como trabalho da disciplina de Estrutura de Dados.

---

## ✨ Funcionalidades e Características

* **Implementação Clássica:** Jogo Torres de Hanói, onde o objetivo é mover todos os discos da primeira para a última haste, seguindo as regras de que apenas um disco pode ser movido por vez e um disco maior nunca pode ser colocado sobre um disco menor.
* **TAD Pilha Múltipla:** A estrutura de dados central do projeto (`TADPilha.h`) utiliza o conceito de Pilha Múltipla (`TpPilhaM3`).
* **Interface Gráfica no Console:** O código utiliza as bibliotecas `conio2.h` e `windows.h` para criar uma interface visual no console, com cores e posicionamento de cursor.
* **Controle de Jogo:** O arquivo `Main.cpp` implementa o menu de seleção da quantidade de discos, o cálculo do número mínimo de movimentos necessários e a lógica de validação de movimentos.

---

## 💻 Estrutura do Código

O projeto é dividido em dois arquivos principais, que separam a definição da estrutura de dados da lógica do jogo:

| Arquivo | Descrição |
| :--- | :--- |
| `TADPilha.h` | **Definição do TAD Pilha Múltipla**. Contém a estrutura da pilha (`TpPilhaM3`) e as funções para manipulação dos elementos: `Inicializar`, `Push`, `Pop`, `ElementoTopo`, `PilhaVazia` e `PilhaCheia`. |
| `Main.cpp` | Contém o código do jogo. É responsável pela interface gráfica (`moldura`, `gotoxy`, `textcolor`), a interação com o usuário (`MenuDiscos`, leitura de movimentos) e a execução da lógica de Hanói utilizando as funções do TAD. |

---

## 🛠️ Requisitos e Compilação

### Requisitos

* **Linguagem:** C++.
* **Compilador C/C++:** Necessário para compilar o código.
* **Biblioteca `conio2.h`:** Essencial para os recursos de console (posicionamento e cores), e deve ser compatível com o ambiente de compilação.

### Como Compilar

Certifique-se de que os arquivos `Main.cpp` e `TADPilha.h` estão no mesmo diretório e que as dependências do console (`conio2.h`) estão configuradas corretamente no seu ambiente de desenvolvimento.
