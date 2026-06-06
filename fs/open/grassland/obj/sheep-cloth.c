#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(HIW + "羊皮大衣" + NOR,({"sheep-cloth"}));
        set_weight(2700);
        set("unit","件");
        set("value", 0);
        set("material","cloth");
        set("armor_type","cloth");
        set("long","綿羊皮所做的大衣，禦寒功能相當優良。\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
		set("no_save",1);
        set("armor_prop/parry", 3);
        set("armor_prop/force", 5);
        set("armor_prop/armor", 10);
		set("wear_msg", HIY + "$N穿上$n，頓時覺得身軀暖烘烘，說不出的受用。\n");
		setup();
}
