// d/village/stream.c
// 黑石鋪・南面幽霧水谷與碎石古溪 (自然採藥、瀑布淬體與史前斷碑)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit RUIN_ROOM_OB;

void create() {
    ::create();
    set_short("幽霧水谷・碎石溪灘");
    set_long("山澗自崖頂轟鳴墜落，在此匯聚成一汪清冽深潭。長年不散的濕冷水霧如白\n"
             "紗般籠罩著兩岸茂密的荊棘灌木。溪灘邊遍佈著被水流沖刷圓潤的大小卵石，\n"
             "幾塊平整的巨大石板斜臥在水邊，上面放著婦人搥洗衣物用的木槌與皂角，\n"
             "屠夫與老獵戶也常把柴刀在石邊擦磨。\n"
             "其中一塊半浸在水中的深青色石板 (stone)，表面生滿了厚厚青苔。\n"
             "瀑布深潭水氣澎湃，是聚落漢子跳入水中鍛鍊肉身耐力的天然之所。\n");

    set_exits(([
        "north": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);

    // 史前斷碑物象設定
    set_relic_target("stone");
    set_required_fate(1); // 只要有天命感應者皆能察覺
    set_required_int(2);
    set_inscription("太古天曆：逆行九宿，星軌反震，大清洗紀元始...");
}

void init() {
    ::init();
    add_action("do_waterfall", "waterfall");
    add_action("do_waterfall", "沖瀑布");
    add_action("do_waterfall", "淬體");
}

int do_waterfall(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 25) {
        write(HIR "你氣血虛弱、面無血色，若貿然跳入千鈞水流，恐有性命之憂！\n" NOR);
        return 1;
    }

    write(HIB "你褪去上衣，毅然縱身躍入深潭巨石之上，任由千鈞瀑布狠狠砸在脊背上！\n" NOR);
    write("冰冷刺骨的水流如同無數鐵錘重擊，你咬緊牙關，體內氣血劇烈奔湧抗衡！\n");

    me->add(VITAL_KEE, -20);
    me->add(STAT_CON, 1);

    write(HIG "【在極端水壓的沖刷淬鍊下，你的筋骨發出沉悶雷音，根骨微幅提升！】\n" NOR);
    return 1;
}
