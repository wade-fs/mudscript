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

// ── 宏觀全域地理拓撲地圖 (World Map) ──────────────────────
string draw_world_map(object me) {
    string msg = "\n" + HIY "【《遺忘的世界》全域城鄉拓撲網絡圖 (Tier 1)】" + NOR + "\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    msg += "                          " + HIW + "[ 鎮風縣 ]" + NOR + " (正北 300 里・天風要塞)\n";
    msg += "                              │\n";
    msg += "      " + HIG + "[ 青河縣 ]" + NOR + " ────────── " + HIY + "[ 金石府城 ]" + NOR + " ────────── " + HIR + "[ 烈礬縣 ]" + NOR + " (東北 320 里)\n";
    msg += "     (正西 280 里)                 │                       (硫礬赤銅)\n";
    msg += "     (藥草水運)                    │                            │\n";
    msg += "                                   │                      " + HIB + "[ 濁水縣 ]" + NOR + " (東南 350 里)\n";
    msg += "                       ┌───────────┴───────────┐          (沼澤黑市)\n";
    msg += "                       │                       │\n";
    msg += "                  " + HIG + "[ 盤木縣 ]" + NOR + "              " + HIW + "[ 重石縣 ]" + NOR + "\n";
    msg += "                 (正南 260 里)           (西南 240 里)\n";
    msg += "                 (林木機巧)              (條石生鐵)\n";
    msg += "                       │                       │\n";
    msg += "                       └───────────┬───────────┘\n";
    msg += "                                   │ (南嶺官道 450 里)\n";
    msg += "                              " + CYN + "[ 黑石鋪 ]" + NOR + " (極南古脈深山・發跡之地)\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    msg += "提示：輸入 map city 查看都城地圖，輸入 map village 查看黑石鋪地圖。\n\n";
    return msg;
}

// ── 金石都城九大分區詳細地圖 (City Map) ─────────────────────
string draw_city_map(object me) {
    string cur = me && environment(me) ? base_name(environment(me)) : "";
    string msg = "\n" + HIY "【金石都城九大分區空間地圖】" + NOR + "\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    msg += "                        [外城大車馬店]\n";
    msg += "                              │\n";
    msg += "      [亂葬義塚] ─── " + HIW + "【金石北關】" + NOR + " ── (北城望荒箭樓)\n";
    msg += "                             │\n";
    msg += "  [官道大貨棧] ─── [北關前校場] ─── [關外車馬店]\n";
    msg += "                             │\n";
    msg += "    [匠籍登記處] ─── " + CYN + "【百工總會】" + NOR + " ─── (分業工坊街：鍛/木/石/革/藥/硝)\n";
    msg += "                             │\n";
    msg += "  " + HIC + "【宣道司】" + NOR + " ────── " + HIY + "【中央青石廣場】" + NOR + " ────── " + HIR + "【鎮武軍鎮】" + NOR + " ─── " + HIW + "【東關城門】" + NOR + "\n";
    msg += "   (玄機真人)          (士民商貿)          (霸山總教頭)      (烈礬/濁水)\n";
    msg += "   (摘星台/偏殿)       ┌─────┴─────┐          (大校場/生死擂)\n";
    msg += "   (聽經閣)        [府衙正堂]   [通寶錢莊]     (披甲兵器庫)\n";
    msg += "                       │           │\n";
    msg += "                   [學塾/醫館]  [通寶當鋪] ── [鬼市暗巷] (下通城下暗渠)\n";
    msg += "                       └─────┬─────┘\n";
    msg += "                             │\n";
    msg += "                        [六縣專材長街] ─── [金石商會總堂]\n";
    msg += "                             │                 │\n";
    msg += "                        [大料初堆棧] ─── [遠行車馬大院]\n";
    msg += "                             │\n";
    msg += "  " + HIB + "【西水門】" + NOR + " ────── " + HIW + "【金石南關】" + NOR + " ─── [南關車馬小棧]\n";
    msg += " (青河水路漕運)              │\n";
    msg += "                             │ (南嶺官道)\n";
    msg += "                             ▼\n";
    msg += "                     往 " + CYN + "【黑石鋪】" + NOR + " 聚落\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    if (me && environment(me)) {
        msg += "你當前身處：" + HIG + environment(me)->query_short() + NOR + " (" + cur + ")\n";
    }
    return msg;
}

// ── 城下暗渠與舊城廢墟地圖 (Underground Map) ───────────────
string draw_under_map(object me) {
    string cur = me && environment(me) ? base_name(environment(me)) : "";
    string msg = "\n" + MAG "【金石城下・太古暗渠與舊城廢墟地圖】" + NOR + "\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    msg += "                 [地面・鬼市暗巷]\n";
    msg += "                        │ (down)\n";
    msg += "                  " + HIY + "【地下鬼市】" + NOR + " (銷贓黑市暗街)\n";
    msg += "                        │\n";
    msg += "  [廢棄水閘] ──── " + HIC + "【古暗渠樞紐】" + NOR + " ──── " + HIR + "【天字一號密室】" + NOR + "\n";
    msg += " (護城河盲區)      (溶洞暗河・擺渡叟)      (需天門引驗證)\n";
    msg += "                        │\n";
    msg += "                  " + MAG + "【史前殘殿】" + NOR + " (人面神像・地煞匯聚)\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    if (me && environment(me)) {
        msg += "你當前身處：" + HIG + environment(me)->query_short() + NOR + " (" + cur + ")\n";
    }
    return msg;
}

