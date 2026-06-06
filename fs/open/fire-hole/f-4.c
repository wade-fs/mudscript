#include <ansi.h>
inherit ROOM;
#include "firestorm.c"
void create ()
{
  set ("short", "火龍幻界");
  set ("long", @LONG
火光四射, 烈燄直衝天頂, 使得這裡的氣候十分炎熱, 四周都是火光,
這大概是統治著這裡的怪物以無窮的力量所造成的火之結界, 當你來到了這
時, 同時被它的火光迷惑, 找不到正確的出路。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f-2.c",
  "southwest" : "/open/fire-hole/f-6.c",
]));
  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  setup();
}
