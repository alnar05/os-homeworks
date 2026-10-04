#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(size_t size, size_t alignment) {

    size_t extra_space = alignment - 1 + sizeof(void*);
    
    void* original_ptr = malloc(size + extra_space);
    if (original_ptr == NULL) {
        return NULL; 
    }


    uintptr_t raw_address = (uintptr_t)original_ptr + sizeof(void*);
    
    uintptr_t aligned_address = (raw_address + alignment - 1) & ~(alignment - 1); // formula for padding
    
    void* aligned_ptr = (void*)aligned_address;

    ((void**)aligned_ptr)[-1] = original_ptr;

    return aligned_ptr;
}

void aligned_free(void* ptr) {
    if (ptr == NULL) return;

    void* original_ptr = ((void**)ptr)[-1];

    free(original_ptr);
}

int main() {

    void* p = aligned_malloc(100, 64);

    if (p != NULL) {
        // it will end in 00, 40, 80, or C0 in hex 
        // (which proves it is cleanly divisible by 64)
        printf("Aligned pointer is at: %p\n", p);
        
        aligned_free(p);
    }

    return 0;
}