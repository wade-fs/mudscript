// Room: /d/oldpine/pine1.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣之五行");
  set ("long", @LONG
你看到一陣風沙漫天而來,你的四週只是一片____ 塵土 _____
飛揚,飛沙走石狂暴的衝擊你的身體,卻又不對你造成任何損傷,幻像
??  是的幻像,這一定只是幻像 !! 只要你能勘破幻像, 必能破解這
奇陣...
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");
  set("exits", ([ /* sizeof() == 4 */
  "wood" : __DIR__"mroom3",
  "gold" : __DIR__"mroom3",
  "fire" : __DIR__"mroom1",
  "water" : __DIR__"mroom4",
]));

  setup();
}

void reset()
{
	::reset();
	set("exits", ([ 
	  "wood" : __DIR__"mroom" + (random(4)),
	  "water" : __DIR__"mroom4",
	  "gold" :  __DIR__"mroom" + (random(4)),
	  "fire" :  __DIR__"mroom" + (random(4)),
	]));
}

int valid_leave(object me, string dir)
{
	write("一陣風沙捲襲著你....\n");
	switch(dir) {
		case "wood":	write("你往木相離開.....\n");	break;
		case "fire":	write("你往火相離開.....\n");	break;
		case "water":	write("你往水相離開.....\n");	break;
		case "gold":	write("你往金相離開.....\n");	break;
		default:
			write("你通過一陣風暴....");
	}
	return 1;
}
