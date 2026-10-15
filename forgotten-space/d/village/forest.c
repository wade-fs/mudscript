// d/village/forest.c
// 黑石鋪・東面荊棘荒林與獸道 (身法敏捷、陷阱與追蹤狩獵區)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

int totem_discovered;

void create() {
    ::create();
    set_short("大荒外緣・荊棘林口");
    set_long("穿過聚落東邊的粗木鹿角柵欄，便是遮蔽天日的原始荒林。老藤如同巨蟒盤\n"
             "踞在粗壯古木之上，地面堆積著厚厚腐葉，散發著泥土與松脂的潮味。泥濘\n"
             "小徑上有幾道新鮮的野獸蹄印與抓痕，路旁倒伏的斷木下暗藏著獵戶布下的\n"
             "竹刺吊套陷阱 (trap)。循著泥濘獸道似乎可深入追蹤獸跡 (track)。\n"
             "遠處林海深處不時傳來沉悶的狼嚎與飛鳥驚起之聲。\n");

    set_exits(([
        "north":     "/d/village/hunter_cabin.c",
        "west":      "/d/village/hunter_cabin.c",
        "northwest": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);
    totem_discovered = 0;

    spawn_item("/clone/item/tainted_pelt.c");
}

void init() {
    ::init();
    add_action("do_inspect_trap", "trap");
    add_action("do_inspect_trap", "檢視陷阱");
    add_action("do_track", "track");
    add_action("do_track", "追蹤");
    add_action("do_commune_totem", "totem");
    add_action("do_commune_totem", "圖騰");
    add_action("do_commune_totem", "感應圖騰");
}

int do_inspect_trap(string arg) {
    object me = this_player();

    if (me->query(VITAL_SP) < 10) {
        write(HIR "你精力耗盡、手腕顫抖，無法專心進行精密機關調試。\n" NOR);
        return 1;
    }

    me->add(VITAL_SP, -10);
    write("你蹲下身，手掌在荊棘叢中精巧地撥開落葉，重新調校竹刺彈簧與吊繩套鎖...\n");

    // 鍛鍊靈巧 dex 與 感知 per
    me->add(STAT_DEX, 1);
    me->add(STAT_PER, 1);

    write(HIG "【在穿針引線般的機巧微調中，你的指節愈發靈敏，靈巧與感知提升！】\n" NOR);
    return 1;
}

int do_track(string arg) {
    object me = this_player();
    write("你壓低身形，指尖拂過濕潤的泥土與斷裂的草莖，目光如夜隼般搜尋獸道痕跡...\n");
    write(MAG "你在落葉掩蓋的泥坑邊發現了幾滴暗紫色的焦灼濁血，散發著令人心悸的地煞凶腥！\n" NOR);
    write("順著血痕撥開重重鐵線荊棘，在一株枯死巨榕的虯曲盤根下，赫然露出一尊倒插於泥沼中的【太古戰神獵獸圖騰玄柱】(totem)！\n");
    totem_discovered = 1;
    me->add(STAT_PER, 1);
    return 1;
}

int do_commune_totem(string arg) {
    object me = this_player();
    if (!totem_discovered) {
        write("密林遮蔽，你尚未發現深處的古老圖騰所在。（請先在林中仔細追蹤獸跡 track）\n");
        return 1;
    }

    if (me->query(VITAL_KEE) < 15) {
        write(HIR "你氣血衰竭，無法承受太古戰神圖騰的狂暴蠻荒意志！\n" NOR);
        return 1;
    }

    me->add(VITAL_KEE, -10);
    write("你伸出手指，緩緩按在圖騰柱上那尊手撕萬丈凶獸的荒古巨人石雕上...\n");
    write(HIR "「吼————！！」\n" NOR);
    write(HIR "一聲源自遠古蠻荒的凶獸咆哮在你的靈魂深處炸裂，體內每一滴血液如烈火烹油般狂暴沸騰！\n" NOR);
    write(HIW "【太古戰祖蠻荒血脈共鳴！你的筋骨骨骼爆響，雙目如電，戰鬥敏捷與肉身力道暴漲！】\n" NOR);

    me->add(STAT_STR, 1);
    me->add(STAT_DEX, 2);
    return 1;
}
