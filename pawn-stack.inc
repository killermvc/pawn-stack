#include <pawn-vector>
#include <pawn-idgen>

static Vec:stacks;
static Idgen:Stack_generator;


#include <YSI\y_hooks>

hook OnScriptInit() {
    stacks = Vec_New(10);
    if(stacks == INVALID_VECTOR_ID) {
        P:F("PAWN-STACK couldn't allocate memory for storing the stacks");
    }
    Stack_generator = Idgen_New(UNLIMITED_CAPACITY);
    return 1;
}

hook OnScriptExit() {
    Vec_Delete(stacks);
    Idgen_Delete(Stack_generator)
}


/*
    api
*/

#define INVALID_STACK_ID        (Stack:-1)

stock Stack:Stack_New(capacity) {
    new id = Idgen_NewId(Stack_generator);
    new Vec:stack = Vec_New(capacity);
    if(stack == INVALID_VECTOR_ID) {
        return INVALID_STACK_ID;
    }
    Vec_SetValueVec(stacks, id, stack);
    return Stack:id;
}

stock Stack_Push(Stack:stack, value) {
    if(Vec_Append(Vec_GetValueVec(stacks, _:stack), value) != VEC_OK) {
        return 1;
    }
    return 0;
}

stock Stack_PushVec(Stack:stack, Vec:value) {
    return Stack_Push(stack, _:value);
}

stock Stack_PushBool(Stack:stack, bool:value) {
    return Stack_Push(stack, _:value);
}

stock Stack_PushFloat(Stack:stack, Float:value) {
    return Stack_Push(stack, _:value);
}

stock Stack_PushStack(Stack:stack, Stack:value) {
    return Stack_Push(stack, _:value);
}

stock Stack_Pop(Stack:stack) {
    new Vec:s = Vec_GetValueVec(stacks, _:stack);
    return Vec_GetValue(s, Vec_GetLength(s)-1);
}

stock Vec:Stack_PopVec(Stack:stack) {
    return Stack_Pop(stack);
}

stock bool:Stack_PopBool(Stack:stack) {
    return Stack_Pop(stack);
}

stock Float:Stack_PopFloat(Stack:stack) {
    return Stack_Pop(stack);
}

stock Stack:Stack_PopStack(Stack:stack) {
    return Stack_Pop(stack);
}

stock Stack_Delete(Stack:stack) {
    Vec_Delete(Vec_GetValueVec(stacks, _:stack));
}