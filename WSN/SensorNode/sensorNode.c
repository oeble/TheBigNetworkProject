#ifdef __cplusplus
 		 extern "C" { 
 		 #endif 
#define nx_struct struct
#define nx_union union
# 150 "/usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h" 3
typedef long int ptrdiff_t;
#line 212
typedef long unsigned int size_t;
#line 324
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 37 "/usr/include/stdint.h" 3
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;









typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;









typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;








typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
#line 120
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
#line 135
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
# 35 "/usr/include/inttypes.h" 3
typedef int __gwchar_t;
#line 283
#line 279
typedef struct __nesc_unnamed4242 {

  long int quot;
  long int rem;
} imaxdiv_t;
# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;
#line 310
static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;
#line 347
static __inline uint32_t __nesc_hton_uint32(void * target, uint32_t value)  ;
#line 431
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 44 "/usr/include/string.h" 3
extern void *memcpy(void *__restrict __dest, 
const void *__restrict __src, size_t __n) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 65
extern void *memset(void *__s, int __c, size_t __n) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;
# 40 "/usr/include/xlocale.h" 3
#line 28
typedef struct __locale_struct {


  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 67 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 3
union wait {

  int w_status;
  struct __nesc_unnamed4243 {


    unsigned int __w_termsig : 7;
    unsigned int __w_coredump : 1;
    unsigned int __w_retcode : 8;
    unsigned int  : 16;
  } 






  __wait_terminated;
  struct __nesc_unnamed4244 {


    unsigned int __w_stopval : 8;
    unsigned int __w_stopsig : 8;
    unsigned int  : 16;
  } 





  __wait_stopped;
};
# 72 "/usr/include/stdlib.h" 3
#line 68
typedef union __nesc_unnamed4245 {

  union wait *__uptr;
  int *__iptr;
} __WAIT_STATUS __attribute((__transparent_union__)) ;
#line 102
#line 98
typedef struct __nesc_unnamed4246 {

  int quot;
  int rem;
} div_t;







#line 106
typedef struct __nesc_unnamed4247 {

  long int quot;
  long int rem;
} ldiv_t;







__extension__ 



#line 118
typedef struct __nesc_unnamed4248 {

  long long int quot;
  long long int rem;
} lldiv_t;
#line 158
__extension__ 
#line 195
__extension__ 




__extension__ 








__extension__ 




__extension__ 
# 31 "/usr/include/x86_64-linux-gnu/bits/types.h" 3
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
#line 134
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct __nesc_unnamed4249 {
#line 144
  int __val[2];
} 
#line 144
__fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void *__timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
#line 61
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
#line 99
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 60 "/usr/include/time.h" 3
typedef __clock_t clock_t;
#line 76
typedef __time_t time_t;
#line 92
typedef __clockid_t clockid_t;
#line 104
typedef __timer_t timer_t;
# 151 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#line 201
typedef unsigned int u_int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int u_int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int u_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int u_int64_t __attribute((__mode__(__DI__))) ;

typedef int register_t __attribute((__mode__(__word__))) ;
# 24 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3
typedef int __sig_atomic_t;







#line 29
typedef struct __nesc_unnamed4250 {

  unsigned long int __val[1024 / (8 * sizeof(unsigned long int ))];
} __sigset_t;
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
typedef __sigset_t sigset_t;
# 120 "/usr/include/time.h" 3
struct timespec {

  __time_t tv_sec;
  long int tv_nsec;
};
# 31 "/usr/include/x86_64-linux-gnu/bits/time.h" 3
struct timeval {

  __time_t tv_sec;
  __suseconds_t tv_usec;
};
# 49 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
#line 76
#line 65
typedef struct __nesc_unnamed4251 {







  __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))];
} 

fd_set;






typedef __fd_mask fd_mask;
# 32 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3
__extension__ 


__extension__ 


__extension__ 
# 229 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 50 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3
typedef unsigned long int pthread_t;






#line 53
typedef union __nesc_unnamed4252 {

  char __size[56];
  long int __align;
} pthread_attr_t;







