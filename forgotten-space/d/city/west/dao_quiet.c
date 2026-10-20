// d/city/west/dao_quiet.c
// 宣道司・靜心聽經閣 (司香道童、打坐清除濁氣)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("宣道司・靜心聽經閣");
    set_long("閣內光線幽暗柔和，四壁懸掛著手抄《清靜經》巨幅布帛。\n"
             "地坪上鋪著數十個厚實的艾草蒲團，一尊白玉古鼎中沉香輕煙直上。\n"
             "道童輕敲玉磬，清脆空靈的磬音在閣內久久迴盪，令聽者雜念全消。\n"
             "在此打坐聽經 (meditate/靜坐)，可消耗 50 文香油錢淨化 50 點紅塵濁氣。\n"
             "南面推開雕花木門，可返回宣道司正堂。\n");

    set_exits(([
        "south": "/d/city/west/dao_hall.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/dao_tong.c");
}

void init() {
    ::init();
    add_action("do_meditate", "meditate");
    add_action("do_meditate", "靜坐");
    add_action("do_meditate", "打坐");
}

int do_meditate(string arg) {
    object me = this_player();
    int cur_turb = me->query("turbidity");
    if (cur_turb <= 0) {
        write("你靈台澄澈，體內無紅塵濁氣積鬱，無需聽經淨化。\n");
        return 1;
    }

    if (me->query("money") < 50) {
        write("添入香爐的香油錢不足（需要 50 文錢）。\n");
        return 1;
    }

    me->add_money(-50);
    cur_turb -= 50;
    if (cur_turb < 0) cur_turb = 0;
    me->set("turbidity", cur_turb);

    write(CYN "你肅然盤坐於艾草蒲團之上，閉目隨悠揚磬音調勻呼吸...\n" NOR);
    write(HIW "空靈磬音洗滌靈台，心中的市井雜念與浮躁濁障消融殆盡！\n" NOR);
    write(HIG "【心神濁氣淨化 50 點，當前濁氣：" + sprintf("%d", cur_turb) + "/100】\n" NOR);
    return 1;
}
