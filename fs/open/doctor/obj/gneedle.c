#include <weapon.h>
#include <ansi.h>
inherit STABBER;

void create()
{
set_name(HIR"赤焰絕炎"HIW"針"NOR, ({"fire needle","fire","needle"}));
    set_weight(5500);
    if( clonep() )
    set_default_object(__FILE__);
    else{
    set("unit", "柄");
    set("long","一柄火紅的針，據說為太上老君以三昧真火所煉製成的火針！\n");
    set("wield_msg", "$N握起手中的$n，一股"HIR"赤焰之氣"NOR"竄入各大穴道，使$N頓時感到全身充滿力量！\n");
    set("unwield_msg", "$N放下了手中的$n，"HIR"赤焰之氣"NOR"隨即從各穴竄出，一時間消逝無蹤！\n");
    set("value", 500000);
    set("material", "iron");
}
    init_stabber(80);
    setup();
}
