//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "脛甲" + NOR + "" + MAG + "ω" + NOR,({"ghost-leggings","leggings"}));
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
              set("long",CYN + "" + BBLU + "冥魔戰甲的一部份。\n" + NOR);
              set("unit","雙");
              set("value",500);
              set("armor_prop/armor",10);
              set("armor_prop/dodge", 10);
			  set("armor_prop/move", 10);
			  set("armor_prop/force",2);
              set("material","leather");
              set("armor_type","leggings");
              set("no_auc",1);
              set("no_sell",1);
              set("no_give",1);
              set("no_put",1);
              set("no_drop",1);
              set("no_get",1);
              set("no_steal",1);
              set("no_save",1);
              set("wear_msg",HIG + "$N肇上$n" + HIG + "，雙腿間湧入源源不絕的充沛魔力。\n" + NOR);
              set("unequip_msg",HIW + "$N取下$n" + HIW + "，突然兩腿酸軟，使不上力量。\n" + NOR); 
            }
              setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的" + MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "脛甲" + NOR + "" + MAG + "ω" + NOR,({"ghost-leggings","leggings"}));
  else
        set_name (MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "脛甲" + NOR + "" + MAG + "ω" + NOR,({"ghost-leggings","leggings"}));
}





