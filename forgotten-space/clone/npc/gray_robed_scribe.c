// /clone/npc/gray_robed_scribe.c
// 無標記灰袍經生・私盟秘密採辦書手 (gray_robed_scribe) - 鬼市暗巷與萬寶閣後門交界 (Ch.96, Ch.98)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("灰袍經生");
    set_short(WHT "無標記灰袍經生" NOR);
    set_long("身穿一件洗得發白、沒有任何三宗標記的灰布棉襖，袖口隱約露出一截帶雷紋的銅印邊角。\n"
             "此人每逢初七與廿二便會出現在雲海票號以三百張零散無標記小額飛錢換取靈石，行事極為鬼祟。\n");
    set_id(({ "gray_robed_scribe", "gray scribe", "scribe", "經生", "灰袍經生", "無標記經生" }));

    setup_archetype("G", 74);
    set("class", "dao");
    set("faction", "private_alliance");
    set("roles", ({ "courier", "agent" }));
    set("home_room", "/d/yunjin/wanbao_back_alley.c");

    add_response(({ "靈石", "飛錢", "黑鐵箱", "太清" }),
        "灰袍經生猛地壓低斗篷帽簷，警覺地後退半步：「休要胡亂打聽公所採買！只是尋常冬炭換帳罷了……」\n"
        "（提示：若聞『通寶總號稽核跨州飛錢餘額』風聲，此人必定心虛驚慌，可於此處指令：rumor audit）");
}
