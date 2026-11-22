// clone/npc/folk/zhongshi_wheelwright.c
// 老車匠沈鐵頭・重石縣條石大車棚（八輪重車修軸與石工運輸日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老車匠沈鐵頭");
    set_short(WHT "重石車棚" NOR " 沈鐵頭");
    set_long("一位光著膀子露出古銅色筋骨、鼻樑沾著黑機油與厚石粉的老車匠。\n"
             "他半輩子都在重石縣修造能扛萬斤條石的八輪鐵軸大車，聽車軸轉動的吱呀聲就能知道木輻裂沒裂。\n");
    set_id(({ "zhongshi_wheelwright", "shen tietou", "wheelwright", "老車匠沈鐵頭", "沈鐵頭", "車匠" }));

    setup_archetype("B", 11);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "craft", "info" }));
    set("no_combat", 1);

    add_response(({ "大車", "修軸", "條石", "潤軸", "差事" }),
        "沈鐵頭敲了敲千斤重的鐵輪軸道：「天亮就有四車重玄條石要往北馳道發運！先幫我給這兩架空車的鐵軸上好牛油插銷（grease axle），再跑一趟【重石石作總坊】向那裡的老匠工（county_worker）報個車號，回來請你喝大碗麥茶！」");
    add_response(({ "馳道", "石工", "騾馬" }),
        "沈鐵頭指著西南官道方向嘆氣：「條石沉得連青石路面都能壓出半尺深槽，一輛車跑壞三副軸承是常事，苦的都是趕車的腳夫跟牲口。」");
}
