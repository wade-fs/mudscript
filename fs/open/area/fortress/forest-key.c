inherit ROOM;		//房間不會update	firedancer
#include <ansi.h>
#include "road.msg"
#include "damage.c"
//string look_token();
//	" + HIY + "<<你發現地上有一塊土黃色火焰形狀的令牌(token)>>" + NOR + "
void create ()
{
        set ("short","森林");
        set ("long","有幾棵被雷劈散的樹木，橫擺\在前方，兩旁斷了一半的樹木，也
在斷處長出新的嫩芽，儘管如此，這裡大部分還是密不透光，只有在
被些微微光照射到的地方，才有點點生意。\n");
        set("exits",([			//設定出口
"out":__DIR__"forest20",
]));
/*        set("item_desc",([		//設定路標
"token":(:look_token:),
]));
*/
        set("objects",([		//設定物件
__DIR__"npc/robber01":3,
__DIR__"npc/obj/token":1,
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
/*
string look_token()
{
	if(!this_object()->query_temp("no_token"))
	{
		message_vision("$N看了一下令牌，把令牌拿走，放在身上。\n",this_player());
		new(__DIR__"npc/obj/token.c")->move(this_player());
		this_object()->set_temp("no_token",1);
		this_object()->set ("long","有幾棵被雷劈散的樹木，橫擺\在前方，兩旁斷了一半的樹木，也
在斷處長出新的嫩芽，儘管如此，這裡大部分還是密不透光，只有在
被些微微光照射到的地方，才有點點生意。\n");
	}
	else
		return "你要看什麼﹖\n";
	return "";
}
*/
