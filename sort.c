#include "push_swap.h"

void sort_stack(stack *a, stack *b) {
    if (is_sorted(a)) {
        return;
    }

    if (stack_size(a) <= 3) {
        simple_sort(a, b);
    } else {
        complex_sort(a, b);
    }
}

void simple_sort(stack *a, stack *b) {
    // Implementação da ordenação simples
}

void complex_sort(stack *a, stack *b) {
    // Implementação da ordenação complexa
}