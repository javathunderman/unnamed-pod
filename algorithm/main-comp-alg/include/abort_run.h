#ifndef ABORT_RUN_H
#define ABORT_RUN_H

extern int g_abort_run;

#define ABORT_RUN __atomic_store_n(&(g_abort_run), 1, __ATOMIC_RELAXED)

#endif
