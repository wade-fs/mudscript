// /clone/npc/tao_sheng.c
// 陶生・廢丹崖回收工頭 (tao_sheng) - 廢丹崖 (Ch.97)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陶生");
    set_short(YEL "廢丹崖回收工頭" NOR " 陶生");
    set_long("四十四歲上下的沉默漢子，雙眼被濃酸煙氣燻得通紅，粗糙手腕佈滿深褐色化學灼斑，\n"
             "右手缺了無名指與小指。他是廢丹崖唯一常駐工頭，雖不懂高深丹理卻記得每一爐廢渣的泥印與去向。\n");
    set_id(({ "tao_sheng", "tao sheng", "taosheng", "tao_shifu", "陶生", "陶師傅", "工頭" }));

    setup_archetype("D", 42);
    set("class", "mortal");
    set("faction", "danding");
    set("roles", ({ "worker", "witness", "quest" }));
    set("home_room", "/d/sects/danding/discarded_pill_cliff.c");

    add_response(({ "封存", "紫泥", "藥渣", "鐵罐", "丙字區" }),
        "陶生看你戴著泡過甘草水的棉口罩與厚鹿皮手套，又肯順手幫忙扶穩沉重木桶，語氣這才緩了三分：\n"
        "「丙字區正常藥渣走明帳，都是『青泥封口』；唯獨每逢十來半月半夜三更，會有不掛牌子的雜役扛著鐵桶\n"
        "倒『紫泥封口』的硬渣——那玩意能把厚木桶燒穿冒黑煙！我去年就攔過兩鐵罐藏在石棚後深溝，\n"
        "裡頭還有一具心肝爛成黑蜂窩的試藥白猿屍首！我去醫理院報備反被扣了三個月工錢……\n"
        "要開盒檢視就就地取證（指令：dissect ape），我這雙缺指的手敢替你按印作證。」");

    add_response(({ "白猿", "腐酸霧", "烈礬泥" }),
        "陶生指著崖下黑褐廢水：「吸兩口這『腐酸霧』氣管得爛半個月，連野鳥都不往崖底飛。當年管事\n"
        "拿『烈礬泥』壓死坑口不准我提白猿的事——我還當那畜生真是得罪了老天。」");
}
