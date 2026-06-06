
#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","打鐵室");
  set ("long", @LONG

    你在還沒進來之前就聽到打鐵的聲音轟轟作響﹐這裡
充滿了各式各樣的兵器﹐以矛﹑槍﹑戢類就多﹐在一旁有
一個粗壯的人在玩弄著兵器﹐邊玩邊打鑄兵器﹐你心想這
人的傢伙那麼多﹐不如先閃為妙。。。
你可以(list)看看有啥武器或(receive)領取武器

LONG);

  set("exits", ([ /* sizeof() == 3 */
        "out":__DIR__"r28",
]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/piko":1,
]));

  set("no_light",1);
  setup();
}
 
