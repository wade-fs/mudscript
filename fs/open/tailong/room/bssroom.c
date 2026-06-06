inherit ROOM;

void create ()
{
  set ("short", "葛雷新專用練功\房");
  set ("long", @LONG
這裡是給葛雷新的分身專用的練功房，平常的人是不容
許進來的。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"d2",
]));
  set("objects",([
  "/u/b/bss/train2.c" : 1,
]));
  setup();
}

