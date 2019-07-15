#ifndef ATOMICS_H
#define ATOMICS_H

/* Used to safely load/store values in CAN_Data struct */
#define STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_RELAXED))
#define LOAD(var) (__atomic_load_n(&(var), __ATOMIC_RELAXED))

#define SEQ_STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_SEQ_CST))
#define SEQ_LOAD(var) (__atomic_load_n(&(var), __ATOMIC_SEQ_CST))


#endif