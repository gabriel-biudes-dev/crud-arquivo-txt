Ao executar o software, a primeira funcionalidade que o usuário se depara é a de cadastrar cliente, onde é possível armazenar informações sobre um cliente dentro do banco de dados.
No caso deste programa, foram utilizados diversos arquivos de texto como forma de armazenar dados.
Caso os arquivos não existam, o software os cria automaticamente, no mesmo diretório onde foi executado, de maneira que o usuário não precise se preocupar com isso. 
No cadastro de clientes, o usuário do sistema deve informar, obrigatoriamente, o nome completo do cliente e uma data de nascimento válida. 
Caso essas condições não sejam cumpridas, é realizado um log no arquivo “erros.txt”, e uma mensagem de erro é mostrada ao usuário, indicando qual foi a entrada de dados inválida.
Além disso, o usuário pode, opcionalmente, informar a quantidade de viagens realizadas pelo cliente, além dos Ids de alimentos que tal cliente pediu. 
Após o preenchimento dos dados, caso todas as entradas sejam válidas, o cliente é armazenado no arquivo “clientes.txt”.
De maneira semelhante, o mesmo é realizado para alimentos, com a diferença de que, nesse caso, o nome, preço e valor calórico são entradas de dados obrigatórias para o cadastro de alimento.
Além disso, o sistema conta também com a opção de mostrar relatório, onde são imprimidos todos os clientes, histórico completo de pedidos, histórico atual de pedidos e alimentos que estão cadastrados no sistema. 
No caso, o histórico completo conta com todos os pedidos que foram realizados na história do software, enquanto o histórico atual não mostra informações sobre pedidos de alimentos que foram removidos do sistema.
Ademais, é possível deletar e editar clientes e pedidos através de seus respectivos Ids. 
No caso de editar, é possível alterar todos os campos, com exceção de seus Ids. 
O programa solicita ao usuário qual é o campo que deve ser editado, logo solicitando qual deve ser o novo valor para tal campo e fazendo a edição do registro no sistema com a nova informação.
Por fim, o sistema conta também com a opção de consultar clientes e alimentos, solicitando o Id do registro para que se possa buscar as informações. 
No caso de alimentos, é mostrado o Id, nome, marca, valor calórico e preço, que são suas características básicas. 
Já nos clientes, além das características básicas, é mostrado também o histórico completo e atual de pedidos do cliente selecionado. 
Vale ressaltar que, devido à alguns testes que deram errado, foi preferível que o código todo fosse colocado em um arquivo só, a fim de manter a compatibilidade com diversos compiladores.
