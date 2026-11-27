// d/city/south/market_special.c
// 六縣專材長街 (青河藥、烈礬銅硃砂、盤木木紙、鎮風弓、濁水金、重石鐵)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・六縣專材長街");
    set_long("這條青石長街兩側排列著全府六大縣城的特產專營鋪席，幡旗招展，客商如織。\n"
             "西首陳列著青河洗靈草與盤木韌桑符紙，東首叫賣著烈礬赤銅硃砂晶與鎮風硬弓，\n"
             "重石生鐵農具與濁水淘金重晶石亦在街頭掛牌結算，匯聚全府物資流通動脈。\n"
             "持通寶牙行經紀印牌者可當街撮合大宗行商簽單 (broker / 撮合)。\n"
             "向北直通中央青石廣場，往南通往大石堆棧，\n"
             "西面是氣勢恢弘的金石商會總堂，東面則是遠行車馬大院。\n");

    set_exits(([
        "north": "/d/city/center/square.c",
        "south": "/d/city/south/yard_material.c",
        "west":  "/d/city/south/shanghui_hq.c",
        "east":  "/d/city/south/caravan_yard.c",
    ]));

    set("is_outdoor", 1);
    set("has_shop", 1);
    set_touch("default", YEL "街邊貨棧疊放著散發松脂香的盤木原木與冰涼堅實的重玄生鐵錠。" NOR);
    set_smell("default", CYN "青河草藥、盤木新鋸木屑、馱獸草料與油墨銀票氣息在熱鬧市聲裡翻騰。" NOR);
    set_listen("default", HIY "算盤劈啪作響、牙人袖口暗語講價聲與貨車鐵輪碾過青石板的轟隆聲此起彼落。" NOR);

    mapping brk_rule = ([
        "require_qualification": "commerce",
        "action_label": "長街公開牙行簽單",
        "sp_cost": 10,
        "sensory_msg": HIY "你取出通寶牙行印牌在雙聯木契上按下火印，幾句老道市井行話便幫青河藥農與重石車行敲定了現銀交割價碼。" NOR,
        "train_stat": ([ "per": 15 ]),
        "exp_gain": 12
    ]);
    add_action_rule("broker", brk_rule);
    add_action_rule("撮合", brk_rule);

    spawn_npc("/clone/npc/market_special_buyer.c");
}

string query_long() {
    string res = ::query_long();
    object cd = find_object(CITY_D);
    if (cd && cd->query_granary_open()) {
        res += HIR "【平糶公告】府衙常平倉現正開倉七五折平糶！長街糧草與專材哄抬之勢已被暫時壓住。\n" NOR;
    }
    object ws = find_object(WORLD_STATE_D);
    if (ws && ws->query_caravan_status() == "blocked") {
        res += YEL "【商道警訊】外縣馱隊受阻尚未入關，幾家專營鋪席門口已豎起「存貨緊俏」的紅牌。\n" NOR;
    }
    return res;
}
