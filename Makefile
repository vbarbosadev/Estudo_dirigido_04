# Variáveis
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iheaders -g
LDFLAGS = -lgtest -lpthread
SRC_DIR = src
HEADERS_DIR = headers
TESTS_DIR = tests
BUILD_DIR = build

# Fontes principais
SRC_FILES = $(SRC_DIR)/Produto.cpp $(SRC_DIR)/Catalogo.cpp $(SRC_DIR)/Pedido.cpp

# Arquivos de testes
TEST_FILE = $(TESTS_DIR)/test.cpp
TEST_ERROR_FILE = $(TESTS_DIR)/testError.cpp

# Executáveis de teste
TEST_EXEC = $(BUILD_DIR)/test
TEST_ERROR_EXEC = $(BUILD_DIR)/testErro

# Regras padrão
all: test testErro

# Compilar o arquivo de teste principal
test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_FILE) $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilar o arquivo de teste de erro
testErro: $(TEST_ERROR_EXEC)

$(TEST_ERROR_EXEC): $(TEST_ERROR_FILE) $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Executar os testes
runTest: test
	./$(TEST_EXEC)

runTestErro: testErro
	./$(TEST_ERROR_EXEC)

# Limpeza
clean:
	rm -rf $(BUILD_DIR)
 