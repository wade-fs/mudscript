// clone/npc/caravan_yard_biaotou.c
// 駱鎮遠・車馬行總鏢頭 (caravan_yard_biaotou) - 遠行車馬大院（緩衝路徑 B）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("駱鎮遠");
    set_short(HIR "車馬行總鏢頭" NOR " 駱鎮遠");
    set_long("一位滿臉絡腮鬍、腰插雙柄短鐵戟的老江湖鏢頭。\n"
             "他走遍金石府六縣官道與山嶺險隘，專為入城無依的健壯流民簽立苦力契據，發放【車馬行短褐腰牌】。\n");
    set_id(({ "caravan_yard_biaotou", "caravan_yard_trailmaster", "luo zhenyuan", "biaotou", "trailmaster", "駱鎮遠", "總鏢頭", "鏢頭", "老趟子手" }));

    setup_archetype("C", 28);
    set("class", "wu_initiate");
    set("faction", "shanghui");
    set("roles", ({ "quest_giver", "service", "info" }));
    set("rules", ([ "daily_wage_copper": 10, "buffer_days": 7 ]));
    set("schedule", "24h");

    add_response(({ "苦力", "搬運", "短褐", "腰牌", "緩衝", "身分", "護送" }),
        "駱鎮遠拍了拍胸膛道：「好手好腳的漢子怕什麼三日通牒！在老子這簽下苦力契據 (ask biaotou about 契約 / work)，日支十文粗食錢，發你【車馬行短褐腰牌】，保你七天合法居留！」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "契約, 苦力, 搬運, 腰牌, work")) {
        if (!present("caravan token", me) && !present("badge", me)) {
            object token = clone_object("/clone/item/caravan_token.c");
            if (token) {
                token->move(me);
                tell_object(me, HIG "【駱鎮遠爽快大笑，遞給你一塊《車馬行短褐腰牌》（+7天合法期）！】\n" NOR);
                return 1;
            }
        } else {
            tell_object(me, YEL "駱鎮遠道：「腰牌已經在你身上了，有空多去初堆棧和貨棧出力氣！」\n" NOR);
            return 1;
        }
    }
    return 0;
}
