// clone/npc/zhao_hunter.c
// 老獵戶 趙老獵 - 林邊哨亭的老獵人

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙老獵");
    set_short(GRN "老獵戶" NOR " 趙老獵");
    set_long("一位身形瘦削精悍的老獵人，臉頰被大荒山風吹得如同枯乾老樹皮，雙目卻亮得\n"
             "宛如夜隼。他身著一件油光發亮的陳舊鹿皮背心，腰間懸著角刀與牛角藥壺，\n"
             "腿上留有幾道被兇獸利爪撕裂的可怖深疤。他正坐在門檻上專注地削製著竹箭。\n");
    set_id(({ "zhao", "hunter", "old hunter", "趙老獵", "老獵戶", "獵戶" }));

    set_level(22);
    set_stat("dex", 28);
    set_stat("per", 26);
    set_stat("str", 20);
    recalc_stats();

    add_response(({ "打獵", "狩獵", "hunt", "大荒" }), 
        "在大荒裡討生活，光靠死力氣走不遠！靈巧的身法是避劫的根本，敏銳的感知能救你的命。" +
        "一絲腐葉微動、一滴野獸腥臊，都分得出活路還是死局！");

    add_response(({ "陷阱", "trap", "機巧" }), 
        "林口我下了幾副竹刺吊套。去東面荒林走走，蹲下身調校竹刺彈簧與套鎖 (trap)，" +
        "把雙手指節和眼力磨得靈巧了，才算入了門！");

    add_response(({ "身世", "柴刀", "background" }), 
        "你從小在大荒林莽與猛獸尖牙下長大，手裡那把生鏽柴刀是你大伯當年進深山前留給你的。" +
        "刀背厚重，砍柴劈路、防狼斷喉全靠它，別弄丟了。");

    add_response(({ "野獸", "異動", "狼群" }), 
        "這幾日深山裡總有些古怪聲響，夜裡連狼群都不敢在斷魂嶺多啼。大荒深處有些不可說的古物，" +
        "莫要貪功冒進。");
}
