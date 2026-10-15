// clone/npc/zhang_butcher.c
// 屠夫 張屠戶 (張大山) - 黑石鋪的粗豪屠戶與獵戶夥伴

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("張屠戶");
    set_short(YEL "屠夫" NOR " 張屠戶");
    set_long("一位滿臉絡腮鬍、身材粗壯如鐵塔的黑石鋪屠夫。他腰間圍著一條油膩厚重的\n"
             "牛皮圍裙，手裡握著一把沉重的厚背剔骨砍刀。性情粗豪爽直，在大荒邊陲靠\n"
             "宰殺山獸與家畜為生，常與老獵戶趙老獵一同進山圍獵野豬。\n");
    set_id(({ "zhang", "butcher", "zhang tuhu", "張屠戶", "屠夫", "張大山" }));

    set_level(20);
    set_stat("str", 26);
    set_stat("con", 24);
    set_stat("dex", 16);
    recalc_stats();

    add_response(({ "磨刀", "砍刀", "刀", "sharpen", "blade" }), 
        "在大荒討生活，刀不利，遇上皮糙肉厚的獠牙山豬就是給畜生送菜！" +
        "老子得空就去南谷溪灘那塊大青石上磨刀 (sharpen blade)！");

    add_response(({ "野豬", "打獵", "趙老獵", "hunt" }), 
        "東面荒林深處最近邪門得很，昨夜狼群嚎得像哭喪。老趙頭昨兒還在哨亭加固鹿角陷阱，" +
        "等商隊過去，老子非跟他進山掏了野豬窩不可！");

    add_response(({ "商隊", "粗鹽", "金石城", "caravan" }), 
        "金石商會要是再被困在山口，聚落的粗鹽可就要見底了！沒鹽巴醃肉，" +
        "這些新鮮獸肉放上兩天全得臭爛在案板上！");

    add_response(({ "石板", "洗衣石", "斷碑", "stele" }), 
        "那塊大石板？老子從小就在上面磨刀，結實得像精鋼，幾百年水沖刀劈都不見裂紋，" +
        "婦人們也天天在上面捶洗粗布，好使得很！");

    add_response(({ "肉乾", "肉", "乾糧", "meat" }), 
        "想吃肉乾？我這有一條剛風乾的五香鹿肉乾，耐飢解乏，去深山走一天都不慌！");

    // 攜帶剔骨砍刀與肉乾
    object knife = clone_object("/clone/weapon/boning_knife.c");
    if (knife) {
        knife->move(this_object());
        equip(knife);
    }
    
    object meat = clone_object("/clone/item/dry_meat.c");
    if (meat) {
        meat->move(this_object());
    }
}
