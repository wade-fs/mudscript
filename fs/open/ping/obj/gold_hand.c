inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIY + "金織手套" + NOR,({"golden hands","hands"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以金絲織成的珍貴手套，其中似乎隱藏著某種魔力。
");
        set("unit", "雙");
        set("value",100000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",5);
        set("armor_prop/attack", 5);
        set("armor_prop/dodge",3);
        }
        setup();
}

