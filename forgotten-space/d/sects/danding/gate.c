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
}
