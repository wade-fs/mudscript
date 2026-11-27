// /clone/item/yanshan_eagle_rubbing.c
// 燕山左撇鷹記拓片 (Ch.133 FS-03 西南獵道實證)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("燕山左撇鷹記拓片", ({ "yanshan_eagle_rubbing", "eagle rubbing", "rubbing", "鷹記拓片", "左撇鷹記拓片" }));
    set_short(HIY "蠟紙拓印・燕山左撇雙羽鷹記" NOR);
    set_long("一張自赤黑焦土裂縫岩石底面拓印下來的蠟紙拓片，清晰可見三道「左撇收腕・雙羽隱括」\n"
             "的黑石鋪燕家獵戶暗記，風化砂層僅三至五年，證明大伯燕山仍活在戰祖西南獵道之中。\n");
    set_weight(20);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborated");
}