#line 61
typedef struct __pthread_internal_list {

  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
#line 104
#line 76
typedef union __nesc_unnamed4253 {

  struct __pthread_mutex_s {

    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    int __spins;
    __pthread_list_t __list;
  } 








  __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;





#line 106
typedef union __nesc_unnamed4254 {

  char __size[4];
  int __align;
} pthread_mutexattr_t;
#line 130
#line 115
typedef union __nesc_unnamed4255 {

  struct __nesc_unnamed4256 {

    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





#line 132
typedef union __nesc_unnamed4257 {

  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;
#line 189
#line 150
typedef union __nesc_unnamed4258 {


  struct __nesc_unnamed4259 {

    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;


    unsigned int __flags;
  } __data;
#line 187
  char __size[56];
  long int __align;
} pthread_rwlock_t;





#line 191
typedef union __nesc_unnamed4260 {

  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;








#line 206
typedef union __nesc_unnamed4261 {

  char __size[32];
  long int __align;
} pthread_barrier_t;





#line 212
typedef union __nesc_unnamed4262 {

  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 349 "/usr/include/stdlib.h" 3
struct random_data {

  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
#line 418
struct drand48_data {

  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  unsigned long long int __a;
};
#line 742
typedef int (*__compar_fn_t)(const void *arg_0x2b5f6494e1f0, const void *arg_0x2b5f6494e4c8);
#line 776
__extension__ 
#line 793
__extension__ 
# 31 "/usr/include/x86_64-linux-gnu/bits/mathdef.h" 3
typedef float float_t;
typedef double double_t;
# 203 "/usr/include/math.h" 3
enum __nesc_unnamed4263 {

  FP_NAN, 

  FP_INFINITE, 

  FP_ZERO, 

  FP_SUBNORMAL, 

  FP_NORMAL
};
#line 303
#line 296
typedef enum __nesc_unnamed4264 {

  _IEEE_ = -1, 
  _SVID_, 
  _XOPEN_, 
  _POSIX_, 
  _ISOC_
} _LIB_VERSION_TYPE;
#line 321
struct exception {


  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};
# 48 "/usr/include/ctype.h" 3
enum __nesc_unnamed4265 {

  _ISupper = 0 < 8 ? (1 << 0) << 8 : (1 << 0) >> 8, 
  _ISlower = 1 < 8 ? (1 << 1) << 8 : (1 << 1) >> 8, 
  _ISalpha = 2 < 8 ? (1 << 2) << 8 : (1 << 2) >> 8, 
  _ISdigit = 3 < 8 ? (1 << 3) << 8 : (1 << 3) >> 8, 
  _ISxdigit = 4 < 8 ? (1 << 4) << 8 : (1 << 4) >> 8, 
  _ISspace = 5 < 8 ? (1 << 5) << 8 : (1 << 5) >> 8, 
  _ISprint = 6 < 8 ? (1 << 6) << 8 : (1 << 6) >> 8, 
  _ISgraph = 7 < 8 ? (1 << 7) << 8 : (1 << 7) >> 8, 
  _ISblank = 8 < 8 ? (1 << 8) << 8 : (1 << 8) >> 8, 
  _IScntrl = 9 < 8 ? (1 << 9) << 8 : (1 << 9) >> 8, 
  _ISpunct = 10 < 8 ? (1 << 10) << 8 : (1 << 10) >> 8, 
  _ISalnum = 11 < 8 ? (1 << 11) << 8 : (1 << 11) >> 8
};
# 23 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/system/tos.h"
enum __nesc_unnamed4266 {
#line 24
  FALSE = 0, TRUE = 1
};
typedef nx_int8_t nx_bool;
uint16_t TOS_NODE_ID = 1;






struct __nesc_attr_atmostonce {
};
#line 35
struct __nesc_attr_atleastonce {
};
#line 36
struct __nesc_attr_exactlyonce {
};
# 51 "/home/ondra/symphony/release/tinyos-2.1.1/tos/types/TinyError.h"
enum __nesc_unnamed4267 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 4 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/hardware.h"
static __inline void __nesc_enable_interrupt();
static __inline void __nesc_disable_interrupt();

typedef uint8_t __nesc_atomic_t;
typedef uint8_t mcu_power_t;

__inline __nesc_atomic_t __nesc_atomic_start(void )  ;



__inline void __nesc_atomic_end(__nesc_atomic_t x)  ;



typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_float;typedef float __nesc_nxbase_nx_float  ;
#line 34
enum __nesc_unnamed4268 {
  TOS_SLEEP_NONE = 0
};
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



typedef struct _IO_FILE FILE;
#line 65
typedef struct _IO_FILE __FILE;
# 95 "/usr/include/wchar.h" 3
#line 83
typedef struct __nesc_unnamed4269 {

  int __count;
  union __nesc_unnamed4270 {


    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 26 "/usr/include/_G_config.h" 3
#line 22
typedef struct __nesc_unnamed4271 {

  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;




#line 27
typedef struct __nesc_unnamed4272 {

  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
#line 53
typedef int _G_int16_t __attribute((__mode__(__HI__))) ;
typedef int _G_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int _G_uint16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int _G_uint32_t __attribute((__mode__(__SI__))) ;
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 172 "/usr/include/libio.h" 3
struct _IO_jump_t;
#line 172
struct _IO_FILE;









typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
};
#line 208
enum __codecvt_result {

  __codecvt_ok, 
  __codecvt_partial, 
  __codecvt_error, 
  __codecvt_noconv
};
#line 273
struct _IO_FILE {
  int _flags;




  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;








  __off64_t _offset;








  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof(int ) - 4 * sizeof(void *) - sizeof(size_t )];
};



typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

struct _IO_FILE_plus;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
#line 366
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, 
size_t __n);







typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn(void *__cookie);
# 80 "/usr/include/stdio.h" 3
typedef __gnuc_va_list va_list;
#line 111
typedef _G_fpos_t fpos_t;
#line 169
struct _IO_FILE;
extern struct _IO_FILE *stdout;
struct _IO_FILE;
#line 243
extern int fflush(FILE *__stream);
#line 363
extern int printf(const char *__restrict __format, ...);
# 23 "/home/ondra/symphony/release/ns-3.14/build/ns3/calls-to-ns3.h"
#line 12
typedef enum __nesc_unnamed4273 {
  RADIO_ON = 0, 
  RADIO_START = 1, 
  RADIO_SLEEP = 2, 
  RADIO_STOP = 3, 
  RADIO_SET_CHANNEL = 4, 
  RADIO_GET_CHANNEL = 5, 
  RADIO_SET_TX_POWER = 6, 
  RADIO_GET_TX_POWER = 7, 
  RADIO_SEND = 8, 
  RADIO_CANCEL = 9
} DeviceCall;








#line 25
typedef enum __nesc_unnamed4274 {
  RADIO_STATE_ON, 
  RADIO_STATE_STANDBY, 
  RADIO_STATE_OFF, 
  RADIO_STATE_SWITCHING_CHANNEL, 
  RADIO_STATE_TX, 
  RADIO_STATE_RX
} RadioState;






#line 34
typedef enum __nesc_unnamed4275 {
  SENSOR_ON = 0, 
  SENSOR_OFF = 1, 
  SENSOR_GET_DATA = 2, 
  SENSOR_RESET = 3
} SensorCall;





#line 41
typedef enum __nesc_unnamed4276 {
  APP_ON = 1, 
  APP_OFF = 2, 
  APP_RX = 3
} ApplicationCall;
# 69 "/home/ondra/symphony/release/ns-3.14/build/ns3/tos-to-ns3-proxy.h"
int gateway(void *obj, int func, int arg);
int setProxy(void *obj);

int gatewayRadio(void *obj, DeviceCall call, int val1, int val2, void *hdr, void *msg);
int gatewaySensor(void *obj, SensorCall call);
# 6 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/sim_main.h"
int a;
int id_this_lib;
void *proxy;





int setUniqueID(int i)   ;





int setProxy(void *con)   ;
# 4 "SensorNode.h"
enum __nesc_unnamed4277 {
  AM_GROUPNR = 6
};





#line 8
typedef nx_struct radio_data_msg {
  nx_uint8_t sender;
  nx_uint16_t partNr;
  nx_uint8_t data[25];
} __attribute__((packed)) radio_data_msg_t;


#line 14
typedef nx_struct radio_conf_msg {
} __attribute__((packed)) radio_conf_msg_t;






#line 17
typedef struct packet_msg {
  nx_uint16_t nodeID;
  nx_uint32_t timestamp;
  nx_uint32_t size;
  nx_uint8_t rawData[];
} packet_msg_t;
# 40 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4278 {
#line 40
  int notUsed;
} 
#line 40
TMilli;
typedef struct __nesc_unnamed4279 {
#line 41
  int notUsed;
} 
#line 41
T32khz;
typedef struct __nesc_unnamed4280 {
#line 42
  int notUsed;
} 
#line 42
TMicro;
# 43 "/home/ondra/symphony/release/tinyos-2.1.1/tos/types/Leds.h"
enum __nesc_unnamed4281 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 44 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/logprinter.h"
#line 17
typedef enum LogLevel {
  LOG_NONE = 0x00000000, 

  LOG_ERROR = 0x00000001, 
  LOG_LEVEL_ERROR = 0x00000001, 

  LOG_WARN = 0x00000002, 
  LOG_LEVEL_WARN = 0x00000003, 

  LOG_DEBUG = 0x00000004, 
  LOG_LEVEL_DEBUG = 0x00000007, 

  LOG_INFO = 0x00000008, 
  LOG_LEVEL_INFO = 0x0000000f, 

  LOG_FUNCTION = 0x00000010, 
  LOG_LEVEL_FUNCTION = 0x0000001f, 

  LOG_LOGIC = 0x00000020, 
  LOG_LEVEL_LOGIC = 0x0000003f, 

  LOG_ALL = 0x1fffffff, 
  LOG_LEVEL_ALL = LOG_ALL, 

  LOG_PREFIX_FUNC = 0x80000000, 
  LOG_PREFIX_TIME = 0x40000000, 
  LOG_PREFIX_NODE = 0x20000000
} LogLevel;
# 6 "/home/ondra/symphony/release/tinyos-2.1.1/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4282 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4283 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 14 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/radioheader.h"
#line 6
typedef struct ns3_metadata_t {

  uint8_t lqi;
  union  {

    uint8_t power;
    uint8_t rssi;
  } ;
} __attribute((__packed__))  ns3_metadata_t;
#line 29
#line 18
typedef nx_struct ns3packet_header_t {

  nx_uint8_t length;
  nx_uint8_t dsn;
  nx_am_id_t type;
  nx_uint16_t fdest;
  nx_am_group_t destpan;
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t padd;
} __attribute__((packed)) 
__attribute((__packed__))  ns3packet_header_t;




#line 31
typedef struct timestamp_metadata_t {

  uint32_t timestamp;
} __attribute((__packed__))  timestamp_metadata_t;




#line 36
typedef nx_struct ns3packet_footer_t {
} __attribute__((packed)) 

__attribute((__packed__))  ns3packet_footer_t;





#line 41
typedef struct flags_metadata_t {


  uint8_t flags;
} __attribute((__packed__))  flags_metadata_t;







#line 48
typedef struct ns3packet_metadata_t {

  timestamp_metadata_t timestamp;
  flags_metadata_t flags;
  ns3_metadata_t ns3;
} __attribute((__packed__))  ns3packet_metadata_t;
# 50 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/platform_message.h"
#line 47
typedef union message_header {
  ns3packet_header_t rf230;
} 
message_header_t;



#line 52
typedef union message_footer {
  ns3packet_footer_t rf230;
} message_footer_t;



#line 56
typedef union message_metadata {
  ns3packet_metadata_t rf230;
} message_metadata_t;
# 19 "/home/ondra/symphony/release/tinyos-2.1.1/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[28];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) __attribute((__packed__))  message_t;
typedef TMilli NsTimerP$Timer$precision_tag;
typedef TMilli SensorNodeC$LocTimer$precision_tag;
enum AMQueueP$__nesc_unnamed4284 {
  AMQueueP$NUM_CLIENTS = 1U
};
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$precision_tag;
typedef TMilli SpliterC$MilliTimer$precision_tag;
# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t PlatformP$Init$init(void );
#line 62
static error_t LedsP$Init$init(void );
#line 62
static error_t NsTimerP$Init$init(void );
# 136 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static uint32_t NsTimerP$Timer$getNow(void );
#line 129
static void NsTimerP$Timer$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void NsTimerP$Timer$stop(void );
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t SchedulerBasicP$TaskBasic$postTask(
# 47 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
uint8_t arg_0x2b5f64c16960);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP$TaskBasic$default$runTask(
# 47 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
uint8_t arg_0x2b5f64c16960);
# 57 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
static void SchedulerBasicP$Scheduler$init(void );







static bool SchedulerBasicP$Scheduler$runNextTask(void );
# 36 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMote.nc"
static void SimMoteP$SimMote$setEuid(long long int euid);



static void SimMoteP$SimMote$turnOn(void );
# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void SensorNodeC$SensorControl$startDone(error_t error);
#line 138
static void SensorNodeC$SensorControl$stopDone(error_t error);
# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Boot.nc"
static void SensorNodeC$Boot$booted(void );
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SensorNodeC$Send$runTask(void );
# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static void SensorNodeC$ActiveMessageAddress$changed(void );
# 3 "Split.nc"
static void SensorNodeC$Split$SendDone(void );

static void SensorNodeC$Split$StartDone(void );
# 22 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/InterruptWithData.nc"
static void SensorNodeC$DataIn$interruptWithData(error_t result, uint16_t length, void *buffer);
# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void SensorNodeC$LocTimer$fired(void );
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(
# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
am_id_t arg_0x2b5f64db0d28, 
# 103 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(
# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x2b5f64db1b90, 
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(
# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x2b5f64db1b90, 
# 96 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );
#line 75
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t Ns3ActiveMessageC$SplitControl$start(void );
# 54 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
static void Ns3ActiveMessageC$SubSend$sendDone(message_t *msg, error_t error);
# 42 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareReceive.nc"
static message_t *Ns3ActiveMessageC$SubReceive$receive(message_t *msg);
# 59 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SendNotifier.nc"
static void Ns3ActiveMessageC$SendNotifier$default$aboutToSend(
# 19 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e041a0, 
# 59 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SendNotifier.nc"
am_addr_t dest, 
#line 57
message_t * msg);
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
static uint8_t Ns3ActiveMessageC$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


Ns3ActiveMessageC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t Ns3ActiveMessageC$Packet$maxPayloadLength(void );
#line 94
static void Ns3ActiveMessageC$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t Ns3ActiveMessageC$AMSend$send(
# 16 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e08900, 
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Ns3ActiveMessageC$Snoop$default$receive(
# 18 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e05670, 
# 71 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 69 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
static void Ns3ActiveMessageC$SubState$done(void );
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void Ns3ActiveMessageC$SplitControlStartDone$runTask(void );
# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static void Ns3ActiveMessageC$ActiveMessageAddress$changed(void );
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Ns3ActiveMessageC$Receive$default$receive(
# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e07a90, 
# 71 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 68 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static am_addr_t Ns3ActiveMessageC$AMPacket$address(void );









static am_addr_t Ns3ActiveMessageC$AMPacket$destination(
#line 74
message_t * amsg);
#line 121
static void Ns3ActiveMessageC$AMPacket$setSource(
#line 117
message_t * amsg, 



am_addr_t addr);
#line 103
static void Ns3ActiveMessageC$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t Ns3ActiveMessageC$AMPacket$type(
#line 143
message_t * amsg);
#line 162
static void Ns3ActiveMessageC$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool Ns3ActiveMessageC$AMPacket$isForMe(
#line 133
message_t * amsg);
#line 187
static void Ns3ActiveMessageC$AMPacket$setGroup(
#line 184
message_t * amsg, 


am_group_t grp);







static am_group_t Ns3ActiveMessageC$AMPacket$localGroup(void );
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void NS3MsgGatewayP$receive$runTask(void );
#line 75
static void NS3MsgGatewayP$sendDoneTask$runTask(void );
# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
static error_t NS3MsgGatewayP$Send$send(message_t *msg);
# 56 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
static error_t NS3MsgGatewayP$State$turnOn(void );
# 55 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$amAddress(void );
# 50 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );




static am_group_t ActiveMessageAddressC$ActiveMessageAddress$amGroup(void );
#line 45
static void ActiveMessageAddressC$ActiveMessageAddress$setAddress(am_group_t group, am_addr_t addr);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );
#line 136
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(
# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x2b5f64ef5160);
# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(
# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x2b5f64ef5160);
# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void SpliterC$AMControl$startDone(error_t error);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SpliterC$send$runTask(void );
# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void SpliterC$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 2 "Split.nc"
static void SpliterC$Split$SplitAndSend(uint8_t *buffer, uint16_t size, uint32_t timest);

static void SpliterC$Split$Start(void );
# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void SpliterC$MilliTimer$fired(void );
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



SpliterC$Receive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t MagnetomiterP$SplitControl$start(void );
# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t PlatformP$SubInit$init(void );
#line 62
static error_t PlatformP$TimerInit$init(void );
# 56 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/PlatformP.nc"
static inline error_t PlatformP$Init$init(void );
# 68 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/system/LedsP.nc"
static inline error_t LedsP$Init$init(void );
# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void NsTimerP$Timer$fired(void );
# 20 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
uint32_t NsTimerP$time_now = 0;








#line 21
typedef struct NsTimerP$__nesc_unnamed4285 {

  uint32_t t0;
  uint32_t dt;
  uint32_t shoot;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} NsTimerP$Timer_t;

NsTimerP$Timer_t NsTimerP$m_timer;

static inline void NsTimerP$updateTimer(void );








extern int tickFired(uint32_t a)   ;
#line 69
static inline void NsTimerP$Timer$stop(void );
#line 99
static inline void NsTimerP$Timer$startOneShotAt(uint32_t t0, uint32_t dt);
#line 112
static inline uint32_t NsTimerP$Timer$getNow(void );
#line 133
static inline error_t NsTimerP$Init$init(void );
# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t SimMainP$SoftwareInit$init(void );
# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Boot.nc"
static void SimMainP$Boot$booted(void );
# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t SimMainP$PlatformInit$init(void );
# 57 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
static void SimMainP$Scheduler$init(void );
# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMainP.nc"
int sim_main_start_mote(int id)   ;
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP$TaskBasic$runTask(
# 47 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
uint8_t arg_0x2b5f64c16960);




extern int runNextEventExternal(uint32_t a)   ;




enum SchedulerBasicP$__nesc_unnamed4286 {

  SchedulerBasicP$NUM_TASKS = 8U, 
  SchedulerBasicP$NO_TASK = 255
};

uint8_t SchedulerBasicP$m_head;
uint8_t SchedulerBasicP$m_tail;
uint8_t SchedulerBasicP$m_next[SchedulerBasicP$NUM_TASKS];








static __inline uint8_t SchedulerBasicP$popTask(void );
#line 93
static inline bool SchedulerBasicP$isWaiting(uint8_t id);




static inline bool SchedulerBasicP$pushTask(uint8_t id);
#line 120
static inline void SchedulerBasicP$Scheduler$init(void );
#line 132
static inline bool SchedulerBasicP$Scheduler$runNextTask(void );
#line 170
static error_t SchedulerBasicP$TaskBasic$postTask(uint8_t id);




static inline void SchedulerBasicP$TaskBasic$default$runTask(uint8_t id);
# 8 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMoteP.nc"
long long int SimMoteP$euid;

bool SimMoteP$isOn;





static inline void SimMoteP$SimMote$setEuid(long long int e);
#line 30
static inline void SimMoteP$SimMote$turnOn(void );
#line 50
long long int sim_mote_euid(int mote)   ;








void sim_mote_set_euid(int mote, long long int id)   ;






long long int sim_mote_start_time(int mote)   ;








int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)   ;









void sim_mote_set_start_time(int mote, long long int t)   ;








bool sim_mote_is_on(int mote)   ;








void sim_mote_turn_on(int mote)   ;







void sim_mote_turn_off(int mote)   ;
#line 127
void sim_mote_enqueue_boot_event(int mote)   ;
# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t SensorNodeC$SensorControl$start(void );
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t SensorNodeC$Send$postTask(void );
# 45 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static void SensorNodeC$ActiveMessageAddress$setAddress(am_group_t group, am_addr_t addr);
# 2 "Split.nc"
static void SensorNodeC$Split$SplitAndSend(uint8_t *buffer, uint16_t size, uint32_t timest);

static void SensorNodeC$Split$Start(void );
# 136 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static uint32_t SensorNodeC$LocTimer$getNow(void );
# 16 "SensorNodeC.nc"
enum SensorNodeC$__nesc_unnamed4287 {
#line 16
  SensorNodeC$Send = 0U
};
#line 16
typedef int SensorNodeC$__nesc_sillytask_Send[SensorNodeC$Send];
uint8_t *SensorNodeC$dataToSend;
uint16_t SensorNodeC$sizeOfData;
bool SensorNodeC$busy;
uint32_t SensorNodeC$timestamp;

static inline void SensorNodeC$Boot$booted(void );







static inline void SensorNodeC$ActiveMessageAddress$changed(void );





static inline void SensorNodeC$Split$StartDone(void );




static inline void SensorNodeC$SensorControl$startDone(error_t err);








static inline void SensorNodeC$DataIn$interruptWithData(error_t result, uint16_t length, void *buffer);
#line 69
static inline void SensorNodeC$Send$runTask(void );









static inline void SensorNodeC$Split$SendDone(void );





static inline void SensorNodeC$SensorControl$stopDone(error_t err);



static inline void SensorNodeC$LocTimer$fired(void );
# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
static error_t /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline error_t /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err);
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(
# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
am_id_t arg_0x2b5f64db0d28, 
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(
# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x2b5f64db1b90, 
# 96 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(
#line 74
message_t * msg);
#line 94
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void );
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(
#line 143
message_t * amsg);
# 126 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4288 {
#line 126
  AMQueueImplP$0$CancelTask = 1U
};
#line 126
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask];
#line 169
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4289 {
#line 169
  AMQueueImplP$0$errorTask = 2U
};
#line 169
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask];
#line 57
#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4290 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = 1;
/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[1];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[1 / 8 + 1];

static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void );
#line 90
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
#line 163
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );




static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );
#line 189
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 215
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void Ns3ActiveMessageC$SplitControl$startDone(error_t error);
# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
static error_t Ns3ActiveMessageC$SubSend$send(message_t *msg);
# 59 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SendNotifier.nc"
static void Ns3ActiveMessageC$SendNotifier$aboutToSend(
# 19 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e041a0, 
# 59 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SendNotifier.nc"
am_addr_t dest, 
#line 57
message_t * msg);
# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void Ns3ActiveMessageC$AMSend$sendDone(
# 16 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e08900, 
# 103 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Ns3ActiveMessageC$Snoop$receive(
# 18 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e05670, 
# 71 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 56 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
static error_t Ns3ActiveMessageC$SubState$turnOn(void );
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t Ns3ActiveMessageC$SplitControlStartDone$postTask(void );
# 50 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t Ns3ActiveMessageC$ActiveMessageAddress$amAddress(void );




static am_group_t Ns3ActiveMessageC$ActiveMessageAddress$amGroup(void );
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Ns3ActiveMessageC$Receive$receive(
# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
am_id_t arg_0x2b5f64e07a90, 
# 71 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 54 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
enum Ns3ActiveMessageC$__nesc_unnamed4291 {
#line 54
  Ns3ActiveMessageC$SplitControlStartDone = 3U
};
#line 54
typedef int Ns3ActiveMessageC$__nesc_sillytask_SplitControlStartDone[Ns3ActiveMessageC$SplitControlStartDone];
#line 54
static inline void Ns3ActiveMessageC$SplitControlStartDone$runTask(void );



extern int radioStateDone(void )   ;





static inline error_t Ns3ActiveMessageC$SplitControl$start(void );
#line 78
static inline ns3packet_header_t *Ns3ActiveMessageC$getHeader(message_t *msg);



static inline void *Ns3ActiveMessageC$getPayload(message_t *msg);







static inline am_addr_t Ns3ActiveMessageC$destination(message_t *msg);



static inline void Ns3ActiveMessageC$setDestination(message_t *msg, am_addr_t addr);







static inline void Ns3ActiveMessageC$setSource(message_t *msg, am_addr_t addr);







static inline void Ns3ActiveMessageC$setGroup(message_t *msg, am_group_t grp);





static error_t Ns3ActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len);
#line 130
static inline void Ns3ActiveMessageC$SubSend$sendDone(message_t *msg, error_t error);
#line 154
static inline void Ns3ActiveMessageC$SendNotifier$default$aboutToSend(am_id_t id, am_addr_t addr, message_t *msg);



static inline void Ns3ActiveMessageC$SubState$done(void );




static inline message_t *Ns3ActiveMessageC$SubReceive$receive(message_t *msg);
#line 176
static inline message_t *Ns3ActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);




static inline message_t *Ns3ActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);






static __inline am_addr_t Ns3ActiveMessageC$AMPacket$address(void );




static __inline am_group_t Ns3ActiveMessageC$AMPacket$localGroup(void );




static __inline bool Ns3ActiveMessageC$AMPacket$isForMe(message_t *msg);





static __inline am_addr_t Ns3ActiveMessageC$AMPacket$destination(message_t *msg);




static __inline void Ns3ActiveMessageC$AMPacket$setDestination(message_t *msg, am_addr_t addr);









static __inline void Ns3ActiveMessageC$AMPacket$setSource(message_t *msg, am_addr_t addr);




static __inline am_id_t Ns3ActiveMessageC$AMPacket$type(message_t *msg);




static __inline void Ns3ActiveMessageC$AMPacket$setType(message_t *msg, am_id_t type);









static __inline void Ns3ActiveMessageC$AMPacket$setGroup(message_t *msg, am_group_t grp);




static __inline void Ns3ActiveMessageC$ActiveMessageAddress$changed(void );
#line 258
static inline uint8_t Ns3ActiveMessageC$Packet$payloadLength(message_t *msg);




static void Ns3ActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len);





static inline uint8_t Ns3ActiveMessageC$Packet$maxPayloadLength(void );




static inline void *Ns3ActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len);
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t NS3MsgGatewayP$receive$postTask(void );
#line 67
static error_t NS3MsgGatewayP$sendDoneTask$postTask(void );
# 54 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
static void NS3MsgGatewayP$Send$sendDone(message_t *msg, error_t error);
# 42 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareReceive.nc"
static message_t *NS3MsgGatewayP$Receive$receive(message_t *msg);
# 69 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
static void NS3MsgGatewayP$State$done(void );
# 40 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
enum NS3MsgGatewayP$__nesc_unnamed4292 {
#line 40
  NS3MsgGatewayP$sendDoneTask = 4U
};
#line 40
typedef int NS3MsgGatewayP$__nesc_sillytask_sendDoneTask[NS3MsgGatewayP$sendDoneTask];



enum NS3MsgGatewayP$__nesc_unnamed4293 {
#line 44
  NS3MsgGatewayP$receive = 5U
};
#line 44
typedef int NS3MsgGatewayP$__nesc_sillytask_receive[NS3MsgGatewayP$receive];
#line 34
message_t *NS3MsgGatewayP$msg_out;
error_t NS3MsgGatewayP$error_out = 0;

message_t *NS3MsgGatewayP$msg_in;


static inline void NS3MsgGatewayP$sendDoneTask$runTask(void );



static inline void NS3MsgGatewayP$receive$runTask(void );



extern int receiveMessage(void *msg)   ;








extern int sendDone(void *msg, error_t err)   ;





extern int radioStartDone(void )   ;






static inline error_t NS3MsgGatewayP$Send$send(message_t *msg);
#line 105
static error_t NS3MsgGatewayP$State$turnOn(void );
# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static void ActiveMessageAddressC$ActiveMessageAddress$changed(void );
# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/ActiveMessageAddressC.nc"
am_addr_t ActiveMessageAddressC$addr = TOS_AM_ADDRESS;


am_group_t ActiveMessageAddressC$group = TOS_AM_GROUP;






static inline am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );








