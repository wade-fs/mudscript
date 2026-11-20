// /clone/item/wang_red_pill_vial.c
// 王鐵牛護心甲震出之暗紅丸藥瓶封樣（第三卷 Ch.114 雲頂力道演武）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("八荒演武暗紅丸藥瓶", ({ "wang_red_pill_vial", "red_pill_vial", "暗紅丸藥瓶", "急鎮丸封樣" }));
    set_short(RED "杜青禾唐映聯署・演武暗紅丸藥封樣" NOR);
    set_long("燕隼於問道天台青鋼岩演武場施《八荒破天弓》震碎王鐵牛半寸精鋼護心甲時掉出之小瓷瓶。\n"
             "八荒醫官杜青禾與破軍女校尉唐映當場衝台封存：內裝過量「急鎮丸」與疑似摻血精烈性催血劑。\n");
    set_weight(120);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
