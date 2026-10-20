// d/city/south/caravan_yard.c
// 遠行車馬大院 (招募鏢師、三日通牒緩衝路徑 B)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石商會・遠行車馬大院");
    set_long("這座寬廣的車馬大院內停駐著數十輛加固生鐵轅的大型貨運馬車。\n"
             "鏢局老趟子手與商隊大掌櫃正聚在木桌前研討跨縣商道防匪事宜。\n"
             "流民初入都城若無度牒，可在此簽署苦力契據 (ask biaotou about 搬運/苦力)，\n"
             "領取【車馬行短褐腰牌】獲得七天合法居留資格。\n"
             "向西走出大院門樓，便回到了六縣專材長街。\n");

    set_exits(([
        "west":  "/d/city/south/market_special.c",
        "south": "/d/city/south/warehouse_shang.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/caravan_yard_biaotou.c");
    spawn_npc("/clone/npc/caravan_yard_manager.c");
}

void init() {
    ::init();
    add_action("do_work", "work");
    add_action("do_work", "搬運");
    add_action("do_work", "苦力");
}

int do_work(string arg) {
    object me = this_player();
    if (!present("caravan token", me) && !present("badge", me)) {
        object token = clone_object("/clone/item/caravan_token.c");
        if (token) {
            token->move(me);
            tell_object(me, HIG "【鏢頭拍了拍你的肩膀，遞給你一塊《車馬行短褐腰牌》以作合法苦力身分憑證！】\n" NOR);
            return 1;
        }
    } else {
        tell_object(me, YEL "鏢頭笑道：「腰牌在身，只管勤勉搬運大石大木，少不了你的工錢粗食。」\n" NOR);
        return 1;
    }
    return 0;
}
