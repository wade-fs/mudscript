// Room: /d/oldpine/pine1.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣之五行");
  set ("long", @LONG
你看到一陣金光隴罩著你,你的四週只是一片金黃!! 金黃!!
金黃!! 萬道金光穿透著你的身體,卻又不對你造成任何損傷,幻像 
?? 是的幻像,這一定只是幻像 !! 只要你能勘破幻像,必能破解這
奇陣...
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "wood" : __DIR__"mroom2",
  "land" : __DIR__"mroom3",
  "fire" : __DIR__"mroom1",
  "water" : __DIR__"mroom0",
]));
  set("light_up", 1);

  setup();
}

void reset()
{
	::reset();
	set("exits", ([ 
          "water":__DIR__"mroom" + (random(4)),
          "land":__DIR__"mroom" + (random(4)),
          "wood":__DIR__"mroom2",
          "fire":__DIR__"mroom" + (random(4)),
	]));
}

int valid_leave(object me, string dir)
{
	write("一道金光直射著你....\n");
	switch(dir) {
		case "wood":	write("你往木相離開.....\n");	break;
		case "land":	write("你往土相離開.....\n");	break;
		case "water":	write("你往水相離開.....\n");	break;
		case "fire":	write("你往火相離開.....\n");	break;
		default:
			write("你通過一道金光....\n");
	}
	return 1;
}
