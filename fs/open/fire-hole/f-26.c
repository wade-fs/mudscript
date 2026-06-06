#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "火龍幻界");
  set ("long", @LONG
火光四射, 烈燄直衝天頂, 使得這裡的氣候十分炎熱, 四周都是火光,
這大概是統治著這裡的怪物以無窮的力量所造成的火之結界, 當你來到了這
時, 同時被它的火光迷惑, 找不到正確的出路。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f-24.c",
  "southwest" : __DIR__"f-30.c",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/fire-bat.c" : 1,
]));

  setup();
}

int start()
{
        object room = this_object();
        call_out("del",1800,room);
        return 1;
}

int del(object room)
{

        room = this_object();
        room->delete("no_reset");
        return 1;
}
