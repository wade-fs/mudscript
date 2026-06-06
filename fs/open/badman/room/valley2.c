// Room: /open/badman/room/valley1.c
// written by powell 96.4.26@FS

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "神秘山谷");
  set ("long", @LONG
一走到這裏，四周都被蒼鬱的樹林所圍繞，只有西邊的樹林較
為稀疏，看來已經沒路可走了。樹林裏的猴子還不時探頭瞧瞧你，
可見得這群猴子還是害怕你這個闖入牠們生活的不速之客。

LONG);
 
  set("objects", ([
  BAD_NPC"m-king" : 1,
  BAD_NPC"monkey" : 2,
  ]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"valley1",
]));

  setup();
}