static inline void ActiveMessageAddressC$ActiveMessageAddress$setAddress(am_group_t myGroup, am_addr_t myAddr);
#line 93
static inline am_group_t ActiveMessageAddressC$ActiveMessageAddress$amGroup(void );
#line 106
static inline am_addr_t ActiveMessageAddressC$amAddress(void );
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void );
# 136 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(
# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x2b5f64ef5160);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4294 {
#line 71
  VirtualizeTimerC$0$updateFromTimer = 6U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4295 {

  VirtualizeTimerC$0$NUM_TIMERS = 2U, 
  VirtualizeTimerC$0$END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4296 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now);
#line 99
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
#line 138
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );
#line 189
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(uint8_t num);
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num);
# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t SpliterC$AMControl$start(void );
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t SpliterC$send$postTask(void );
# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t SpliterC$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 126 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
static 
#line 123
void * 


SpliterC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
# 3 "Split.nc"
static void SpliterC$Split$SendDone(void );

static void SpliterC$Split$StartDone(void );
# 68 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static am_addr_t SpliterC$AMPacket$address(void );
# 18 "SpliterC.nc"
enum SpliterC$__nesc_unnamed4297 {
#line 18
  SpliterC$send = 7U
};
#line 18
typedef int SpliterC$__nesc_sillytask_send[SpliterC$send];
message_t SpliterC$packetS;
uint8_t SpliterC$dest = 0;
uint16_t SpliterC$partNr = 0;
bool SpliterC$locked;

