#include "Objects.h"

Champion* Me() {
	return (Champion*)* (DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
}
