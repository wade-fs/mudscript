// Room: /open/wu/room/luroom28.c
// 瀧山任朝陽的寢室
inherit ROOM;
void create ()
{
  set ("short", "朝陽閣");
	set( "build", 12 );
  set ("long", @LONG
你一走進房間，一股濃厚的酒味撲鼻而來，令你頓時頭昏眼花，差點跌倒
，你回神過來，看到地上擺滿了酒壺，一個彪型大漢正躺在地上呼呼大睡，牆
上掛這一個錦旗寫著：縣大會武術冠軍，你不禁懷疑....難道他是真人不露相?
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luroom25",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/sun_jen.c" : 1,
]));
  set("light_up", 1);
  setup();
}
