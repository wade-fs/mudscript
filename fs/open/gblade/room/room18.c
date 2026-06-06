// Room: /u/m/moner/tree/room17.c
inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG

你跟隨著光線前進，藉著微弱的光線，你可以看清四周，你驚訝的發
現，這裡的山壁平滑，顯然是出於人手，照地勢的起伏看來，這裡應該是
山腰。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room19.c",
  "east" : __DIR__"room17.c",
]));
set("objects",([
"/daemon/class/blademan/npc/sublade2.c":1,
]));
set("no_transmit", 1);
  setup();
}
int valid_leave(object me, string dir)
{
if(dir=="west"&&(present("sublade man",environment(me))||present("sublade1 man",environment(me))))
   return notify_fail("守關者說道：沒打倒我就想進去，別妄想了!!!\n");
return ::valid_leave(me,dir);
}
