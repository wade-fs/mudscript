#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "專業殺手訓練室");
  set("long", @LONG
  這裡有一系列的訓練課程，由初級到高級，應有盡有。
  在一樓的是初級班，適合新進殺手拿匕首練習。
  在二樓的是高級班，一般新進殺手可不要亂闖。

LONG);
    set("light_up", 10);
   set("exits", ([
   "north": __DIR__"waterm.c",
    "west": __DIR__"r12",
    "east": __DIR__"r11.c",
      "up": __DIR__"r0u.c",
   "south": __DIR__"boardrm.c",
    ]));
   set("objects",([
         "/open/killer/npc/train_d.c":  3,
           ]));
 setup();
}
