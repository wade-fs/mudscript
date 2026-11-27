// /clone/npc/wanwu_auditor_qi.c
// 齊九軸（萬物主機城・外環維修工會總工頭）(Ch.137-138, 145, 147, 155, 162)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("齊九軸");
    set_short(HIY "外環維修工會總工頭" NOR " 齊九軸");
    set_long("一位右臂裝著精鋼可拆卸活榫義肢的老匠工頭，眼角滿是機油燻痕與鐵砂細疤。\n"
             "他痛恨稽核司只顧帳面達成率、把維修工友當消耗零件，堅守著『可維修、不神識接駁』的底線。\n");
    set_id(({ "wanwu_auditor_qi", "auditor qi", "qi jiuzhou", "齊九軸", "總工頭" }));

    setup_archetype("E", 88);
    set("class", "gong");
    set("path", "wu");
    set("faction", "wanwu_guild");
    set("roles", ({ "artisan", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/wanwu/scrap_ring.c");

    add_response(({ "試工", "車軸", "公差", "銅匣" }),
        "齊九軸敲了敲鋼鐵義肢：「少拿那些虛頭巴腦的符文糊弄老子！把三號運料車軸公差修順了\n"
        "（repair axle），我才發你進登錄廳的試工牌，順便借你機床替太虛那邊補鍛三枚穩壓銅芯。」");

    add_response(({ "走私", "赤火", "三號線" }),
        "齊九軸眼神驟冷：「三號廢料拆解線暗槽裡藏著一箱印有『赤火』篆印的走私晶箱！\n"
        "今晚外環停機空窗期就去暗洞伏擊那個灰紋掮客（ambush broker）。」");

    add_response(({ "停工", "條例", "陳楷" }),
        "齊九軸哼聲道：「二十四座零件站只要嚴格照《安全公差條例》停爐複驗（declare strike），\n"
        "陳楷死抱著的那張『自修達成率』考勤板馬上就得跌穿底線！」");
}
