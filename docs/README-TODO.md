想要新建一個 mudlib/area/lm/ (註：lm = light minecraft), 
也就是讓 area/newbie 與 area/lm  同時存在。建立一個新命令，隨時傳送到 lm 的入口。
可以先獨立一個 html 頁面，處理 world 的 json map,
換掉前端，用 Canvas 或簡單 WebGL 渲染 2D 方塊地圖，後端傳 JSON 地圖資料到前端。
在 lm 世界，不再使用文字命令，希望全圖形界面操作

先用一個「大房間即全世界」的設計最簡單：
一個 LPC 物件 world.c，裡面存一個 mapping 代表整個地圖，所有玩家都在這個物件裡，各自有 x,y 座標。
底下只是一個想法，不代表要照著這樣子去修改，所以我沒有放到程式碼中。

```
/// world.c
#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/room";

#define WORLD_W 20
#define WORLD_H 20
#define SPAWN_X 10
#define SPAWN_Y 10
#define SAVE_FILE "/data/world/newbie_world"

// 方塊地圖：key = "x,y"，value = 方塊類型字串
mapping blocks;

// 玩家位置：key = player_id，value = ({ x, y })
mapping player_pos;

void create() {
    ::create();
    set_short("新手村世界");
    set_long("一片開放的土地，你可以在這裡挖掘與建造。\n");
    
    player_pos = ([]);
    
    // 嘗試從磁碟還原地圖
    if (!restore_world()) {
        init_default_world();
    }
}

// ── 地圖初始化 ──────────────────────────────

void init_default_world() {
    blocks = ([]);
    int x, y;
    
    // 底部兩層是石頭
    for (x = 0; x < WORLD_W; x++) {
        for (y = 0; y < 2; y++) {
            m_add(blocks, sprintf("%d,%d", x, y), "stone");
        }
    }
    // 地表是草地
    for (x = 0; x < WORLD_W; x++) {
        m_add(blocks, sprintf("%d,%d", x, 2), "grass");
    }
    // 幾棵樹（木頭方塊）
    m_add(blocks, "3,3", "wood");
    m_add(blocks, "3,4", "wood");
    m_add(blocks, "3,5", "leaves");
    m_add(blocks, "15,3", "wood");
    m_add(blocks, "15,4", "leaves");
    
    save_world();
}

int restore_world() {
    string data = read_file(SAVE_FILE + ".o");
    if (!data) return 0;
    // 用 restore_object 恢復 blocks 變數
    return restore_object(SAVE_FILE);
}

void save_world() {
    save_object(SAVE_FILE);
}

// ── 玩家進出 ────────────────────────────────

// 玩家進入世界時呼叫（在 user.c 的 setup() 裡改為 move_object 到這裡）
void player_enter(object player) {
    string pid = player->get_id();
    if (!player_pos[pid]) {
        m_add(player_pos, pid, ({ SPAWN_X, SPAWN_Y }));
    }
    broadcast_map(player);
}

void player_leave(object player) {
    string pid = player->get_id();
    m_delete(player_pos, pid);
}

// ── 核心：廣播地圖給一個或所有玩家 ──────────

void broadcast_map(object target_player) {
    string pid = target_player->get_id();
    int *pos = player_pos[pid];
    if (!pos) pos = ({ SPAWN_X, SPAWN_Y });
    
    // 收集所有在線玩家位置，一起送到前端
    mapping online_players = ([]);
    object *here = all_inventory(this_object());
    foreach (object p in here) {
        if (userp(p)) {
            string oid = p->get_id();
            int *opos = player_pos[oid];
            if (opos) {
                m_add(online_players, oid, opos);
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
    
    target_player->write(sprintf(
        "{\"ui\":\"map\",\"data\":%s}\n",
        json_encode(payload)
    ));
}

void broadcast_map_all() {
    object *here = all_inventory(this_object());
    foreach (object p in here) {
        if (userp(p)) broadcast_map(p);
    }
}

// ── 方塊操作 API（供指令呼叫）───────────────

// 回傳 0=成功, 1=超出邊界, 2=該位置沒有方塊
int dig_block(object player, int x, int y) {
    if (x < 0 || x >= WORLD_W || y < 0 || y >= WORLD_H) return 1;
    string key = sprintf("%d,%d", x, y);
    if (!blocks[key]) return 2;
    
    string btype = blocks[key];
    m_delete(blocks, key);
    save_world();
    
    // 給玩家一個對應的物品
    object item = clone_object("/d/newbie/obj/block_item.c");
    item->set_block_type(btype);
    move_object(item, player);
    
    broadcast_map_all();
    return 0;
}

// 回傳 0=成功, 1=超出邊界, 2=該位置已有方塊, 3=背包沒有該方塊
int place_block(object player, int x, int y, string btype) {
    if (x < 0 || x >= WORLD_W || y < 0 || y >= WORLD_H) return 1;
    string key = sprintf("%d,%d", x, y);
    if (blocks[key]) return 2;
    
    // 確認玩家背包有這種方塊物品
    object found = 0;
    object *inv = all_inventory(player);
    foreach (object item in inv) {
        if (objectp(item) && item->query_block_type() == btype) {
            found = item;
            break;
        }
    }
    if (!found) return 3;
    
    destruct(found);
    m_add(blocks, key, btype);
    save_world();
    broadcast_map_all();
    return 0;
}

// 移動玩家座標
int move_player(object player, int dx, int dy) {
    string pid = player->get_id();
    int *pos = player_pos[pid];
    if (!pos) pos = ({ SPAWN_X, SPAWN_Y });
    
    int nx = pos[0] + dx;
    int ny = pos[1] + dy;
    
    if (nx < 0 || nx >= WORLD_W || ny < 0 || ny >= WORLD_H) return 1;
    string key = sprintf("%d,%d", nx, ny);
    if (blocks[key]) return 2;  // 被方塊擋住
    
    m_add(player_pos, pid, ({ nx, ny }));
    broadcast_map_all();
    return 0;
}

// 給指令用的查詢函式
int *query_player_pos(object player) {
    return player_pos[player->get_id()];
}

string query_block(int x, int y) {
    return blocks[sprintf("%d,%d", x, y)];
}
```

