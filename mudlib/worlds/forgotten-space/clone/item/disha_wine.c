// clone/item/disha_wine.c
// 【雄黃辟煞烈血酒】 (小說第14章瘋郎中葛半仙秘製)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("雄黃辟煞烈血酒");
    set_short(HIR "【雄黃辟煞烈血酒】" NOR);
    set_long("一口以粗陶小酒罈封裝的滾燙烈酒。酒液泛著赤紅如血的光澤，散發著\n"
             "雄黃、天南星與百年野山參的辛辣藥香。瘋郎中葛半仙以秘法釀造，\n"
             "飲下 (drink wine) 可壯旺純陽氣血、通達十二正經，短時間內抵禦地煞毒瘴！\n");
    set_id(({ "disha wine", "wine", "烈酒", "辟煞酒", "雄黃酒", "藥酒" }));

    set_weight(800);
    set_value(400);
    set("doses", 3);
}

void init() {
    ::init();
    add_action("do_drink", "drink");
    add_action("do_drink", "喝");
    add_action("do_drink", "飲");
}

int do_drink(string arg) {
    if (!arg || (arg != "wine" && arg != "烈酒" && arg != "辟煞酒" && arg != "雄黃酒")) return 0;
    
    object me = this_player();
    int doses = query("doses");
    if (doses <= 0) {
        write("酒壇裡空空如也，已經一滴不剩了。\n");
        return 1;
    }

    set("doses", doses - 1);
    write(HIR "\n你拔開塞子，咕咚灌下一大口【雄黃辟煞烈血酒】！\n" NOR);
    write(YEL "一股烈火般的辛辣暖流瞬間順著咽喉轟入丹田，四肢百骸氣血如沸，\n" +
              "周身毛孔閉鎖，神識一片通明，地煞陰霾被這股純陽血氣硬生生逼退開來！\n" NOR);
    write(HIG "【你的氣血 +50，精力 +50，神識 +30！】\n\n" NOR);

    me->add(VITAL_KEE, 50);
    me->add(VITAL_SP, 50);
    me->add(VITAL_SEN, 30);
    me->set_temp("anti_disha_buff", 1);

    if (query("doses") <= 0) {
        write("這壇藥酒已被你飲盡，空罈子隨手丟在了地上。\n");
        destruct(this_object());
    }
    return 1;
}
