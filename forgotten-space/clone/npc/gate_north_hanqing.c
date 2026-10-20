// clone/npc/gate_north_hanqing.c
// 韓清・城門典吏 (gate_north_hanqing) - 金石北關城門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("韓清");
    set_short(CYN "北關城門典吏" NOR " 韓清");
    set_long("一位手持關防名冊、神色冷峻嚴謹的青袍典吏。\n"
             "他端坐於金石北關官道門洞旁的簽押案後，專司審查外荒商旅路引、\n"
             "盤查未註冊火器與走私大荒獸皮，對出入北塞之人秋毫必察。\n");
    set_id(({ "gate_north_hanqing", "hanqing", "han qing", "north clerk", "韓清", "城門典吏", "典吏" }));

    setup_archetype("A", 18);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "gatekeeper", "tax", "info" }));
    set("rules", ([ "tax_commoner": 2, "tax_no_papers": 10, "exempt": "six_county_pass" ]));
    set("schedule", "day");

    add_response(({ "外荒情報", "鎮風", "北關", "煞潮" }),
        "韓清翻閱關防邸報，沉聲道：「鎮風縣天風要塞三日前傳來急報，北山罡風夾帶地煞異動，往來行商切莫在荒原夜宿。」");

    add_response(({ "軍械盤查", "稅則", "入城", "逃民" }),
        "韓清按冊道：「依金石府律：持六縣路引者免徵茶湯錢；一般良民入關繳二文；無文牒流民需繳十文工本費，限三日內在城中覓得保人或考取道牒，嚴禁夾帶私造火器與染煞獸皮！」");
}
