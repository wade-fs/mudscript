// /d/sects/bahuang/west_wall_breach.c
// 黑山長城西段・三十丈崩塌缺口暨二道內門（Ch.118-119：冰獄骨龍破關、巨靈神機支撐與三元鎮脈陣）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑山長城西段・三十丈崩塌缺口");
    set_long("天台鎮脈主陣驟停半數協同後遭【冰獄骨龍】一息凍裂垮塌的整整三十丈厚重\n"
             "條石城牆缺口！兩座重型弩樓傾頹於側，第二道內門門洞上方萬鈞石樑正由萬仞天工山\n"
             "玄鐵暗門踏出的十丈【巨靈神機】肩背以純淨地肺熱壓暨不融黑鐵連接桿死死頂住！\n"
             "東側完整城牆下方通有平民疏散排水石道（啟動三元鎮脈陣配輪替破核：stabilize array）。\n"
             "向東南沿長城牆頂連回【北線長城巡防牆暨關口】，向南經玄鐵暗門直入【天工閣・萬機地窟】。\n");

    set_exits(([
        "southeast": "/d/sects/bahuang/great_wall_gate.c",
        "south":     "/d/sects/tiangong/machinery_depths.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "缺口崩裂的巨石斷面覆著一層極寒冰煞，指尖觸碰會感到刺痛般的陰氣反彈。" NOR);
    set_smell("default", MAG "深寒冰霧裡混雜著地煞腐蝕氣味與下方排水石道滲出的潮濕泥腥。" NOR);
    set_listen("default", HIR "凜冽煞風在牆缺口尖嘯盤旋，冰骨龍骸骨摩擦發出令人牙酸的咯吱聲。" NOR);

    spawn_npc("/clone/npc/ice_bone_dragon.c");
}

void init() {
    ::init();
    add_action("do_stabilize", "stabilize");
}

int do_stabilize(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "array" && arg != "gate" && arg != "鎮脈陣" && arg != "缺口") {
        notify_fail("你想協同穩住哪一項防線？試試：stabilize array\n");
        return 0;
    }
    message_vision("$N依《逆星歲差修訂模型》撥正十二根星柱東三度七分立起「三元鎮脈陣」，\n"
                   "減緩冰獄骨龍雙翼三成並鎖定左肋熔岩舊創；同步拉動巨靈神機黑鐵連接桿右傾半尺架住\n"
                   "骨龍冰尾半息，配合八荒三段輪替重弓《破核》一箭轟穿骨龍左肋迫退殘獸潮！\n"
                   "黑鐵連接桿雖過載報廢、雪地亦留八十餘冰冷忠骨，終究死死守住第二道內關！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "stabilize", "target": "array" ]));
    }
    return 1;
}
