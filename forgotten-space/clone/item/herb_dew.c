// clone/item/herb_dew.c
// 帶露晨露草 - 於破曉時分採擷之天地靈露草

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("晨露草", ({ "dew herb", "dew_herb", "chenlucao", "晨露草" }));
    set_short(HIG "帶露晨露草" NOR);
    set_long("一株只在卯辰時分、借天地破曉紫氣凝聚晨露時採擷的極品靈草。\n"
             "青翠欲滴的細小葉片上凝結著幾顆晶瑩剔透的夜露，靈氣充沛，生機旺盛。\n"
             "是煉製高級淬火靈液與保命靈丹的絕佳原料，商隊掌櫃極為看重。\n");
    set_weight(150);
    set_value(50);
    set("herb_type", "dew");
}
