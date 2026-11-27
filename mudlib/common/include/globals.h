#ifndef GLOBALS_H
#define GLOBALS_H

// ── 共用核心守護進程路徑 ──────────────────────────────────
#define SYSTEM_D        "/secure/system_d.c"
#define LANGUAGE_D      "/secure/language_d.c"
#define COMMAND_D       "/secure/command_d.c"
#define SOCIAL_D        "/secure/social_d.c"
#define CHANNEL_D       "/secure/channel_d.c"
#define NATURE_D        "/secure/nature_d.c"
#define QUEST_D         "/secure/quest_d.c"

#define SCHEMA_D        "/daemon/schema_d.c"
#define ROOM_FACTORY_D  "/daemon/room_factory_d.c"
#define NPC_FACTORY_D   "/daemon/npc_factory_d.c"
#define ITEM_FACTORY_D  "/daemon/item_factory_d.c"
#define QUEST_ENGINE_D  "/daemon/quest_engine_d.c"
#define WORLD_STATE_D   "/daemon/world_state_d.c"
#define PHASE_D         "/daemon/phase_d.c"
#define UI_BRIDGE_D     "/daemon/ui_bridge_d.c"

// ── 標準物件基底類別路徑 ──────────────────────────────────
#define USER_OB         "/std/user.c"
#define NPC_OB          "/std/npc.c"
#define ROOM_OB         "/std/room.c"
#define ITEM_OB         "/std/item.c"
#define WEAPON_OB       "/std/weapon.c"
#define ARMOUR_OB       "/std/armour.c"

#endif
