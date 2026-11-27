// clone/item/secret_letter.c
// 城防軍火漆密信 - 截獲自巡檢伍長胡三身上的官商勾結罪證 (小說第8、9、10章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("火漆密信", ({ "secret letter", "letter", "密信", "信件", "信" }));
    set_short(HIR "染血的火漆密信" NOR);
    set_long("一封用厚重黑火漆封口的軍用密信，信角沾染著斑駁暗紅的血跡。\n"
             "信上赫然蓋著大荒城防軍統領的私印，字跡森冷殘酷：\n"
             "『……黑石山口地煞異動已成，官軍封卡，黑市路引炒至八十兩。三日內商隊補給將盡，\n"
             "屆時襲殺大掌櫃，吞沒大荒古礦。黑石鋪民戶，若有異動，一律按通匪罪論處，滿鎮皆戮……』\n");
    set_weight(50);
    set_value(500);
    set("no_sell", 1);
}
