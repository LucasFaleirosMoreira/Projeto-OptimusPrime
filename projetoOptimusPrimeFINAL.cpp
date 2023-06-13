#include <iostream>
#include<iomanip>
#include<string>

using namespace std;

//Registro criado para armezenar os dados dos produtos que existem no estoque
struct estoque {
    string nome;
	float preco;
	int codigo;
	int quantidade;
};

  //declarando globais as variáveis usadas durante o decorrer do código
  int admCodigo;
  int admQuantidade = 0;
  char admResposta;
  int usuarioCodigo;
  int usuarioQuantidade = 0;
  char usuarioResposta;
  float usuarioDinheiro = 0;
  float valorTotalCompra = 0.00;
  float usuarioTroco = 0.00;
  char continuar;
	int resposta;
	int quantidade[10]{10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  double faturamentoProduto;
  double faturamentoTotal;
  double faturamentoAtual = 0;

  struct estoque produtos[10];

//função para inicializar os produtos com seus preços, nomes, quantidade e codigo de maneira global para o código inteiro 
  void iniciarProdutos(){
    produtos[0].codigo = 0;
    produtos[0].nome = "Água";
    produtos[0].preco = 3.00;
    produtos[0].quantidade = quantidade[0];
          	
    produtos[1].nome = "Toddynho";
    produtos[1].codigo = 1;
    produtos[1].preco = 4.59;
    produtos[1].quantidade = quantidade[1];
          
    produtos[2].nome = "Coca-cola";
    produtos[2].codigo = 2;
    produtos[2].preco = 4.99;
    produtos[2].quantidade = quantidade[2];
          	
    produtos[3].nome = "Guaraná antarctica";
    produtos[3].codigo = 3;
    produtos[3].preco = 4.99;
    produtos[3].quantidade = quantidade[3];
        
    produtos[4].nome = "Barra de chocolate";
    produtos[4].codigo = 4;
    produtos[4].preco = 2.00;
    produtos[4].quantidade = quantidade[4];
        
    produtos[5].nome = "Doritos";
    produtos[5].codigo = 5;
    produtos[5].preco = 9.99;
    produtos[5].quantidade = quantidade[5];
        
    produtos[6].nome = "Cheetos";
  	produtos[6].codigo = 6;
    produtos[6].preco = 5.59;
  	produtos[6].quantidade = quantidade[6];
        
    produtos[7].nome = "Fandangos";
    produtos[7].codigo = 7;
    produtos[7].preco = 6.99;
    produtos[7].quantidade = quantidade[7];
        
    produtos[8].nome = "Cebolitos";
    produtos[8].codigo = 8;
    produtos[8].preco = 8.99;
    produtos[8].quantidade = quantidade[8];
        
    produtos[9].nome = "Ruffles";
    produtos[9].codigo = 9;
    produtos[9].preco = 7.99;
    produtos[9].quantidade = quantidade[9];
  
  }

  //função para listar os produtos
  void listarProdutos(){

    //Mostrando os produtos definidos na tela
    for(int i = 0; i < 10; i++){	
      cout << "\n Código = " << produtos[i].codigo << "\n";
      cout << " Produto = " << produtos[i].nome << "\n";
      cout << " R$ " << produtos[i].preco << "\n";
      cout << " Quantidade no estoque = " << quantidade[i] << "\n";
      cout << " ----------------------------\n";
    }

  }

  //função para o administrador adicionar quantidade para algum produto
  void adicionarQuantidade(){
    
    listarProdutos();
            
			//Armazenando as escolhas do administrador
			cout << "\nDigite o código do produto que deseja alterar: ";
			cin >> admCodigo;
					
			cout <<"Digite a quantidade que deseja inserir no sistema (Digite -1 para colocar o produto como indisponível): ";
			cin >> admQuantidade;

      //definindo que um produto está indisponivel ou adicionando quantidade
      if(admQuantidade == -1){
        quantidade[admCodigo] = 0;
        produtos[admCodigo].nome = "Produto indisponível";
        produtos[admCodigo].preco = 0.00;
      }else 
				quantidade[admCodigo] += admQuantidade;
			
			//Verificação se o administrador deseja adicionar mais algum produto
			cout << "Deseja finalizar a edição de estoque? (S/s ou N/n) ";
			cin >> admResposta;
  }

  //função que mostra o faturamento possivel da máquina
  void faturamentoPossivel(){
    
    for(int i = 0; i < 10; i++){	
			faturamentoProduto = produtos[i].quantidade * produtos[i].preco;
			faturamentoTotal = faturamentoProduto + faturamentoTotal;
		}
						
			cout << " ______________________________\n|                              |\n| Faturamento possível: R$"<< faturamentoTotal<<"\n|______________________________|\n";
      faturamentoTotal = 0;
    
  }

  //função para gravar as escolhas do usuario
  void escolhasUsuario(){
    
    //Armazenando as escolhas do usuário
  		cout << " ____________________________\n|                            |\n| Digite o código do produto |\n|____________________________|\n R:";
  		cin >> usuarioCodigo;

      while(quantidade[usuarioCodigo] == 0){
        
        cout << "Produto indisponível, por favor insira outro código: ";
        cin >> usuarioCodigo;
     
      }

      cout <<" ____________________________\n|                            |\n|     Digite a quantidade    |\n|____________________________|\n R:";
      cin >> usuarioQuantidade;
      
  		while(usuarioQuantidade > quantidade[usuarioCodigo]){
  			
        cout << " ____________________________\n|          !ERROR!           |\n|   Estoque sem quantidade   |\n|   suficiente do produto!   |\n|____________________________|\n \n Digite uma nova quantidade: ";
        cin >> usuarioQuantidade;
  			 
  		}

        // retirando produto do estoque
        quantidade[usuarioCodigo] -= usuarioQuantidade;

  }

  void pagamentoUsuario(){
    
    //Cálculo do valor da compra
  		valorTotalCompra += produtos[usuarioCodigo].preco * usuarioQuantidade;
      

        cout << "\n ------------------------------\n Valor total da compra: R$ " << valorTotalCompra << "\n";
  
      	//Armazenando o valor que o usuário vai inserir na máquina
      	cout << " Insira o valor a ser pago: ";
      	cin >> usuarioDinheiro;

      
      		while(usuarioDinheiro < valorTotalCompra){
      
              cout << " ------------------------------\n Saldo insuficiente!!" << "\n" << " Insira o valor a ser pago: ";
              cin >> usuarioDinheiro;
              usuarioTroco = 0.00;
          }
      
          //Cálculo para definir o troco do usuário
        if(usuarioDinheiro > valorTotalCompra)  
          usuarioTroco = usuarioDinheiro - valorTotalCompra;
        else   
          usuarioTroco = 0.00;
        
  }

  //função do administrador 
  void administrador(){

		do{
			cout << " ___________________________\n|                           |\n"<< 
			"|     MODO ADMINISTRADOR    |\n"<<"|___________________________|\n|                           |\n" ;
	
			cout << "| 1 - Editar quantidade do  |\n| produto                   |\n|                           |\n"<< "| 2 - Vizualizar o fatura-  |\n| mento da máquina até o    |\n| momento                   |\n|                           |\n" << "| 3 - Vizualizar o fatura-  |\n| mento máximo da máquina   |\n"<<"|___________________________|\n R: ";
			cin >> resposta;
			
			switch(resposta){
	
				case 1:
	
			    do{

            adicionarQuantidade();
          
				}while(admResposta == 'N'||admResposta =='n');
				
					break;
				
        case 2:

            cout << " ___________________________\n|                           |\n| Faturamento atual: R$" << faturamentoAtual << "              \n|___________________________|\n";
					  break;
				
        case 3:

          faturamentoPossivel();
					break;
				
        default:
	
				cout << " __________________________\n|                          |\n|      Opção inválida      |\n|__________________________|";
				
			}	
      resposta = 0;
			
			cout << "\n ___________________________\n|                           |\n| Deseja continuar no modo  |\n| administrador?(S/s ou N/n)|\n|___________________________|\n R: ";
			cin >> continuar;
			
		}while(continuar == 'S' || continuar == 's');

  }

    //função do usuario
    void usuario(){
  
    cout << " ___________________________\n|                           |\n"<< 
			"|       MODO USUÁRIO        |\n"<<"|___________________________|\n";
  
  	do{
  		
      listarProdutos();
      escolhasUsuario();
      pagamentoUsuario();
        
      //Mostrar ao usuário o valor que foi inserido por ele, o total da compra e o troco
      cout << " ------------------------------\n Valor inserido: R$ " << usuarioDinheiro << "\n" << " Valor total da compra: R$ " << valorTotalCompra << "\n"<< " Troco: R$ " << setprecision(3) << usuarioTroco <<"\n _____________________________\n|                             |\n|   Pode retirar o produto!   |\n|_____________________________| \n \n";

      faturamentoAtual += valorTotalCompra;
      valorTotalCompra = 0.00;

    //Verificação se o usuário deseja adicionar mais algum produto
      cout << " _____________________________\n|                             |\n| Deseja continuar comprando? |\n| (S/s ou N/n)                |\n|_____________________________|\n R:";
      cin >> usuarioResposta;
  		
  	}while(usuarioResposta == 'S'||usuarioResposta =='s');
  }

  //função para inicializar como adm ou usuario, conforme a escolha
  void inicio(){

    do{
      
    cout << " ___________________________\n|                           |\n|  ---MÁQUINA DE VENDAS---  |\n|___________________________|\n";

    cout << " ___________________________\n|                           |\n"<< 
			"| DIGITE O MODO DE OPERAÇÃO |\n"<<"|___________________________|\n|                           |\n" << "|  0 - Modo administrador   |\n"<< "|  1 - Modo Usuário         |\n" << "|  2 - Sair                 |\n|___________________________|" << "\n R:";
    cin >> resposta;

      if(resposta == 0){

          administrador();
          
      } else if (resposta == 1){

          usuario();
        
      }
      
    }while(resposta != 2);

		cout << " ___________________________\n|                           |\n|   OBRIGADA POR ESCOLHER   |\n|    E CONFIAR NA MÁQUINA   |\n|       OPTIMUS PRIME!      |\n|___________________________|\n";
		
		cout << " ___________________________\n|                           |\n|        !DESLIGANDO!       |\n|___________________________|\n";
  }

  int main() {

    iniciarProdutos();
    inicio();
    
  }