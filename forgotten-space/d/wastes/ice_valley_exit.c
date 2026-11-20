// /d/wastes/ice_valley_exit.c
// 廢棄應急通道暨冰谷窄口（Ch.110：百丈懸崖、萬年雪簷崩塌與私盟大執事伏擊戰）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・冰谷窄口伏擊道");
    set_long("寬約三十丈、兩側夾著百丈垂直冰脊懸崖的幽閉雪谷出口，正乃通往勘探隊大營的\n"
             "咽喉要道。出口立著兩塊十丈黑色冰岩，左上方凸出一道已裂開橫縫的萬年巨型雪簷，\n"
             "經精算三倍高頻震動即可引爆雪崩砸封敵軍後路兩側弩手（指令：trigger avalanche）。\n"
             "私盟大執事親率死士與虎煞戰鬥機關獸嚴陣堵殺！西南返【東側冷卻豁口】，正東繞祁十六\n"
             "熟識之隱蔽冰槽退返【冰脊高地勘探大營】。\n");

    set_exits(([
        "southwest": "/d/wastes/ark_cooling_breach.c",
        "east":      "/d/wastes/expedition_camp.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/private_league_envoy.c");
    spawn_npc("/clone/npc/tiger_mech_beast.c");
}

void init() {
    ::init();
    add_action("do_trigger", "trigger");
}

int do_trigger(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "avalanche" && arg != "snow" && arg != "雪崩" && arg != "雪簷") {
        notify_fail("你想引動什麼機關或地勢？試試：trigger avalanche\n");
        return 0;
    }
    message_vision("$N立小型紫微偏轉星陣撥開破甲連弩箭雨，同時擲出腐金濁毒煙籠罩虎煞機關獸與\n"
                   "前排死士面甲；算準左上方萬年雪簷橫縫共振頻率後甩出炸藥爆鳴筒——\n"
                   "轟隆萬鈞雪崩斷去死士後路，驚得大執事仰首露出咽喉三寸縫隙！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "trigger", "target": "avalanche" ]));
    }
    return 1;
}
