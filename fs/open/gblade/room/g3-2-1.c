#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "王元霸的房間");
  set ("long", @LONG

房間的陳設相當的華麗，臨窗的大炕上鋪著猩紅洋毯，正面設著大紅金線
蟒引枕，秋香色金線蟒大條縟；兩邊設一對梅花式洋漆小几，左邊擺著文
王鼎，鼎傍匙莇香盒。右邊擺著汝窯美人觚，裡面插著時鮮花草。地下面
四張大椅都搭著銀紅撒花椅搭，底下四副腳踏。

LONG);

  set("light_up", 1 );
  set("exits", ([ /* sizeof() == 1 */
  "south": __DIR__"g3-2",
]));

create_door("south", "雕花紫檀木門", "north", DOOR_CLOSED);
  setup();
}
