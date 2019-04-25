/************************************************************************/
/*				Used to obtain DX9_Endscene for hooking                 */
/************************************************************************/

#include "Device.h"

/** GetD3D9VTable
 * LoadLibrary for D3D9 to obtain DX9 Device
 */
DWORD GetD3D9VTable(DWORD Len) {
	DWORD base = 0;

	base = (DWORD) LoadLibrary("d3d9.dll");

	while(base++ < base + Len) {
		if((*(WORD*) (base + 0x00)) == 0x06C7
			&& (*(WORD*) (base + 0x06)) == 0x8689
			&& (*(WORD*) (base + 0x0C)) == 0x8689) {
			base += 2;
			break;
		}
	}

	return (base);
}


/** GetDX9EndsceneAddress
 *	Search DX9 VTable for the End-scene Address
 */
DWORD GetDX9EndsceneAddress(int VTableIndex) {
	PDWORD VTable;
	*(DWORD*) & VTable = *(DWORD*) GetD3D9VTable(0x128000); // 0x128000 is DX9_EndScene
	return VTable[VTableIndex];
}

