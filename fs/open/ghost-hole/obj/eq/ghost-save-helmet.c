//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name(MAG"ω"CYN""BBLU"冥魔"HIR"帝冠"NOR""MAG"ω"NOR,({"ghost-helmet","helmet"}));
    set("long",CYN""BBLU"冥魔戰甲的一部份"NOR);   
    set_weight(25);
        set("armor_type","head");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "頂");
                set("value", 500);
                set("material","steel");
                set("armor_prop/armor", 10);
                set("armor_prop/cure" ,10);
				set("armor_prop/plan" ,10);
				set("armor_prop/force",2);
				set("armor_type","head");
                set("no_auc",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_put",1);
                set("no_drop",1);
                set("no_get",1);
                set("no_steal",1);
                set("no_save",1);
                set("thunder", 1000000000000);
                set("wear_msg",HIG"$N戴上$n"HIG"，突然只想瘋狂的沉醉於殺戮之中。\n"NOR);
                set("unequip_msg",HIW"$N拿下$n"HIW"，殺意退散，恢復仁慈的本性。\n"NOR);
       }
        setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"帝冠"NOR""MAG"ω"NOR,({"ghost-helmet","helmet"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"帝冠"NOR""MAG"ω"NOR,({"ghost-helmet","helmet"}));
}
