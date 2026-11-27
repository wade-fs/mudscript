// /clone/npc/ironback_wolf.c
// 鐵背荒狼頭狼 (ironback_wolf) - 八荒武山・黑石峽試煉道 (Ch.87)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("缺耳鐵背狼王");
    set_short(HIB "缺耳鐵背荒狼王" NOR);
    set_long("一頭體型壯碩如牛犢的成年二階鐵背荒狼頭狼，左耳缺了一塊舊傷疤，\n"
             "脊背毛皮宛如鐵針倒豎，一雙幽綠冷目在岩石高處陰鷙地盯視著試煉者的動靜。\n");
    set_id(({ "ironback_wolf", "ironback wolf", "wolf", "缺耳鐵背狼王", "鐵背荒狼", "頭狼" }));

    setup_archetype("D", 55);
    set("class", "beast");
    set("faction", "wastes_beast");
    set("home_room", "/d/sects/bahuang/black_stone_gorge.c");

    set_exp_reward(650);
    set_gold_reward(120);
    set_drop_list(({ "/item/material/wolf_fur.c" }));
    set_respawn(45);
    set_aggro_msg("缺耳鐵背狼王發出一聲低沉狼嚎，四足蹬碎凍石，朝著目標喉間猛撲而下！\n");
    set_special_atk("鐵背碎骨撲", 28);
}
