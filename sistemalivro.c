#include <stdio.h>

struct Livro {
	char titulo[50];
	char autor[50];
	char ISBN[20];
	int anopublicacao;
	char assunto[120];
};

struct Catalogo {
	struct Livro livros[100];
	int quantidadeLivros;
};

void adicionarLivro(struct Catalogo *catalogo);

int main( int argc, char * argv[] ) {
    struct Catalogo livrosCatalogo;
    livrosCatalogo.quantidadeLivros = 0;

    adicionarLivro(&livrosCatalogo);

    return 0;
}

void adicionarLivro(struct Catalogo *catalogo) {
    printf("Digite o titulo: ");
    scanf(" %[^\n]", catalogo->livros[catalogo->quantidadeLivros].titulo);

    printf("Digite o autor: ");
    scanf(" %[^\n]", catalogo->livros[catalogo->quantidadeLivros].autor);

    printf("Digite o ISBN: ");
    scanf(" %[^\n]", catalogo->livros[catalogo->quantidadeLivros].ISBN);

    printf("Digite o ano: ");
    scanf("%d", &catalogo->livros[catalogo->quantidadeLivros].anopublicacao);

    printf("Digite o assunto: ");
    scanf(" %[^\n]", catalogo->livros[catalogo->quantidadeLivros].assunto);

    catalogo->quantidadeLivros++;
}
