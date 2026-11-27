#ifndef CONFIG_H
#define CONFIG_H

// ── 預設核心常數 (各世界可在自己的 include/config.h 覆寫) ──
#ifndef START_ROOM
#define START_ROOM      "/rooms/start"
#endif

#ifndef MASTER_FILE
#define MASTER_FILE     "/master.c"
#endif

#ifndef ISSUE_FILE
#define ISSUE_FILE      "/etc/issue"
#endif

// ── 基礎戰鬥與升級常數 ────────────────────────────────────
#define BASE_ATTACK     10
#define BASE_DEFENCE    5
#define MAX_LEVEL       50
#define BASE_EXP_PER_LV 1000

// ── 物品種類 ──────────────────────────────────────────────
#define ITEM_WEAPON     "weapon"
#define ITEM_ARMOUR     "armour"
#define ITEM_CONSUMABLE "consumable"
#define ITEM_MISC       "misc"

// ── 武器類型與射程 ────────────────────────────────────────
#define WPN_SWORD       "sword"
#define WPN_AXE         "axe"
#define WPN_STAFF       "staff"
#define WPN_BOW         "bow"
#define WPN_DAGGER      "dagger"
#define WPN_SPEAR       "spear"
#define RANGE_MELEE     "melee"
#define RANGE_THROWN    "thrown"
#define RANGE_RANGED    "ranged"
#define RANGE_MAGIC     "magic"

// ── 防具部位 ──────────────────────────────────────────────
#define SLOT_HEAD       "head"
#define SLOT_BODY       "body"
#define SLOT_HANDS      "hands"
#define SLOT_FEET       "feet"
#define SLOT_WEAPON     "weapon"
#define SLOT_SHIELD     "shield"
#define SLOT_LEGS       "legs"
#define SLOT_SHOULDER   "shoulder"
#define SLOT_WAIST      "waist"
#define SLOT_NECK       "neck"
#define SLOT_RING       "ring"
#define SLOT_BACK       "back"
#define SLOT_OFFHAND    "offhand"

// ── 基礎幣制常數 ──────────────────────────────────────────
#define COIN_COPPER     1
#define COIN_SILVER     100
#define COIN_GOLD       10000

// ── 跨服緩存目錄 ──────────────────────────────────────────
#define FS_CACHE_DIR    "/data/fs_cache"

#include "/include/globals.h"

#endif
