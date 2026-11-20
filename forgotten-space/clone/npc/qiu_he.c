// /clone/npc/qiu_he.c
// 邱禾・泥途商棧管事 (qiu_he) - 泥途商棧 (Ch.84, Ch.85, Ch.90)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("邱禾");
    set_short(HIW "泥途商棧管事" NOR " 邱禾");
    set_long("三十二歲的結實婦人，出身北境雪橇車隊壓車副手，熟稔倉儲盤點、貨損核算與山道時程。\n"
             "她腰間別著一柄雪鏟與銅算尺，凡事講究將工錢、傷亡責任與耗損比例白紙黑字寫進短契。\n");
    set_id(({ "qiu_he", "qiu he", "qiuhe", "邱禾", "管事" }));

    setup_archetype("D", 40);
    set("class", "mortal");
    set("faction", "mudway_store");
    set("roles", ({ "steward", "logistics" }));
    set("home_room", "/d/yunjin/mudway_store.c");

    add_response(({ "短契", "入夥", "工錢" }),
        "邱禾把寫好的短契紙拍在榆木桌上：「每月兩百文底錢外加千分之三抽成，非我偷懶造成之雪天貨損不能扣工錢。\n"
        "先簽三個月試手，若商棧發不出餉，我扛走這兩張榆木桌抵債；只要你照實算帳，這棧房的炭袋藥箱我替你盯得死死的。」");

    add_response(({ "帳簿", "朔望", "暗語", "歳貢" }),
        "邱禾翻開公開雙聯帳簿，壓低嗓音道：「太清扣兩成風雪耗損、八荒壓一成肉乾價、天工扣廢鐵額、丹鼎延工分……\n"
        "每逢初一十五送貨上山，貨單左下角的炭筆斜度與麻繩三道單結我都按東家吩咐打得嚴絲合縫，半點破綻不留。」");
}
