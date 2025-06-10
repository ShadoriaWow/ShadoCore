/*
* Copyright (C) 2010 - 2015 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNA_UTIL_H
#define _ELUNA_UTIL_H

#include <unordered_map>
#include <unordered_set>
#include "Common.h"
#include "SharedDefines.h"
#include "ObjectDefines.h"
#include "QueryResult.h"
#include "Object.h"

// Some dummy includes containing BOOST_VERSION:
// ObjectAccessor.h Config.h Log.h

typedef QueryResult ElunaQuery;
#define ELUNA_LOG_INFO(...)     TC_LOG_INFO("eluna", __VA_ARGS__);
#define ELUNA_LOG_ERROR(...)    TC_LOG_ERROR("eluna", __VA_ARGS__);
#define ELUNA_LOG_DEBUG(...)    TC_LOG_DEBUG("eluna", __VA_ARGS__);
#define GET_GUID                GetGUID

class Unit;
class WorldObject;

namespace ElunaUtil
{
    uint32 GetCurrTime();

    uint32 GetTimeDiff(uint32 oldMSTime);

    class ObjectGUIDCheck
    {
    public:
        ObjectGUIDCheck(ObjectGuid guid);
        bool operator()(WorldObject* object);

        ObjectGuid _guid;
    };

    // Binary predicate to sort WorldObjects based on the distance to a reference WorldObject
    class ObjectDistanceOrderPred
    {
    public:
        ObjectDistanceOrderPred(WorldObject const* pRefObj, bool ascending = true);
        bool operator()(WorldObject const* pLeft, WorldObject const* pRight) const;

        WorldObject const* m_refObj;
        const bool m_ascending;
    };

    // Doesn't get self
    class WorldObjectInRangeCheck
    {
    public:
        WorldObjectInRangeCheck(bool nearest, WorldObject const* obj, float range,
            uint16 typeMask = 0, uint32 entry = 0, uint32 hostile = 0);
        WorldObject const& GetFocusObject() const;
        bool operator()(WorldObject* u);

        WorldObject const* i_obj;
        uint32 i_hostile;
        uint32 i_entry;
        float i_range;
        uint16 i_typeMask;
        bool i_nearest;
    };

    /*
     * Usage:
     * Inherit this class, then when needing lock, use
     * ReadGuard guard(GetLock());
     * or
     * WriteGuard guard(GetLock());
     *
     * The lock is automatically released at end of scope
     */
    class RWLockable
    {
    public:

        typedef ACE_RW_Thread_Mutex LockType;
        typedef ACE_Read_Guard<LockType> ReadGuard;
        typedef ACE_Write_Guard<LockType> WriteGuard;

        LockType& GetLock() { return _lock; }

    private:
        LockType _lock;
    };
};

#endif
