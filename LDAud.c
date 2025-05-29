#include <link.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#  define NOTUSED(x) NOTUSED_ ## x __attribute__((__unused__))
#include <dlfcn.h>

unsigned int la_version(unsigned int version){
        printf( "%s:%d:%s version = %i\n", __FILE__, __LINE__, __func__, version );
        return version;

}

void la_preinit(uintptr_t *cookie) {
        printf("la_preinit called with cookie: %p\n", cookie);
}

//name is search path
//cookie is the object that started the search
//flag should again be set to a value
char *la_objsearch( const char *name, uintptr_t* cookie, unsigned int flag ){
  //  printf( "%s:%d:%s name=%s, cookie=%p, flags=%s\n",
    //    __FILE__, __LINE__, __func__,
      //  name,
       // cookie,
       // flag & LA_SER_ORIG    ? "LA_SER_ORIG"    :
       // flag & LA_SER_LIBPATH ? "LA_SER_LIBPATH" :
       // flag & LA_SER_RUNPATH ? "LA_SER_RUNPATH" :
       // flag & LA_SER_CONFIG  ? "LA_SER_CONFIG"  :
       // flag & LA_SER_DEFAULT ? "LA_SER_DEFAULT" :
        //flag & LA_SER_SECURE  ? "LA_SER_SECURE"  :
       // "UNKNOWN_FLAG");
       //

        printf("Searching for: %s\n", name);
        //if (flag & LA_SER_ORIG) {
        //      printf("  Origin: DT_NEEDED or dlopen()\n");
        //}

        return (char*) name;
}


//cookie is the object at head of linked map of libraries
//flag should be set to one of the values LA_ACT_ADD, etc
void la_activity(uintptr_t *cookie, unsigned int flag) {
        printf("la_activity called: ");
//      switch (flag) {
//              case LA_ACT_ADD:
  //                    printf("LA_ACT_ADD\n");
    //                  break;
      //        case LA_ACT_DELETE:
        //              printf("LA_ACT_DELETE\n");
          //            break;

        //      case LA_ACT_CONSISTENT:
          //            printf("LA_ACT_CONSISTENT\n");
            //          break;
        //      default:
          //            printf("Unknown flag: %u\n", flag);
        //}
}

uintptr_t la_objopen(struct link_map *l, Lmid_t lmid, uintptr_t *cookie) {
        printf("la_objopen called for %s\n", l->l_name);
        *cookie = (uintptr_t)l; // store link_map as cookie
        return LA_FLG_BINDTO | LA_FLG_BINDFROM;
}



