// Room: /open/ping/room/road3.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 1179 );
  set ("long", @LONG
這裡就是平南城鬧區了, 平南城雖地處偏疆, 可是中土有的東西,
這裡也樣樣都有, 運氣好的話, 你還可以買到苗疆的特產呢 !
    你的北方是一家錢莊, 南方則是一家樂透彩券商店.     

LONG);


      set("no_kill", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/ping/npc/sells2" : 1,
  "/open/ping/npc/woman" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road4",
  "north" : __DIR__"pingbank.c",
  "south" : __DIR__"loto",  
  "east" : __DIR__"road2",
]));

  setup();
}
