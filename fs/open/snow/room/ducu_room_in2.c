#include <room.h>
#include "../../open.h"
inherit ROOM;

void create()
{
	set("short","獨孤愁衣冠陵");
          set("long",@LONG
這裡是獨孤愁的衣冠陵﹐所陳放的是獨孤愁慣的用的衣服物品﹐
相傳獨孤愁生前曾遠赴東北太行山﹐打死千嶺邪狼﹐並取下邪狼的皮
做成一件「邪雲霞衣」﹐是一件珍寶﹐據聞一般的兵器是無法割開此
衣的﹐而當年獨孤愁乃是靠著雪蒼派所流傳下的神兵利器「惘劍帳刀
」才制服邪狼﹐但現今為防此寶衣遭竊﹐已被藏在某一密秘地帶﹐除
了雪蒼派幾為輩份較高的人之外﹐沒人知道。

 
LONG);
        set("exits", ([
	"south":__DIR__"ducu_room_in1",
        ]) );
	set("objects",([
	SNOW_OBJ"c_box":1,
	]));
	set("light_up",1);
        setup();
}
