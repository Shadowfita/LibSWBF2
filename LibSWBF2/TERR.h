#pragma once
#include "HeaderNames.h"
#include "FileWriter.h"
#include "FileReader.h"
#include "Logger.h"
#include "List.h"
#include "LibString.h"
#include "Vector2.h"

namespace LibSWBF2::Chunks::Terrain
{
	using Logging::Logger;
	using Logging::ELogType;
	using LibSWBF2::Types::List;
	using LibSWBF2::Types::Vector2;
	using LibSWBF2::Types::String;

	// TODO: Move to Types into a dedicated header file
	struct LIBSWBF2_EXP TextureLayer
	{
		String DiffuseName;
		String DetailName;
	};

	// TODO: Move to Types into a dedicated header file
	struct LIBSWBF2_EXP WaterLayer
	{
		float_t WaterHeight;
		Vector2 UVAnimationVelocity;
		Vector2 UVAnimationRepeat;
		uint8_t RGBA[4]; // TODO: Introduce new Color32 type and use here
		String TextureName;
	};

	struct LIBSWBF2_EXP TERR
	{
		TERR() = default;
		~TERR() = default;

		void WriteToStream(FileWriter& stream);
		void ReadFromStream(FileReader& stream);
		bool WriteToFile(const string& Path);
		bool ReadFromFile(const string& Path);

#pragma region Header
		uint32_t FileVersion;
		uint16_t TerrainExtents[4];
		float_t TileRange[16];
		uint8_t TextureLayerMapping[16];
		float_t MapHeightMultiplier;
		float_t GridScale;
		uint32_t MapSize;
		uint32_t TerrainOptions;
		TextureLayer TextureLayers[16];
		WaterLayer WaterLayers[16];
		String RoadDecalTextureNames[16];
#pragma endregion Header

#pragma region Blocks
		List<List<uint16_t>> Heights;
		List<List<uint8_t[4]>> Color;
		List<List<uint8_t[4]>> Color2;
		List<List<uint8_t[16]>> Texture;

		List<List<uint8_t[2]>> BlendHeights1;
		List<List<uint8_t[2]>> BlendHeights2;
#pragma endregion Blocks
	};
}