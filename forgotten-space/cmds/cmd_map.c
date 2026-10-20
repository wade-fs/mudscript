// /cmds/cmd_map.c
// 地圖指令

#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    object map_d = load_object("/secure/map_d.c");
    if (!map_d) {
        write("地圖系統暫不可用。\n");
        return 1;
    }

    if (arg && arg != "") {
        arg = trim(arg);
        if (arg == "world" || arg == "全域" || arg == "六縣") {
            write(map_d->draw_world_map(me));
            return 1;
        }
        if (arg == "city" || arg == "都城" || arg == "府城") {
            write(map_d->draw_city_map(me));
            return 1;
        }
        if (arg == "village" || arg == "黑石鋪" || arg == "新手村" || arg == "村落") {
            write(map_d->draw_village_map(me));
            return 1;
        }
        if (arg == "under" || arg == "地下" || arg == "鬼市" || arg == "暗渠") {
            write(map_d->draw_under_map(me));
            return 1;
        }
        if (arg == "panmu" || arg == "盤木" || arg == "盤木縣") {
            write(map_d->draw_panmu_map(me));
            return 1;
        }
        if (arg == "zhongshi" || arg == "重石" || arg == "重石縣") {
            write(map_d->draw_zhongshi_map(me));
            return 1;
        }
    }

    int range = 2; // 預設 5x5
    if (arg && arg != "") {
        range = to_int(arg);
        if (range < 1) range = 1;
        if (range > 5) range = 5;
    }

    write(map_d->draw_map(me, range));
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  map [city|village|under|world|range]\n  Show map around current location, or inspect specific regions.\n  Examples: map, map city, map village, map under, map world\n",
        "zh-TW": "【指令】\n  map [city|village|under|world|範圍]\n  顯示目前位置地圖，或檢視指定區域地圖。\n  範例：map (當前區域)、map city (都城全圖)、map village (黑石鋪全圖)、map under (地下暗渠)、map world (全域城鄉)\n",
        "zh-CN": "【指令】\n  map [city|village|under|world|范围]\n  显示目前位置地图，或检视指定区域地图。\n  范例：map (当前区域)、map city (都城全图)、map village (黑石铺全图)、map under (地下暗渠)、map world (全域城乡)\n"
    ]));
}
