
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
    set_name(HIY + "真" + HIW + "翔" + HIY + "龍" + HIW + "轉" + HIY + "念" + HIW + "盤" + NOR,({"dragon turn shield","shield","dragon","turn"}));
    set_weight(3000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
    set("long","丐幫傳世之寶, 有反射的效果 .\n");
    set("unit","件");
	set("value",300);
	set("material","steel");
	set("armor_type","shield");
    set("armor_prop/armor",7);
    set("armor_prop/parry",2);
    set("armor_prop/staff",1);
    set("armor_prop/attck",5);
	}
        setup();
}