'''
/// block_item.c

inherit "/std/object";

string block_type;

void create() {
    ::create();
}

void set_block_type(string t) {
    block_type = t;
    set_short(t + " 方塊");
    set_long("一塊 " + t + "，可以放置到世界中。\n");
    set_id(({ t, t + "_block", "block" }));
}

string query_block_type() { return block_type; }
'''

```
/// cmd_mc.c
// 用法：
//   mc move n/s/e/w
//   mc dig <x> <y>
//   mc place <x> <y> <方塊類型>
//   mc map   （重新要求地圖）

#include "/include/config.h"
#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    object world = find_object("/d/newbie/world.c");
    if (!world) world = load_object("/d/newbie/world.c");
    
    if (!arg || arg == "") {
        write("用法：mc move n|s|e|w / mc dig x y / mc place x y 類型 / mc map\n");
        return 1;
    }
    
    string *parts = explode(trim(arg), " ");
    string subcmd = parts[0];
    
    // ── mc map ──
    if (subcmd == "map") {
        world->broadcast_map(me);
        return 1;
    }
    
    // ── mc move ──
    if (subcmd == "move") {
        if (sizeof(parts) < 2) {
            write("用法：mc move n|s|e|w\n"); return 1;
        }
        int dx = 0, dy = 0;
        switch(parts[1]) {
            case "n": case "north": dy =  1; break;
            case "s": case "south": dy = -1; break;
            case "e": case "east":  dx =  1; break;
            case "w": case "west":  dx = -1; break;
            default:
                write("方向請用 n/s/e/w\n"); return 1;
        }
        int result = world->move_player(me, dx, dy);
        switch(result) {
            case 0: break;  // 地圖已廣播，不需額外訊息
            case 1: write("已到達世界邊界。\n"); break;
            case 2: write("前方有方塊擋路！\n"); break;
        }
        return 1;
    }
    
    // ── mc dig ──
    if (subcmd == "dig") {
        if (sizeof(parts) < 3) {
            write("用法：mc dig <x> <y>\n"); return 1;
        }
        int x = to_int(parts[1]);
        int y = to_int(parts[2]);
        int result = world->dig_block(me, x, y);
        switch(result) {
            case 0: write(GREEN("挖掘成功！") + "\n"); break;
            case 1: write("座標超出世界範圍。\n"); break;
            case 2: write("那個位置沒有方塊。\n"); break;
        }
        return 1;
    }
    
    // ── mc place ──
    if (subcmd == "place") {
        if (sizeof(parts) < 4) {
            write("用法：mc place <x> <y> <類型>\n"); return 1;
        }
        int x = to_int(parts[1]);
        int y = to_int(parts[2]);
        string btype = parts[3];
        int result = world->place_block(me, x, y, btype);
        switch(result) {
            case 0: write(GREEN("放置成功！") + "\n"); break;
            case 1: write("座標超出世界範圍。\n"); break;
            case 2: write("那個位置已有方塊。\n"); break;
            case 3: write("背包裡沒有 " + btype + " 方塊。\n"); break;
        }
        return 1;
    }
    
    write("未知子指令。用法：mc move|dig|place|map\n");
    return 1;
}
```


