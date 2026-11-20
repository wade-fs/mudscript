// /clone/npc/jian_su.c
// 簡素真人・太清宮苦修派長老 (jian_su) - 清修偏峰 (Ch.92, Ch.111)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("簡素真人");
    set_short(WHT "太清苦修派長老" NOR " 簡素真人");
    set_long("七十餘歲的老道姑，身著洗得發白的粗布道袍，頭髮花白卻背脊挺得如雪山青松。\n"
             "她在清修偏峰獨居多年，不赴宮宴亦拒服來路不明的延命丹丸，只靜靜看著太清的病灶。\n");
    set_id(({ "jian_su", "jian su", "jiansu", "簡素真人", "簡素", "苦修長老" }));

    setup_archetype("G", 90);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "elder", "hermit" }));
    set("home_room", "/d/sects/taiqing/quiet_peak.c");

    add_response(({ "坐化", "延命丹", "道化", "升仙台" }),
        "簡素真人站在柴扉前淡淡望了你一眼，聲音雖老邁卻毫無遲滯：「世人只道羽化登仙，\n"
        "偏峰上的老骨頭卻都看見了——靠來歷不明的暗紅丹丸吊命，不過是把神魂拖進更大的欠債裡。\n"
        "若真想替後來人尋一條活路，先拿得出不害人的實證手藝再來敲門。」");

    add_response(({ "元青", "弟子", "證詞" }),
        "簡素真人微微頷首：「口舌之爭無益。哪天你能真切穩住一個早期晶化弟子的神魂而不添新毒，\n"
        "老身這雙老眼，自會替你站上雲頂作證。」");
}
