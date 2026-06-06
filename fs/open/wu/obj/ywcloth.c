#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
   set_name("金鏤玉衣" ,({"gold cloth","cloth"}));
   set_weight(30000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("unit","件");
   set("value",150000);
   set("material", "cloth");
   set("long",HIW"這是一件由傳說中玄天玉加上金鏤線所編成的寶衣。\n"NOR);
   set("wear_msg", "$N將$n穿上，"HIY"金鏤衣"NOR"的力量貫注在$N身中。\n");
   set("unequip_msg", "$N將$n脫掉，"HIY"金鏤衣"NOR"的力量隨之逝去。\n");
   set("armor_prop/armor",30);
   set("armor_prop/force",3);
   set("armor_prop/unarme",3);
   set("armor_prop/dodge",-5);
}
        setup();
}
