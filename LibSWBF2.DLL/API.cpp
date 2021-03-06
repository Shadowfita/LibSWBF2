#include "stdafx.h"
#include "API.h"

namespace LibSWBF2::API
{
#define CheckPtr(msh, ret) if (msh == nullptr) { LOG("[API] Given Pointer was NULL!", ELogType::Error); return ret; }

	// Logging //
	LIBSWBF2_API void LOG_SetCallbackMethod(const LogCallback Callback)
	{
		CheckPtr(Callback,)
		Logger::SetLogCallback(Callback);
	}

	LIBSWBF2_API void LOG_SetLogfileLevel(ELogType LogfileLevel)
	{
		Logger::SetLogfileLevel(LogfileLevel);
	}


	// MSH //
	LIBSWBF2_API MSH* MSH_Create()
	{
		return MSH::Create();
	}

	LIBSWBF2_API bool MSH_Delete(MSH* msh)
	{
		CheckPtr(msh, false)
		MSH::Destroy(msh);
		return true;
	}

	LIBSWBF2_API bool MSH_ReadFromFile(MSH* msh, const char* path)
	{
		CheckPtr(msh, false)
		return msh->ReadFromFile(string(path));
	}

	LIBSWBF2_API bool MSH_WriteToFile(MSH* msh, const char* path)
	{
		CheckPtr(msh, false)
		return msh->WriteToFile(string(path));
	}

	LIBSWBF2_API void STRP_CalcPolygons(STRP* strp)
	{
		CheckPtr(strp,)
		strp->CalcPolygons();
	}

	LIBSWBF2_API EModelPurpose MODL_GetEstimatedPurpose(MODL* modl)
	{
		CheckPtr(modl, EModelPurpose::Miscellaneous)
		return modl->GetEstimatedPurpose();
	}

	LIBSWBF2_API CRCChecksum CalcLowerCRC(const char* str)
	{
		CheckPtr(str, 0)
		return LibSWBF2::CRC::CalcLowerCRC(str);
	}
}