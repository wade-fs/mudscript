// /d/yunjin/tournament_combat_arena.c
// 問道天台・北側力法演武與八柱雷網台（Ch.114：破軍重弓震王鐵牛與避雷銅柱死角點破韓蒼晶斑）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("問道天台・力法演武大比台");
    set_long("由整塊厚重青鋼岩鋪成的北側主武場，一側圍立著八根預埋於地面的粗大「避雷銅柱」，\n"
             "構成太清壓軸雷網大陣。場邊醫療區與裁判台立著杜青禾與唐映，場中則分別站著\n"
             "服過量急鎮丸虛衝的王鐵牛，及眉心貼著遮光青玉佩的韓蒼（測算星曆公差搶入千分之三息\n"
             "避雷死角點碎玉佩：step deadzone）。向東返回【問道天台質證高台】。\n");

    set_exits(([
        "east": "/d/yunjin/hearing_hall.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/wang_tieniu.c");
    spawn_npc("/clone/npc/han_cang.c");
}

void init() {
    ::init();
    add_action("do_step", "step");
}

int do_step(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "deadzone" && arg != "thunder" && arg != "死角" && arg != "雷網") {
        notify_fail("你想踏入哪處公差身位？試試：step deadzone\n");
        return 0;
    }
    message_vision("$N據【逆星斷碑拓片】精算「東北偏三度・半息滯後」公差，提前半息踏入\n"
                   "八根避雷銅柱間千分之三息死角閃過十六道紫霄雷網與三十二道雷矛，一指點碎韓蒼\n"
                   "眉心遮光青玉佩——當場顯露其原有淡青結晶細紋與左眼半顆玉珠化症狀！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "step", "target": "deadzone" ]));
    }
    return 1;
}
