// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("馬刀", ({ "horse blade","blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("unit", "柄");
	  set("value", 300);
	  set("material", "iron");
	  set("long", "馬刀乃騎兵專用之兵刃, 史記「彪騎兵」即曾以馬刀之威, 屢挫西域異族進侵, "+
	  "立下彪炳戰績, 形狀與倭刀略似。 \n");
	}
	init_blade(40);
	setup();
}
