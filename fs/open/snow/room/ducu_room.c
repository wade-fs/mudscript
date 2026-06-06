#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤陵門口");
          set("long",@LONG
這裡是獨孤陵的門口﹐只見牆上掛著牌子寫著﹕
     
       【 雪蒼派第三代掌門 「九轉邪雲」獨孤愁之陵寢 】
 
       【 黃 】                               【 一 】
       【 雲 】                               【 生 】
       【 白 】                               【 一 】
       【 髮 】                               【 笑 】
       【 雪 】                               【 莫 】
       【 蒼 】                               【 知 】
       【 蒼 】                               【 愁 】
 
 
LONG);
        set("exits", ([
	"west":__DIR__"ducu_room_in",
	"east":__DIR__"room20",
        ]) );
	set("light_up",1);
        setup();
}
