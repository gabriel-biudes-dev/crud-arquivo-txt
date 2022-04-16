typedef struct{
  char* nome_completo;
  int dia, mes, ano, viagens;
} Cliente;

typedef struct{
  char* nome;
  char* marca;
  float valor_calorico;
  float preco;
} Alimento;

//Lista os IDs de um arquivo
//Pré-condição: nenhuma
//Pós-condição: imprime na tela os IDs do arquivo
void listarIDS(char *nomeArquivo);

//Verifica se existe um registro com determinado ID no arquivo
//Pré-condição: nenhuma
//Pós-condição: retorna as informações do registro caso ele exista, uma string vazia caso contrário
char* consultarRegistro(char* nomeArquivo, char *id);

//Consulta as informações de um registro no arquivo
//Pré-condição: nenhuma
//Pós-condição: imprime na tela as informações de tal registro
void consultar(char* nomeArquivo);

//Verifica se existe tal ID em um arquivo e chama a função de editar seu respectivo arquivo
//Pré-condição: nenhuma
//Pós-condição: chama a função que edita seu respectivo arquivo
void editar(char* nomeArquivo);

//Mostra o menu ao usuário
//Pré-condição: nenhuma
//Pós-condição: retorna a operação escolhida
int mostrarMenu();

//Faz o log de um erro ocorrido no arquivo
//Pré-condição: nenhuma
//Pós-condição: armazena o erro no arquivo "erros.txt"
void guardarErro(char *msg);

//Acessa o maior ID registrado no arquivo, dado que ele está em um índice n
//Pré-condição: nenhuma
//Pós-condição: retorna o número do maior ID registrado no arquivo
int maiorId(char *arq, int n);

//Acessa a maior string em um arquivo, dado um determinado í­ndice n
//Pré-condição: nenhuma
//Pós-condição: retorna o tamanho da maior string do arquivo no í­ndice n
int maiorString(char *fn, int n);

//Remove uma linha de um arquivo
//Pré-condição: deve receber "0" em idn caso seja necessário a entrada de dados
//Pós-condição: remove um registro do arquivo
void removerLinha(char *nomeArquivo, char *idn, int n);

//Verifica se a entrada de dados é válida
//Pré-condição: nenhuma
//Pós-condição: retorna 1 caso seja válida, 0 caso contrário
int validarCliente(Cliente *cliente);

//Regista o cliente no arquivo
//Pré-condição: nenhuma
//Pós-condição: faz o registro do alimento no arquivo
void registrarCliente(Cliente *cliente);

//Recebe os dados do cliente
//Pré-condição: nenhuma
//Pós-condição: envia os dados recebidos para a função que registra o cliente no arquivo
void cadastrarCliente();

//Mostra os clientes registrados
//Pré-condição: nenhuma
//Pós-condição: mostra os clientes registrados
void mostrarClientes();

//Edita um cliente a partir de seu ID
//Pré-condição: nenhuma
//Pós-condição: altera o registro no arquivo
void editarCliente(char *registro);

//Verifica se a entrada de dados é válida
//Pré-condição: nenhuma
//Pós-condição: retorna 1 caso seja válida, 0 caso contrário
int validarAlimento(Alimento *alimento);

//Registra o alimento no arquivo
//Pré-condição: nenhuna
//Pós-condição: faz o registro do alimento no arquivo
void registrarAlimento(Alimento *alimento);

//Recebe os dados do alimento
//Pré-condição: nenhuma
//Pós-condição: envia os dados recebidos para a função que registra o alimento no arquivo
void cadastrarAlimento();

//Mostra os alimentos registrados
//Pré-condição: nenhuma
//Pós-condição: mostra os alimentos registrados
void mostrarAlimentos();

//Edita um alimento a partir de seu ID
//Pré-condição: nenhuma
//Pós-condição: altera o registro no arquivo
void editarAlimento(char* registro);

//Mostra um relatório de todos os registros de clientes e alimentos
//Pré-condição: nenhuma
//Pós-condição: imprime na tela todos os registros de clientes e alimentos
void mostrarRelatorio();

//Mostra um pedido
//Pré-condição: requer uma cadeia de caracteres como entrada
//Pós-condição: imprime na tela o pedido
void mostrarPedido(char *str);

//Mostra todos os pedidos de determinado cliente
//Pré-condição: deve receber o id como string
//Pós-condição: chama a função mostrarPedido para mostrar todos os pedidos do cliente
void mostrarPedidos(char *nomeArquivo, char *id);

//Faz um registro no arquivo
//Pré-condição: nenhuma
//Pós-condição: faz um registro no arquivo
void registrar(char *nomeArquivo, char* registro);

//Registra os pedidos em arquivos
//Pré-condição: nenhuma
//Pós-condição: registra os pedidos em arquivos
void registrarPedidos(Cliente *cliente, int id);

//Verifica se o arqvuivo está vazio
//Pré-condição: nenhuma
//Pós-condição: retorna 1 caso o arquivo esteja vazio, 0 caso contrário
int vazio(char* nomeArquivo);
