#ifndef INSTALL_INFO_TYPE_H
#define INSTALL_INFO_TYPE_H

struct installPath {
	char data_dir[SIZE_BIG + 1];
	char index[SIZE_BIG +1];
	char doc[SIZE_BIG +1];
	char log[SIZE_BIG +1];
};

struct installInfo {
	struct installPath path;
};

#endif