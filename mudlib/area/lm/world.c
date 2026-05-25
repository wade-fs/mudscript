// mudlib/area/lm/world.c
// Light Minecraft (LM) 世界核心 - 修復版

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/room.c";

#define WORLD_W 20
#define WORLD_H 20
#define SPAWN_X 10
#define SPAWN_Y 10
#define SAVE_FILE "/data/world/newbie_world"

// 方塊地圖：key = "x,y"，value = 方塊類型字串
mapping blocks;

// 玩家位置：key = player_id，value = ({ x, y })
mapping player_pos;

void save_world() {
    save_object(SAVE_FILE);
}

void init_default_world() {
    blocks = ([]);
    int x, y;
    
    for (x = 0; x < WORLD_W; x++) {
        for (y = 0; y < 2; y++) {
            m_add(blocks, sprintf("%d,%d", x, y), "stone");
        }
    }
    for (x = 0; x < WORLD_W; x++) {
        m_add(blocks, sprintf("%d,%d", x, 2), "grass");
    }
    m_add(blocks, "3,3", "wood");
    m_add(blocks, "3,4", "wood");
    m_add(blocks, "3,5", "leaves");
    m_add(blocks, "15,3", "wood");
    m_add(blocks, "15,4", "leaves");
    
    save_world();
}

int restore_world() {
    if (file_size(SAVE_FILE + ".o") <= 0) return 0;
    return restore_object(SAVE_FILE);
}

void broadcast_map(object target_player) {
    if (!target_player || !userp(target_player)) return;
    
    string pid = target_player->get_id();
    mapping online_players = ([]);
    object *here = all_inventory(this_object());
    
    foreach (object p in here) {
        if (userp(p)) {
            string oid = p->get_id();
            mixed pos = player_pos[oid];
            if (pos) {
                m_add(online_players, oid, pos);
            }
        }
    }
    
    mapping payload = ([
        "blocks"  : blocks,
        "players" : online_players,
        "self_id" : pid,
        "width"   : WORLD_W,
        "height"  : WORLD_H
    ]);
    
    tell_object(target_player, sprintf(
        "{\"ui\":\"mc_map\",\"data\":%s}\n",
        json_encode(payload)
    ));
}

void broadcast_map_all() {
    object *here = all_inventory(this_object());
    foreach (object p in here) {
        if (userp(p)) broadcast_map(p);
    }
}

void create() {
    ::create();
    set_short("輕量創世神世界");
    set_long("這是一片充滿可能性的土地，你可以在這裡挖掘與建造。\n輸入 'mc map' 開啟圖形界面。\n");
    
    player_pos = ([]);
    blocks = ([]);
    
    if (!restore_world()) {
        init_default_world();
    }
}

void init() {
    ::init();
    object me = this_player();
    if (userp(me)) {
        string pid = me->get_id();
        if (!player_pos[pid]) {
            m_add(player_pos, pid, ({ SPAWN_X, SPAWN_Y }));
        }
        call_out("broadcast_map", 1, me);
    }
}

int dig_block(object player, int x, int y) {
    if (x < 0 || x >= WORLD_W || y < 0 || y >= WORLD_H) return 1;
    string key = sprintf("%d,%d", x, y);
    if (!blocks[key]) return 2;
    
    string btype = blocks[key];
    m_delete(blocks, key);
    save_world();
    
    object item = clone_object("/area/lm/block_item");
    if (item) {
        item->set_block_type(btype);
        if (!item->move(player)) {
            move_object(item, this_object());
        }
    }
    
    broadcast_map_all();
    return 0;
}

int place_block(object player, int x, int y, string btype) {
    if (x < 0 || x >= WORLD_W || y < 0 || y >= WORLD_H) return 1;
    string key = sprintf("%d,%d", x, y);
    if (blocks[key]) return 2;
    
    object *inv = all_inventory(player);
    object found = 0;
    foreach (object item in inv) {
        // 🚀 關鍵：確保物件具備 query_block_type 函式
        if (function_exists("query_block_type", item)) {
            if (item->query_block_type() == btype) {
                found = item;
                break;
            }
        }
    }
    
    if (!found) {
        tell_object(player, YEL("【系統提示】你身上沒有 " + btype + " 方塊物品。\n"));
        return 3;
    }
    
    destruct(found);
    m_add(blocks, key, btype);
    save_world();
    broadcast_map_all();
    return 0;
}

int move_player(object player, int dx, int dy) {
    string pid = player->get_id();
    mixed pos = player_pos[pid];
    if (!pos) pos = ({ SPAWN_X, SPAWN_Y });
    
    int nx = pos[0] + dx;
    int ny = pos[1] + dy;
    
    if (nx < 0 || nx >= WORLD_W || ny < 0 || ny >= WORLD_H) return 1;
    
    string key = sprintf("%d,%d", nx, ny);
    if (blocks[key]) return 2;
    
    m_add(player_pos, pid, ({ nx, ny }));
    broadcast_map_all();
    return 0;
}

int *query_player_pos(object player) {
    return player_pos[player->get_id()];
}
