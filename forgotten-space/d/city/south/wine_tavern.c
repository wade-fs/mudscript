// d/city/south/wine_tavern.c
// 金石城南・老酒肆（Tier 1 民間市井酒館與跑商差價生態）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城南水陸・金石老酒肆");
    set_long("一間挑著褪色酒幌、門檻被無數車夫與小商販踩出深槽的臨街老酒肆。\n"
             "屋裡擺著八張沾滿油漬的老榆木八仙桌，櫃檯上排著大肚粗陶酒壇與幾盤五香茴香豆、鹵豬頭肉。\n"
             "這兒沒有雅間琴曲，全城南跑腿腳夫、外縣跑商最愛聚在此處喝兩文錢一碗的濁米酒吹牛打探行情。\n"
             "向南推開吱呀木門即回【官辦糧食市集】，往西拐入低矮牌坊則是【城南染坊窄巷】。\n");

    set_exits(([
        "south": "/d/city/south/grain_market.c",
        "west":  "/d/city/south/dye_alley.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);
    set("has_tavern", 1);

    set_touch("default", YEL "油亮黏手的老榆木八仙桌邊沿沾著酒漬，粗陶酒碗厚重冰涼。" NOR);
    set_smell("default", YEL "辛辣老白乾、八角茴香豆與炒花生殼的市井酒氣熱鬧地浮在屋裡。" NOR);
    set_listen("default", HIY "幾桌跑商吹牛喊價的豪笑聲、酒令聲與街外糧車轔轔駛過的聲音熱鬧交織。" NOR);

    spawn_npc("/clone/npc/folk/tavern_merchant.c");
}

void init() {
    ::init();
    add_action("do_drink_wine", "drink");
    add_action("do_drink_wine", "喝酒");
    add_action("do_trade_goods", "trade");
    add_action("do_trade_goods", "跑商");
}

int do_drink_wine(string arg) {
    object me = this_player();
    if (!me) return 0;
    write(YEL "你掏出五文錢叫了一壺濁米酒配一碟五香毛豆慢酌起來，渾身頓時暖烘烘地舒坦了不少。\n" NOR);
    me->add(VITAL_KEE, 15);
    me->add(VITAL_SP, 20);
    return 1;
}

int do_trade_goods(string arg) {
    object me = this_player();
    if (!me) return 0;
    object ws = load_object(WORLD_STATE_D);
    int profit = 35;
    string item_desc = "青河粗藥乾與重石石粉";
    if (ws) {
        mapping lf = ws->query_county_status("liefan");
        if (mapp(lf) && lf["price_pct"] > 120) {
            profit = 45 + (lf["price_pct"] - 100) / 10;
            item_desc = "明礬代用品與南市耐火粗土";
        }
    }
    write(HIG "你依著跑商陳大牙透露的六縣即時行情，用少量現錢短線倒手了一批「" + item_desc + "」，\n"
          "轉眼便在南市牙行平帳脫手，實打實掙了 " + sprintf("%d", profit) + " 文差價！\n" NOR);
    me->add_money(profit);
    me->add_exp(10);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "trade", "target": "goods" ]));
    }
    return 1;
}