// ── 黑石鋪新手村五方微生態地圖 (Village Map) ────────────────
string draw_village_map(object me) {
    string cur = me && environment(me) ? base_name(environment(me)) : "";
    string msg = "\n" + CYN + "【黑石鋪・聚落五方微生態地圖 (Tier 0)】" + NOR + "\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    msg += "                             【黑石古礦道】(北崖古礦坑)\n";
    msg += "                                   │ (up/down)\n";
    msg += "                             【地下崩塌坑道】(深井生鐵索具)\n";
    msg += "                                   │\n";
    msg += "   【荒廢殘壇】                    │                    往 " + HIY + "【金石府城】" + NOR + "\n";
    msg += "    (迎風孤岩)                     │                          ▲\n";
    msg += "        │                         │                          │ (northeast)\n";
    msg += "   【三清偏殿】 ───────── " + HIY + "【青石街市】" + NOR + " ───────── 【老鐵匠鋪】\n";
    msg += "    (枯木老道)                 (核心樞紐)                 (阿鐵爐火)\n";
    msg += "        │                         │                          │\n";
    msg += "   【客棧後街】 ───────── 【廢柴房】                   【獵戶哨亭】\n";
    msg += "    (青石暗巷)                 (沈泥窩棚)                 (趙老獵)\n";
    msg += "                                   │                          │\n";
    msg += "                             【碎石溪灘】 ───────── 【大荒荒林】\n";
    msg += "                              (幽霧水谷)                  (東林獸道)\n";
    msg += "                                   │\n";
    msg += "                             【墜龍瀑布】\n";
    msg += "                              (寒潭瀑布淬體)\n";
    msg += "                                   │\n";
    msg += "                             【採藥草廬】(葛半仙草堂)\n";
    msg += WHT "──────────────────────────────────────────────────────────\n" + NOR;
    if (me && environment(me)) {
        msg += "你當前身處：" + HIG + environment(me)->query_short() + NOR + " (" + cur + ")\n";
    }
    return msg;
}

string draw_map(object me, int range) {
    if (!me) return "";
    
    object me_env = environment(me);
    if (me_env) {
        string loc = base_name(me_env);
        if (strsrch(loc, "/d/city/under/") != -1) {
            return draw_under_map(me);
        }
        if (strsrch(loc, "/d/city/") != -1) {
            return draw_city_map(me);
        }
        if (strsrch(loc, "/d/village/") != -1) {
            return draw_village_map(me);
        }
    }
    
    mixed coords = me_env ? me_env->query_coordinate() : 0;
    if (!coords) return _t("map_not_found") + "\n";
    
    int cur_x = coords[0];
    int cur_y = coords[1];
    int cur_z = coords[2];
    
    mapping explored = me->query_explored_rooms();
    string room_name = me_env->query_short();
    
    string title = _t("minimap_title");
    title = replace_string(title, "$room", room_name);
    title = replace_string(title, "$x", sprintf("%d", cur_x));
    title = replace_string(title, "$y", sprintf("%d", cur_y));
    title = replace_string(title, "$z", sprintf("%d", cur_z));
    
    string out = "\n" + "$HIW$" + title + "$NOR$" + "\n";
    
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
                        if (mapp(n_exits) && n_exits[opp[i]]) {
                            string target = resolve_path(n_exits[opp[i]], neighbor_file);
                            if (target == r_file) {
                                visible = 1;
                                break;
                            }
                        }
                    }
                }
            }

            // 1. 繪製房間符號
            if (x == cur_x && y == cur_y) {
                room_line += "$HIY$ * $NOR$"; // 當前位置
            } else if (!visible) {
                room_line += "   "; // 不可見則留白
            } else if (explored && explored[r_file]) {
                object r_ob = find_object(r_file);
                if (!r_ob) r_ob = load_object(r_file);

                if (r_ob->query_has_bank()) room_line += "$HIW$ B $NOR$";
                else if (r_ob->query_has_shop()) room_line += "$HIY$ A $NOR$";
                else if (r_ob->query_has_tavern()) room_line += "$MAG$ T $NOR$";
                else if (r_ob->query_has_guild()) room_line += "$HIB$ G $NOR$";
                else if (r_ob->query_has_forge()) room_line += "$YEL$ F $NOR$";
                else if (r_ob->query_has_lab()) room_line += "$HIG$ L $NOR$";
                else if (r_ob->query_no_combat()) room_line += "$HIC$ S $NOR$";
                else room_line += "$WHT$ # $NOR$";
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
                        string target = resolve_path(e1["east"], r_file);
                        if (target == next_file) connected = 1;
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
                        string target = resolve_path(e1["south"], r_file);
                        if (target == south_file) connected = 1;
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
        
    string legend = _t("minimap_legend");

    out += "$HIW$----------------------$NOR$" + "\n";
    out += "$CYN$" + compass + "$NOR$";
    out += legend + "\n";
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
                    if (mapp(e1) && e1["east"]) {
                        string target = resolve_path(e1["east"], r_file);
                        if (target == next_f) {
                            connections += ({ ({ x, y, x+1, y }) });
                        }
                    }
                }
            }
            // Check vertical connection
            if (y > cur_y - range) {
                string south_f = get_room_file(x, y-1, cur_z);
                if (r_file && south_f) {
                    object r1 = load_object(r_file);
                    mapping e1 = r1->query_exits();
                    if (mapp(e1) && e1["south"]) {
                        string target = resolve_path(e1["south"], r_file);
                        if (target == south_f) {
                            connections += ({ ({ x, y, x, y-1 }) });
                        }
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
