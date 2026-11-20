// /clone/item/tiangong_anchor_blueprint.c
// 巨靈神機推進錨機延長線草圖暨脆化鐵屑封樣（第三卷 Ch.95, Ch.99）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("推進錨機延長線草圖", ({ "tiangong_anchor_blueprint", "anchor blueprint", "mechanism blueprint", "推進錨機延長線草圖", "錨機草圖" }));
    set_short(HIY "巨靈神機・推進錨機結構草圖" NOR);
    set_long("林鐵生與聞九於陣圖工房秘密合繪的羊皮分段草圖，旁附一紙包自傀儡內壁擦下的暗紫脆化鐵屑。\n"
             "受力延長線顯示巨靈神機原非人形戰鬥傀儡，而係裝載於超巨型船體或太古平台側面的「推進錨機或\n"
             "轉向關節」；其三尺粗黑色主軸微米螺紋竟與太古不融黑鐵齒輪完全同源，且地窟銅管已見脈衝脆化麻點。\n");
    set_weight(70);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
