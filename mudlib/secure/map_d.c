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
    
    object me_env = environment(me);
    mixed coords = me_env ? me_env->query_coordinate() : 0;
    if (!coords) return select_lang(([
        "en": "You cannot draw a map from your current location.\n",
        "zh-TW": "你目前所在的位置無法繪製地圖。\n",
        "zh-CN": "你目前所在的位置无法绘制地图。\n"
    ]));
    
    int cur_x = coords[0];
    int cur_y = coords[1];
    int cur_z = coords[2];
    
    mapping explored = me->query_explored_rooms();
    string room_name = me_env->query_short();
    
    string title = select_lang(([
        "en": "=== Minimap: " + room_name + " (",
        "zh-TW": "=== 區域地圖：" + room_name + " (",
        "zh-CN": "=== 区域地图：" + room_name + " ("
    ]));
    string map_header = title + cur_x + "," + cur_y + "," + cur_z + ") ===";
    string out = "\n" + BOLD_WHT(map_header) + "\n";
    
    // 從北到南 (y 遞減)
    for (int y = cur_y + range; y >= cur_y - range; y--) {
        string room_line = "  ";
        string path_line = "  ";
        
        // 從西到東 (x 遞增)
        for (int x = cur_x - range; x <= cur_x + range; x++) {
            string r_file = get_room_file(x, y, cur_z);
            
            // 判斷是否為「可見」房間
            int visible = 0;
            if (x == cur_x && y == cur_y) visible = 1;
            else if (r_file && explored && explored[r_file]) visible = 1;
            else if (r_file) {
                // 檢查周圍是否有已探索房間且有通路連向這裡
                string *dirs = ({ "north", "south", "east", "west" });
                int *dx = ({ 0, 0, 1, -1 });
                int *dy = ({ 1, -1, 0, 0 });
                string *opp = ({ "south", "north", "west", "east" });
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    string neighbor_file = get_room_file(nx, ny, cur_z);
                    
                    if (neighbor_file && ((nx == cur_x && ny == cur_y) || (explored && explored[neighbor_file]))) {
                        object n_ob = find_object(neighbor_file);
                        if (!n_ob) n_ob = load_object(neighbor_file);
                        mapping n_exits = n_ob->query_exits();
                        if (mapp(n_exits) && n_exits[opp[i]] && strsrch(n_exits[opp[i]], r_file) != -1) {
                            visible = 1;
                            break;
                        }
                    }
                }
            }

            // 1. 繪製房間符號
            if (x == cur_x && y == cur_y) {
                room_line += HIY(" * "); // 當前位置
            } else if (!visible) {
                room_line += "   "; // 不可見則留白
            } else if (explored && explored[r_file]) {
                object r_ob = find_object(r_file);
                if (!r_ob) r_ob = load_object(r_file);

                if (r_ob->query_has_bank()) room_line += HIW(" B ");
                else if (r_ob->query_has_shop()) room_line += HIY(" A ");
                else if (r_ob->query_has_tavern()) room_line += MAG(" T ");
                else if (r_ob->query_has_guild()) room_line += HIB(" G ");
                else if (r_ob->query_has_forge()) room_line += YEL(" F ");
                else if (r_ob->query_has_lab()) room_line += HIG(" L ");
                else if (r_ob->query_no_combat()) room_line += HIC(" S ");
                else room_line += WHT(" # ");
            } else {
                room_line += " ? "; // 通路連接但未曾進入
            }
            
            // 2. 繪製水平連接 (向東)
            if (x < cur_x + range) {
                string next_file = get_room_file(x+1, y, cur_z);
                if (r_file && next_file) {
                    object r1 = find_object(r_file);
                    if (!r1) r1 = load_object(r_file);
                    mapping e1 = r1->query_exits();
                    int connected = 0;
                    if (mapp(e1) && e1["east"]) {
                        string target = e1["east"];
                        if (strsrch(target, next_file) != -1) connected = 1;
                    }
                    
                    // 只有當其中一端是可見時才繪製連線
                    int next_visible = 0;
                    if ((x+1 == cur_x && y == cur_y) || (explored && explored[next_file])) next_visible = 1;
                    
                    if (connected && (visible || next_visible)) room_line += "-"; else room_line += " ";
                } else {
                    room_line += " ";
                }
            }
            
            // 3. 繪製垂直連接 (向南)
            if (y > cur_y - range) {
                string south_file = get_room_file(x, y-1, cur_z);
                int south_visible = 0;
                if (south_file) {
                    if ((x == cur_x && y-1 == cur_y) || (explored && explored[south_file])) south_visible = 1;
                }

                if (r_file && south_file) {
                    object r1 = find_object(r_file);
                    if (!r1) r1 = load_object(r_file);
                    mapping e1 = r1->query_exits();
                    int connected = 0;
                    if (mapp(e1) && e1["south"]) {
                        string target = e1["south"];
                        if (strsrch(target, south_file) != -1) connected = 1;
                    }
                    if (connected && (visible || south_visible)) path_line += " | "; else path_line += "   ";
                } else {
                    path_line += "   ";
                }
                if (x < cur_x + range) path_line += " ";
            }
        }
        out += room_line + "\n";
        if (y > cur_y - range) out += path_line + "\n";
    }
    
    string compass = 
        "      N      \n" +
        "    W + E    \n" +
        "      S      \n";
        
    string legend = select_lang(([
        "en": "Legend: " + HIY(" * ") + " You " + WHT(" # ") + " Visited " + HIC(" S ") + " Safe " + YEL(" F ") + " Forge " + HIG(" L ") + " Lab " + HIW(" B ") + " Bank " + MAG(" T ") + " Tavern " + HIY(" A ") + " Shop " + " ?  Unknown\n",
        "zh-TW": "圖例: " + HIY(" * ") + " 你 " + WHT(" # ") + " 已探索 " + HIC(" S ") + " 安全 " + YEL(" F ") + " 鐵匠 " + HIG(" L ") + " 藥劑 " + HIW(" B ") + " 銀行 " + MAG(" T ") + " 酒館 " + HIY(" A ") + " 商店 " + " ?  未探索\n",
        "zh-CN": "图例: " + HIY(" * ") + " 你 " + WHT(" # ") + " 已探索 " + HIC(" S ") + " 安全 " + YEL(" F ") + " 铁匠 " + HIG(" L ") + " 药剂 " + HIW(" B ") + " 银行 " + MAG(" T ") + " 酒馆 " + HIY(" A ") + " 商店 " + " ?  未探索\n"
    ]));

    out += BOLD_WHT("----------------------") + "\n";
    out += CYN(compass);
    out += legend;
    return out;
}

