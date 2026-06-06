// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "臥房");
  set ("long", @LONG
這是儒門內堂東邊的臥房，只見床上十分的凌亂，
就可知道儒生平常並不整理，看見儒生們正坐臥在床上
研究著四書五經。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"in.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/trainee.c" : 2,
]));

  setup();
}
