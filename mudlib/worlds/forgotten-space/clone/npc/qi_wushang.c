// /clone/npc/qi_wushang.c
// 祁無傷・八荒北荒巡哨隊斥候 (qi_wushang) - 北荒巡哨營 (Ch.94)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("祁無傷");
    set_short(HIW "北荒巡哨隊斥候" NOR " 祁無傷");
    set_long("二十四歲的北荒邊民出身斥候，雙唇常被寒風吹得發紫，手裡拎著一根綁著紅布條的\n"
             "測冰長鐵簽。他不完全信任山門高層，卻比任何人都熟悉大黑山的雪線、獸道與暗河冰聲。\n");
    set_id(({ "qi_wushang", "qi wushang", "wushang", "祁無傷", "斥候" }));

    setup_archetype("K", 62);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "scout", "guide", "quest" }));
    set("home_room", "/d/sects/bahuang/north_watch.c");

    add_response(({ "鬼哭冰澗", "走山隊", "冰層", "暗河" }),
        "祁無傷拿測冰長鐵簽在青石上頓了頓：「大黑山東側無人邊線外三里便是鬼哭冰澗。\n"
        "去年雪崩塌了東坡一半，冰殼底下全是空的暗河裂縫！昨晚罡風剛好刮去一層浮雪，\n"
        "要下去找五年前走山隊的痕跡，先拴牛筋安全繩、拿長鐵簽試實承重（指令：probe ice）。」");

    add_response(({ "軍需副本", "夜震", "斥候" }),
        "祁無傷看了一眼長城北面：「有幾個夜晚大裂谷深處會傳來很有規律的地底震動，像鐵鎚敲銅鐘，\n"
        "絕不是野獸腳步……至於五年前到底抽調過什麼軍火，軍需檔案多被抽過頁，得問營裡的雷老將或炊事阿滿姐。」");
}
