// include/globals.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 全域巨集定義

#ifndef GLOBALS_H
#define GLOBALS_H

#define MUD_NAME        "遺忘的世界"
#define MUD_NAME_EN     "THE FORGOTTEN SPACE"
#define MUD_VERSION     "v0.1.0"

#include "/include/background.h"

// ── 空間目錄常數 ─────────────────────────────────────────
#define WORLD_DIR       "/world/"
#define D_DIR           "/d/"
#define VILLAGE_DIR     "/d/village/"
#define CITY_DIR        "/d/city/"
#define MOUNTAIN_DIR    "/d/mountain/"
#define REALM_DIR       "/d/realm/"
#define SECRET_DIR      "/d/secret/"
#define NARRATIVE_DIR   "/narrative/"

#include "/include/world_event.h"

// ── 核心守護進程 (System Daemons) ───────────────────────
#define QUEST_D         "/daemon/questd.c"
#define QUEST_ENGINE_D  "/daemon/quest_engine_d.c"
#define MYSTERY_D       "/daemon/mysteryd.c"
#define CAREER_D        "/daemon/career_d.c"
#define WORLD_STATE_D   "/daemon/world_state_d.c"
#define EVENT_MANAGER_D "/daemon/event_manager.c"
#define SKILL_D         "/secure/skill_d.c"
#define COMBAT_D        "/secure/combat_d.c"

// ── 先天核心六維屬性 (Primary Attributes) ────────────────
#define STAT_STR        "str"     // 臂力（力之本）
#define STAT_CON        "con"     // 根骨（力之體）
#define STAT_INT        "int"     // 悟性（法之理）
#define STAT_SPI        "spi"     // 靈性（法之神）
#define STAT_DEX        "dex"     // 靈巧（物之手）
#define STAT_PER        "per"     // 感知（物之心）

// ── 動態狀態三柱 (Secondary Vitals) ─────────────────────
#define VITAL_KEE       "kee"     // 氣血池 (HP)  = str + con
#define VITAL_SEN       "sen"     // 神識池 (SAN) = spi + int
#define VITAL_SP        "sp"      // 精力池 (ENG) = dex + per

// ── 終極隱藏屬性 (Meta Attributes / Tier 4 鑰匙) ────────
#define STAT_KAR        "kar"     // 福緣（外在機緣、拾遺、避劫）
#define STAT_FATE       "fate"    // 天命（史前共鳴、破除認知盲區）

// ── 標準物件基底類別路徑 ────────────────────────────────
#define USER_OB         "/std/user.c"
#define NPC_OB          "/std/npc.c"
#define ROOM_OB         "/std/room.c"
#define RUIN_ROOM_OB    "/std/room/ruin.c"
#define WEAPON_OB       "/std/weapon.c"
#define ARMOUR_OB       "/std/armour.c"
#define ITEM_OB         "/std/item.c"
#define RELIC_OB        "/std/object/relic.c"

#endif // GLOBALS_H
