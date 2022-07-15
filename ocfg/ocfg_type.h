#ifndef OCFG_TYPE_H
#define OCFG_TYPE_H

#ifndef SIZEDEF_H
#define SIZEDEF_H

#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif

struct ody_path{
	char data_dir[SIZE_BIG +1];
	char data_file[SIZE_BIG +1];
	char doc[SIZE_BIG +1];
	char log[SIZE_BIG +1];
};

struct odyconf {
	struct ody_path path;
	void *headptr;
};
#ifndef ODYCONF_TYPE
#define ODYCONF_TYPE
typedef struct odyconf Odyconf;
#endif

#endif