//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(MAG"ω"CYN""BBLU"冥魔"HIR"足環"NOR""MAG"ω"NOR,({"ghost-pants","pants"}));
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("long",CYN""BBLU"冥魔戰甲的一部份。\n"NOR);
                set("unit","件");
                set("value",500);
                set("no_auc",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_put",1);
                set("no_drop",1);
                set("no_get",1);
                set("no_steal",1);
                set("no_save",1);
                set("armor_prop/armor",10);
                set("armor_prop/move", 10);
				set("armor_prop/riding", 10);
				set("armor_prop/armor", 10);
				set("armor_prop/force",2);
                set("material","leather");
                set("armor_type","pants");
                set("wear_msg",HIG"$N穿上$n"HIG"，步法變得如陰夜風雲般詭譎無常。\n"NOR);
                set("unequip_msg",HIW"$N脫下$n"HIW"，步法變得如常人般沉重雜亂。\n"NOR);
             }
                setup();
        }
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"足環"NOR""MAG"ω"NOR,({"ghost-pants","pants"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"足環"NOR""MAG"ω"NOR,({"ghost-pants","pants"}));
}



