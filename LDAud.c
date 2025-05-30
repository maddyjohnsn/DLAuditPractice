#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#define __USE_GNU
#include <link.h>
#include <dlfcn.h>

//called (all of LDAudit) before LDPreload it appears
unsigned int la_version(unsigned int version){
        printf( "%s:%d:%s version = %i\n", __FILE__, __LINE__, __func__, version );
        printf("\n");
	return version;

}

//called after last activity call
//happens right before main application runs
void la_preinit(uintptr_t *cookie) {
        printf("la_preinit called with cookie: %p\n", cookie);
}

//called after activity
//name is search path
//cookie is the object that started the search
//flag should again be set to a value
char *la_objsearch( const char *name, uintptr_t* cookie, unsigned int flag ){
    printf( "%s:%d:%s name=%s, cookie=%p, flags=%s\n",
        __FILE__, __LINE__, __func__,
        name,
        cookie,
        flag & LA_SER_ORIG    ? "LA_SER_ORIG"    :
        flag & LA_SER_LIBPATH ? "LA_SER_LIBPATH" :
        flag & LA_SER_RUNPATH ? "LA_SER_RUNPATH" :
        flag & LA_SER_CONFIG  ? "LA_SER_CONFIG"  :
        flag & LA_SER_DEFAULT ? "LA_SER_DEFAULT" :
        flag & LA_SER_SECURE  ? "LA_SER_SECURE"  :
        "UNKNOWN_FLAG");
       
	printf("\n");
        return (char*) name;
}

//called second
//and then again after objsearch
//in this current code nothing is ever being deleted
//runs multiple times because it is just stating that activity has occurred. 
//cookie is the object at head of linked map of libraries
//flag should be set to one of the values LA_ACT_ADD, etc
void la_activity(uintptr_t *cookie, unsigned int flag) {
        printf("la_activity called: ");
      switch (flag) {
              case LA_ACT_ADD:
                      printf("LA_ACT_ADD\n");
                      break;
              case LA_ACT_DELETE:
                      printf("LA_ACT_DELETE\n");
                      break;

              case LA_ACT_CONSISTENT:
                      printf("LA_ACT_CONSISTENT\n");
                      break;
              default:
                      printf("Unknown flag: %u\n", flag);
        }
      printf("\n");
}

//called first
unsigned int la_objopen(struct link_map *l, Lmid_t lmid, uintptr_t *cookie) {
        printf("la_objopen called for %s\n", l->l_name);
        *cookie = (uintptr_t)l; // store link_map as cookie
        printf("\n");
	return LA_FLG_BINDTO | LA_FLG_BINDFROM;
}


//object has not been unloaded, but happens are finalization of code for executed object
unsigned int la_objclose(uintptr_t *cookie){
	printf("Object Closing\n");
	printf("\n");
}


//Called after obj_open before activity
//Symname is name of symbol and symbol points to info about the symbol being bound
//ndx- index of the symbol in symbol table of shared object
//refcook- identifies shared object
//defcook- shared object that defines the referenced symbol- this identifier is given to objopen too
uintptr_t la_symbind64(Elf64_Sym *sym, unsigned int ndx, uintptr_t *refcook, uintptr_t *defcook, unsigned int *flags, const char *symname){
	printf("la_symbind64: Symbol name: %s\n", symname);	
	return sym->st_value;
}

//called before a PLT control is called
//Doesn't seem to be running in this implementation
Elf64_Addr la_i86_gnu_pltenter(Elf32_Sym *sym, unsigned int ndx,uintptr_t *refcook, uintptr_t *defcook, La_x32_regs *regs, unsigned int *flags,const char *symname, long int *framesizep){
	printf("Entering PLT for function: %s\n", symname); 
	return sym->st_value;

}


//called when a PLT entry returns 
unsigned int la_i86_gnu_pltexit(Elf32_Sym *sym, unsigned int ndx,uintptr_t *refcook, uintptr_t *defcook, const La_x32_regs *inregs, La_x32_retval *outregs, const char *symname){
	
	return 0;
}
