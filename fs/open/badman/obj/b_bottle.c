// b_bottle.c by powell 

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name("青色小瓶子",({"blue bottle","bottle"})); 
        set("long","一個淡青色的小瓶子，看不出裏面裝的是甚。\n"+
                   "也許\你想嘗嘗看瓶裏的東東(eat bottle)。\n");

	set("unit", "瓶");
        set("base_unit", "瓶");
        set("value", 0);
        set("base_weight", 50);
	set_amount(1);
	setup();
}

void init()
{
		add_action("eat_bottle","eat");
}

int eat_bottle(string arg)
{      
	object who = this_player();
        if(arg=="bottle"){
        message_vision(
			"$N把瓶子裏的藥丸拿出來並吞進肚裏。\n",who );
	if (who->query_condition("snake_poison")) {
	who->apply_condition("snake_poison",0);
        tell_object(who,HIB + "你中的蛇毒解了!\n" + NOR);
	}
	else {
	tell_object(who,"你將藥丸吞下後，甚麼事也沒發生。\n");
	}
	tell_object(who,"因為瓶子已經空了，你隨手將瓶子丟棄。\n");
	destruct (this_object());
	}
	tell_object(who,"你要吃甚麼??\n");
	return 1;
}

