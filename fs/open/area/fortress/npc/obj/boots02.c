#include <ansi.h>
#include <armor.h>
inherit BOOTS;
object me=this_player();
void create()
{
        set_name(YEL + "木常靴" + NOR,({"mu chang boots","boots"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "雙");
	        set("value",0);
	        set("material","steel");
	        set("long","一雙土黃色的短靴，斑駁的色澤與略有破損的表面，刻畫出它存在的歷史痕跡。\n");
		set("wear_msg","$N低下身，把$n穿套於腳上。\n");
		set("remove_msg","$N低下身，把穿套於腳上的$n脫下。\n");
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", -1);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",-1);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",-1);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",-1);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",-1);
        this_object()->set("armor_prop/parry",-1);
        this_object()->set("armor_prop/force",-1);
        this_object()->set("armor_prop/dodge",-1);
        this_object()->set("armor_prop/move",-1);
        this_object()->set("armor_prop/armor",1);
}
