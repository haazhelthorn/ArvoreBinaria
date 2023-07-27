//  Alisson Max Menezes Oliveira
//  Estrutura de Dados em C
//  Turno da turma: Quinta : 18:30 as 21:00
//  
//  
//  Deverá ser implementado em C um sistema que armazene um número inteiro em uma árvore binária. E que também seja possível exibir o percurso escolhido pelo usuário, a saber: pré-ordem, em ordem pós-ordem. O sistema deverá possuir o seguinte menu:
//  
//  1 - Inserir nó na árvore
//  2 - Percurso em Pré-Ordem
//  3 - Percurso em ordem
//  4 - Percurso em Pós-ordem
//  
//  =======================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int chave;
  struct No *filho_esq;
  struct No *filho_dir;
} No;

No* novo_no (int chave) {
  No* no = (No*)malloc(sizeof(No));
  no -> chave = chave;
  no -> filho_esq = NULL;
  no -> filho_dir = NULL;
  return no;
}

void insere_arvore_binaria(No **raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = novo_no(chave);
    } else if (chave < (*raiz)->chave) {
        insere_arvore_binaria(&(*raiz)->filho_esq, chave);
    } else {
        insere_arvore_binaria(&(*raiz)->filho_dir, chave);
    }
}


void pre_ordem (No *ptr) {
  printf("%d ", ptr -> chave );
  if (ptr -> filho_esq != NULL)
    pre_ordem( ptr -> filho_esq );
  if (ptr -> filho_dir != NULL)
    pre_ordem( ptr -> filho_dir );
}

void ordem_sim (No *ptr) {
  if (ptr -> filho_esq != NULL)
    ordem_sim( ptr -> filho_esq );
  printf("%d ", ptr -> chave );
  if (ptr -> filho_dir != NULL)
    ordem_sim( ptr -> filho_dir );
} 

void pos_ordem (No *ptr) {
  if (ptr -> filho_esq != NULL)
    pos_ordem( ptr -> filho_esq );
  if (ptr -> filho_dir != NULL)
    pos_ordem( ptr -> filho_dir );
  printf("%d ", ptr -> chave );
} 

int main(void) {
  int opcao, data;
  No* pai = NULL;
  do{
    printf("\nMenu:\n");
    printf("1 - Inserir nó na árvore\n");
    printf("2 - Percurso em Pré-Ordem\n");
    printf("3 - Percurso em ordem\n");
    printf("4 - Percurso em Pós-ordem\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 0:
        printf("Encerrando o programa.\n");
        break;
      case 1:
        printf("Digite um número inteiro para inserir na árvore: ");
        scanf("%d", &data);
        insere_arvore_binaria(&pai, data);
        break;
      case 2:
        printf("Percurso em Pré-Ordem: ");
        pre_ordem(pai);
        printf("\n");
        break;
      case 3:
        printf("Percurso em ordem: ");
        ordem_sim(pai);
        printf("\n");
        break;
      case 4:
        printf("Percurso em Pós-ordem: ");
        pos_ordem(pai);
        printf("\n");
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
      }
  } while (opcao != 0);

free(pai);
return 0;}
