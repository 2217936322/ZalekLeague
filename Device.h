/************************************************************************/
/*				Used to obtain DX9_Endscene for hooking                 */
/************************************************************************/
#include <d3d9.h>
#pragma once

/** GetD3D9VTable
 * LoadLibrary for D3D9 to obtain DX9 Device
 */
DWORD GetD3D9VTable(DWORD Len);

/** GetDX9EndsceneAddress
 *	Search DX9 VTable for the End-scene Address
 */
DWORD GetDX9EndsceneAddress(int VTableIndex);