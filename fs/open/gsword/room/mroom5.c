// Room: /d/oldpine/pine1.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣之五行");
  set ("long", @LONG
你看到一陣妖火漫天而來,你的四週只是一片: 火 !! 火 !! 火
 !! 熊熊烈火像似燃燒著你的身體,卻又不對你造成任何損傷,幻像?
? 是的幻像,這一定只是幻像 !! 只要你能勘破幻像,必能破解這奇陣
...
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");
  set("exits", ([ /* sizeof() == 4 */
  "wood" : __DIR__"mroom1",
  "gold" : __DIR__"mcenter",
  "land" : __DIR__"mroom2",
  "water" : __DIR__"mroom2",
]));

  setup();
}

void reset()
{
	::reset();
	set("exits", ([ 
	  "wood" : __DIR__"mroom" + (random(4)),
	  "gold" : __DIR__"mcenter",
	  "water" :  __DIR__"mroom" + (random(4)),
	  "land" :  __DIR__"mroom" + (random(4)),
	]));
}

int valid_leave(object me, string dir)
{
	write("一陣妖火捲襲著你....\n");
	switch(dir) {
		case "wood":	write("你往木相離開.....\n");	break;
		case "land":	write("你往土相離開.....\n");	break;
		case "water":	write("你往水相離開.....\n");	break;
		case "gold":	write("你往金相離開.....\n");	break;
		default:
			write("你通過一道火燄....");
	}
	return 1;
}
