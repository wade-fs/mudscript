// Room: /open/main/room/M10.c

inherit ROOM;

void create()
{
	set("light_up",1);
	set("short", "聖龍口");
	set("long", @LONG
	走到這已經是長廊的盡頭，眼前有座石碑，上頭刻著
	「聖龍口」三個字，火就是從石碑上發出的，實在是
	匪夷所思，附近除了長廊外並沒有其他的通道，或許
	這塊神秘的石碑(chaitya)會是個秘密入口喔。


LONG
	);
	set("item_desc",([
	"chaitya"	: "用看的，不如摸一摸(touch)吧！\n",
		]));
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"M11a",
]));

	setup();
}

void init()
{
	add_action("do_touch","touch");
}

int do_touch(string arg)
{
	object who;
	who = this_player();
	if(!arg || arg != "chaitya" )
	return notify_fail("你要摸什麼東西？\n");
	if(who->query("class") != "taoist"
	|| !who->query("class") )
	return notify_fail("冷冰冰的一塊石碑，沒有啥特別。\n");
	else
	{
	message_vision("當$N碰觸到石碑時，一陣光芒將$N帶走了！\n",
	who);
	who->move("/open/tendo/room/door");
	return 1;
	}
}

