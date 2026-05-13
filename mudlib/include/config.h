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
#define WPN_SPEAR       "spear"
#define WPN_HAMMER      "hammer"
#define WPN_WAND        "wand"

// ── 武器飛行/射程屬性 ───────────────────────────────────
#define RANGE_MELEE     "melee"    // 近戰（無射程）
#define RANGE_THROWN    "thrown"   // 投擲武器（可飛行一次）
#define RANGE_RANGED    "ranged"   // 遠程武器（弓、弩）
#define RANGE_MAGIC     "magic"    // 魔法射程（法杖、魔杖）

// ── 防具部位 ────────────────────────────────────────────
#define SLOT_HEAD       "head"
#define SLOT_BODY       "body"
#define SLOT_HANDS      "hands"
#define SLOT_FEET       "feet"
#define SLOT_WEAPON     "weapon"
#define SLOT_SHIELD     "shield"
#define SLOT_LEGS       "legs"     // 腿甲
#define SLOT_SHOULDER   "shoulder" // 肩甲
#define SLOT_WAIST      "waist"    // 腰帶
#define SLOT_NECK       "neck"     // 頸環/項鍊
#define SLOT_RING       "ring"     // 戒指（可配戴雙手）
#define SLOT_BACK       "back"     // 背部（斗篷/背甲）
#define SLOT_OFFHAND    "offhand"  // 副手（匕首/盾牌替代）

// ── NPC 棲息地類型 ──────────────────────────────────────
#define HABITAT_LAND    "land"     // 陸地（預設）
#define HABITAT_WATER   "water"    // 水中
#define HABITAT_UNDERGROUND "underground" // 地下/土裡
#define HABITAT_SKY     "sky"      // 天空
#define HABITAT_CAVE    "cave"     // 洞穴

// ── NPC 行為模式 ────────────────────────────────────────
#define BEHAV_PASSIVE   "passive"  // 被動（不主動攻擊）
#define BEHAV_AGGRESSIVE "aggressive" // 主動攻擊
#define BEHAV_GUARD     "guard"    // 守衛（保護特定範圍）
#define BEHAV_PATROL    "patrol"   // 巡邏
#define BEHAV_FLEE      "flee"     // 低血量逃跑
#define BEHAV_WANDER    "wander"   // 隨機移動

// ── 經驗值與等級 ────────────────────────────────────────
#define MAX_LEVEL       50
#define BASE_EXP_PER_LV 1000

// ── 路徑常數 ────────────────────────────────────────────
#define START_ROOM      "/area/newbie/room_4_4.c"
#define MASTER_FILE     "/master.c"
#define ISSUE_FILE      "/etc/issue"
