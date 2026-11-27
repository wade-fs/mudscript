// d/village/old_granary_yard.c
// 黑石鋪・村北舊晾穀場與牛棚（生活支翼：石碾、老黃牛與村務轉運點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・舊晾穀場與牛棚");
    set_long("這是一片鋪著夯實黃土與平整青石的開闊院落。院角搭著一間遮風避雨的茅草牛棚，\n"
             "一頭老黃牛正甩著尾巴反芻乾草，旁邊立著一具三人合抱的沉重花崗岩轉磨石碾 (mill)。\n"
             "秋收時全村都在此攤曬雜糧；平時則堆著備用擔架、草蓆與修補農車的榆木備料。\n"
             "向西進入【陳記雜糧鋪】，向南沿坡路走向【南山青石採石場】。\n");

    set_exits(([
        "west":  "/d/village/chen_grain_shop.c",
        "south": "/d/village/south_quarry.c",
    ]));

    set("is_outdoor", 1);
    set_touch("default", WHT "石碾磨盤被數十年推拉磨得光滑冰涼，牛棚乾草堆暖烘烘地透著草木氣。" NOR);
    set_smell("default", YEL "乾燥穀殼、曬透的黃土氣息與牛棚裡的稻草乾糞味混成濃濃山村鄉氣。" NOR);
    set_listen("default", CYN "老黃牛脖頸木鈴偶爾晃出「咯咚」一聲，伴隨遠處麻雀啄食地上碎穀的撲翅聲。" NOR);

    mapping mill_rule = ([
        "targets": ({ "mill", "stone", "石碾", "" }),
        "sp_cost": 10,
        "sensory_msg": YEL "你扶住木柄沉腰發力推動數百斤重的石碾，穀殼在磨齒咬合下發出清脆碾裂聲，金黃的去殼小米順著石槽簌簌滾落。" NOR,
        "train_stat": ([ "str": 10, "con": 8 ]),
        "exp_gain": 10
    ]);
    add_action_rule("grind", mill_rule);
    add_action_rule("推磨", mill_rule);
}
