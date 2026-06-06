#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","洞穴入口");
  set ("long", @LONG
這個洞穴看起來挺神秘似的﹐洞穴的石壁刻著一條龍的形狀
相傳武林中有一個殺手組織﹐名叫「黑牙聯」﹐據聞此組織十分
神秘﹐所培養出來的殺手﹐殺無不克﹐奪人命於瞬間﹐而這個組
織的象徵標制﹐和這條龍形十分類似。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"out":__DIR__"black2",
	"enter":__DIR__"black4",
]));
       set("objects",([
   "/open/killer/npc/guard.c" : 2,  ]));

  setup();
}
