// clone/npc/folk/taiqing_copy_senior.c
// 太清門・戒律抄經師兄（宗門底層弟子日常壓抑與抄經苦差線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("戒律抄經師兄");
    set_short(CYN "青衫墨袖" NOR " 戒律抄經師兄");
    set_long("一位右手中指與食指關節微腫、雙眼布滿血絲的太清門三代外門師兄。\n"
             "他十年如一日地守在抄經堂前檢查新弟子謄寫的竹紙道經，錯一筆便罰抄十卷。\n");
    set_id(({ "taiqing_copy_senior", "copy_senior", "senior", "戒律抄經師兄", "抄經師兄", "師兄" }));

    setup_archetype("E", 16);
    set("class", "immortal");
    set("faction", "taiqing");
    set("roles", ({ "info" }));
    set("no_combat", 1);

    add_response(({ "抄經", "罰抄", "戒律", "抄寫" }),
        "抄經師兄頭也不抬地敲敲戒尺：「外門弟子連天道引氣都得排班輪候，平日若不靠抄寫三百卷《太清守靜科儀》(copy scripture) 換取兩點宗門功勞，拿什麼去換半枚培元丸？」");
    add_response(({ "手痠", "休息", "喝粥", "勞逸" }),
        "抄經師兄長嘆一聲：「手腕發僵就少寫兩行吧……其實隔壁丹鼎門膳堂這時辰正好在施捨清心蓮子粥，你若抄完這卷 (copy scripture)，不如溜過去向那位火頭道姑討碗粥喝（ask nun about 領粥），別告訴戒律執事是我說的。」");
}
