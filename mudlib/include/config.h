// include/config.h - 全域常數定義

// ── 屬性常數 ────────────────────────────────────────────
#define STAT_STR    "str"      // 力量
#define STAT_DEX    "dex"      // 敏捷
#define STAT_INT    "int"      // 智力
#define STAT_CON    "con"      // 體魄
#define STAT_WIS    "wis"      // 智慧
#define STAT_CHA    "cha"      // 魅力

// ── 戰鬥相關 ────────────────────────────────────────────
#define MAX_HP_PER_CON  10     // 每點體魄提供的最大 HP
#define BASE_ATTACK     10     // 基礎攻擊力
#define BASE_DEFENCE    5      // 基礎防禦力
#define HIT_RATE_BASE   75     // 基礎命中率 (%)
#define CRIT_RATE_BASE  5      // 基礎暴擊率 (%)
#define CRIT_MULTIPLIER 2      // 暴擊傷害倍率

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
#define BASE_EXP_PER_LV 1000   // 每級所需基礎經驗值 (會依等級倍增)

// ── 路徑常數 ────────────────────────────────────────────
#define START_ROOM      "/area/newbie/room_2_2.c"
#define MASTER_FILE     "/master.c"
