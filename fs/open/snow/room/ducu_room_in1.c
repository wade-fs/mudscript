#include <room.h>
#include "../../open.h"

inherit ROOM;

void create()
{
	set("short","獨孤靈寢");
          set("long",@LONG
這裡是獨孤愁的靈寢﹐停放著一具棺木﹐外層用黑紗包住﹐棺木
所停放的想必是雪蒼派的絕代高人獨孤愁的靈體﹐相傳獨孤愁是無疾
而終的﹐但也有人懷疑獨孤愁是遭人暗算而死﹐此外﹐另有一說﹐說
獨孤愁是裝死以瞞天下人耳目﹐但裝死的目地為何﹐卻又無法解釋。
 
LONG);
        set("exits", ([
	"east":__DIR__"ducu_room_in",
	"north":__DIR__"ducu_room_in2",
        ]) );
	set("objects",([
		SNOW_OBJ"box":1,
	]));
	set("light_up",1);
        setup();
}
