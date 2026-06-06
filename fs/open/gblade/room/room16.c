// Room: /u/m/moner/tree/room16.c
inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG

經過了重重的路徑，你來到了樹林的出口，就在你鬆了一口氣的時後
，你發現前方有一個山洞，一絲絲的光線從洞中傳出，你決定進去看看。
      天空烏雲滿佈，陰暗的光線中勉強能看清方向。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17.c",
  "north" : __DIR__"room15.c",
]));
  set("outdoors", "wind");
set("no_plan",1);
  setup();
}
int valid_leave(object me, string dir)
{
if(dir=="west")
if((me->query("family/family_name")!="魔刀莫測")&&me->query("family/family_name"
)!="魔刀門")
return notify_fail("只有魔刀才可進。\n");
  return ::valid_leave(me,dir);
}
