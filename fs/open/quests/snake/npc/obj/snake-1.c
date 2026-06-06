#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC + "蛇頭模組" + NOR,({"snake head","head","c-snake-1"}));
	set_weight(100);
	set("long","
這是一個蛇的頭部部分，還欠缺蛇身與蛇尾，才能組合(compose)
成一條完整的蛇。\n");
	set("unit","個");
	set("value",100);
setup();
}

void init()
{
add_action("do_compose","compose");
}

int do_compose()
{
object me,obj;

	me = this_player();

	if( !present("c-snake-1",me) || !present("c-snake-2",me) || !present("c-snake-3",me) )
		return 0;

	message_vision(HIY + "$N將蛇頭接於蛇身，在將蛇尾裝上，一條完整的蛇就組裝好了～\n" + NOR,me);
	obj = new(__DIR__"snake-key-2");
	obj->move(me);
	destruct(present("c-snake-2",me));
	destruct(present("c-snake-3",me));
	destruct(present("c-snake-1",me));
return 1;
}
		
