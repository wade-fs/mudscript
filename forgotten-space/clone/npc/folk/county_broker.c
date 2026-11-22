// clone/npc/folk/county_broker.c
// 六縣地方通寶分號朝奉／市集牙人（隨 WORLD_STATE_D 動態反映當地行情與匯兌狀態）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("地方朝奉");
    set_short(HIY "通寶牙行" NOR " 地方朝奉");
    set_long("一位端坐高櫃或貨棧帳桌後的精明老朝奉。\n"
             "手中紅木算盤打得飛快，專管各縣貨物過秤折算、抵押契單與飛錢兌付風聲。\n");
    set_id(({ "county_broker", "broker", "pawn_clerk", "clerk", "地方朝奉", "朝奉", "牙人" }));

    setup_archetype("H", 12);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "broker", "bank", "info" }));
    set("no_combat", 1);

    add_response(({ "典當", "匯兌", "銀票", "飛錢", "appraise" }),
        "朝奉推了推眼鏡：「通寶飛錢跨縣匯兌要看金石總號的臉色與四關押銀車隊動靜；現銅現銀倒是不論何時都能當場清點。可在這裡輸入『appraise』或『browse』查查底數。」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object env = environment(this_object());
    string cid = env ? env->query_county() : "";
    object ws = load_object(WORLD_STATE_D);
    mapping st = (ws && cid != "") ? ws->query_county_status(cid) : 0;

    if (topic == "行情" || topic == "物價" || topic == "專材" || topic == "市價") {
        if (mapp(st)) {
            tell_object(me, query_name() + sprintf(" 撥了幾顆算盤珠道：「%s眼下第 %d 階段（%s）：『%s』行情指數已經走到 %d%%。%s」\n",
                st["name"], st["stage"], st["stage_desc"], st["commodity"], st["price_pct"],
                st["price_pct"] >= 200 ? "上面若是再不放貨，民間小戶全得斷炊！" : "這價碼還算有商有量。"));
            return 1;
        }
    }

    return ::do_chat(me, topic);
}

void init() {
    ::init();
    add_action("do_county_cargo", "cargo");
    add_action("do_county_cargo", "跑商");
}

int do_county_cargo(string arg) {
    object me = this_player();
    if (!me) return 0;
    object env = environment(this_object());
    string cid = (env && env->query_county()) ? env->query_county() : "city";
    if (!cid || cid == "") cid = "city";
    object ws = load_object(WORLD_STATE_D);
    if (!ws) return 0;

    if (!arg || arg == "" || arg == "list" || arg == "行情") {
        write(ws->format_trade_board(cid));
        return 1;
    }
    string sub = "";
    string item_id = "";
    if (sscanf(arg, "%s %s", sub, item_id) == 2 && (sub == "buy" || sub == "買")) {
        mapping bres = ws->buy_trade_cargo(me, item_id, cid);
        write(bres["msg"] + "\n");
        return 1;
    }
    if (arg == "sell" || arg == "賣") {
        mapping sres = ws->sell_trade_cargo(me, cid);
        write(sres["msg"] + "\n");
        return 1;
    }
    write("用法：cargo list | cargo buy <貨號> | cargo sell\n");
    return 1;
}
