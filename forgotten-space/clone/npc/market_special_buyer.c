// clone/npc/market_special_buyer.c
// 程通四海・六縣採辦總牙人 (market_special_buyer) - 六縣專材長街

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("程通四海");
    set_short(HIY "六縣採辦總牙人" NOR " 程通四海");
    set_long("一位頭戴八方員外帽、袖中藏著六縣物價行情摺子的精明行商代表。\n"
             "他協調專材長街上青河藥、烈礬銅與硃砂、盤木鐵力木與符紙、鎮風強弓與石英、濁水金砂與毒囊、重石條石與鐵錠的六縣專櫃採辦。\n");
    set_id(({ "market_special_buyer", "market_special_qinghe_buyer", "market_special_liefan_buyer", "market_special_panmu_buyer", "market_special_zhenfeng_buyer", "market_special_zhuoshui_buyer", "market_special_zhongshi_buyer", "cheng tongsihai", "buyer", "程通四海", "採辦商賈", "採辦總牙人" }));

    setup_archetype("H", 18);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "shop", "broker", "info" }));
    set("schedule", "day");

    add_response(({ "六縣", "專材", "行情", "物價", "採辦" }),
        "程通四海展開行情摺子如數家珍：「青河靈草、烈礬銅砂、盤木韌紙、鎮風硬弓、濁水毒囊、重石玄鐵——六縣產物只要有一處道路受阻，長街上的牌價立時翻倍！」");
}
