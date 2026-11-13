// clone/item/zhongshi_timber_order.c
// 重石抽減鐵木指令拓本 - 卷二第三幕核心證言物證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("重石抽減鐵木指令拓本", ({ "zhongshi timber order", "zhongshi_timber_order", "tuoben", "指令拓本", "鐵木指令" }));
    set_short(WHT "【重石抽減鐵木指令拓本】" NOR);
    set_long("自重石縣穿山寨採石場少工頭杜小山秘密帳簿上拓印而下的血指拓本。\n"
             "記載黑石鋪北崖礦難發生前整整兩個月，金石商會總堂內堂持最高長老令，以西南防汛調配為藉口，\n"
             "強令穿山寨工頭暗中抽走撥給北崖古礦的三成「百年老沉陰鐵木支護大梁」，更調包為中空爛桐木，\n"
             "直接誘發地煞爆發與塌方慘案，為定罪商會內堂故意製造礦難之強間接佐證（corroborative）。\n");
    set_weight(50);
    set_value(700);
    set("is_evidence", 1);
    set("evidence_type", "zhongshi_timber");
    set("evidence_level", "corroborative");
}
