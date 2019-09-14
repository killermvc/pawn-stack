#include <pawn-vector>
#include <pawn-idgen>

#define INVALID_STACK_ID        (Stack:-1)

stock Stack:Stack_New(capacity = -1) {
    
    new Vec:stack;
    if(capacity == -1) {        
        stack = Vec_New();
    } else {
        stack = Vec_New(capacity);
    }
    
    if(stack == INVALID_VECTOR_ID) {        
        return INVALID_STACK_ID;
    }
    
    return Stack:stack;
}

stock Stack_Push(Stack:stack, value) {
    if(Vec_Append(Vec:stack, value) != VEC_OK) {
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
    new val = Vec_GetValue(Vec:stack, Vec_GetLength(Vec:stack)-1);
    Vec_Remove(Vec:stack, Vec_GetLength(Vec:stack)-1);
    return val;
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

stock Stack_Peek(Stack:stack) {
    return Vec_GetValue(Vec:stack, Vec_GetLength(Vec:stack)-1);
}

stock Vec:Stack_PeekVec(Stack:stack) {
    return Stack_Peek(stack);
}

stock bool:Stack_PeekBool(Stack:stack) {
    return Stack_Peek(stack);
}

stock Float:Stack_PeekFloat(Stack:stack) {
    return Stack_Peek(stack);
}

stock Stack:Stack_PeekStack(Stack:stack) {
    return Stack_Peek(stack);
}

stock bool:Stack_IsEmpty(Stack:stack) {
    return Vec_GetLength(Vec:stack) == 0 ? true : false;
}

stock Stack_Delete(Stack:stack) {
    Vec_Delete(Vec:stack);
}