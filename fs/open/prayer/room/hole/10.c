///open/prayer/room/hole/10.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	你一走進來就聞到了薰人的惡臭，一堆一堆的骷髏還有屍體，地上全
	都是令人做嘔的蛆, 讓你不知道下一步要怎麼走, 唯有踩過這些嘔心
	的蛆方可前進, 你覺得還是快走比較好, 再不走那些蛆就往你身上爬
	了! 

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/carapace-bee" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"12",
  "south":__DIR__"8",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
