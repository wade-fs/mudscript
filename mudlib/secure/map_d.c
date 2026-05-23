// /secure/map_d.c
// 地圖守護進程 (Map Daemon)
// 負責繪製 ASCII 小地圖並處理探索邏輯

#include "/include/ansi.h"

inherit "/std/object";

void create() {
    ::create();
}

// 根據坐標取得房間路徑
string get_room_file(int x, int y, int z) {
    // 地面區域
    if (z == 0) {
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
            return sprintf("/area/newbie/room_%d_%d.c", x, y);
        if (x == 10 && y == 0)
            return "/area/water/lake_0_0_0.c";
    }
    // 地下區域 (z = -1)
    if (z == -1) {
        if (x == 0 && y == 0) return "/area/cave/cave_0_0_minus1.c";
        if (x == 0 && y == 1) return "/area/cave/cave_0_1_minus1.c";
    }
    // 高塔區域 (z > 0)
    if (z == 0 && x == 0 && y == 5) return "/area/tower/tower_1f.c";
    if (z == 1 && x == 0 && y == 5) return "/area/tower/tower_2f.c";
    
    return 0;
}

string draw_map(object me, int range) {
    if (!me) return "";
    
    mixed coords = me->query_coordinate();
    if (!coords) return select_lang(([
        "en": "You cannot draw a map from your current location.\n",
        "zh-TW": "你目前所在的位置無法繪製地圖。\n",
        "zh-CN": "你目前所在的位置无法绘制地图。\n"
    ]));
    
    int cur_x = coords[0];
    int cur_y = coords[1];
    int cur_z = coords[2];
    
    mapping explored = me->query_explored_rooms();
    string title = select_lang(([
        "en": "=== Area Map (",
        "zh-TW": "=== 區域地圖 (",
        "zh-CN": "=== 区域地图 ("
    ]));
    string map_header = title + cur_x + "," + cur_y + ") ===";
    string out = "\n" + HIW(map_header) + "\n";
    
    // 從北到南 (y 遞減)
    for (int y = cur_y + range; y >= cur_y - range; y--) {
        string line = "  ";
        // 從西到東 (x 遞增)
        for (int x = cur_x - range; x <= cur_x + range; x++) {
            if (x == cur_x && y == cur_y) {
                line += HIY("[★]"); // 當前位置
                continue;
            }
            
            string r_file = get_room_file(x, y, cur_z);
            if (!r_file) {
                line += "   "; // 邊界外
                continue;
            }
            
            if (explored && explored[r_file]) {
                // 已探索，顯示符號
                object r_ob = find_object(r_file);
                if (!r_ob) r_ob = load_object(r_file);
                
                if (r_ob->query_no_combat()) line += HIC("[S]"); // 安全區
                else if (r_ob->query_has_forge()) line += HIY("[F]"); // 鐵匠
                else if (r_ob->query_has_lab()) line += HIG("[L]"); // 藥劑
                else line += WHT("[#]"); // 普通房間
            } else {
                line += " ? "; // 未探索 (Fog of War)
            }
        }
        out += line + "\n";
    }
    
    string legend = select_lang(([
        "en": "Legend: " + HIY("[★] You  ") + WHT("[#] Room  ") + HIC("[S] Safe  ") + HIY("[F] Forge  ") + HIG("[L] Lab\n"),
        "zh-TW": "圖例: " + HIY("[★] 你  ") + WHT("[#] 房間  ") + HIC("[S] 安全  ") + HIY("[F] 鐵匠  ") + HIG("[L] 藥劑\n"),
        "zh-CN": "图例: " + HIY("[★] 你  ") + WHT("[#] 房间  ") + HIC("[S] 安全  ") + HIY("[F] 铁匠  ") + HIG("[L] 药剂\n")
    ]));

    out += HIW("======================") + "\n";
    out += legend;
    return out;
}

// 提供給 Web UI 的 JSON 資料
mapping get_map_json(object me, int range) {
    mapping res = ([ "center_name": "", "grid": ({}) ]);
    if (!me) return res;
    
    mixed coords = me->query_coordinate();
    if (!coords) return res;
    
    int cur_x = coords[0];
    int cur_y = coords[1];
    int cur_z = coords[2];
    
    object env = environment(me);
    if (env) {
        res["center_name"] = env->query_short();
    }
    
    mapping explored = me->query_explored_rooms();
    mixed grid = ({});
    
    // 從北到南 (y 遞減)
    for (int y = cur_y + range; y >= cur_y - range; y--) {
        mixed row = ({});
        // 從西到東 (x 遞增)
        for (int x = cur_x - range; x <= cur_x + range; x++) {
            if (x == cur_x && y == cur_y) {
                row += ({ "player" });
                continue;
            }
            
            string r_file = get_room_file(x, y, cur_z);
            if (!r_file) {
                row += ({ "void" });
                continue;
            }
            
            if (explored && explored[r_file]) {
                object r_ob = find_object(r_file);
                if (!r_ob) r_ob = load_object(r_file);
                
                if (r_ob->query_no_combat()) row += ({ "safe" });
                else if (r_ob->query_has_forge()) row += ({ "forge" });
                else if (r_ob->query_has_lab()) row += ({ "lab" });
                else row += ({ "room" });
            } else {
                row += ({ "fog" });
            }
        }
        grid += ({ row });
    }
    
    res["grid"] = grid;
    return res;
}
