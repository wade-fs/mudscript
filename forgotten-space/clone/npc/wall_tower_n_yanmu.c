// clone/npc/wall_tower_n_yanmu.c
// 嚴目・瞭望長 (wall_tower_n_yanmu) - 北城望荒箭樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("嚴目");
    set_short(HIW "望荒箭樓瞭望長" NOR " 嚴目");
    set_long("一位雙目如鷹隼般銳利的城防老弓手，背負鎮風鐵胎強弓，手搭涼棚遠眺北方天際。\n"
             "他在北城最高處的望荒箭樓值守十餘年，能從數十里外的雲氣變化判讀北山煞潮與獸群動向。\n");
    set_id(({ "wall_tower_n_yanmu", "yanmu", "yan mu", "lookout chief", "嚴目", "瞭望長" }));

    setup_archetype("D", 22);
    set("class", "wu_initiate");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));
    set("schedule", "24h");

    add_response(({ "煞潮", "北山", "警戒", "望荒", "動向" }),
        "嚴目指向北方地平線：「你看北嶺上空那層鉛灰色的雲翳——每逢利貞交替之時，地脈濁煞便會隨北風南壓，箭樓狼煙一旦點燃，全城皆需戒備！」");
}
