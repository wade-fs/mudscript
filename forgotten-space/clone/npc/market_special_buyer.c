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
        "程通四海展開行情摺子如數家珍：「青河靈草、烈礬銅砂、盤木韌紙、鎮風硬弓、濁水毒囊、重石玄鐵——六縣產物只要有一處道路受阻，長街上的牌價立時翻倍！客官若要詳查，不妨鍵入『list』或『行情』！」");

    add_response(({ "鐵木", "重石", "穿山寨", "抽減" }),
        "程通四海壓低聲音：「穿山寨少工頭杜小山的血指拓本？！嘶……商會內堂在塌方前兩個月強令抽走三成沉陰鐵木支護……這根本就是蓄意屠殺！」");
}

string render_market_board() {
    object ws_d = find_object(WORLD_STATE_D);
    if (!ws_d) ws_d = load_object(WORLD_STATE_D);
    object city_d = find_object(CITY_D);
    if (!city_d) city_d = load_object(CITY_D);

    int granary_factor = city_d ? city_d->query_granary_price_pct() : 100;
    string res = "\n" HIY "┏━━━━━━━━━━━━━━━ 金石府都城・六縣專材即時行情牌價 ━━━━━━━━━━━━━━━┓" NOR "\n";
    if (granary_factor < 100) {
        res += HIR "  【特別通告】金石常平倉緊急平糶中！全府大宗專材獲府衙七五折平抑配額！" NOR "\n";
    }

    mapping commodities = ([
        "qinghe":    ([ "name": "青河洗靈草", "county": "青河縣", "base": 40 ]),
        "liefan":    ([ "name": "烈礬特級耐火泥", "county": "烈礬縣", "base": 60 ]),
        "panmu":     ([ "name": "盤木紅杉原木", "county": "盤木縣", "base": 50 ]),
        "zhenfeng":  ([ "name": "鎮風風蝕石英", "county": "鎮風縣", "base": 45 ]),
        "zhuoshui":  ([ "name": "濁水腐骨毒囊", "county": "濁水縣", "base": 80 ]),
        "zhongshi":  ([ "name": "重石重玄鐵錠", "county": "重石縣", "base": 55 ])
    ]);

    foreach (string cid in keys(commodities)) {
        mapping item = commodities[cid];
        int pct = 100;
        int stage = 1;
        if (ws_d) {
            mapping st = ws_d->query_county_status(cid);
            if (st) {
                pct = st["price_pct"];
                stage = st["stage"];
            }
        }
        int cur_price = (item["base"] * pct / 100) * granary_factor / 100;
        string status_str = (pct >= 180) ? HIR "【暴漲告急】" NOR : (pct >= 130) ? YEL "【緊俏上浮】" NOR : HIG "【平穩充裕】" NOR;
        res += sprintf("  %-16s (產地: %-6s)  牌價: %3d 文  指數: %3d%%  階段: 第%d階段  %s\n",
            item["name"], item["county"], cur_price, pct, stage, status_str);
    }
    res += HIY "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" NOR "\n";
    return res;
}

void init() {
    ::init();
    add_action("do_list", "list");
    add_action("do_list", "行情");
}

int do_list(string arg) {
    write(render_market_board());
    return 1;
}
