#include <stdio.h>
#include <string.h>

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
int buscarISBN(struct Catalogo catalogo, char busca[]);

int main( int argc, char * argv[] ) {
    struct Catalogo livrosCatalogo;
    livrosCatalogo.quantidadeLivros = 0;

    int opcao;

    while(1) {
        printf("\n  Menu \n");
        printf("1. Adicionar Livro. \n");
        printf("2. Buscar livro por ISBN. \n");
        printf("3. Listar todos os livros. \n");
        printf("4. Listar livros por assunto.\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if(opcao == 5){
           break;
    }

        switch(opcao) {
            case 1:
                adicionarLivro(&livrosCatalogo);
                break;
            case 2: {
               char ISBNbuscado[20];
               printf("Digite o ISBN do livro: ");
               scanf(" %[^\n]", ISBNbuscado);
               int resultado = buscarISBN(livrosCatalogo, ISBNbuscado);
               if(resultado != -1) {
                  printf("Livro encontrado: %s\n", livrosCatalogo.livros[resultado].titulo);
               } else {
                    printf("Livro não encontrado.\n");
               }
               break;
            }
            case 3:
               break;
            case 4:
               break;
            default:
               printf("Opção inválida.\n");

}    
}
    
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

int buscarISBN(struct Catalogo catalogo, char busca[]) {
    for(int i = 0; i < catalogo.quantidadeLivros; i++) {
        if(strcmp(catalogo.livros[i].ISBN, busca) == 0) {
            return i;
        }
    }
    return -1;
}
