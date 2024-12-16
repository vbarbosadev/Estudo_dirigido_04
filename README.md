# Projeto: Sistema de Gerenciamento de Pedidos

## Descrição
Este é um projeto para o gerenciamento de pedidos em uma loja virtual. Ele inclui:
- Cadastro de produtos.
- Criação e manutenção de um catálogo de produtos.
- Geração de pedidos, incluindo cálculo automático de descontos para compras acima de R$100,00.

## Estrutura do Projeto

- **headers/**: Contém os arquivos de cabeçalho (.h).
- **src/**: Contém as implementações das classes.
- **tests/**: Contém os arquivos de teste.
- **build/**: Diretório gerado automaticamente para armazenar os executáveis.

### Classes Principais

1. **Produto**:
   - Representa um produto no catálogo.
   - Propriedades: `id`, `nome`, `preco`.
   - Métodos: `getId()`, `getNome()`, `getPreco()`, `display()`.

2. **Catalogo**:
   - Gerencia os produtos do catálogo.
   - Métodos: `adicionarProduto()`, `listarProdutos()`, `buscarProdutoPorId()`.

3. **Pedido**:
   - Gerencia os pedidos feitos por clientes.
   - Propriedades: `produtos`, `cliente`.
   - Métodos: `adicionarProduto()`, `calcularTotal()`, `exibirResumo()`.

## Requisitos

- Compilador com suporte ao **C++17**.
- Google Test para testes unitários.

## Como Compilar e Executar

1. Clone o repositório e organize os arquivos conforme a estrutura do projeto.

2. Compile e execute os testes:
   ```bash
   make all
   ```

3. Execute os testes principais:
   ```bash
   make runTest
   ```

4. Execute os testes de erro:
   ```bash
   make runTestErro
   ```

5. Limpe os arquivos gerados:
   ```bash
   make clean
   ```

## Estrutura do Makefile

- **Variáveis**:
  - `CXX`: Define o compilador a ser usado.
  - `CXXFLAGS`: Define as flags do compilador (ex.: padrão C++17, avisos).
  - `LDFLAGS`: Flags para o linker (inclui o Google Test).
  - `SRC_DIR`, `HEADERS_DIR`, `TESTS_DIR`, `BUILD_DIR`: Diretórios principais do projeto.

- **Regras**:
  - `all`: Compila todos os testes.
  - `test`: Compila o executável principal de testes.
  - `testErro`: Compila o executável para testar erros.
  - `runTest`: Executa os testes principais.
  - `runTestErro`: Executa os testes de erros.
  - `clean`: Remove os arquivos gerados no diretório de build.

## Exemplos de Uso

1. **Cadastro de produtos:**
   - Adicione produtos ao catálogo e exiba a lista completa.

2. **Criação de pedidos:**
   - Crie pedidos com produtos do catálogo e calcule o total.

3. **Desconto:**
   - Se o valor do pedido exceder R$100,00, um desconto de 10% é aplicado automaticamente.

## Testes

- **Testes Unitários:**
  - Validação das funcionalidades individuais das classes.

- **Testes de Integração:**
  - Simulação de cenários completos com múltiplos produtos e pedidos.

---
Desenvolvido para a disciplina de Boas Práticas de Programação, UFRN.
