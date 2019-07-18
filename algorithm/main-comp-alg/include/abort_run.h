#ifndef ABORT_RUN_H
#define ABORT_RUN_H

extern int g_abort_run;
extern int g_shutoff;

#define ABORT_RUN __atomic_store_n(&(g_abort_run), 1, __ATOMIC_RELAXED)
#define SHUTOFF_POD __atomic_store_n(&(g_shutoff), 1, __ATOMIC_RELAXED)

#endif
