// Room: /u/r/ranko/vil1.c
inherit ROOM;

void create ()
{
  set ("short", "隔世村村口");
  set ("long", @LONG
這裡是隔世村的村口，此村由於地處偏僻，且村民大多自給自
足，不需外來的物資供給，因此此地鮮有外人造訪，村民們過著與
世隔絕的生活，這也是此村村名的命名來由。
 
LONG);

  set("light_up", 1);
  set("outdoors", "/u/r/ranko");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"road9.c",
  "west" : __DIR__"v2-1.c",
]));

  setup();
}
