// Room: /open/poison/room/path4
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
你來到一個坑道中，這裡一片死寂，相當沈靜，遠方傳
來陣陣的滴水聲，似乎是在勾惑著你的靈魂，心想幸好自己
修為夠，定性強，否則早就崩潰於此地。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/poison/room/path5",
  "eastup" : "/open/poison/room/path3",
]));

  setup();
}
