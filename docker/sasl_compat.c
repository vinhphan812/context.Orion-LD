#include <sasl/sasl.h>

/* Stub implementations delegating to libsasl2.so.3 */
/* Version script tags these with SASL2 version */

int sasl_client_init(const sasl_callback_t *callbacks) {
    extern int sasl_client_init(const sasl_callback_t *);
    return sasl_client_init(callbacks);
}

int sasl_client_start(sasl_conn_t *conn, const char *mechlist, sasl_interact_t **prompt_need,
                     const char **clientout, unsigned *clientoutlen, const char **mech) {
    extern int sasl_client_start(sasl_conn_t *, const char *, sasl_interact_t **,
                                 const char **, unsigned *, const char **);
    return sasl_client_start(conn, mechlist, prompt_need, clientout, clientoutlen, mech);
}

int sasl_client_step(sasl_conn_t *conn, const char *serverin, unsigned serverinlen,
                     sasl_interact_t **prompt_need, const char **clientout, unsigned *clientoutlen) {
    extern int sasl_client_step(sasl_conn_t *, const char *, unsigned, sasl_interact_t **,
                                const char **, unsigned *);
    return sasl_client_step(conn, serverin, serverinlen, prompt_need, clientout, clientoutlen);
}

int sasl_client_new(const char *service, const char *serverFQDN, const char *iplocalport,
                    const char *ipremoteport, const sasl_callback_t *prompt_supp,
                    unsigned flags, sasl_conn_t **pconn) {
    extern int sasl_client_new(const char *, const char *, const char *, const char *,
                                const sasl_callback_t *, unsigned, sasl_conn_t **);
    return sasl_client_new(service, serverFQDN, iplocalport, ipremoteport, prompt_supp, flags, pconn);
}

int sasl_client_done(void) {
    extern int sasl_client_done(void);
    return sasl_client_done();
}

const char * sasl_errdetail(sasl_conn_t *conn) {
    extern const char * sasl_errdetail(sasl_conn_t *);
    return sasl_errdetail(conn);
}

const char * sasl_errstring(int saslerr, const char *langlist, const char **outlang) {
    extern const char * sasl_errstring(int, const char *, const char **);
    return sasl_errstring(saslerr, langlist, outlang);
}

void sasl_dispose(sasl_conn_t **pconn) {
    extern void sasl_dispose(sasl_conn_t **);
    sasl_dispose(pconn);
}

const char ** sasl_global_listmech(void) {
    extern const char ** sasl_global_listmech(void);
    return sasl_global_listmech();
}

void sasl_set_mutex(sasl_mutex_alloc_t *malloc_fn, sasl_mutex_lock_t *lock_fn,
                    sasl_mutex_unlock_t *unlock_fn, sasl_mutex_free_t *free_fn) {
    extern void sasl_set_mutex(sasl_mutex_alloc_t *, sasl_mutex_lock_t *,
                                sasl_mutex_unlock_t *, sasl_mutex_free_t *);
    sasl_set_mutex(malloc_fn, lock_fn, unlock_fn, free_fn);
}
