///open/prayer/room/hole/14.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	這裡使你感到非常陰涼，前面冷風颼颼不停吹來，讓你渾身上下都
	不舒服，魔獸的咆嘯聲不停在你耳際迴盪，而地上閃閃發亮的都是
	魔獸身上剝落下來的鱗片!!

LONG	);
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/lion" : 1,		
   "/open/prayer/npc/carapace-bee" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"16",
  "east":__DIR__"19",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
