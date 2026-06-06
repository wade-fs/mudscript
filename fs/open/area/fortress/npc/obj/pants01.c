#include <ansi.h>
#include <armor.h>
inherit PANTS;
object me=this_player();
void create()
{
        set_name(YEL"山寨褲"NOR,({"fortress pants","pants"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
        set("value",0);
        set("material","steel");
        set("long","極火山寨的褲子，在褲子的兩側，刺有極火山寨的記印。\n");
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 1);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",1);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",1);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",1);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",1);
        this_object()->set("armor_prop/move",1);
        this_object()->set("armor_prop/parry",1);
        this_object()->set("armor_prop/dodge",1);
        this_object()->set("armor_prop/force",1);
        this_object()->set("armor_prop/armor",1);
}
