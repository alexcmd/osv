#ifndef NETPORT_H
#define NETPORT_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

int osv_curtid(void);

#define wakeup_one(...)
#define wakeup(...)
struct knote {
    int __unused;
};

#define priv_check_cred(...)        (0)
#define priv_check(...)        (0)

#define FEATURE(...)

#define intotcpcb(ip)   ((struct tcpcb *)(ip)->inp_ppcb)
#define intotw(ip)  ((struct tcptw *)(ip)->inp_ppcb)
#define sototcpcb(so)   (intotcpcb(sotoinpcb(so)))


#ifndef _KERNEL
    #define _KERNEL 1
#endif

#include <sys/types.h>
#include <bsd/sys/sys/queue.h>

/*
 * User credential, some function use this as arguments,
 * later on we'll have wrappers for them.
 */
struct ucred {
    int __unused;
};

/* Implemented in bsd/sys/kern/subr_hash.c */
struct malloc_type;
void    hashdestroy(void *, struct malloc_type *, u_long);
void    *hashinit(int count, struct malloc_type *type, u_long *hashmask);
void    *hashinit_flags(int count, struct malloc_type *type,
    u_long *hashmask, int flags);
#define HASH_NOWAIT 0x00000001
#define HASH_WAITOK 0x00000002


void domaininit(void *dummy);
void domainfinalize(void *dummy);

#define DECLARE_MODULE(...)
#define MODULE_VERSION(...)

#define devctl_notify(...) do{}while(0)

void getmicrotime(struct timeval *tvp);
int tvtohz(struct timeval *tv);

/* Defines how many ticks are in 1 second (microsec) */
#define hz (1000000L)

#define MALLOC_DEFINE(...)
#define MALLOC_DECLARE(...)

#define SYSINIT(...)
#define SYSUNINIT(...)
#define SYSCTL_NODE(...)
#define SYSCTL_DECL(...)
#define SYSCTL_UINT(...)
#define SYSCTL_INT(...)
#define SYSCTL_ULONG(...)
#define SYSCTL_PROC(...)
#define SYSCTL_OPAQUE(...)
#define SYSCTL_STRING(...)
#define SYSCTL_STRUCT(...)
#define SYSCTL_OID(...)
#define TUNABLE_INT(...)
#define TUNABLE_ULONG(...)
#define TUNABLE_INT_FETCH(...)

#define __NO_STRICT_ALIGNMENT

/* pseudo-errors returned inside kernel to modify return to process */
#define EJUSTRETURN (-2)        /* don't modify regs, just return */
#define ENOIOCTL    (-3)        /* ioctl not handled by this layer */
#define EDIRIOCTL   (-4)        /* do direct ioctl in GEOM */

#define sx_slock(...) do{}while(0)
#define sx_sunlock(...) do{}while(0)
#define sx_xlock(...) do{}while(0)
#define sx_xunlock(...) do{}while(0)

#ifndef time_uptime
#define time_uptime (1)
#endif

#define __packed    __attribute__((__packed__))

#ifndef INET
    #define INET (1)
#endif

#define panic(...) abort()

#define log(x, fmt, ...) do {} while(0)

#ifndef __BSD_VISIBLE
    #define __BSD_VISIBLE (1)
#endif

typedef __uint8_t   __sa_family_t;

#define PAGE_SIZE (4096)
#define PAGE_MASK (PAGE_SIZE-1)

void abort(void);
void* malloc(size_t size);
void free(void* object);
size_t strlcat(char *dst, const char *src, size_t siz);
size_t strlcpy(char *dst, const char *src, size_t siz);

/* Tracing... */
#define CTR0(m, d)          (void)0
#define CTR1(m, d, p1)          (void)0
#define CTR2(m, d, p1, p2)      (void)0
#define CTR3(m, d, p1, p2, p3)      (void)0
#define CTR4(m, d, p1, p2, p3, p4)  (void)0
#define CTR5(m, d, p1, p2, p3, p4, p5)  (void)0
#define CTR6(m, d, p1, p2, p3, p4, p5, p6)  (void)0

#ifndef NULL
    #define NULL (0)
#endif

#define KASSERT(exp,msg) do {} while (0)

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

/*
* flags to malloc.
*/
#define M_NOWAIT    0x0001      /* do not block */
#define M_WAITOK    0x0002      /* ok to block */
#define M_ZERO      0x0100      /* bzero the allocation */
#define M_NOVM      0x0200      /* don't ask VM for pages */
#define M_USE_RESERVE   0x0400      /* can alloc out of reserve memory */
#define M_NODUMP    0x0800      /* don't dump pages in this allocation */


