#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

struct Funcionario{
    char nome[100];
    char cargo[100];
    float salarioBase;
    float beneficios;
    float descontos;
};

struct Loja{
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int quantidade;
};

void cadastrarFuncionario(Loja *loja) {
    if (loja->quantidade >= MAX_FUNCIONARIOS) {
        printf("Nao e possível cadastrar mais funcionarios.\n");
        return;
    }
    Funcionario f;
    printf("Nome: ");
    scanf("%s", f.nome);
    printf("Cargo: ");
    scanf("%s", f.cargo);
    printf("Salário base: ");
    scanf("%f", &f.salarioBase);
    printf("Benefícios: ");
    scanf("%f", &f.beneficios);
    printf("Descontos: ");
    scanf("%f", &f.descontos);

    loja->funcionarios[loja->quantidade++] = f;
}

void exibirFuncionarios(Loja loja) {
    for (int i = 0; i < loja.quantidade; i++) {
        Funcionario f = loja.funcionarios[i];
        float salarioLiquido = f.salarioBase + f.beneficios - f.descontos;
        printf("\nFuncionario %d\n", i + 1);
        printf("Nome: %s\n", f.nome);
        printf("Cargo: %s\n", f.cargo);
        printf("Salario Liquido: %.2f\n", salarioLiquido);
    }
}

void exibirMedSal(Loja loja) {
    float somaSal = 0;
    for (int i = 0; i < loja.quantidade; i++) {
        Funcionario f = loja.funcionarios[i];
        somaSal += f.salarioBase + f.beneficios - f.descontos;
    }
    float mediaSalarial = somaSal / loja.quantidade;
    printf("\nMedia Salarial: %.2f\n", mediaSalarial);
}

void exibirMaiorSal(Loja loja) {
    if (loja.quantidade == 0) {
        printf("Nao há funcionarios cadastrados.\n");
        return;
    }

    Funcionario *fMaiorSalario = &loja.funcionarios[0];
    float maiorSalario = fMaiorSalario->salarioBase + fMaiorSalario->beneficios - fMaiorSalario->descontos;

    for (int i = 1; i < loja.quantidade; i++) {
        Funcionario *f = &loja.funcionarios[i];
        float salarioLiquido = f->salarioBase + f->beneficios - f->descontos;
        if (salarioLiquido > maiorSalario) {
            fMaiorSalario = f;
            maiorSalario = salarioLiquido;
        }
    }

    printf("\nMaior Salario:\n");
    printf("Nome: %s\n", fMaiorSalario->nome);
    printf("Cargo: %s\n", fMaiorSalario->cargo);
    printf("Salario Liquido: %.2f\n", maiorSalario);
}

int main() {
    Loja loja;
    loja.quantidade = 0;

    int opcao;
    do {printf("\n---------MENU---------    ");
        printf("\n1-> Cadastrar Funcionario\n");
        printf("2-> Listar Funcionarios\n");
        printf("3-> Exibir Madia Salarial\n");
        printf("4-> Exibir Maior Salario\n");
        printf("5-> Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(&loja);
                break;
            case 2:
                exibirFuncionarios(loja);
                break;
            case 3:
                exibirMedSal(loja);
                break;
            case 4:
                exibirMaiorSal(loja);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
