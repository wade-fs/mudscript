// d/city/center/inn_main.c
// 金石大客棧 (三層雕樑石樓)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・金石大客棧");
    set_long("這座三層雕樑畫棟的青石大客棧是府城規格最高、聲名最盛的落腳之處。\n"
             "一樓大堂寬敞明亮，四面擺滿了酸枝木八仙桌，往來巨賈、世家子弟與各派修士杯盤狼藉。\n"
             "大掌櫃錢不換笑口常開地穿梭招呼，眼線遍佈全城市井。\n"
             "向南邁出大門可直達中央青石廣場，往東可步入官辦遞鋪驛館。\n");

    set_exits(([
        "south": "/d/city/center/square.c",
        "out":   "/d/city/center/square.c",
        "east":  "/d/city/center/post_station.c",
        "west":  "/d/city/center/granary.c",
        "north": "/d/city/center/tea_alley.c",
    ]));

    set("is_outdoor", 0);
    set("has_tavern", 1);

    set_touch("default", YEL "酸枝木八仙桌打磨得溫潤滑亮，桌邊擺著溫熱潔淨的青花細瓷茶盞。" NOR);
    set_smell("default", HIY "上等花雕酒香、清蒸河鮮、燻肉與大堂裡名貴檀香交織出內城的富貴氣息。" NOR);
    set_listen("default", HIY "席間權貴子弟與巨賈舉杯寒暄的笑語聲、堂倌唱菜聲與絲竹餘韻熱鬧不俗。" NOR);

    spawn_npc("/clone/npc/inn_main_qianbuhuan.c");
}

void init() {
    ::init();
    add_action("do_inn_sleep", "lodge");
    add_action("do_inn_sleep", "投宿");
    add_action("do_inn_feast", "feast");
    add_action("do_inn_feast", "用膳");
}

int do_inn_sleep(string arg) {
    object me = this_player();
    if (!me) return 0;
    object city_d = load_object(CITY_D);
    mapping tier = city_d ? city_d->query_social_tier(me) : ([]);
    mapping res = mapp(tier) ? tier["resources"] : ([]);
    if (!mapp(res) || !res["inner_inn_allowed"]) {
        write(HIR "錢不換皮笑肉不笑地合上帳簿：「抱歉客官，金石大客棧內院上房按府衙律例須核驗保書或正式立籍，無籍散工請回南關外矮巷罷！」\n" NOR);
        return 1;
    }
    int cost = res["inner_inn_cost"] ? res["inner_inn_cost"] : 50;
    if (me->query("money") < cost) {
        write(sprintf(YEL "掌櫃撥了撥算盤笑道：「上房清靜一宿承惠 %d 文，沒帶足銀錢可上樓不得。」\n" NOR, cost));
        return 1;
    }
    me->add_money(-cost);
    me->add(VITAL_KEE, 50);
    me->add(VITAL_SEN, 35);
    me->add(VITAL_SP, 45);
    write(sprintf(HIY "你付了 %d 文房資入住三樓檀香清靜雅間，飽睡一宿後精神百倍。（氣血 +50、神識 +35、精力 +45）\n" NOR, cost));
    return 1;
}

int do_inn_feast(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (me->query("money") < 30) {
        write(YEL "堂倌瞄了你兩眼：「這兒一桌花雕河鮮雅席要三十文，沒這盤纏還是南市老酒肆喝兩文濁酒實惠。」\n" NOR);
        return 1;
    }
    me->add_money(-30);
    me->add(VITAL_KEE, 40);
    me->add(VITAL_SP, 40);
    write(HIY "你花三十文要了一桌青河鮮魚配陳年花雕，吃得齒頰留香、氣力充沛。（氣血 +40、精力 +40）\n" NOR);
    return 1;
}
