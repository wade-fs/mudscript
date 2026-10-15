// d/village/forest.c
// 黑石鋪・東面荊棘荒林與獸道 (身法敏捷、陷阱與追蹤狩獵區)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("大荒外緣・荊棘林口");
    set_long("穿過聚落東邊的粗木鹿角柵欄，便是遮蔽天日的原始荒林。老藤如同巨蟒盤\n"
             "踞在粗壯古木之上，地面堆積著厚厚腐葉，散發著泥土與松脂的潮味。泥濘\n"
             "小徑上有幾道新鮮的野獸蹄印與抓痕，路旁倒伏的斷木下暗藏著獵戶布下的\n"
             "竹刺吊套陷阱。遠處林海深處不時傳來沉悶的狼嚎與飛鳥驚起之聲。\n");

    set_exits(([
        "west": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_inspect_trap", "trap");
    add_action("do_inspect_trap", "檢視陷阱");
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
