#include "../headers/Produto.h"
#include "../headers/Catalogo.h"
#include "../headers/Pedido.h"
#include <gtest/gtest.h>

TEST(CatalogoTest, AdicionarEListarProdutos) {
    Catalogo catalogo;
    auto produto1 = std::make_shared<Produto>(1, "Notebook", 2500.00f);
    auto produto2 = std::make_shared<Produto>(2, "Mouse", 50.00f);

    catalogo.adicionarProduto(produto1);
    catalogo.adicionarProduto(produto2);

    EXPECT_EQ(catalogo.buscarProdutoPorId(1)->getNome(), "Notebook");
    EXPECT_EQ(catalogo.buscarProdutoPorId(2)->getNome(), "Mouse");
    EXPECT_EQ(catalogo.buscarProdutoPorId(3), nullptr);
}

TEST(PedidoTest, CalculoTotalSemDesconto) {
    Pedido pedido("Cliente 1");
    auto produto1 = std::make_shared<Produto>(1, "Mouse", 50.00f);
    auto produto2 = std::make_shared<Produto>(2, "Teclado", 40.00f);

    pedido.adicionarProduto(produto1);
    pedido.adicionarProduto(produto2);

    EXPECT_FLOAT_EQ(pedido.calcularTotal(), 90.00f);
}

TEST(PedidoTest, CalculoTotalComDesconto) {
    Pedido pedido("Cliente 2");
    auto produto1 = std::make_shared<Produto>(1, "Notebook", 2500.00f);

    pedido.adicionarProduto(produto1);

    EXPECT_FLOAT_EQ(pedido.calcularTotal(), 2250.00f); // 10% de desconto
}

TEST(IntegracaoTest, FluxoCompleto) {
    Catalogo catalogo;
    auto produto1 = std::make_shared<Produto>(1, "Cadeira", 120.00f);
    auto produto2 = std::make_shared<Produto>(2, "Mesa", 200.00f);

    catalogo.adicionarProduto(produto1);
    catalogo.adicionarProduto(produto2);

    Pedido pedido("Cliente Teste");
    pedido.adicionarProduto(catalogo.buscarProdutoPorId(1));
    pedido.adicionarProduto(catalogo.buscarProdutoPorId(2));

    EXPECT_FLOAT_EQ(pedido.calcularTotal(), 288.00f); // 320.00 com 10% de desconto
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
