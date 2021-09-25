#pragma once
//runtime meme to break sIgnAtUre DeteCtioNs
#define SEED 1337

#define HASH __LINE__

#define INLINE_STATE (HASH + SEED)

#define COND ((INLINE_STATE % 2) == 0)

#define FORCEINLINE __forceinline
#define NOINLINE __declspec(noinline)


#define IS_VALID_PTR( pointer ) ( pointer != NULL && (DWORD_PTR)pointer >= MIN_POINTER_VAL && (DWORD_PTR)pointer < MAX_POINTER_VAL )


