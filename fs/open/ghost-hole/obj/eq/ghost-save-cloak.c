//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <armor.h>
#include <ansi.h>
inherit CAPE;

void create()
{
    set_name(MAG"ω"CYN""BBLU"冥魔"HIR"披風"NOR""MAG"ω"NOR,({"ghost-cloak","cloak"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", CYN""BBLU"冥魔戰甲的一部份。\n"NOR); 
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_save",1);       
        set("unit", "件");
        set("value", 500);
        set("material", "leather");
		set("armor_type","cape");
		set("armor_prop/armor", 15);
        set("armor_prop/stabber", 15);
		set("armor_prop/sowrd", 15);
		set("armor_prop/force",3);
        set("wear_msg",HIG"$N披上$n"HIG"，君臨天下的氣勢使世間魔物伏首。\n"NOR);
        set("unequip_msg", HIW"$N脫下$n"HIW"，無敵霸氣於煞那間消失殆盡。\n"NOR);
        }
        setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"MAG"ω"CYN""BBLU"冥魔"HIR"披風"NOR""MAG"ω"NOR,({"ghost-cloak","cloak"}));
  else
        set_name (MAG"ω"CYN""BBLU"冥魔"HIR"披風"NOR""MAG"ω"NOR,({"ghost-cloak","cloak"}));
}





