# Compilação e Execução do Sistema no Replit

## 1. Criar o Projeto no Replit

1. Acesse [Replit](https://replit.com/).
2. Faça login ou crie uma conta.
3. Crie um novo projeto clicando no botão "Create" ou "New Repl".
4. Selecione a linguagem de programação **C++** e dê nome ao projeto.
5. Ele precisa ser público, o replit já virá com essa opção marcada.

## 2. Configuração do Ambiente

1. **Adicione os Arquivos ao Projeto:**
   - Selecione a opção "Files" no painel à esquerda e crie os arquivos necessários.
   - Adicione todos os arquivos do sistema. Basta clicar em "Add file" e nomear cada um dos arquivos conforme seu código.

2. **Carregar os Arquivos CSV:**
   - Para carregar dados no sistema, você precisa adicionar também os arquivos CSV que contêm as informações de cidades, passageiros, transportes, trajetos e viagens.
   - Adicione esses arquivos CSV na pasta "Files" do Replit.

## 3. Compilando o Sistema
No Replit, a compilação do código é feita automaticamente ao clicar no botão "Run" (Executar). No entanto, você pode forçar uma compilação manualmente utilizando o terminal integrado:

1. **Abra o Terminal:**
   - Clique na aba "Shell" ou "Console" no Replit para abrir o terminal.

2. **Comando de Compilação:**
   - No terminal, digite o seguinte comando para compilar o sistema:
     ```bash
     g++ -o sistema main.cpp carregar_dados.cpp
     ```
     Esse comando irá compilar os arquivos `main.cpp` e `carregar_dados.cpp` e gerar um executável chamado `sistema`.

## 4. Executando o Sistema
Após compilar o código, você pode executar o sistema da seguinte maneira:

1. **Executando o Programa:**
   - No terminal, digite o seguinte comando para executar o programa:
     ```bash
     ./sistema
     ```
   - O sistema será iniciado e você verá a saída diretamente no console do Replit. Se houver algum erro, ele será exibido no terminal.

## 5. Depuração e Erros
Se o programa gerar erros durante a compilação ou execução:

- **Erros de Compilação:** O Replit mostrará mensagens de erro no terminal, indicando a linha e o tipo do erro.
- **Erros em Tempo de Execução:** O sistema pode gerar mensagens de erro relacionadas ao carregamento de dados (por exemplo, arquivos não encontrados ou dados inválidos).


# Observações Importantes

## 1. Salvar Dados
Para salvar os dados no sistema, aconselho que selecione a opção no menu 2x. Se abrir os arquivos csv, verá sendo salvo na hora. Mas é preciso clicar 2x.

## 2. Funções não desenvolvidas:
1. Avançar horas e atualizar estado do sistema.
2. Registrar chegada do transporte na cidade de destino.
3. Calcular o melhor trajeto entre cidades (calcula apenas o tempo de chegada).
4. Relatar as cidades mais visitadas (exibe apenas as cadastradas).

