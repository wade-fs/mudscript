// /clone/npc/shen_zhaochen.c
// 沈照塵・周天星律院世家弟子 (shen_zhaochen) - 太清外門雲舍 (Ch.86)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("沈照塵");
    set_short(HIW "太清世家經生" NOR " 沈照塵");
    set_long("十九歲上下的青年修士，身披月白雲紋道袍，腰懸祖傳靜心玉符。\n"
             "他出身北境小世家，擅長星盤推算與符陣記憶，外表沉穩自信，實則極度畏懼遭門派淘汰。\n");
    set_id(({ "shen_zhaochen", "shen zhaochen", "zhaochen", "沈照塵", "經生" }));

    setup_archetype("G", 58);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "disciple", "rival" }));
    set("home_room", "/d/sects/taiqing/outer_court.c");

    add_response(({ "登天梯", "問心陣", "叩首", "星曆" }),
        "沈照塵神色略顯緊繃地按住腰間玉符：「登天梯上威壓如山，依先賢規矩行叩拜禮順應天律減壓有何不對？\n"
        "我家世代靠宗門星曆預報避開北境雪災，哪能像某些山下來的土包子一樣，拿支炭筆就去質疑星辰誤差！」");
}
