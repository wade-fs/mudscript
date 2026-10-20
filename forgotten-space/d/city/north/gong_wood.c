// d/city/north/gong_wood.c
// 天工木作大棚 (魯長生、敲榫考核第2階段)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・天工木作大棚");
    set_long("整座大棚瀰漫著清新濃郁的松香與冷杉木屑氣息。\n"
             "棚下堆疊著自盤木縣採伐運抵的數十根百年鐵力木巨樑與造梯滑輪。\n"
             "大木作把頭魯長生正在指揮工匠搶修城防吊車架構。\n"
             "棚柱中央橫架著一根受力微傾的重木大樑，榫卯卡榫 (tenon) 處微有鬆動，\n"
             "學徒可手持鐵錘敲擊榫楔 (strike tenon/敲榫) 以平衡應力結構。\n"
             "向北穿過木廊回到萬機正堂，往東是熟皮鞣革坊，往西則是採百草分堂。\n");

    set_exits(([
        "north": "/d/city/north/gong_hall.c",
        "east":  "/d/city/north/gong_leather.c",
        "west":  "/d/city/north/gong_alchemy.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/gong_luchangsheng.c");
}

void init() {
    ::init();
    add_action("do_strike", "strike");
    add_action("do_strike", "敲榫");
    add_action("do_strike", "敲打");
}

int do_strike(string arg) {
    object me = this_player();
    if (!arg || (arg != "tenon" && arg != "榫" && arg != "榫卯" && arg != "榫楔")) {
        write("你想敲打校正什麼？(strike tenon)\n");
        return 1;
    }

    write(CYN "你深吸一口氣，手持鍛錘，凝神注視著大木橫樑的應力微紋...\n" NOR);
    write(HIY "叮！叮！叮！三記清脆錘擊精準打入螺旋榫楔，受力巨樑發出一陣平穩低鳴，瞬間咬合穩固！\n" NOR);
    write(HIG "【木作匠人們齊聲讚嘆：「眼力精準，應力無差，好手藝！」】\n" NOR);

    object q_engine = load_object(QUEST_ENGINE_D);
    if (q_engine) {
        q_engine->trigger_quest_event(me, "action", ({ "strike", "tenon" }));
    }
    return 1;
}
