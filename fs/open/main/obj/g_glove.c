inherit EQUIP;
#include <ansi.h>
void create()
{
    set_name(HIY"金"+HIW"蠶"+NOR"護手",({"gold gloves","gloves"}));
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
千年金蠶絲所製成的手套，能提升防禦度及加強自身攻擊。
");
        set("unit", "雙");
	set("value",4000);
        set("material","cloth");
	set("armor_type", "hands");
	set("armor_prop/armor",10);
      set("armor_prop/attack",8);
      set("armor_prop/parry",8);
        }
        setup();
}
