// /clone/npc/xuanshu_menzhu.c
// 玄樞門主・千機百巧門門主 (xuanshu_menzhu) - 問道天台 (Ch.112-120)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("玄樞門主");
    set_short(HIC "千機百巧門主" NOR " 玄樞門主");
    set_long("執掌天工閣與丹鼎宗兩大主脈的千機百巧門總門主，道袍袖口繡著精微連環齒輪暨九鼎銀紋。\n"
             "公開質證時曾嚴詞質問沈泥與羅九秤『煽動三宗內亂之罪誰擔』；待見四線互證後亦果斷蓋印\n"
             "停採拆爐，災起時更與紫霄真人聯手結陣將半山毒域硬壓在百丈方圓內。\n");
    set_id(({ "xuanshu_menzhu", "xuanshu", "千機門主", "玄樞門主" }));

    setup_archetype("E", 98);
    set("class", "gong");
    set("faction", "qianji");
    set("roles", ({ "leader", "judge" }));
    set("home_room", "/d/yunjin/hearing_hall.c");

    add_response(({ "會武", "丙字柒號", "赤煉", "海捕" }),
        "玄樞門主手中九股玄鐵算環冷冷相擊，語聲如尺量度石：「問道天台不是州縣衙門，可既有萬機地窟\n"
        "領用簿、丹火窟紫泥樣本、雪線試毒針與萬寶暗標帳互相印證——該拆的拆，該辦的辦！\n"
        "即日查封拆除丹鼎宗地底『丙字柒號』秘爐、嚴密看守候審之鶴壽；至若趁亂從萬仞地火暗道逃遁的赤煉，\n"
        "三宗已發海捕文書……只是山深道雜，短期內休想輕易抓回，爾等更要提防那些停爐後斷了生計的老苦力生變！」");
}
