#include <armor.h>
#include <ansi.h>
inherit LEGGINGS;

void create()
{
 	        set_name(HIY + "妖幻護膝" + NOR, ({ "ghost legging" ,"legging" }) );
	        set_weight(50);
       		if( clonep() )
                set_default_object(__FILE__);
        	else {
		set("long", "千年樹妖–舞風揚所擁有，擁有絕佳的防護力的護膝。\n");
                set("unit", "雙");
                set("value", 300000);
                set("material", "steal");
		set("type", 1); 
		set("no_steal",1);
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", 5);
		set("armor_prop/parry", 5);
		set("armor_prop/attack", 5);
		set("armor_prop/force", 10);
		set("wear_msg", HIW + "$N雙腳輕輕裝上了護膝，$n" + HIW + "已舒適的穿在" + HIW + "$N的腳上。\n" + NOR);
		set("unequip_msg", HIW + "$N脫下了$n" + HIW + "$N" + HIW + "的防護力顯得變弱了。\n" + NOR);

       		}
		setup();
}
  
