//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(MAG"ω"CYN""BBLU"冥魔"HIR"羽靴"NOR""MAG"ω"NOR,({"ghost-boots","boots"}));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
          set("long",CYN""BBLU"冥魔戰甲的一部份。\n"NOR);
          set("unit","雙");
          set("value",500);
          set("armor_prop/armor", 10);
          set("armor_prop/dodge", 10);
          set("armor_prop/move",  10);
		  set("armor_prop/force",2);
          set("no_auc",1);
          set("no_sell",1);
          set("no_give",1);
          set("no_put",1);
          set("no_drop",1);
          set("no_get",1);
          set("no_steal",1);
          set("no_save",1);
          set("material","leather");
          set("armor_type","boots");
          set("wear_msg",HIG"$N套上$n"HIG"，身影猶如玄幻魔風般模糊了起來。\n");
          set("unequip_msg",HIW"$N脫下$n"HIW"，身形逐漸於空氣中顯露出來。\n"NOR);
         }
          setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"羽靴"NOR""MAG"ω"NOR,({"ghost-boots","boots"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"羽靴"NOR""MAG"ω"NOR,({"ghost-boots","boots"}));
}




