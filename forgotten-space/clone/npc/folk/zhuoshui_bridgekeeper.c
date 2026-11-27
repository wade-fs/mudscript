// clone/npc/folk/zhuoshui_bridgekeeper.c
// 橋工老譚・濁水縣黑水老薑驅瘴攤（浮橋維護與防瘴草藥日常） (Ch.64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("橋工老譚");
    set_short(MAG "黑水橋工" NOR " 老譚");
    set_long("一位褲腳捲到膝蓋、小腿泛著水澤濕疹斑痕的五十多歲老橋工。\n"
             "他白天巡查三號浮橋木樁與鐵鏈，傍晚就在縣驛旁的草棚架起大銅鍋，賣些便宜的老薑防瘴湯給窮苦淘金客暖胃。\n");
    set_id(({ "zhuoshui_bridgekeeper", "old tan", "bridgekeeper", "橋工老譚", "老譚", "橋工" }));

    setup_archetype("C", 9);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "worker", "info" }));
    set("no_combat", 1);

    add_response(({ "瘴氣", "薑湯", "驅瘴", "浮橋", "差事" }),
        "老譚拿木勺攪動冒著辛辣白氣的大鍋嘆道：「水澤濕氣又重了，浮橋那邊幾個修鐵鏈的弟兄冷得直哆嗦！你幫我顧著火候把這鍋老薑花椒湯熬透（boil soup），再替我端一桶送到【黑水埗・三號木樁浮橋】交給修橋匠工（county_worker），回來給你算工錢！」");
    add_response(({ "淘金幫", "黑水埗", "濁水" }),
        "老譚朝南邊瞟了一眼壓低聲音：「浮橋底下水深不見底，那些拎著刀的亡命客只顧著淘金砂賣毒囊，誰管木樁爛沒爛？沒我們這幾個老骨頭天天釘釘子，整座水集早散架了。」");
}