#define bcopy(src, dst, len)    memcpy((dst), (src), (len))
#define bzero(buf, size)    memset((buf), 0, (size))
#define bcmp(b1, b2, len)   (memcmp((b1), (b2), (len)) != 0)


typedef uintptr_t __uintptr_t;

#ifndef __DECONST
#define __DECONST(type, var)    ((type)(__uintptr_t)(const void *)(var))
#endif

#ifndef __DEVOLATILE
#define __DEVOLATILE(type, var) ((type)(__uintptr_t)(volatile void *)(var))
#endif

#ifndef __DEQUALIFY
#define __DEQUALIFY(type, var)  ((type)(__uintptr_t)(const volatile void *)(var))
#endif

#ifdef INVARIANTS
#undef INVARIANTS
#endif

/* Segment flag values. */
enum uio_seg {
    UIO_USERSPACE,      /* from user data space */
    UIO_SYSSPACE,       /* from system space */
    UIO_NOCOPY      /* don't copy, already in object */
};

enum    uio_rw { UIO_READ, UIO_WRITE };

struct uio {
    struct  iovec *uio_iov;     /* scatter/gather list */
    int uio_iovcnt;     /* length of scatter/gather list */
    off_t   uio_offset;     /* offset in target object */
    ssize_t uio_resid;      /* remaining bytes to process */
    enum    uio_seg uio_segflg; /* address space */
    enum    uio_rw uio_rw;      /* operation */
    struct  thread *uio_td;     /* owner */
};

int uiomove(void *cp, int n, struct uio *uio);

struct malloc_type {
    int unused;
};

#define __printflike(m, n) __attribute__((format(printf,m,n)))
/*
 * Unusual type definitions.
 */
typedef __builtin_va_list   __va_list;  /* internally known to gcc */

/* Max number conversion buffer length: a u_quad_t in base 2, plus NUL byte. */
#define MAXNBUF (sizeof(intmax_t) * NBBY + 1)


int copyin(const void *uaddr, void *kaddr, size_t len);
int copyout(const void *kaddr, void *uaddr, size_t len);
int copystr(const void *kfaddr, void *kdaddr, size_t len, size_t *done);
int copyinstr(const void *uaddr, void *kaddr, size_t len, size_t *done);

typedef __uint32_t  intrmask_t; /* Interrupt mask (spl, xxx_imask...) */

/* Stubs for obsolete functions that used to be for interrupt management */
static __inline void        spl0(void)      { return; }
static __inline intrmask_t  splbio(void)        { return 0; }
static __inline intrmask_t  splcam(void)        { return 0; }
static __inline intrmask_t  splclock(void)      { return 0; }
static __inline intrmask_t  splhigh(void)       { return 0; }
static __inline intrmask_t  splimp(void)        { return 0; }
static __inline intrmask_t  splnet(void)        { return 0; }
static __inline intrmask_t  splsoftcam(void)    { return 0; }
static __inline intrmask_t  splsoftclock(void)  { return 0; }
static __inline intrmask_t  splsofttty(void)    { return 0; }
static __inline intrmask_t  splsoftvm(void)     { return 0; }
static __inline intrmask_t  splsofttq(void)     { return 0; }
static __inline intrmask_t  splstatclock(void)  { return 0; }
static __inline intrmask_t  spltty(void)        { return 0; }
static __inline intrmask_t  splvm(void)     { return 0; }
static __inline void        splx(intrmask_t ipl)   { return; }


/*
 * OSv: Copied from kern_time.c
 *
 * ppsratecheck(): packets (or events) per second limitation.
 *
 * Return 0 if the limit is to be enforced (e.g. the caller
 * should drop a packet because of the rate limitation).
 *
 * maxpps of 0 always causes zero to be returned.  maxpps of -1
 * always causes 1 to be returned; this effectively defeats rate
 * limiting.
 *
 * Note that we maintain the struct timeval for compatibility
 * with other bsd systems.  We reuse the storage and just monitor
 * clock ticks for minimal overhead.
 */
int ppsratecheck(struct timeval *lasttime, int *curpps, int maxpps);

/*
 * ratecheck(): simple time-based rate-limit checking.
 */
int ratecheck(struct timeval *lasttime, const struct timeval *mininterval);

#endif