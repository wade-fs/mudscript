// Room: /open/doctor/room/rset_room.c
inherit ROOM;

void create ()
{
  set ("short", "東廂房");
  set ("long", @LONG
這裡只有簡單的幾項用具，放著一張床、一張桌子和幾張椅子，不
過簡撲的東西帶來了簡單的生活，對於病人來說，是休息的最好的地點
。因為是病人休息的地方，所以請不要大聲說話。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/lee" : 1,
]));

  setup();
}
