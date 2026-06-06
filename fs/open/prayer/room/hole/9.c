///open/prayer/room/hole/9.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	走到這裡你感到一陣徬惶，往東往西都是濃霧，根本無法辨出方
	向，還不時聞到一股強烈的腥味，令人不禁作嘔，四週散佈著紅
	色煙霧，你開始告訴自己不用勉強，早點回頭，留得青山在，哪
	怕沒材燒......

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/room/npc/crab-ox" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"11",
  "north":__DIR__"7",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
