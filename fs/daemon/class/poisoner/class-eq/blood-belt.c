//******魔教職業套裝 c0 **************//
#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
    set_name(HIY"《"HIR"冥蠱復仇者之擁"HIY"》"NOR, ({"blood belt"}) );
    set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "付");
            set("material", "leather");
            set("value", 20000);
            set("long","傳說中的魔教之寶。
                        套裝加成 - 
                        1件 - 使你魔教所有特攻曾加30 % 的傷害值 
                        2件 - 使你魔教所有特攻皆有一定的機會不會delay 
                        3件 - 使你魔教用毒的消耗量全免, 並使五毒掌致命一擊的機率
                              提高一成 \n");
           set("no_auc",1);
           set("no_give",1);
           set("no_sell",1);
           set("no_put",1);
           set("no_drop",1);
           set("no_get",1);
           set("armor_prop/dodge",4);
           set("armor_prop/staff",3);
           set("armor_prop/armor",2);
 }
            setup();
}

