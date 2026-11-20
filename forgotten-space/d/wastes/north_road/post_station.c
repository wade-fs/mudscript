// /d/wastes/north_road/post_station.c
// 北境官道・斷崖石棚驛站 (Ch.83：退門武師與藥徒、野菊抗寒湯救護腳夫)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北境官道・斷崖石棚驛站");
    set_long("這是一處半嵌在青石斷崖下的避雪驛棚，兩扇厚柏木門板擋住了門外呼嘯的\n"
             "暴雪，屋內瀰漫著濕羊皮、松柴濃煙與汗氣。火塘邊擺著一口熬水的粗陶罐，\n"
             "可於此處烹煎驅寒草藥（指令：brew decoction）救治凍傷失溫的年輕腳夫。\n"
             "角落坐著幾名南下的退門弟子與行腳隊領隊穆雪。\n"
             "向南回望【黑風口雪坡】，往北翻越雪道可至【青石埡口】。\n");

    set_exits(([
        "south": "/d/wastes/north_road/cold_plain_entry.c",
        "north": "/d/wastes/north_road/qing_pass.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/mu_xue.c");
    spawn_npc("/clone/npc/zhou_tieshan.c");
    spawn_npc("/clone/npc/chen_qing.c");
}

void init() {
    ::init();
    add_action("do_brew", "brew");
}

int do_brew(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "decoction" && arg != "湯劑" && arg != "herbs") {
        notify_fail("你想熬煮什麼？試試：brew decoction\n");
        return 0;
    }
    message_vision("$N蹲在火塘石塊邊，將金石野菊花、防瘴草籽與生薑投入沸水陶罐文火慢煎，\n"
                   "隨即端起滾熱的湯劑遞給縮在草堆發抖的年輕腳夫，逼出凍傷寒氣。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "brew", "target": "decoction" ]));
    }
    return 1;
}
