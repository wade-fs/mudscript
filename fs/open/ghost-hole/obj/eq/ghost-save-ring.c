//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
int kar;
void create()
{
     set_name(MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "指戒" + NOR + "" + MAG + "ω" + NOR,({"ghost-ring","ring"}) );
     set_weight(25);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long",CYN + "" + BBLU + "冥魔戰甲的一部份\n" + NOR);
            set("unit", "件");
            set("value",500);
            set("material","steal");
            set("no_auc",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_put",1);
            set("no_drop",1);
            set("no_get",1);
            set("no_steal",1);
            set("no_save",1);;
			set("light_up",-1);
            set("armor_type","finger");
			set("armor_prop/armor", 5);
            set("armor_prop/magic",10);
			set("armor_prop/force",10);
			set("armor_prop/spells",10);
			set("wear_msg",HIG + "$N套上$n" + HIG + "，惡魔力量開始注入已疲憊的身心。\n" + NOR);
			set("unequip_msg",HIW + "$N脫下$n" + HIW + "，逐漸將心中的邪念壓抑下來。\n" + NOR);
           }
        setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的" + MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "指戒" + NOR + "" + MAG + "ω" + NOR,({"ghost-ring","ring"}) );
  else
        set_name (MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "指戒" + NOR + "" + MAG + "ω" + NOR,({"ghost-ring","ring"}) );
}




