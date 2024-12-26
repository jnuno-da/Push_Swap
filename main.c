#include "push_swap.h"

int main(int argc, char **argv) {
    // Inicializa as pilhas a e b
    stack *a = initialize_stack();
    stack *b = initialize_stack();

    // Lê os argumentos e preenche a pilha a
    if (!parse_arguments(argc, argv, a)) {
        // Lidar com erro de argumentos inválidos
        return 1;
    }

    // Verifica se os argumentos são válidos
    if (!is_valid_stack(a)) {
        // Lidar com erro de pilha inválida
        return 1;
    }

    // Chama a função sort_stack(a, b)
    sort_stack(a, b);

    // Libera a memória alocada
    free_stack(a);
    free_stack(b);

    return 0;
}