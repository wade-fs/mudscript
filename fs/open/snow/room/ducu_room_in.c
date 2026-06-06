#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤陵靈堂");
          set("long",@LONG
這裡就是獨孤陵的靈堂﹐堂上所祭拜的乃是雪蒼派第三代掌門獨孤愁﹐外號叫
「九轉邪雲」﹐相傳在十年前﹐獨孤愁乃是武林四大高手之一﹐與仙劍派的鄭士欣
﹐魔刀莫測﹐及儒門第一高手刑千書三人並列﹐獨孤愁以拿手的雪蒼鬼影腳及其自
創之黑影迷蹤步法﹐奪得武林「霸王尊」之名。在靈位旁的是獨孤愁生前所作的詩
句﹐詩句上寫著﹕
      
          「江湖幾番狂霸中﹐奈合幾回無名」
 
                          「四海何時風雲起﹐怎知獨孤無愁」
 
 
LONG);
        set("exits", ([
	"east":__DIR__"ducu_room",
	"west":__DIR__"ducu_room_in1",
	"north":__DIR__"ducu_live",
        ]) );
	set("light_up",1);
        setup();
}
