// /clone/npc/xuan_ming.c
// 玄冥真人・太清雷符殿與刑律執法長老 (xuan_ming) - 升仙台 (Ch.92, Ch.96, Ch.101)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("玄冥真人");
    set_short(HIB "太清執法長老" NOR " 玄冥真人");
    set_long("面容瘦削冷峻的太清內門長老，雙目如鷹隼般陰鷙，掌管雷符殿與宗門刑律稽查。\n"
             "仔細看時，他寬大的紫金道袍左袖總有意無意地緊扣著，袖內微透一絲不自然的僵冷氣息。\n");
    set_id(({ "xuan_ming", "xuan ming", "xuanming", "玄冥真人", "玄冥", "執法長老" }));

    setup_archetype("G", 90);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "elder", "enforcer" }));
    set("home_room", "/d/sects/taiqing/ascension_platform.c");

    add_response(({ "坐化", "鶴鳴", "升仙台", "帷幕" }),
        "玄冥真人袖口雷紋微閃，眼神森寒地壓下聲調：「鶴鳴師兄功德圓滿、神歸太虛，乃我太清無上榮耀！\n"
        "外門經生領命站在三十步外石台記錄星氣餘韻即可，再多問一個字，執法殿雷鞭不容情！」");

    add_response(({ "晶化", "左臂", "稽查", "調核令" }),
        "玄冥真人臉色微微一沉，左腕不自覺往袍袖深處縮了半分：「凡塵小商棧若敢夾帶未報備之異地污垢與水銀廢漿，\n"
        "本座簽發私印協同公所查封便在情理之中——不遵規矩者，休怪雷法無眼。」");
}
