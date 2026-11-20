// /clone/npc/li_qingyun.c
// 李青雲・丹鼎宗鶴壽首徒 (li_qingyun) - 問道天台丹鼎藥試台 (Ch.113)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("李青雲");
    set_short(MAG "丹鼎鶴壽首徒" NOR " 李青雲");
    set_long("身著華貴紫邊藥師袍的丹鼎內門首徒，袖口隱隱透著一縷異常甜腥氣，面前紫銅藥鼎裡\n"
             "正捧出帶九道紅金丹紋的二階上等「九轉增元丹」，意氣風發欲壓過西台「三元生機丹」。\n");
    set_id(({ "li_qingyun", "li qingyun", "liqingyun", "李青雲", "首徒" }));

    setup_archetype("F", 84);
    set("class", "gong");
    set("faction", "danding");
    set("roles", ({ "challenger", "alchemist" }));
    set("home_room", "/d/yunjin/tournament_craft_arena.c");

    add_response(({ "九轉增元丹", "銀針", "赤參精髓", "血毒" }),
        "李青雲盯著那根插進丹液兩息便冒灰黑煙、枯死雪線苔活葉的純銀試毒針，雙腿發軟失聲叫道：\n"
        "「不對！我封爐前確實用高品階藥引洗過丹毒……師、師父！這味紅血引子不是您親自配給弟子說是『百年赤參精髓』的嗎？！」");
}
