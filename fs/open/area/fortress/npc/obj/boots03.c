#include <armor.h>
#include <ansi.h>
inherit BOOTS;
object me=this_player();

void create()
{
        set_name(YEL + "真。木常靴" + NOR,({"jhen mu_chang boots","boots"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "雙");
	        set("value",0);
	        set("material","steel");
	        set("long","一雙土黃色的短靴，斑駁的色澤與略有破損的表面，刻畫出它存在的歷史痕跡。\n");
        }
        setup();
}

void init()
{
	add_action("do_wear","wear");
	add_action("do_remove","remove");
}

int do_wear(string str)
{
	object ob = this_object();
	if(str=="boots" || str="jhen mu_chang boots")
		if( !query("equipped") )
		{
			if(!this_player()->query_temp("boot",1))
			{
				message_vision("沒有增加效果，不能穿\n",me);
			}
			else
			{
				message_vision(YEL + "有增加效果，穿上去了\n" + NOR,me);
				if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 1);
				if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",1);
				if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",1);
				if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",1);
				if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",1);
				        this_object()->set("armor_prop/parry",1);
				        this_object()->set("armor_prop/force",1);
				        this_object()->set("armor_prop/dodge",1);
				        this_object()->set("armor_prop/move",1);
				        this_object()->set("armor_prop/armor",1);
			}
		}
}

int do_remove(string str)
{
	object ob = this_object();
	if(str=="boots" || str="jhen mu_chang boot")
		if( query("equipped") )
		{
			message_vision(HIC + "$N脫下木常靴\n" + NOR,me);
		}
}
