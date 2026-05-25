// mudlib/cmds/cmd_mc.c
// Minecraft 互動指令

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

int main(object me, string verb, string arg) {
    object world = find_object("/area/lm/world");
    if (!world) world = load_object("/area/lm/world");
    
    if (environment(me) != world) {
        write("你必須在創世神世界中才能執行此指令。\n");
        return 1;
    }

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
            case 0: break; 
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
            case 0: write(HIG("挖掘成功！") + "\n"); break;
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
            case 0: write(HIG("放置成功！") + "\n"); break;
            case 1: write("座標超出世界範圍。\n"); break;
            case 2: write("那個位置已有方塊。\n"); break;
            case 3: write("背包裡沒有 " + btype + " 方塊。\n"); break;
        }
        return 1;
    }
    
    write("未知子指令。用法：mc move|dig|place|map\n");
    return 1;
}

string *query_verbs() { return ({ "mc" }); }
string query_category() { return "Special"; }

string help() {
    return "【創世神指令】\n" +
           "  mc move <方向>    在世界中移動 (n/s/e/w)\n" +
           "  mc dig <x> <y>    挖掘指定位置的方塊\n" +
           "  mc place <x> <y> <類型>  在指定位置放置方塊\n" +
           "  mc map            重新整理地圖資料\n";
}
