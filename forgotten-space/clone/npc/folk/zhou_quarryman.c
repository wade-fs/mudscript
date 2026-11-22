// clone/npc/folk/zhou_quarryman.c
// 石匠老周・南山青石採石場（黑石鋪礦難後自救採石線人物）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("石匠老周");
    set_short(WHT "南山採石" NOR " 石匠老周");
    set_long("一位虎背熊腰、額頭纏著粗布吸汗帶的老石匠，皮膚被石粉抹得灰白。\n"
             "北崖古礦塌方後，他領著幾名無事可幹的礦工來南山露天採青石條，給村裡修補牆垣與水渠。\n");
    set_id(({ "zhou_quarryman", "mason zhou", "lao zhou", "石匠老周", "老周", "石匠" }));

    setup_archetype("C", 11);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));

    add_response(({ "採石", "青石", "修牆", "quarry" }),
        "老周掄起鐵釺叮噹敲進石縫道：「北邊那座鬼礦坑咱不敢再隨便下去了！南山這片青石雖硬，起碼見得著天日，敲出來的石條既能墊街口，也能賣給過路修橋的！」");
    add_response(({ "備炭", "冬天", "取暖", "凍裂", "charcoal" }),
        "老周伸出龜裂流血的大手嘆氣：「山谷裡石風刺骨，採石場這口舊鐵爐快沒木炭燒了！誰要是能去西嶺伐木坡燒兩筐好木炭 (burn charcoal) 送來暖爐，我拿一塊磨刀好青石謝他！」");
}
