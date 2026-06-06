///open/prayer/room/hole/19.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	由牆壁長滿的青苔來看，這裡比其它地方來的潮濕，腳下也都是
	爛泥，角落的岩石插著一枝箭直沒箭矢，你不禁讚嘆射箭之人功\
	力如此深厚...

LONG	);
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/emery-giant" : 1,		
   "/open/prayer/npc/lion" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"20",
  "west":__DIR__"18",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
