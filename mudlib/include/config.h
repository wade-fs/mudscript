// include/config.h - 全域常數定義

// ── 屬性常數 ────────────────────────────────────────────
#define STAT_STR    "str"
#define STAT_DEX    "dex"
#define STAT_INT    "int"
#define STAT_CON    "con"
#define STAT_WIS    "wis"
#define STAT_CHA    "cha"

// ── 戰鬥相關 ────────────────────────────────────────────
#define MAX_HP_PER_CON  10
#define BASE_ATTACK     10
#define BASE_DEFENCE    5
#define HIT_RATE_BASE   75
#define CRIT_RATE_BASE  5
#define CRIT_MULTIPLIER 2

// ── 物品種類 ────────────────────────────────────────────
#define ITEM_WEAPON     "weapon"
#define ITEM_ARMOUR     "armour"
#define ITEM_CONSUMABLE "consumable"
#define ITEM_MISC       "misc"

// ── 武器類型 ────────────────────────────────────────────
#define WPN_SWORD       "sword"
#define WPN_AXE         "axe"
#define WPN_STAFF       "staff"
#define WPN_BOW         "bow"
#define WPN_DAGGER      "dagger"

// ── 防具部位 ────────────────────────────────────────────
#define SLOT_HEAD       "head"
#define SLOT_BODY       "body"
#define SLOT_HANDS      "hands"
#define SLOT_FEET       "feet"
#define SLOT_WEAPON     "weapon"
#define SLOT_SHIELD     "shield"

// ── 經驗值與等級 ────────────────────────────────────────
#define MAX_LEVEL       50
#define BASE_EXP_PER_LV 1000

// ── 路徑常數 ────────────────────────────────────────────
#define START_ROOM      "/area/newbie/room_4_4.c"
#define MASTER_FILE     "/master.c"
#define ISSUE_FILE      "/etc/issue"
