// /d/yunjin/wanbao_back_alley.c
// 雲津・鬼市暗巷與萬寶閣後門交界處 (Ch.98：散播通寶稽核風聲截獲私盟密帳索引)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津・萬寶閣後門暗巷交界");
    set_long("緊挨萬寶閣高牆的背陰夾道，地面積雪印著三口沉重黑鐵箱拖過與快馬踏雪的車轍。\n"
             "巷口半搭著一座寒酸茶攤，每逢三更前後總有一名身穿洗白灰布棉襖的無標記經生騎馬經過。\n"
             "若趁夜放出「通寶總號稽核跨州飛錢」風聲驚動馬匹，或可逼其遺失貼身帳冊（指令：rumor audit）。\n"
             "往西南退入【雲海鬼市】，向北可直達【萬寶閣雲津分號】側巷。\n");

    set_exits(([
        "southwest": "/d/yunjin/ghost_market.c",
        "north":     "/d/yunjin/wanbao_pavilion.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "背陰夾道積雪凍得又硬又滑，黑鐵箱拖過的車轍邊緣結著鋒利冰稜。" NOR);
    set_smell("default", YEL "寒酸茶攤煤爐煙味、凍泥味與夜馬身上飄出的汗馬腥氣。" NOR);
    set_listen("default", WHT "高牆夾道裡風聲格外陰森，三更前後隱約能聽見孤騎踏雪的急促蹄音。" NOR);

    spawn_npc("/clone/npc/gray_robed_scribe.c");
}

void init() {
    ::init();
    add_action("do_rumor", "rumor");
}

int do_rumor(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "audit" && arg != "飛錢" && arg != "稽核") {
        notify_fail("你想散播什麼風聲引蛇出洞？試試：rumor audit\n");
        return 0;
    }
    message_vision("$N暗中藉公所腳夫茶攤放出風聲：『通寶總號今夜緊急派員來核對金石府涉案商號的\n"
                   "跨州飛錢餘額！』果見一名灰袍經生驚慌打馬欲遁入太清山霧，坐騎滑倒間一包覆著\n"
                   "防火油布、餘溫猶存的《延命私盟密帳索引》啪地滾落雪堆之中！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "rumor", "target": "audit" ]));
    }
    return 1;
}
