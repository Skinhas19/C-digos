#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
} Pizza;

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[100];
} Cliente;

typedef struct
{
    int codigo_pizza;
    int codigo_cliente;
    int qtd_pizza;
    float valor_pago;
} Venda;

int verificar_codigo_existente(int codigo, Pizza *pizzas, int n)
{
    
	
	int i;
	
	for(i = 0; i < n; i++)
    {
        if (pizzas[i].codigo == codigo)
        {
            return 1;
        }
    }
    return 0;
}

int verificar_nome_existente(char *nome, Pizza *pizzas, int n)
{
    
	
	int i;
	for (i = 0; i < n; i++)
    {
        if (strcmp(pizzas[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int verificar_codigo_cliente_existente(int codigo, Cliente *clientes, int n)
{
    
	int i;
	
	for (i = 0; i < n; i++)
    {
        if (clientes[i].codigo == codigo)
        {
            return 1;
        }
    }
    return 0;
}

void cadastrar_pizzas(Pizza *pizzas, int *n_pizzas)
{
    
	int i;
	printf("Digite o número de pizzas que deseja cadastrar: ");
    scanf("%d", n_pizzas);
    pizzas = realloc(pizzas, (*n_pizzas) * sizeof(Pizza));

    for (i = 0; i < *n_pizzas; i++)
    {
        printf("Digite os dados da pizza %d:\n", i + 1);

        do
        {
            printf("Código: ");
            scanf("%d", &pizzas[i].codigo);
            if (verificar_codigo_existente(pizzas[i].codigo, pizzas, i))
            {
                printf("Código já em uso. Digite um novo código.\n");
            }
        } while (verificar_codigo_existente(pizzas[i].codigo, pizzas, i));

        do
        {
            printf("Nome: ");
            scanf("%s", pizzas[i].nome);
            if (verificar_nome_existente(pizzas[i].nome, pizzas, i))
            {
                printf("Nome já em uso. Digite um novo nome.\n");
            }
        } while (verificar_nome_existente(pizzas[i].nome, pizzas, i));

        printf("Preço: ");
        scanf("%f", &pizzas[i].preco);
    }
}

void cadastrar_clientes(Cliente *clientes, int *n_clientes)
{
    int i;
	
	
	printf("Digite o número de clientes que deseja cadastrar: ");
    scanf("%d", n_clientes);
    clientes = realloc(clientes, (*n_clientes) * sizeof(Cliente));

    for (i = 0; i < *n_clientes; i++)
    {
        printf("Digite os dados do cliente %d:\n", i + 1);

        do
        {
            printf("Código: ");
            scanf("%d", &clientes[i].codigo);
            if (verificar_codigo_cliente_existente(clientes[i].codigo, clientes, i))
            {
                printf("Código já em uso. Digite um novo código.\n");
            }
        } while (verificar_codigo_cliente_existente(clientes[i].codigo, clientes, i));

        printf("Nome: ");
        scanf("%s", clientes[i].nome);

        printf("Endereço: ");
        scanf(" %[^\n]s", clientes[i].endereco);
    }
}

void gravar_pizzas(Pizza *pizzas, int n)
{
    
	int i;
	
	FILE *fp = fopen("pizzas.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo pizzas.txt\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", pizzas[i].codigo, pizzas[i].nome, pizzas[i].preco);
    }

    fclose(fp);
}

void gravar_clientes(Cliente *clientes, int n)
{
    
	int i;
	
	FILE *fp = fopen("clientes.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d,%s,%s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco);
    }

    fclose(fp);
}

void gravar_vendas(Venda *vendas, int n)
{
    
	int i;
	
	FILE *fp = fopen("vendas.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo vendas.txt\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d,%d,%d,%.2f\n", vendas[i].codigo_pizza, vendas[i].codigo_cliente, vendas[i].qtd_pizza, vendas[i].valor_pago);
    }

    fclose(fp);
}

Pizza *ler_pizzas(int *n)
{
    FILE *fp = fopen("pizzas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo pizzas.txt\n");
        return NULL;
    }

    Pizza *pizzas = NULL;
    *n = 0;
    Pizza p;

    while (fscanf(fp, "%d,%[^,],%f\n", &p.codigo, p.nome, &p.preco) == 3)
    {
        (*n)++;
        pizzas = realloc(pizzas, (*n) * sizeof(Pizza));
        pizzas[*n - 1] = p;
    }

    fclose(fp);
    return pizzas;
}

Cliente *ler_clientes(int *n)
{
    FILE *fp = fopen("clientes.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return NULL;
    }

    Cliente *clientes = NULL;
    *n = 0;
    Cliente c;

    while (fscanf(fp, "%d,%[^,],%[^\n]\n", &c.codigo, c.nome, c.endereco) == 3)
    {
        (*n)++;
        clientes = realloc(clientes, (*n) * sizeof(Cliente));
        clientes[*n - 1] = c;
    }

    fclose(fp);
    return clientes;
}

Venda *ler_vendas(int *n)
{
    FILE *fp = fopen("vendas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo vendas.txt\n");
        return NULL;
    }

    Venda *vendas = NULL;
    *n = 0;
    Venda v;

    while (fscanf(fp, "%d,%d,%d,%f\n", &v.codigo_pizza, &v.codigo_cliente, &v.qtd_pizza, &v.valor_pago) == 4)
    {
        (*n)++;
        vendas = realloc(vendas, (*n) * sizeof(Venda));
        vendas[*n - 1] = v;
    }

    fclose(fp);
    return vendas;
}

void imprimir_pizzas(Pizza *pizzas, int n)
{
    
	int i;
	
	printf("\nPizzas cadastradas:\n");
    for (i = 0; i < n; i++)
    {
        printf("Código: %d, Nome: %s, Preço: %.2f\n", pizzas[i].codigo, pizzas[i].nome, pizzas[i].preco);
    }
}

void imprimir_clientes(Cliente *clientes, int n)
{
    
	
	int i;
	printf("\nClientes cadastrados:\n");
    for (i = 0; i < n; i++)
    {
        printf("Código: %d, Nome: %s, Endereço: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco);
    }
}

void imprimir_vendas(Venda *vendas, int n)
{
    int i;
	
	printf("\nVendas realizadas:\n");
    for (i = 0; i < n; i++)
    {
        printf("Código da Pizza: %d, Código do Cliente: %d, Quantidade: %d, Valor Pago: %.2f\n", vendas[i].codigo_pizza, vendas[i].codigo_cliente, vendas[i].qtd_pizza, vendas[i].valor_pago);
    }
}

void imprimir_relatorio(Venda *vendas, int n)
{
    int qtd_total = 0,i;
    float valor_total = 0.0;
    for(i = 0; i < n; i++)
    {
        qtd_total += vendas[i].qtd_pizza;
        valor_total += vendas[i].valor_pago;
    }
    printf("\nRelatório do dia:\n");
    printf("Quantidade total de pizzas vendidas: %d\n", qtd_total);
    printf("Valor total recebido: %.2f\n", valor_total);
}

int main()
{
    int opcao;
    int n_pizzas = 0;
    int n_clientes = 0;
    int n_vendas = 0;
    Pizza *pizzas = NULL;
    Cliente *clientes = NULL;
    Venda *vendas = NULL;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Cadastrar pizzas\n");
        printf("2 - Cadastrar clientes\n");
        printf("3 - Gravar venda\n");
        printf("4 - Ler dados das pizzas\n");
        printf("5 - Ler dados dos clientes\n");
        printf("6 - Ler vendas\n");
        printf("7 - Imprimir relatório do dia\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar_pizzas(pizzas, &n_pizzas);
            break;
        case 2:
            cadastrar_clientes(clientes, &n_clientes);
            break;
        case 3:
            n_vendas++;
            vendas = realloc(vendas, n_vendas * sizeof(Venda));
            printf("Digite os dados da venda %d:\n", n_vendas);

            printf("Código da pizza: ");
            scanf("%d", &vendas[n_vendas - 1].codigo_pizza);

            printf("Código do cliente: ");
            scanf("%d", &vendas[n_vendas - 1].codigo_cliente);

            printf("Quantidade de pizza: ");
            scanf("%d", &vendas[n_vendas - 1].qtd_pizza);

            printf("Valor pago: ");
            scanf("%f", &vendas[n_vendas - 1].valor_pago);

            gravar_vendas(vendas, n_vendas);
            break;
        case 4:
            pizzas = ler_pizzas(&n_pizzas);
            imprimir_pizzas(pizzas, n_pizzas);
            break;
        case 5:
            clientes = ler_clientes(&n_clientes);
            imprimir_clientes(clientes, n_clientes);
            break;
        case 6:
            vendas = ler_vendas(&n_vendas);
            imprimir_vendas(vendas, n_vendas);
            break;
        case 7:
            vendas = ler_vendas(&n_vendas);
            imprimir_relatorio(vendas, n_vendas);
            break;
        case 0:
            printf("Obrigado por usar o programa. Até mais!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
