#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para usar bool

    struct Carta {
        char estado;
        char codigo[4];
        char nomeDaCidade[50];
        unsigned long int populacao;
        float area;
        float pib;
        int pontosTuristicos;
        float densidadePopulacional;
        float pibPerCapita;
        double superPoder;  //usei double porque o valor ficou grande pois converti a densidade invertida para ficar melhor de visualizar, pois retornava um nuemro 0,00000 e queria que ficasse 123,45678 por exemplo
    };
    
    //variaveis globais para armazenar os resultados das comparações
    bool resultadoPopulacao, resultadoArea, resultadoPib, resultadoPontosTuristicos, resultadoDensidadePopulacional, resultadoPibPerCapita, resultadoSuperPoder;
    short int a = 0, b = 0; //guardar os pontos de cada jogador

    void lerCartas(struct Carta *ptr){
        fpurge(stdin);
        printf("Digite o estado da cidade: ");
        scanf("%c", &ptr->estado);
        printf("Digite o código da cidade: ");      
        scanf("%s", ptr->codigo);
        printf("Digite o nome da cidade: ");
        scanf("%s", ptr->nomeDaCidade);
        fpurge(stdin);
        printf("Digite a população da cidade: ");
        scanf("%lu", &ptr->populacao);
        printf("Digite a área da cidade: ");
        scanf("%f", &ptr->area);
        printf("Digite o PIB da cidade: ");
        scanf("%f", &ptr->pib);
        printf("Digite os pontos turisticos da cidade: ");
        scanf("%d", &ptr->pontosTuristicos);
    }

    void exibirCartas(struct Carta x){
        printf("Estado: %c\n", x.estado);
        printf("Codigo: %s\n", x.codigo);
        printf("Nome da Cidade: %s\n", x.nomeDaCidade);
        printf("Populacao: %lu\n", x.populacao);
        printf("Area: %.2f km²\n", x.area);
        printf("PIB: %.2f bilhões de reais\n", x.pib);
        printf("Pontos Turisticos: %d\n", x.pontosTuristicos);
        x.densidadePopulacional = (float)x.populacao / x.area;
        x.pibPerCapita = (x.pib*1e9) / (float)x.populacao; //pesquisei e usei 1e9(mesma coisa que multiplicar por 1.000.000.000) para converter reais para bilhões exemplo 699.28 reais fica 699.280.000.000 reais
        x.superPoder = (float)x.populacao + x.area + x.pib + (float)x.pontosTuristicos + x.pibPerCapita + (1 / x.densidadePopulacional * 1e6);
        printf("Densidade Populacional: %.2f hab/km²\n", x.densidadePopulacional);
        printf("PIB per Capita: %.2f reais/habitante\n", x.pibPerCapita);
        printf("Super Poder: %.2lf\n", x.superPoder);
    }

    void logicaBoolean(struct Carta x, struct Carta y){
        resultadoPopulacao = x.populacao > y.populacao;
        resultadoArea = x.area > y.area;
        resultadoPib = x.pib > y.pib;
        resultadoPontosTuristicos = x.pontosTuristicos > y.pontosTuristicos;
        resultadoDensidadePopulacional = x.densidadePopulacional < y.densidadePopulacional;
        resultadoPibPerCapita = x.pibPerCapita > y.pibPerCapita;
        resultadoSuperPoder = x.superPoder > y.superPoder;
        }
    
    void menuComparacao(struct Carta x, struct Carta y){
        //Exibrir o Menu para escolher qual atributo sera comparado
        short int opcao;
        printf("Escolha qual atributo deseja comparar:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turisticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("Opcao: ");
        scanf("%hd", &opcao);

        //Menu para escolher qual atributo será comparado
        switch(opcao){
            case 1:
                if (resultadoPopulacao){
                    a++;
                    printf("A cidade %s possui mais população que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);

                }else{
                    b++;
                    printf("A cidade %s possui mais população que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 2:
                if (resultadoArea){
                    a++;
                    printf("A cidade %s possui mais área que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);
                }else{
                    b++;
                    printf("A cidade %s possui mais área que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 3:
                if (resultadoPib){
                    a++;
                    printf("A cidade %s possui mais PIB que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);
                }else{
                    b++;
                    printf("A cidade %s possui mais PIB que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 4:
                if (resultadoPontosTuristicos){
                    a++;
                    printf("A cidade %s possui mais pontos turisticos que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);
                }else{
                    b++;
                    printf("A cidade %s possui mais pontos turisticos que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 5:
                if (resultadoDensidadePopulacional){
                    a++;
                    printf("A cidade %s possui menos densidade populacional que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);
                }else{
                    b++;
                    printf("A cidade %s possui menos densidade populacional que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 6:
                if (resultadoPibPerCapita){
                    a++;
                    printf("A cidade %s possui mais PIB per Capita que a cidade %s\n", x.nomeDaCidade, y.nomeDaCidade);
                }else{
                    b++;
                    printf("A cidade %s possui mais PIB per Capita que a cidade %s\n", y.nomeDaCidade, x.nomeDaCidade);
                }
                break;
            case 7:
                if (resultadoSuperPoder){
                    a++;
                    printf("A Carta 1 possui mais Super Poder que a Carta 2\n");
                }else{
                    b++;
                    printf("A Carta 2 possui mais Super Poder que a Carta 1\n");
                }
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }    
    
    int main() {         
        //Comecar o programa limpando a tela do terminal
        system("clear");
        struct Carta carta1, carta2;
    
        //Chamar a função lerCartas para ler os dados de cada carta
        lerCartas(&carta1);
        system("clear");
        lerCartas(&carta2);
        system("clear");
    
        // Exibir as Cartas:
        exibirCartas(carta1);
        getchar(); //limpando o buffer
        printf("\nPressione Enter para continuar...");
        getchar();
        system("clear");
        exibirCartas(carta2);
        printf("\nPressione Enter para continuar...");
        getchar();
        system("clear");
        //Comparar as cartas e armarzenar os resultados nas variaveis globais do tipo Bool
        logicaBoolean(carta1, carta2);

        //Menu para escolher qual atributo será comparado
        menuComparacao(carta1, carta2);
        getchar(); //limpando o buffer
        printf("\nPressione Enter para continuar...");
        getchar();
        system("clear");
        menuComparacao(carta1, carta2);
        getchar(); //limpando o buffer
        printf("\nPressione Enter para continuar...");
        getchar();
        system("clear");

        //Exibir o resultado final
        if (a > b){
            printf("Carta 1 venceu!\n");
        }else if (a < b){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empate!\n");
        }
        
    
    
        return 0;
    }

    /*
    Programa esta comparando duas vezes, uma para cada atributo escolhido, e armazenando os pontos de cada jogador.
    */