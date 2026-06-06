// Room: /open/badman/room/r1
inherit ROOM;

void create ()
{
  set ("short", "小飯館");
  set ("long", @LONG
幾張擺設樸素的小圓桌，和幾張老舊的長板凳，在橘黃色的燈
火照耀下，使得整個小飯館看起來格外的令人感到溫馨。出乎你意
料的，店裡面的顧客似乎不多，感覺其來不太像是一般山寨裡的食
堂那樣，鬧哄哄的擠滿了一堆愛喝酒鬧事的流氓。
    北邊的房間傳來陣陣的香味。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r13",
  "east" : __DIR__"b8",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/ha" : 1,
]));

  setup();
}
