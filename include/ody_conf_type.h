#ifndef ODY_CONF_TYPE_H
#define ODY_CONF_TYPE_H

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif

struct odyPath{
	char data[SIZE_BIG +1];
	char entry[SIZE_BIG +1];
	char doc[SIZE_BIG +1];
	char log[SIZE_BIG +1];
};

struct odyConf {
	struct odyPath path;
};

#endif