//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
     set_name(MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "腰帶" + NOR + "" + MAG + "ω" + NOR,({"ghost-belt","belt"}) );
     set_weight(200);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long",CYN + "" + BBLU + "冥魔戰甲的一部份。\n" + NOR);
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
            set("no_save",1);
			set("armor_type", "waist");
            set("armor_prop/armor", 10);
            set("armor_prop/poison",10);
			set("armor_prop/throwing",10);
			set("armor_prop/force",3);
            set("wear_msg",HIG + "$N束上$n" + HIG + "，凶邪魔妖的力量直接貫入丹田中。\n" + NOR);
            set("unequip_msg", HIW + "$N脫下$n" + HIW + "，黑暗的魔力逐漸由丹田散去。\n" + NOR);
           }
        setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的" + MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "腰帶" + NOR + "" + MAG + "ω" + NOR,({"ghost-belt","belt"}) );
  else
        set_name (MAG + "ω" + CYN + "" + BBLU + "冥魔" + HIR + "腰帶" + NOR + "" + MAG + "ω" + NOR,({"ghost-robe","robe"}) );
}

