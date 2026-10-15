// d/village/altar.c
// 黑石鋪・西面迎風孤岩與荒廢道壇 (觀星望氣、心神吐納與法道啟蒙)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("迎風孤岩・荒廢道壇");
    set_long("順著陡峭狹窄的石梯登上聚落西面突兀危岩，視野豁然開朗。此處高出地面\n"
             "數十丈，山巔罡風呼嘯凜冽，將衣袍吹得獵獵作響。崖頂中央坐落著半座坍\n"
             "塌的白石法壇，壇面雕刻著早已辨認不清的陰陽卦紋，一株盤根錯節的老松\n"
             "迎風挺立在萬丈深淵之畔。遠離了凡間市井牲畜的煙火騷氣，唯有蒼茫天宇\n"
             "與流轉星漢相伴。\n");

    set_exits(([
        "east": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_meditate", "meditate");
    add_action("do_meditate", "打坐");
    add_action("do_meditate", "觀想");
}

int do_meditate(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 10) {
        write(HIR "你肉身極度疲憊，無法抵禦山巔刺骨寒風，靜不下心來打坐。\n" NOR);
        return 1;
    }

    write(HIC "你在白石殘壇上盤膝而坐，微闔雙目，迎著呼嘯山風緩緩吐納...\n" NOR);
    write("四周喧囂漸遠，你的心神彷彿化作一縷微風，感應著蒼穹之上的日月星光運轉。\n");

    me->add(VITAL_KEE, -5);
    me->add(VITAL_SEN, 15);
    me->add(STAT_SPI, 1);

    write(HIG "【靈台漸入空明，神識得到滋養，你的靈性微幅提升！】\n" NOR);
    return 1;
}
