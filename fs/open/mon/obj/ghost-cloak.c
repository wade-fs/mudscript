#include <armor.h>
#include <ansi.h>
inherit CAPE;

void create()
{
 	        set_name(HIY + "妖幻披掮" + NOR, ({ "ghost cloak" ,"cloak" }) );
	        set_weight(50);
       		if( clonep() )
                set_default_object(__FILE__);
        	else {
        	set("long", "千年樹妖–舞風揚所擁有，輕輕的披在身上，讓你散發著無限魅力。\n");
                set("unit", "件");
                set("value", 300000);
                set("material", "steal");
		set("type", 1); 
		set("no_steal",1);
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", 5);
		set("armor_prop/parry", 5);
		set("armor_prop/attack", 5);
		set("armor_prop/force", 10);
		set("wear_msg", HIW + "$N輕輕的著起了$n" + HIW + "，無限的魅力正持續的開始散發。\n" + NOR);
		set("unequip_msg", HIW + "輕輕的脫下$n" + HIW + "，$N的魅力正一點一滴的消散。\n" + NOR);

       		}
		setup();
}
