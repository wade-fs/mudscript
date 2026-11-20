// /clone/npc/lei_lie.c
// 雷烈・八荒黑山營獨臂老將 (lei_lie) - 黑山煞血營 (Ch.87)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("雷烈");
    set_short(HIY "黑山營獨臂老將" NOR " 雷烈");
    set_long("五十歲上下的鐵血宿將，肩背厚重如城牆，左臂卻齊肘而斷，腰間懸一柄寬厚黑鞘狂刀。\n"
             "他是燕隼大伯燕山的當年舊識，為人剛直重義，卻亦背負著五年前軍務舊案的隱痛。\n");
    set_id(({ "lei_lie", "lei lie", "leilie", "雷烈", "老將", "狂刀" }));

    setup_archetype("K", 88);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "commander", "quest", "mentor" }));
    set("home_room", "/d/sects/bahuang/black_mountain_camp.c");

    add_response(({ "入營", "腰牌", "八方武館", "霸山" }),
        "雷烈虎目如電地打量著來者左肩壓腕的扣弓習慣，神色微震：「霸山那老小子推薦來的人，果然沒丟八方武館的臉！\n"
        "拿好這塊黑山營鐵腰牌，明日卯時點卯領甲。記住老子的話——上陣殺敵，別光顧著替旁人賣命，先把命留穩！」");

    add_response(({ "燕山", "走山隊", "箭記", "藥丸" }),
        "雷烈沉默兩息，沉聲壓低了嗓音：「老夫確實認得那手壓腕扣弦與收箭小動作……五年前的事，如今還沒到翻開底牌的時候。\n"
        "營裡頭些許流言別輕信，先在黑山營立穩腳跟，查得實據再來尋我。」");
}
