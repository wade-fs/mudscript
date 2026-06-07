// /area/newbie/hidden_cave.c
inherit "/std/room";

void create() {
    
    set("short", select_lang("隱秘的山洞"));
    set("long", select_lang("山洞內部陰冷潮濕，石壁上掛著點點水珠。\n" +
             "洞穴深處似乎有一雙眼睛在黑暗中注視著你。\n"));
    
    set_is_outdoor(0);
    set("coordinate", ({ 10, 11, 0 }));
    
    set("exits/" + "south", "./secret_entrance.c");

    // 放置主動攻擊的野狼
    object wolf = spawn_npc("/npc/wolf.c");
    if (wolf) {
        wolf->set("name", select_lang("飢餓的野狼"));
        wolf->set_aggressive(1); // 設為好鬥
        wolf->set_aggro_msg("野狼發出一聲長嘯，猛地朝你撲了過來！\n");
    }

    // 放置一個隱藏的寶箱
    add_hidden_element("chest", ([
        "type": "item",
        "value": "/item/treasure_chest.c",
        "msg": "你在洞穴的角落裡搜尋，在厚厚的塵土下發現了一個沉重的木箱！"
    ]));
}
