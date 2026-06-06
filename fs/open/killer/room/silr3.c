#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","銀狼組組");
  set ("long", @LONG
這裡是黑牙聯總壇大廳左翼，也是黑牙聯最狡詐的銀狼暗殺組的所在地。
韋亦玄在此處，策畫黑牙連的所有暗殺計畫，並且訓練暗殺人員。
各大門派有不少人，被銀狼組所設下的圈套所殺害。
如果沒事還是不要在此處亂走，以免遭到殺害。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east":__DIR__"silr4",
  "north":__DIR__"silr2",
]));

  set("objects",([
        "/open/killer/npc/hu_fa2.c" : 1,
        ]));  
  setup();
}
