//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <armor.h>
#include <ansi.h>

inherit EQUIP;

void create()
{
    set_name(MAG"ω"CYN""BBLU"冥魔"HIR"肩甲"NOR""MAG"ω"NOR,({"ghost-armband","armband"}));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
        set("long",CYN""BBLU"冥魔戰甲的部份。\n"NOR);
        set("unit", "副");
        set("value", 500);
        set("material", "blacksteel");
        set("armor_prop/armor", 15);
        set("armor_prop/unarmed",10);
        set("armor_prop/arrow", 15);
		 set("armor_prop/dagger", 15);
		 set("armor_prop/force",2);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_save",1);
        set("armor_type","armbands");
        set("wear_msg",HIG"$N戴上$n"HIG"，一股凶惡的毀滅性力量環繞全身。\n"NOR);
        set("unequip_msg",HIW"$N取下$n"HIW"，肩上一輕，覺得毫無安全感。\n"NOR);
       }
        setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"肩甲"NOR""MAG"ω"NOR,({"ghost-armband","armband"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"肩甲"NOR""MAG"ω"NOR,({"ghost-armband","armband"}));

}