uint16_t SpliterC$left;

uint8_t *SpliterC$dataToSend;
uint16_t SpliterC$sizeOfData;
uint32_t SpliterC$timestamp;

static inline void SpliterC$AMControl$startDone(error_t err);
#line 43
static inline void SpliterC$MilliTimer$fired(void );



static inline void SpliterC$send$runTask(void );
#line 85
static inline message_t *SpliterC$Receive$receive(message_t *bufPtr, void *payload, uint8_t len);






static void SpliterC$AMSend$sendDone(message_t *bufPtr, error_t error);
#line 111
static inline void SpliterC$Split$Start(void );




static inline void SpliterC$Split$SplitAndSend(uint8_t *buffer, uint16_t size, uint32_t timest);
# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void MagnetomiterP$SplitControl$startDone(error_t error);
#line 138
static void MagnetomiterP$SplitControl$stopDone(error_t error);
# 22 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/InterruptWithData.nc"
static void MagnetomiterP$data$interruptWithData(error_t result, uint16_t length, void *buffer);
# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/MagnetomiterP.nc"
static inline error_t MagnetomiterP$SplitControl$start(void );




extern int sensorStartDone(error_t error)   ;








extern int sensorStopDone(error_t error)   ;




extern void interruptData(error_t result, uint16_t lenght, void *buffer)   ;
# 10 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/hardware.h"
__inline  __nesc_atomic_t __nesc_atomic_start(void )
#line 10
{
  return 0;
}

__inline  void __nesc_atomic_end(__nesc_atomic_t x)
#line 14
{
}

# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t SpliterC$send$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(SpliterC$send);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 116 "SpliterC.nc"
static inline void SpliterC$Split$SplitAndSend(uint8_t *buffer, uint16_t size, uint32_t timest)
{
  SpliterC$timestamp = timest;
  SpliterC$dataToSend = buffer;
  SpliterC$sizeOfData = size;
  SpliterC$send$postTask();
}

# 2 "Split.nc"
inline static void SensorNodeC$Split$SplitAndSend(uint8_t *buffer, uint16_t size, uint32_t timest){
#line 2
  SpliterC$Split$SplitAndSend(buffer, size, timest);
#line 2
}
#line 2
# 69 "SensorNodeC.nc"
static inline void SensorNodeC$Send$runTask(void )
{

  printf("Buffer has: %dX%d bytes\n", sizeof(uint8_t ), SensorNodeC$sizeOfData);
  if (!SensorNodeC$busy) {
      SensorNodeC$Split$SplitAndSend(SensorNodeC$dataToSend, SensorNodeC$sizeOfData, SensorNodeC$timestamp);
      SensorNodeC$busy = 1;
    }
}

# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  SpliterC$AMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(m, err);
}

# 215 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(uint8_t arg_0x2b5f64db1b90, message_t * msg, error_t error){
#line 100
  switch (arg_0x2b5f64db1b90) {
#line 100
    case 0U:
#line 100
      /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(arg_0x2b5f64db1b90, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 163 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[last].msg = (message_t *)(void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, err);
}

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void )
#line 169
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current, /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg, FAIL);
}

#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[last].msg = (message_t *)(void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 56 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
inline static error_t Ns3ActiveMessageC$SubState$turnOn(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = NS3MsgGatewayP$State$turnOn();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 64 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline error_t Ns3ActiveMessageC$SplitControl$start(void )
#line 64
{
  Ns3ActiveMessageC$SubState$turnOn();
  return 0;
}

# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static error_t SpliterC$AMControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = Ns3ActiveMessageC$SplitControl$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/MagnetomiterP.nc"
static inline error_t MagnetomiterP$SplitControl$start(void )
#line 17
{

  return gatewaySensor(proxy, SENSOR_ON);
}

# 104 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static error_t SensorNodeC$SensorControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = MagnetomiterP$SplitControl$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 36 "SensorNodeC.nc"
static inline void SensorNodeC$Split$StartDone(void )
{
  SensorNodeC$SensorControl$start();
}

# 5 "Split.nc"
inline static void SpliterC$Split$StartDone(void ){
#line 5
  SensorNodeC$Split$StartDone();
#line 5
}
#line 5
# 106 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/ActiveMessageAddressC.nc"
static inline am_addr_t ActiveMessageAddressC$amAddress(void )
#line 106
{
  am_addr_t myAddr;

#line 108
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 108
    myAddr = ActiveMessageAddressC$addr;
#line 108
    __nesc_atomic_end(__nesc_atomic); }
  return myAddr;
}

#line 72
static inline am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void )
#line 72
{
  return ActiveMessageAddressC$amAddress();
}

# 50 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
inline static am_addr_t Ns3ActiveMessageC$ActiveMessageAddress$amAddress(void ){
#line 50
  unsigned short __nesc_result;
#line 50

#line 50
  __nesc_result = ActiveMessageAddressC$ActiveMessageAddress$amAddress();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 188 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static __inline am_addr_t Ns3ActiveMessageC$AMPacket$address(void )
{
  return Ns3ActiveMessageC$ActiveMessageAddress$amAddress();
}

# 68 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static am_addr_t SpliterC$AMPacket$address(void ){
#line 68
  unsigned short __nesc_result;
#line 68

#line 68
  __nesc_result = Ns3ActiveMessageC$AMPacket$address();
#line 68

#line 68
  return __nesc_result;
#line 68
}
#line 68
# 30 "SpliterC.nc"
static inline void SpliterC$AMControl$startDone(error_t err)
#line 30
{
  if (err == SUCCESS) {
      printf("AMControl.startDone: TOS_NODE_ID == %d TOS_NODE_ADDR == %d\n ", TOS_NODE_ID, SpliterC$AMPacket$address());
      SpliterC$Split$StartDone();
    }
  else 
#line 34
    {
      SpliterC$AMControl$start();
    }
}

# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static void Ns3ActiveMessageC$SplitControl$startDone(error_t error){
#line 113
  SpliterC$AMControl$startDone(error);
#line 113
}
#line 113
# 54 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline void Ns3ActiveMessageC$SplitControlStartDone$runTask(void )
#line 54
{
  Ns3ActiveMessageC$SplitControl$startDone(SUCCESS);
}

# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 281
{
  const uint8_t *base = (uint8_t *)source;

#line 283
  return base[0];
}

# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline ns3packet_header_t *Ns3ActiveMessageC$getHeader(message_t *msg)
#line 78
{
  return (ns3packet_header_t *)msg->header;
}

#line 224
static __inline am_id_t Ns3ActiveMessageC$AMPacket$type(message_t *msg)
{
  return __nesc_ntoh_uint8(Ns3ActiveMessageC$getHeader(msg)->type.nxdata);
}

# 189 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current >= 1) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current, msg, err);
    }
  else {
      ;
    }
}

# 110 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static void Ns3ActiveMessageC$AMSend$sendDone(am_id_t arg_0x2b5f64e08900, message_t * msg, error_t error){
#line 110
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(arg_0x2b5f64e08900, msg, error);
#line 110
}
#line 110
# 130 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline void Ns3ActiveMessageC$SubSend$sendDone(message_t *msg, error_t error)
{
  Ns3ActiveMessageC$AMSend$sendDone(Ns3ActiveMessageC$AMPacket$type(msg), msg, error);
}

# 54 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
inline static void NS3MsgGatewayP$Send$sendDone(message_t *msg, error_t error){
#line 54
  Ns3ActiveMessageC$SubSend$sendDone(msg, error);
#line 54
}
#line 54
# 40 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
static inline void NS3MsgGatewayP$sendDoneTask$runTask(void )
#line 40
{
  NS3MsgGatewayP$Send$sendDone(NS3MsgGatewayP$msg_out, NS3MsgGatewayP$error_out);
}

# 181 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline message_t *Ns3ActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
{
  return msg;
}

# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
inline static message_t * Ns3ActiveMessageC$Snoop$receive(am_id_t arg_0x2b5f64e05670, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = Ns3ActiveMessageC$Snoop$default$receive(arg_0x2b5f64e05670, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 85 "SpliterC.nc"
static inline message_t *SpliterC$Receive$receive(message_t *bufPtr, void *payload, uint8_t len)
#line 85
{
  if (SpliterC$partNr == 1) {
      SpliterC$send$postTask();
    }
  return bufPtr;
}

# 176 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline message_t *Ns3ActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
{
  return msg;
}

# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Receive.nc"
inline static message_t * Ns3ActiveMessageC$Receive$receive(am_id_t arg_0x2b5f64e07a90, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x2b5f64e07a90) {
#line 78
    case 6:
#line 78
      __nesc_result = SpliterC$Receive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = Ns3ActiveMessageC$Receive$default$receive(arg_0x2b5f64e07a90, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 310 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 310
{
  const uint8_t *base = (uint8_t *)source;

#line 312
  return ((uint16_t )base[0] << 8) | base[1];
}

# 90 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline am_addr_t Ns3ActiveMessageC$destination(message_t *msg)
#line 90
{
  return __nesc_ntoh_uint16(Ns3ActiveMessageC$getHeader(msg)->dest.nxdata);
}

#line 204
static __inline am_addr_t Ns3ActiveMessageC$AMPacket$destination(message_t *msg)
{
  return Ns3ActiveMessageC$destination(msg);
}

#line 198
static __inline bool Ns3ActiveMessageC$AMPacket$isForMe(message_t *msg)
{
  am_addr_t addr = Ns3ActiveMessageC$AMPacket$destination(msg);

#line 201
  return addr == Ns3ActiveMessageC$AMPacket$address() || addr == AM_BROADCAST_ADDR;
}

#line 258
static inline uint8_t Ns3ActiveMessageC$Packet$payloadLength(message_t *msg)
{
  return sizeof(ns3packet_header_t );
}

#line 82
static inline void *Ns3ActiveMessageC$getPayload(message_t *msg)
#line 82
{
  return (void *)msg->data;
}

#line 163
static inline message_t *Ns3ActiveMessageC$SubReceive$receive(message_t *msg)
{
  am_id_t id = Ns3ActiveMessageC$AMPacket$type(msg);
  void *payload = Ns3ActiveMessageC$getPayload(msg);
  uint8_t len = Ns3ActiveMessageC$Packet$payloadLength(msg);

  Ns3ActiveMessageC$AMPacket$isForMe(msg) ? 
  Ns3ActiveMessageC$Receive$receive(id, msg, payload, len) : 
  Ns3ActiveMessageC$Snoop$receive(id, msg, payload, len);

  return msg;
}

# 42 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareReceive.nc"
inline static message_t *NS3MsgGatewayP$Receive$receive(message_t *msg){
#line 42
  nx_struct message_t *__nesc_result;
#line 42

#line 42
  __nesc_result = Ns3ActiveMessageC$SubReceive$receive(msg);
#line 42

#line 42
  return __nesc_result;
#line 42
}
#line 42
# 44 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
static inline void NS3MsgGatewayP$receive$runTask(void )
#line 44
{
  NS3MsgGatewayP$Receive$receive(NS3MsgGatewayP$msg_in);
}

# 112 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
static inline uint32_t NsTimerP$Timer$getNow(void )
#line 112
{

  return NsTimerP$time_now;
}

# 136 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = NsTimerP$Timer$getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 138 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow());
}

# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void NsTimerP$Timer$fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired();
#line 83
}
#line 83
# 33 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
static inline void NsTimerP$updateTimer(void )
#line 33
{

  if (NsTimerP$m_timer.shoot == NsTimerP$time_now) {

      NsTimerP$Timer$fired();
    }
}

#line 99
static inline void NsTimerP$Timer$startOneShotAt(uint32_t t0, uint32_t dt)
#line 99
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 100
    {
      NsTimerP$m_timer.isoneshot = true;
      NsTimerP$m_timer.dt = dt;
      NsTimerP$m_timer.t0 = t0;
      NsTimerP$m_timer.shoot = t0 + dt;
      NsTimerP$m_timer.isrunning = true;
    }
#line 106
    __nesc_atomic_end(__nesc_atomic); }

  NsTimerP$updateTimer();
}

