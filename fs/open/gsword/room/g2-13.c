// Room: /open/gsword/room/nghouse2.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
	set( "build", 60 );
  set ("long", @LONG
這廣場是仙劍門徒練劍的場所，只見廣場中間一個頗大的太極圖，在
太極圖上依照著八卦的方位滿佈木樁。在廣場的左邊的一塊大石頭上有著
幾行字(words)。
 
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/trainee1.c" :1,
     "/daemon/class/swordsman/tengyu": 1,
]));

set("item_desc", ([
"words" : "愛落紅塵心已死....
羅嚴塔爾.........於98/4/24\n",
]));
  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/g2-8.c",
  "west" : "/open/gsword/room/g2-10.c",
  "south" : "/open/gsword/room/g2-12.c",
  "east" : "/open/gsword/room/g2-6.c",
]));

  setup();
}
