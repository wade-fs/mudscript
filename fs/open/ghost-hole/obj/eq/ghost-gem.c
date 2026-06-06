//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
      set_name(CYN + "" + BBLU + "冥魔" + HIR + "寶墜" + NOR,({"ghost-king-gem","gem"}));
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
      set("armor_prop/armor", 5);
      set("armor_prop/spells", 2);
      set("armor_prop/magic", 2);
     }
      setup();
}


