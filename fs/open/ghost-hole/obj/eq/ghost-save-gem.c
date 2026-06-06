//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
      set_name(MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "寶墜" + NOR + "" + MAG + "ω" + NOR,({"ghost-gem","gem"}));
      set_weight(100);
      if( clonep() )
      set_default_object(__FILE__);
      else
     {
      set("long",CYN + "" + BBLU + "冥魔戰甲的一部份\n" + NOR);
      set("unit", "面");
      set("value", 500);
      set("material", "gem");
      set("armor_type","neck");
      set("armor_prop/armor", 10);
      set("armor_prop/spells", 10);
      set("armor_prop/magic", 10);
	  set("armor_prop/force",2);
      set("no_auc",1);
      set("no_sell",1);
      set("no_give",1);
      set("no_put",1);
      set("no_drop",1);
      set("no_get",1);
      set("no_steal",1);
      set("no_save",1);    
      set("wear_msg",HIG + "$N戴上$n" + HIG + "，內心得到了幽冥魔力的強力加持。\n" + NOR);
      set("unequip_msg",HIW + "$N取下$n" + HIW + "，幽冥魔君邪念不再控制心神。\n" + NOR);
     }
      setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的" + MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "寶墜" + NOR + "" + MAG + "ω" + NOR,({"ghost-gem","gem"}));
  else
        set_name (MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "寶墜" + NOR + "" + MAG + "ω" + NOR,({"ghost-gem","gem"}));
}