// 提供給 Web UI 的 JSON 資料
mapping get_map_json(object me, int range) {
    mapping res = ([ "center_name": "", "grid": ({}), "connections": ({}) ]);
    if (!me) return res;
    
    object me_env2 = environment(me);
    mixed coords = me_env2 ? me_env2->query_coordinate() : 0;
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
    mixed connections = ({});
    
    // 從北到南 (y 遞減)
    for (int y = cur_y + range; y >= cur_y - range; y--) {
        mixed row = ({});
        for (int x = cur_x - range; x <= cur_x + range; x++) {
            string type = "void";
            string r_file = get_room_file(x, y, cur_z);
            
            if (x == cur_x && y == cur_y) {
                type = "player";
            } else if (r_file) {
                if (explored && explored[r_file]) {
                    object r_ob = find_object(r_file);
                    if (!r_ob) r_ob = load_object(r_file);
                    if (r_ob->query_has_bank()) type = "bank";
                    else if (r_ob->query_has_shop()) type = "shop";
                    else if (r_ob->query_has_tavern()) type = "tavern";
                    else if (r_ob->query_has_guild()) type = "guild";
                    else if (r_ob->query_has_forge()) type = "forge";
                    else if (r_ob->query_has_lab()) type = "lab";
                    else if (r_ob->query_no_combat()) type = "safe";
                    else type = "room";
                } else {
                    type = "fog";
                }
            }
            row += ({ type });

            // Check horizontal connection
            if (x < cur_x + range) {
                string next_f = get_room_file(x+1, y, cur_z);
                if (r_file && next_f) {
                    object r1 = load_object(r_file);
                    mapping e1 = r1->query_exits();
                    if (mapp(e1) && e1["east"] && strsrch(e1["east"], next_f) != -1) {
                        connections += ({ ({ x, y, x+1, y }) });
                    }
                }
            }
            // Check vertical connection
            if (y > cur_y - range) {
                string south_f = get_room_file(x, y-1, cur_z);
                if (r_file && south_f) {
                    object r1 = load_object(r_file);
                    mapping e1 = r1->query_exits();
                    if (mapp(e1) && e1["south"] && strsrch(e1["south"], south_f) != -1) {
                        connections += ({ ({ x, y, x, y-1 }) });
                    }
                }
            }
        }
        grid += ({ row });
    }
    
    res["grid"] = grid;
    res["connections"] = connections;
    return res;
}
