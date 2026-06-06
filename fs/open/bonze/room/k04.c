// Room: /open/bonze/room/k01.c
inherit ROOM;

void create ()
{
  set ("short", "伙房");
  set ("long", @LONG
這裡是少林寺的伙房，為了應付少林寺龐大的人口，到處都是特大
號的煮飯工具。伙房師父忙進忙出的，手上拿著各式的工具開始開伙，
如果少林弟子有需要的話，還可以跟這些師父要吃的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/k_monk" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"k06.c",
  "west" : __DIR__"k01.c",
  "south" : __DIR__"k05.c",
]));
  set("no_magic", 1);
  set("no_fight", 1);
  set("light_up", 1);

  setup();
}
