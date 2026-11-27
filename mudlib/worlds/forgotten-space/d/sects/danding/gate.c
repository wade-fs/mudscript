// /d/sects/danding/gate.c
// 千機百巧門・丹鼎宗・百草丹門 (Ch.89)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎宗・百草丹門");
    set_long("終年籠罩在淡青白藥霧之中的石砌山門，門額懸著「百草辨偽」古匾。霧氣\n"
             "雖帶著濃郁藥香，細嗅卻隱約夾雜著一絲淡淡的澀口礦酸氣息。\n"
             "向西南下山可返【雲津萬山廣場】，向東北穿過藥霧步入【百毒試藥谷暨百草谷】。\n");

    set_exits(([
        "southwest": "/d/yunjin/wanshan_square.c",
        "northeast": "/d/sects/danding/herb_garden.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", CYN "門柱青石被終年不斷的藥霧浸得微濕滑膩，觸手帶著淡淡涼意。" NOR);
    set_smell("default", HIG "濃烈草木藥香深處，隱約藏著一絲令人舌根發澀的礦酸與微腥氣息。" NOR);
    set_listen("default", CYN "門內山谷傳來木杵搗藥的沉悶咚咚聲與山風吹拂藥霧的沙沙響動。" NOR);

    mapping scent_rule = ([
        "targets": ({ "mist", "plaque", "藥霧", "門匾", "" }),
        "sp_cost": 4,
        "sensory_msg": HIG "你站在『百草辨偽』古匾下屏息分辨門前藥霧裡的雜味，練出幾分辨識真偽草石的直覺。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("sniff", scent_rule);
    add_action_rule("辨藥氣", scent_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
