// /clone/npc/wanwu_inspector_chen.c
// 陳楷（萬物主機城・外環稽核司主事，中階具名反派）(Ch.138, 152, 155, 162)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陳楷");
    set_short(CYN "外環稽核司主事" NOR " 陳楷");
    set_long("一名穿戴整齊青金邊袍、腋下總夾著三塊考勤木板的外環稽核司主事。\n"
             "他並不以虐殺為樂，卻把『季度自修達成率』視為命根，凡不在離艦名冊內的人與物皆視作可回收材料。\n");
    set_id(({ "wanwu_inspector_chen", "inspector chen", "chen kai", "陳楷", "稽核主事" }));

    setup_archetype("H", 90);
    set("class", "gong");
    set("path", "wu");
    set("faction", "wanwu_audit");
    set("roles", ({ "antagonist", "quest" }));
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/wanwu/scrap_ring.c");

    add_response(({ "達成率", "無主材料", "清零", "配額" }),
        "陳楷面無表情翻動考勤木板：「離艦總冊裡沒名字的就是無主可回收材料！若灰燼石堡拿不出\n"
        "實物抵扣過維護工時的在籍補冊憑證，強制清零令照章執行。」");
}
