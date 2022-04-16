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
//Pr�-condi��o: nenhuma
//P�s-condi��o: imprime na tela os IDs do arquivo
void listarIDS(char *nomeArquivo);

//Verifica se existe um registro com determinado ID no arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna as informa��es do registro caso ele exista, uma string vazia caso contr�rio
char* consultarRegistro(char* nomeArquivo, char *id);

//Consulta as informa��es de um registro no arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: imprime na tela as informa��es de tal registro
void consultar(char* nomeArquivo);

//Verifica se existe tal ID em um arquivo e chama a fun��o de editar seu respectivo arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: chama a fun��o que edita seu respectivo arquivo
void editar(char* nomeArquivo);

//Mostra o menu ao usu�rio
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna a opera��o escolhida
int mostrarMenu();

//Faz o log de um erro ocorrido no arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: armazena o erro no arquivo "erros.txt"
void guardarErro(char *msg);

//Acessa o maior ID registrado no arquivo, dado que ele est� em um �ndice n
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna o n�mero do maior ID registrado no arquivo
int maiorId(char *arq, int n);

//Acessa a maior string em um arquivo, dado um determinado �ndice n
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna o tamanho da maior string do arquivo no �ndice n
int maiorString(char *fn, int n);

//Remove uma linha de um arquivo
//Pr�-condi��o: deve receber "0" em idn caso seja necess�rio a entrada de dados
//P�s-condi��o: remove um registro do arquivo
void removerLinha(char *nomeArquivo, char *idn, int n);

//Verifica se a entrada de dados � v�lida
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna 1 caso seja v�lida, 0 caso contr�rio
int validarCliente(Cliente *cliente);

//Regista o cliente no arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: faz o registro do alimento no arquivo
void registrarCliente(Cliente *cliente);

//Recebe os dados do cliente
//Pr�-condi��o: nenhuma
//P�s-condi��o: envia os dados recebidos para a fun��o que registra o cliente no arquivo
void cadastrarCliente();

//Mostra os clientes registrados
//Pr�-condi��o: nenhuma
//P�s-condi��o: mostra os clientes registrados
void mostrarClientes();

//Edita um cliente a partir de seu ID
//Pr�-condi��o: nenhuma
//P�s-condi��o: altera o registro no arquivo
void editarCliente(char *registro);

//Verifica se a entrada de dados � v�lida
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna 1 caso seja v�lida, 0 caso contr�rio
int validarAlimento(Alimento *alimento);

//Registra o alimento no arquivo
//Pr�-condi��o: nenhuna
//P�s-condi��o: faz o registro do alimento no arquivo
void registrarAlimento(Alimento *alimento);

//Recebe os dados do alimento
//Pr�-condi��o: nenhuma
//P�s-condi��o: envia os dados recebidos para a fun��o que registra o alimento no arquivo
void cadastrarAlimento();

//Mostra os alimentos registrados
//Pr�-condi��o: nenhuma
//P�s-condi��o: mostra os alimentos registrados
void mostrarAlimentos();

//Edita um alimento a partir de seu ID
//Pr�-condi��o: nenhuma
//P�s-condi��o: altera o registro no arquivo
void editarAlimento(char* registro);

//Mostra um relat�rio de todos os registros de clientes e alimentos
//Pr�-condi��o: nenhuma
//P�s-condi��o: imprime na tela todos os registros de clientes e alimentos
void mostrarRelatorio();

//Mostra um pedido
//Pr�-condi��o: requer uma cadeia de caracteres como entrada
//P�s-condi��o: imprime na tela o pedido
void mostrarPedido(char *str);

//Mostra todos os pedidos de determinado cliente
//Pr�-condi��o: deve receber o id como string
//P�s-condi��o: chama a fun��o mostrarPedido para mostrar todos os pedidos do cliente
void mostrarPedidos(char *nomeArquivo, char *id);

//Faz um registro no arquivo
//Pr�-condi��o: nenhuma
//P�s-condi��o: faz um registro no arquivo
void registrar(char *nomeArquivo, char* registro);

//Registra os pedidos em arquivos
//Pr�-condi��o: nenhuma
//P�s-condi��o: registra os pedidos em arquivos
void registrarPedidos(Cliente *cliente, int id);

//Verifica se o arqvuivo est� vazio
//Pr�-condi��o: nenhuma
//P�s-condi��o: retorna 1 caso o arquivo esteja vazio, 0 caso contr�rio
int vazio(char* nomeArquivo);
