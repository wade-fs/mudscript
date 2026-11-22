// clone/npc/folk/county_bailiff.c
// 六縣地方縣衙班頭／城門巡丁

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("地方巡檢卒");
    set_short(CYN "縣防" NOR " 地方巡檢卒");
    set_long("一名身著褪色青布號衣、腰懸鐵尺與木牌的縣城巡檢。\n"
             "他守在縣衙公堂或關卡門樓旁，盤查過往車馬路引，也抱怨上頭文卷越積越厚。\n");
    set_id(({ "county_bailiff", "bailiff", "guard", "patrol", "地方巡檢卒", "巡檢卒", "班頭", "衙役" }));

    setup_archetype("E", 10);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));

    add_response(({ "治安", "盤查", "路引", "公堂" }),
        "巡檢卒按了按鐵尺：「如今六縣專材緊俏，流民與走私客多得緊！進金石大城記得備妥保書路引，在這外縣倒只要別鬧事傷人，官府一般不為難平民。」");
}
