// clone/item/miner_thumbprints.c
// 黑石鋪倖存礦工指血結狀 - 卷二第四幕核心人證物證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑石鋪倖存礦工指血結狀", ({ "miner thumbprints", "miner_thumbprints", "jiezhuang", "血指結狀", "礦工狀紙" }));
    set_short(RED "【黑石鋪倖存礦工指血結狀】" NOR);
    set_long("老礦工魯大山率領二十二名從黑石嶺塌方地火中九死一生逃出之礦工，\n"
             "在府衙推官與案牘主簿文承敬面前具結畫押的正式控狀。\n"
             "狀紙上按滿了二十二枚鮮紅刺目的血手印，字字泣血控訴錢百川抽減沉陰鐵木支護大梁、\n"
             "並於塌方之時自外反鎖逃生鐵門企圖悶死全坑礦工滅口之暴行，為關鍵核心人證物證（conclusive）。\n");
    set_weight(40);
    set_value(1500);
    set("is_evidence", 1);
    set("evidence_type", "miner_thumbprints");
    set("evidence_level", "conclusive");
}