# 129 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  NsTimerP$Timer$startOneShotAt(t0, dt);
#line 129
}
#line 129
# 69 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
static inline void NsTimerP$Timer$stop(void )
#line 69
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 71
    {
      NsTimerP$m_timer.isoneshot = false;
      NsTimerP$m_timer.dt = 0;
      NsTimerP$m_timer.t0 = 0;
      NsTimerP$m_timer.shoot = 0;
      NsTimerP$m_timer.isrunning = false;
    }
#line 77
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void ){
#line 78
  NsTimerP$Timer$stop();
#line 78
}
#line 78
# 99 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = false;
  uint8_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = true;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(now);
        }
      else {
#line 134
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(now, min_remaining);
        }
    }
}

# 347 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint32_t __nesc_hton_uint32(void * target, uint32_t value)
#line 347
{
  uint8_t *base = (uint8_t *)target;

#line 349
  base[3] = value;
  base[2] = value >> 8;
  base[1] = value >> 16;
  base[0] = value >> 24;
  return value;
}

#line 315
static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 315
{
  uint8_t *base = (uint8_t *)target;

#line 317
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

#line 286
static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 286
{
  uint8_t *base = (uint8_t *)target;

#line 288
  base[0] = value;
  return value;
}

# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(am_id_t arg_0x2b5f64db0d28, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = Ns3ActiveMessageC$AMSend$send(arg_0x2b5f64db0d28, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = Ns3ActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
#line 147
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = Ns3ActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 94 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  Ns3ActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 90 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 1) {
      return FAIL;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg != (void *)0) {
      return EBUSY;
    }
  ;

  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current >= 1) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(msg);

      ;
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          ;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = 1;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg = (message_t *)(void *)0;
        }

      return err;
    }
  else {
      ;
    }
  return SUCCESS;
}

# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Send.nc"
inline static error_t /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 229 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static __inline void Ns3ActiveMessageC$AMPacket$setType(message_t *msg, am_id_t type)
{
  __nesc_hton_uint8(Ns3ActiveMessageC$getHeader(msg)->type.nxdata, type);
}

# 162 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  Ns3ActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
# 94 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline void Ns3ActiveMessageC$setDestination(message_t *msg, am_addr_t addr)
#line 94
{
  __nesc_hton_uint16(Ns3ActiveMessageC$getHeader(msg)->dest.nxdata, addr);
}

#line 209
static __inline void Ns3ActiveMessageC$AMPacket$setDestination(message_t *msg, am_addr_t addr)
{
  Ns3ActiveMessageC$setDestination(msg, addr);
}

# 103 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static void /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  Ns3ActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline error_t /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(msg, dest);
  /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(msg, 6);
  return /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(msg, len);
}

# 80 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static error_t SpliterC$AMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*SensorNodeApp.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 274 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline void *Ns3ActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len)
{
  for (; 0; ) ;

  return (void *)msg->data;
}

# 126 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static void * SpliterC$Packet$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = Ns3ActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 47 "SpliterC.nc"
static inline void SpliterC$send$runTask(void )
#line 47
{
  printf("SPLITERC::void task send() TOS_NODE_ID::%d  - DEST::%d\n", TOS_NODE_ID, SpliterC$dest);
  if (SpliterC$locked) {
      printf("LOCKED\n");
      return;
    }
  else {
      radio_data_msg_t *sP = (radio_data_msg_t *)SpliterC$Packet$getPayload(&SpliterC$packetS, sizeof(radio_data_msg_t ));

#line 55
      if (sP == (void *)0) {
          printf("sP == NULL\n");
          return;
        }
      __nesc_hton_uint8(sP->sender.nxdata, TOS_NODE_ID);
      __nesc_hton_uint16(sP->partNr.nxdata, SpliterC$partNr);

      if (SpliterC$partNr == 0) 
        {

          printf("TOSNODE:: %d CREATING PACKET LEN %d SIZEOFDATA: %d\n", TOS_NODE_ID, sizeof(radio_data_msg_t ), SpliterC$sizeOfData);


          __nesc_hton_uint16((* (nx_uint16_t *)&sP->data[0]).nxdata, SpliterC$sizeOfData);
          __nesc_hton_uint32((* (nx_uint32_t *)&sP->data[2]).nxdata, SpliterC$timestamp);
        }
      else {
          printf("TOSNODE:: %d CREATING SENDED: %d PARTNR %d\n", TOS_NODE_ID, 25 * (SpliterC$partNr - 1), SpliterC$partNr);

          SpliterC$left = SpliterC$sizeOfData - (SpliterC$partNr - 1) * 25;
          memcpy(sP->data, &SpliterC$dataToSend[(SpliterC$partNr - 1) * 25], SpliterC$left > 25 ? 25 : SpliterC$left);
        }
      if (SpliterC$AMSend$send(SpliterC$dest, &SpliterC$packetS, sizeof(radio_data_msg_t )) == SUCCESS) {
          SpliterC$locked = true;
        }
      return;
    }
}

# 175 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
static inline void SchedulerBasicP$TaskBasic$default$runTask(uint8_t id)
{
}

# 75 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static void SchedulerBasicP$TaskBasic$runTask(uint8_t arg_0x2b5f64c16960){
#line 75
  switch (arg_0x2b5f64c16960) {
#line 75
    case SensorNodeC$Send:
#line 75
      SensorNodeC$Send$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask();
#line 75
      break;
#line 75
    case Ns3ActiveMessageC$SplitControlStartDone:
#line 75
      Ns3ActiveMessageC$SplitControlStartDone$runTask();
#line 75
      break;
#line 75
    case NS3MsgGatewayP$sendDoneTask:
#line 75
      NS3MsgGatewayP$sendDoneTask$runTask();
#line 75
      break;
#line 75
    case NS3MsgGatewayP$receive:
#line 75
      NS3MsgGatewayP$receive$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask();
#line 75
      break;
#line 75
    case SpliterC$send:
#line 75
      SpliterC$send$runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SchedulerBasicP$TaskBasic$default$runTask(arg_0x2b5f64c16960);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 74 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
static __inline uint8_t SchedulerBasicP$popTask(void )
{
  if (SchedulerBasicP$m_head != SchedulerBasicP$NO_TASK) 
    {
      uint8_t id = SchedulerBasicP$m_head;

#line 79
      SchedulerBasicP$m_head = SchedulerBasicP$m_next[SchedulerBasicP$m_head];
      if (SchedulerBasicP$m_head == SchedulerBasicP$NO_TASK) 
        {
          SchedulerBasicP$m_tail = SchedulerBasicP$NO_TASK;
        }
      SchedulerBasicP$m_next[id] = SchedulerBasicP$NO_TASK;
      return id;
    }
  else 
    {
      return SchedulerBasicP$NO_TASK;
    }
}

#line 132
static inline bool SchedulerBasicP$Scheduler$runNextTask(void )
{

  uint8_t nextTask;

#line 136
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      nextTask = SchedulerBasicP$popTask();
      if (nextTask == SchedulerBasicP$NO_TASK) 
        {
          {
            unsigned char __nesc_temp = 
#line 141
            true;

            {
#line 141
              __nesc_atomic_end(__nesc_atomic); 
#line 141
              return __nesc_temp;
            }
          }
        }
    }
#line 145
    __nesc_atomic_end(__nesc_atomic); }
#line 144
  SchedulerBasicP$TaskBasic$runTask(nextTask);
  return true;
}

