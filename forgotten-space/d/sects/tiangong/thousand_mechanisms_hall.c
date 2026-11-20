// /d/sects/tiangong/thousand_mechanisms_hall.c
// 天工閣・千鍛地火廊暨千機院 (Ch.88：青銅搬山傀儡軸套公差修復考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・千鍛地火廊暨千機院");
    set_long("熱浪逼人的長條形地下石廊，兩側排列著十二座燃著橙紅地肺火舌的鍛造爐台。\n"
             "每座石台正中央架著一具半人高的二階「青銅搬山傀儡」右臂驅動關節（puppet），\n"
             "一側堆放著高碳熟鐵條、溫油淬槽與測試用的三百斤重鐵坨（指令：repair puppet）。\n"
             "主考台前站著千機院魯長老與地火鍛兵台總匠章百鍊。\n"
             "向西穿過閘門可返【千鍛百巧門】。\n");

    set_exits(([
        "west": "/d/sects/tiangong/gate.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/lu_zhanglao.c");
    spawn_npc("/clone/npc/zhang_bailian.c");
}

void init() {
    ::init();
    add_action("do_repair", "repair");
}

int do_repair(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "puppet" && arg != "傀儡" && arg != "搬山傀儡") {
        notify_fail("你想檢修什麼？試試：repair puppet\n");
        return 0;
    }
    message_vision("$N沒有盲目往表面糊塗流銀符紙，而是以卡尺量出軸套半厘偏角與內壁暗紫脆化麻點，\n"
                   "隨即以兩塊高碳熟鐵鍛出雙契榫楔溫油慢淬嵌合，並完成三百斤負重三十次起落複驗！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "repair", "target": "puppet" ]));
    }
    return 1;
}
