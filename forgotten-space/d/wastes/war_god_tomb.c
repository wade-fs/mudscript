// /d/wastes/war_god_tomb.c
// 荒古戰神巨石遺塚（Ch.105：十二玄石巨柱、五尺凍血跡、燕山護心鏡、北荒冰熊王與暖風裂隙）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑冰深處・荒古戰神巨石遺塚");
    set_long("兩座如劍鋒交錯的黑曜石崖壁夾角下方，巍然聳立著一座高逾三十丈的太古巨石遺塚。\n"
             "沒有任何飛簷雕欄，僅以十二根十人合抱不過來的粗糙黑色巨柱撐起扁平玄石穹頂，\n"
             "柱面鑿著先民追殺太古凶獸的粗獷刻痕，離最右側石壁一丈寬裂隙最近那根巨柱中央\n"
             "正有個與「獵獸圖騰骨片」嚴絲合縫的凹痕（按骨片共鳴：resonate totem）。裂隙前石板\n"
             "凝著五尺暗紫拖拽血跡與一面帶「燕」字的凹損護心鏡。南返【舊勘探隊營地廢墟】，往東退入暖風裂隙赴【方舟冷卻管線艙段】。\n");

    set_exits(([
        "south": "/d/wastes/old_expedition_camp.c",
        "east":  "/d/wastes/ark_foundation.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/ice_bear_king.c");
}

void init() {
    ::init();
    add_action("do_resonate", "resonate");
}

int do_resonate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "totem" && arg != "pillar" && arg != "bone" && arg != "圖騰" && arg != "遺塚") {
        notify_fail("你想共鳴哪樣信物？試試：resonate totem\n");
        return 0;
    }
    message_vision("$N將【太古戰神獵獸圖騰骨片】按入黑色巨柱中央凹痕，石柱頓時響起如遠古巨人\n"
                   "心跳般的低頻悶響，柱面閃出荒古死戰與鎖煞於骨髓、收力輪替的呼吸節律——\n"
                   "你壓住暴衝氣血，收妥裂隙邊五尺凍血跡盡頭帶「燕」字的凹損護心鏡，不戀戰徑退暖風裂隙！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "resonate", "target": "totem" ]));
    }
    return 1;
}