# 269 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline uint8_t Ns3ActiveMessageC$Packet$maxPayloadLength(void )
{
  return 28;
}

#line 102
static inline void Ns3ActiveMessageC$setSource(message_t *msg, am_addr_t addr)
#line 102
{
  __nesc_hton_uint16(Ns3ActiveMessageC$getHeader(msg)->src.nxdata, addr);
}

#line 219
static __inline void Ns3ActiveMessageC$AMPacket$setSource(message_t *msg, am_addr_t addr)
{
  Ns3ActiveMessageC$setSource(msg, addr);
}

#line 110
static inline void Ns3ActiveMessageC$setGroup(message_t *msg, am_group_t grp)
#line 110
{
  __nesc_hton_uint8(Ns3ActiveMessageC$getHeader(msg)->destpan.nxdata, grp);
}

#line 239
static __inline void Ns3ActiveMessageC$AMPacket$setGroup(message_t *msg, am_group_t grp)
{
  Ns3ActiveMessageC$setGroup(msg, grp);
}

# 93 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/ActiveMessageAddressC.nc"
static inline am_group_t ActiveMessageAddressC$ActiveMessageAddress$amGroup(void )
#line 93
{
  am_group_t myGroup;

#line 95
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 95
    myGroup = ActiveMessageAddressC$group;
#line 95
    __nesc_atomic_end(__nesc_atomic); }
  return myGroup;
}

# 55 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
inline static am_group_t Ns3ActiveMessageC$ActiveMessageAddress$amGroup(void ){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = ActiveMessageAddressC$ActiveMessageAddress$amGroup();
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 193 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static __inline am_group_t Ns3ActiveMessageC$AMPacket$localGroup(void )
{
  return Ns3ActiveMessageC$ActiveMessageAddress$amGroup();
}

#line 154
static inline void Ns3ActiveMessageC$SendNotifier$default$aboutToSend(am_id_t id, am_addr_t addr, message_t *msg)
{
}

# 59 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SendNotifier.nc"
inline static void Ns3ActiveMessageC$SendNotifier$aboutToSend(am_id_t arg_0x2b5f64e041a0, am_addr_t dest, message_t * msg){
#line 59
    Ns3ActiveMessageC$SendNotifier$default$aboutToSend(arg_0x2b5f64e041a0, dest, msg);
#line 59
}
#line 59
# 70 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
static inline error_t NS3MsgGatewayP$Send$send(message_t *msg)
#line 70
{
  NS3MsgGatewayP$msg_out = msg;


  a = gatewayRadio(proxy, RADIO_SEND, -1, -1, (void *)msg, (void *)msg);
  return 0;
}

# 46 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/BareSend.nc"
inline static error_t Ns3ActiveMessageC$SubSend$send(message_t *msg){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  __nesc_result = NS3MsgGatewayP$Send$send(msg);
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 43 "SpliterC.nc"
static inline void SpliterC$MilliTimer$fired(void )
#line 43
{
}

# 89 "SensorNodeC.nc"
static inline void SensorNodeC$LocTimer$fired(void )
#line 89
{
}

# 204 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num)
{
}

# 83 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(uint8_t arg_0x2b5f64ef5160){
#line 83
  switch (arg_0x2b5f64ef5160) {
#line 83
    case 0U:
#line 83
      SpliterC$MilliTimer$fired();
#line 83
      break;
#line 83
    case 1U:
#line 83
      SensorNodeC$LocTimer$fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(arg_0x2b5f64ef5160);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 93 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
static inline bool SchedulerBasicP$isWaiting(uint8_t id)
{
  return SchedulerBasicP$m_next[id] != SchedulerBasicP$NO_TASK || SchedulerBasicP$m_tail == id;
}

static inline bool SchedulerBasicP$pushTask(uint8_t id)
{
  if (!SchedulerBasicP$isWaiting(id)) 
    {
      if (SchedulerBasicP$m_head == SchedulerBasicP$NO_TASK) 
        {
          SchedulerBasicP$m_head = id;
          SchedulerBasicP$m_tail = id;
        }
      else 
        {
          SchedulerBasicP$m_next[SchedulerBasicP$m_tail] = id;
          SchedulerBasicP$m_tail = id;
        }
      return true;
    }
  else 
    {
      return false;
    }
}

# 65 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 78
    /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = 1;
    }
}

# 78 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = Ns3ActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 79 "SensorNodeC.nc"
static inline void SensorNodeC$Split$SendDone(void )
{
  SensorNodeC$busy = 0;
  printf("event Split.SendDone()");
}

# 3 "Split.nc"
inline static void SpliterC$Split$SendDone(void ){
#line 3
  SensorNodeC$Split$SendDone();
#line 3
}
#line 3
# 120 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
static inline void SchedulerBasicP$Scheduler$init(void )
{
  /* atomic removed: atomic calls only */


  {
    memset((void *)SchedulerBasicP$m_next, SchedulerBasicP$NO_TASK, sizeof SchedulerBasicP$m_next);
    SchedulerBasicP$m_head = SchedulerBasicP$NO_TASK;
    SchedulerBasicP$m_tail = SchedulerBasicP$NO_TASK;
  }
}

# 57 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
inline static void SimMainP$Scheduler$init(void ){
#line 57
  SchedulerBasicP$Scheduler$init();
#line 57
}
#line 57
# 133 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
static inline error_t NsTimerP$Init$init(void )
#line 133
{
  /* atomic removed: atomic calls only */
#line 134
  NsTimerP$time_now = 0;
  return 0;
}

# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t PlatformP$TimerInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = NsTimerP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 68 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/system/LedsP.nc"
static inline error_t LedsP$Init$init(void )
#line 68
{

  return SUCCESS;
}

# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t PlatformP$SubInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = LedsP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 69 "/home/ondra/symphony/release/tinyos-2.1.1/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 56 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/PlatformP.nc"
static inline error_t PlatformP$Init$init(void )
{
  error_t ok = SUCCESS;

  ok = ecombine(ok, PlatformP$SubInit$init());
  PlatformP$TimerInit$init();
  return SUCCESS;
}

# 62 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t SimMainP$PlatformInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
inline static error_t SimMainP$SoftwareInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = NsTimerP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 111 "SpliterC.nc"
static inline void SpliterC$Split$Start(void )
{
  SpliterC$AMControl$start();
}

# 4 "Split.nc"
inline static void SensorNodeC$Split$Start(void ){
#line 4
  SpliterC$Split$Start();
#line 4
}
#line 4
# 30 "SensorNodeC.nc"
static inline void SensorNodeC$ActiveMessageAddress$changed(void )
{

  SensorNodeC$Split$Start();
}

# 244 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static __inline void Ns3ActiveMessageC$ActiveMessageAddress$changed(void )
{
}

# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
inline static void ActiveMessageAddressC$ActiveMessageAddress$changed(void ){
#line 60
  Ns3ActiveMessageC$ActiveMessageAddress$changed();
#line 60
  SensorNodeC$ActiveMessageAddress$changed();
#line 60
}
#line 60
# 81 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/ActiveMessageAddressC.nc"
static inline void ActiveMessageAddressC$ActiveMessageAddress$setAddress(am_group_t myGroup, am_addr_t myAddr)
#line 81
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 82
    {
      ActiveMessageAddressC$addr = myAddr;
      ActiveMessageAddressC$group = myGroup;
    }
#line 85
    __nesc_atomic_end(__nesc_atomic); }
  ActiveMessageAddressC$ActiveMessageAddress$changed();
}

# 45 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
inline static void SensorNodeC$ActiveMessageAddress$setAddress(am_group_t group, am_addr_t addr){
#line 45
  ActiveMessageAddressC$ActiveMessageAddress$setAddress(group, addr);
#line 45
}
#line 45
# 22 "SensorNodeC.nc"
static inline void SensorNodeC$Boot$booted(void )
#line 22
{
  printf("App: booted calling SplitAndSend%d\n", TOS_NODE_ID);

  SensorNodeC$ActiveMessageAddress$setAddress(AM_GROUPNR, TOS_NODE_ID);
}

# 60 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/Boot.nc"
inline static void SimMainP$Boot$booted(void ){
#line 60
  SensorNodeC$Boot$booted();
#line 60
}
#line 60
# 16 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMoteP.nc"
static inline void SimMoteP$SimMote$setEuid(long long int e)
#line 16
{
  SimMoteP$euid = e;
}











static inline void SimMoteP$SimMote$turnOn(void )
#line 30
{
  SimMoteP$isOn = true;
}

# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t NS3MsgGatewayP$receive$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(NS3MsgGatewayP$receive);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t NS3MsgGatewayP$sendDoneTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(NS3MsgGatewayP$sendDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t Ns3ActiveMessageC$SplitControlStartDone$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(Ns3ActiveMessageC$SplitControlStartDone);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 158 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static inline void Ns3ActiveMessageC$SubState$done(void )
#line 158
{
  Ns3ActiveMessageC$SplitControlStartDone$postTask();
}

