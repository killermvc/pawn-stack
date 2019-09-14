#define RUN_TESTS
#include <a_samp>
#include "pawn-stack.inc"
#include <YSI_Core\y_testing>

Test:PushPop() {
    new Stack:stack = Stack_New();

    Stack_Push(stack, 10);
    Stack_Push(stack, 15);
    Stack_Push(stack, 20);

    ASSERT(Stack_Pop(stack) == 20);
    ASSERT(Stack_Pop(stack) == 15);
    ASSERT(Stack_Pop(stack) == 10);
}

Test:Peek() {
    new Stack:stack = Stack_New();

    Stack_Push(stack, 10);
    ASSERT(Stack_Peek(stack) == 10);
    Stack_Push(stack, 15);
    ASSERT(Stack_Peek(stack) == 15);
    Stack_Push(stack, 20);
    ASSERT(Stack_Peek(stack) == 20);
}

Test:IsEmpty() {
    new Stack:stack = Stack_New();
    ASSERT(Stack_IsEmpty(stack));

    Stack_Push(stack, 10);
    ASSERT(!Stack_IsEmpty(stack));
    
    Stack_Pop(stack);
    ASSERT(Stack_IsEmpty(stack));
}

Test:CreateMany() {
    const size = 500;
    new Stack:stacks[size];

    for(new i = 0; i < size; i++) {
        stacks[i] = Stack_New(50);
    }
}