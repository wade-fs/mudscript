// clone/npc/folk/tavern_merchant.c
// 跑商陳大牙・金石城南老酒肆（酒館吹牛與 WORLD_STATE_D 六縣物價差價跑商）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("跑商陳大牙");
    set_short(HIY "南市跑商" NOR " 陳大牙");
    set_long("一位留著山羊鬍、袖筒裡常年揣著半本油漬小帳簿與三枚假銀角子的走南闖北跑商。\n"
             "他最愛坐在老酒肆靠門的條凳上邊啃茴香豆邊吹噓六縣行情，真話七分假話三分，懂門道的人卻總能從他嘴裡套出差價。\n");
    set_id(({ "tavern_merchant", "chen daya", "merchant", "跑商陳大牙", "陳大牙", "跑商" }));

    setup_archetype("H", 10);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "merchant", "info" }));
    set("no_combat", 1);

    add_response(({ "吹牛", "差價", "行商", "門道" }),
        "陳大牙壓低聲音敲著酒桌道：「別看府城官市價死板，六縣物產一日三變！你去南市糧食集看看實價（或打聽『糧價』），再回來酒肆拿幾十文做筆小倒買（trade goods），夠你吃三頓醬牛肉啦！」");
    add_response(({ "酒肆", "喝酒", "下酒菜" }),
        "陳大牙哈哈大笑：「老張這兒一壺水酒配一碟五香毛豆才五文錢，上回那幫穿青衫的宗門公子還嫌粗俗，懂什麼叫江湖煙火！」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object ws = load_object(WORLD_STATE_D);

    if (topic == "行情" || topic == "六縣" || topic == "物價") {
        if (ws) {
            mapping zf = ws->query_county_status("zhenfeng");
            mapping qh = ws->query_county_status("qinghe");
            mapping lf = ws->query_county_status("liefan");
            string msg = "陳大牙抿了口老白乾壓低聲音道：「聽好這可是花錢都買不到的活風聲——\n";
            if (mapp(lf)) msg += sprintf("  ・烈礬縣(%s)：目前指數 %d%% (%s)\n", lf["commodity"], lf["price_pct"], lf["stage_desc"]);
            if (mapp(qh)) msg += sprintf("  ・青河縣(%s)：目前指數 %d%% (%s)\n", qh["commodity"], qh["price_pct"], qh["stage_desc"]);
            if (mapp(zf)) msg += sprintf("  ・鎮風縣(%s)：目前指數 %d%% (%s)\n", zf["commodity"], zf["price_pct"], zf["stage_desc"]);
            msg += "  想小賺一筆，先去城南糧集對對實價，再回來喊聲『trade goods』！」\n";
            tell_object(me, msg);
            return 1;
        }
    }
    return ::do_chat(me, topic);
}