# 69 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/radio/RadioState.nc"
inline static void NS3MsgGatewayP$State$done(void ){
#line 69
  Ns3ActiveMessageC$SubState$done();
#line 69
}
#line 69
# 41 "SensorNodeC.nc"
static inline void SensorNodeC$SensorControl$startDone(error_t err)
#line 41
{
  if (err == SUCCESS) {
      printf("SensorControl.startDone: TOS_NODE_ID == %d\n", TOS_NODE_ID);
      fflush(stdout);
    }
  else 
#line 45
    {
      SensorNodeC$SensorControl$start();
    }
}

# 113 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static void MagnetomiterP$SplitControl$startDone(error_t error){
#line 113
  SensorNodeC$SensorControl$startDone(error);
#line 113
}
#line 113
# 85 "SensorNodeC.nc"
static inline void SensorNodeC$SensorControl$stopDone(error_t err)
#line 85
{
}

# 138 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static void MagnetomiterP$SplitControl$stopDone(error_t error){
#line 138
  SensorNodeC$SensorControl$stopDone(error);
#line 138
}
#line 138
# 67 "/home/ondra/symphony/release/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t SensorNodeC$Send$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP$TaskBasic$postTask(SensorNodeC$Send);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 189 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
}

# 136 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static uint32_t SensorNodeC$LocTimer$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(1U);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 50 "SensorNodeC.nc"
static inline void SensorNodeC$DataIn$interruptWithData(error_t result, uint16_t length, void *buffer)
#line 50
{









  if (result == SUCCESS) {
      SensorNodeC$timestamp = SensorNodeC$LocTimer$getNow();
      printf("event void InterruptWithData.interruptWithData NODE_ID %d - data lenght %d timestamp %d \n", TOS_NODE_ID, length, SensorNodeC$timestamp);
      SensorNodeC$sizeOfData = length;
      SensorNodeC$dataToSend = (uint8_t *)buffer;
      SensorNodeC$Send$postTask();
    }
}

# 22 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/InterruptWithData.nc"
inline static void MagnetomiterP$data$interruptWithData(error_t result, uint16_t length, void *buffer){
#line 22
  SensorNodeC$DataIn$interruptWithData(result, length, buffer);
#line 22
}
#line 22
# 4 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/hardware.h"
static __inline void __nesc_enable_interrupt()
#line 4
{
}

#line 5
static __inline void __nesc_disable_interrupt()
#line 5
{
}

# 14 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/sim_main.h"
  int setUniqueID(int i)
#line 14
{
  TOS_NODE_ID = i;
  id_this_lib = i;
  return id_this_lib;
}

  int setProxy(void *con)
#line 20
{
  proxy = con;
  if (proxy != (void *)0) {
      a = gateway(proxy, 0, id_this_lib);
    }
  else 
    {
      printf("FROM toslib: ops! no proxy\n");
    }
  return id_this_lib;
}

# 52 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
extern   int runNextEventExternal(uint32_t a)
#line 52
{

  SchedulerBasicP$Scheduler$runNextTask();
  return 0;
}

# 263 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
static void Ns3ActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len)
{
  for (; 0; ) ;
  __nesc_hton_uint8(Ns3ActiveMessageC$getHeader(msg)->length.nxdata, len);
}

#line 116
static error_t Ns3ActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len)
{
  if (len > Ns3ActiveMessageC$Packet$maxPayloadLength()) {
    return EINVAL;
    }
  Ns3ActiveMessageC$Packet$setPayloadLength(msg, len);
  Ns3ActiveMessageC$AMPacket$setSource(msg, Ns3ActiveMessageC$AMPacket$address());
  Ns3ActiveMessageC$AMPacket$setGroup(msg, Ns3ActiveMessageC$AMPacket$localGroup());
  Ns3ActiveMessageC$AMPacket$setType(msg, id);
  Ns3ActiveMessageC$AMPacket$setDestination(msg, addr);
  Ns3ActiveMessageC$SendNotifier$aboutToSend(id, addr, msg);
  return Ns3ActiveMessageC$SubSend$send(msg);
}

# 73 "/home/ondra/symphony/release/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now)
{
  uint8_t num;

#line 76
  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = false;
                }
              else {
#line 89
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 170 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SchedulerBasicP.nc"
static error_t SchedulerBasicP$TaskBasic$postTask(uint8_t id)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 172
    {
#line 172
      {
        unsigned char __nesc_temp = 
#line 172
        SchedulerBasicP$pushTask(id) ? SUCCESS : EBUSY;

        {
#line 172
          __nesc_atomic_end(__nesc_atomic); 
#line 172
          return __nesc_temp;
        }
      }
    }
#line 175
    __nesc_atomic_end(__nesc_atomic); }
}

# 174 "/home/ondra/symphony/release/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void )
#line 174
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current < 1) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(nextMsg);

#line 182
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask();
        }
    }
}

# 92 "SpliterC.nc"
static void SpliterC$AMSend$sendDone(message_t *bufPtr, error_t error)
#line 92
{
  if (&SpliterC$packetS == bufPtr) {
      SpliterC$locked = false;
      printf("event void AMSend.sendDone %d\n", TOS_NODE_ID);
      SpliterC$partNr++;

      if (SpliterC$partNr != 1) {
          if ((SpliterC$partNr - 1) * 25 <= SpliterC$sizeOfData) {
              SpliterC$send$postTask();
            }
          else 
            {
              SpliterC$partNr = 0;
              SpliterC$Split$SendDone();
            }
        }
    }
}

# 105 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
static error_t NS3MsgGatewayP$State$turnOn(void )
#line 105
{
  void *buff = (void *)0;

#line 107
  return gatewayRadio(proxy, RADIO_ON, -1, -1, buff, buff);
}

# 42 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/timers/NsTimerP.nc"
extern   int tickFired(uint32_t a)
#line 42
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 44
    NsTimerP$time_now = a;
#line 44
    __nesc_atomic_end(__nesc_atomic); }
  NsTimerP$updateTimer();
  runNextEventExternal(0);

  NsTimerP$Timer$fired();
  return 0;
}

# 17 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMainP.nc"
  int sim_main_start_mote(int id)
#line 17
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 21
    {






      SimMainP$Scheduler$init();





      SimMainP$PlatformInit$init();






      SimMainP$SoftwareInit$init();

      TOS_NODE_ID = id;
    }
#line 44
    __nesc_atomic_end(__nesc_atomic); }







  SimMainP$Boot$booted();







  return 0;
}

# 50 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sim/SimMoteP.nc"
  long long int sim_mote_euid(int mote)
#line 50
{





  return 3;
}

  void sim_mote_set_euid(int mote, long long int id)
#line 59
{


  SimMoteP$SimMote$setEuid(id);
}


  long long int sim_mote_start_time(int mote)
#line 66
{





  return 2;
}

  int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)
#line 75
{
  int result = 0;





  return result;
}

  void sim_mote_set_start_time(int mote, long long int t)
#line 85
{
}







  bool sim_mote_is_on(int mote)
#line 94
{





  return SimMoteP$isOn;
}

  void sim_mote_turn_on(int mote)
#line 103
{
  printf("sim_main_start_mote\n");


  SimMoteP$SimMote$turnOn();
}


  void sim_mote_turn_off(int mote)
#line 111
{
}

#line 127
  void sim_mote_enqueue_boot_event(int mote)
#line 127
{
}

# 58 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/Ns3ActiveMessageC.nc"
extern   int radioStateDone(void )
#line 58
{
  printf("\t radio state done\n");
  Ns3ActiveMessageC$SplitControlStartDone$postTask();
  return 0;
}

# 48 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/NS3MsgGatewayP.nc"
extern   int receiveMessage(void *msg)
#line 48
{


  NS3MsgGatewayP$msg_in = (message_t *)msg;

  NS3MsgGatewayP$receive$postTask();
  return 0;
}

extern   int sendDone(void *msg, error_t err)
#line 57
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 58
    NS3MsgGatewayP$error_out = err;
#line 58
    __nesc_atomic_end(__nesc_atomic); }
  NS3MsgGatewayP$sendDoneTask$postTask();
  return 0;
}

extern   int radioStartDone(void )
#line 63
{
  NS3MsgGatewayP$State$done();
  return 0;
}

# 22 "/home/ondra/symphony/release/tinyos-2.1.1/tos/platforms/ns3/sensors/MagnetomiterP.nc"
extern   int sensorStartDone(error_t error)
#line 22
{
  MagnetomiterP$SplitControl$startDone(error);
  return 0;
}





extern   int sensorStopDone(error_t error)
#line 31
{
  MagnetomiterP$SplitControl$stopDone(error);
  return 0;
}

extern   void interruptData(error_t result, uint16_t lenght, void *buffer)
#line 36
{
  MagnetomiterP$data$interruptWithData(result, lenght, buffer);
}

 #ifdef __cplusplus 
 		 } 
 		 #endif 
