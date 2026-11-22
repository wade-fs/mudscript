// /clone/npc/salt_market_broker.c
// 殘晶黑市牙人（萬物外環跑腿收鹽小吏）(Ch.129)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("外環牙人");
    set_short(YEL "殘晶黑市" NOR " 外環牙人");
    set_long("一名穿青金邊短襖、腰間掛著外環臨時銅牌的瘦削小吏，手裡握著鐵尺與交割木板，\n"
             "神色冷漠地驗收石堡鹽工挑來的粗鹽晶，背後停著裝滿半截報廢石匣的鐵板車。\n");
    set_id(({ "salt_market_broker", "market broker", "broker", "外環牙人", "牙人" }));

    setup_archetype("H", 60);
    set("class", "mortal");
    set("faction", "wanwu_outer");
    set("roles", ({ "merchant", "quest" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/edge/stardust_salt_flats.c");

    add_response(({ "鹽晶", "預扣", "折抵", "晶柱" }),
        "牙人敲著鐵尺冷哼：「別怪老子心狠！今兒起每批粗鹽一律預扣三成『戰備折抵』，\n"
        "三十斤粗鹽才換一柱報廢蓄能石匣！上頭稽核司陳大人這陣子急著屯料修補外環，愛換不換！」");

    add_response(({ "鐵牌", "九號", "方舟" }),
        "牙人瞥了一眼桌角墊腳的鏽鐵片：「那破鐵片？荒漠溝裡刨出來的九號補給營廢鐵，\n"
        "除了你們這群無名無冊的野人拿來墊桌腳，主機城才懶得理會。」");
}
