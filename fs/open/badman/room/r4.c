// Room: /open/badman/room/r4

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "病房");
  set ("long", @LONG
一走進這裡，你就聞到一股刺鼻的藥味，原來這裡是萬春流試
驗新藥材的房間。你看到一旁的爐子上正煮著各式各樣的藥草，每
樣都是你沒看過的新藥材，讓你大開眼界。自從當年萬春流躲入惡
人谷以後，便潛心研究更高深的醫術，二十多年來也陸續發現了許
多新的藥方，無一不是彌足珍貴。不過在這間房間中最吸引你注意
的，還是放在牆角邊的一個大藥缸。
    東邊有一扇木製的門。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r2",
]));
  set("light_up", 1);

  create_door("east", "木門", "west", DOOR_CLOSED);
  setup();
}
