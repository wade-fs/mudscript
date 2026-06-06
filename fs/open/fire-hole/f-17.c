#include <ansi.h>
#include "firestorm.c"
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
  "northwest" : __DIR__"f-7.c",
  "southeast" : __DIR__"f-22.c",
]));
  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  setup();
}
