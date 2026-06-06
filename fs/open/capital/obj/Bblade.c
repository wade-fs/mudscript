// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("朴刀", ({ "bo blade","blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("unit", "柄");
	  set("value", 500);
	  set("material", "iron");
	  set("long", "朴刀一向用作古代步戰, 刀身狹長, 以劈、刺近搏為主, 故兵刃典籍有謂"+
	  "「雙刀為父母, 拼命之時用朴刀」, 又謂「刀如猛虎先走紅」, 不出則已, 出則見血。 \n");
	}
	init_blade(30);
	setup();
}
