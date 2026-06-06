//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
 set_name(MAG"ω"CYN""BBLU"冥魔"HIR"甲冑"NOR""MAG"ω"NOR,({"ghost-armor","armor"}));
 set_weight(100);
 if ( clonep() )
 set_default_object(__FILE__);
 else {
       set("long", CYN""BBLU"冥魔戰甲的一部份。\n"NOR);
       set("unit", "付");
       set("armor_type", "cloth");
       set("material", "leather");
       set("value", 500);
       set("armor_prop/armor", 15);
	   set("armor_prop/staff", 15);
	   set("armor_prop/blade",15 );
	   set("armor_prop/force",3);
       set("no_auc",1);
       set("no_sell",1);
       set("no_give",1);
       set("no_put",1);
       set("no_drop",1);
       set("no_get",1);
       set("no_steal",1);
       set("no_save",1);
       set("wear_msg",HIG"$N穿起$n"HIG"，感覺得到了刀槍不入的不死之驅。\n"NOR);
       set("unequip_msg",HIW"$N卸除$n"HIW"，渾身上下的破綻都顯露出來。\n"NOR);
     }
       setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"甲冑"NOR""MAG"ω"NOR, ({"ghost-armor","armor"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"甲冑"NOR""MAG"ω"NOR, ({"ghost-armor","armor"}));

}





