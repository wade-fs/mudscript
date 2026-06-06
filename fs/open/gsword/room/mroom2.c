// Room: /d/oldpine/pine1.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣之五行");
  set ("long", @LONG
你看到滿山的樹木圍著你,你的四週只是一片: 樹 !! 樹 !!
樹 !! 無數藤蔓纏繞著你的身體,卻又不對你造成任何損傷,幻像
?? 是的幻像,這一定只是幻像 !! 只要你能勘破幻像,必能破解這
奇陣...
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "gold" : __DIR__"mroom3",
  "land" : __DIR__"mroom3",
  "fire" : __DIR__"mroom2",
  "water" : __DIR__"mroom1",
]));
  set("light_up", 1);

  setup();
}

void reset()
{
	::reset();
	set("exits", ([ 
	  "fire" : __DIR__"mroom" + (random(4)),
	  "water" : __DIR__"mroom" + (random(4)),
	  "land" :  __DIR__"mroom3",
	  "gold" :  __DIR__"mroom" + (random(4)),
	]));
}

int valid_leave(object me, string dir)
{
	write("無數荊棘環繞著你....\n");
	switch(dir) {
		case "fire":	write("你往火相離開.....\n");	break;
		case "land":	write("你往土相離開.....\n");	break;
		case "water":	write("你往水相離開.....\n");	break;
		case "gold":	write("你往金相離開.....\n");	break;
		default:
			write("你通過一片荊棘....");
	}
	return 1;
}
