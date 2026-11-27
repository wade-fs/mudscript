// /clone/item/yanshan_broken_arrow.c
// 燕山鷹記斷折骨箭與八方舊皮甲封樣（第三卷 Ch.94 鬼哭冰澗）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("燕山鷹記斷折骨箭", ({ "yanshan_broken_arrow", "broken arrow", "yanshan arrow", "燕山鷹記斷折骨箭", "斷折骨箭" }));
    set_short(WHT "燕山鷹記斷折骨箭（封樣）" NOR);
    set_long("半截纏著雙股黑麻線與野鷹尾羽的粗木骨箭，連同一塊印著半邊「八方」字樣的凍硬舊皮甲\n"
             "一併包於編號油紙中。距斷口兩寸處深嵌「一橫折、兩斜掠鷹翅」的燕山箭記，而斷茬呈現重斧\n"
             "或軍用破甲弩從側面近距離硬生生削斷的整齊斜切痕。（目前僅能證明曾遭兵刃攔截，未見遺骸）\n");
    set_weight(110);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "lead_only");
}
