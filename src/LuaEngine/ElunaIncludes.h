/*
* Copyright (C) 2010 - 2015 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNA_INCLUDES_H
#define _ELUNA_INCLUDES_H

// Required
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Chat.h"
#include "Channel.h"
#include "DBCStores.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "Mail.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "Pet.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#include "Config.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "WeatherMgr.h"
#include "Battleground.h"
#include "revision.h"

#include "Vehicle.h"
#include "ArenaTeam.h"

typedef Opcodes                 OpcodesList;

/*
 * Note: if you add or change a CORE_NAME #define,
 *   please update LuaGlobalFunctions::GetCoreName docstring.
 */
#define CORE_NAME               "TrinityCore"
#define CORE_VERSION            _DATE
#define eWorld                  (sWorld)
#define eMapMgr                 (sMapMgr)
#define eConfigMgr              (sConfigMgr)
#define eGuildMgr               (sGuildMgr)
#define eObjectMgr              (sObjectMgr)
#define eAccountMgr             (sAccountMgr)
#define eAuctionMgr             (sAuctionMgr)
#define eObjectAccessor         (sObjectAccessor)
#define REGEN_TIME_FULL
typedef ThreatContainer::StorageType ThreatList;

#define NUM_MSG_TYPES           NUM_OPCODE_HANDLERS

#endif // _ELUNA_INCLUDES_H
