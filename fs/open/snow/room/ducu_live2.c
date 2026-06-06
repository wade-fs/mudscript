#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤居小廳");
          set("long",@LONG
這裡是獨孤居的正廳﹐雖然只是一間小房廳﹐但布置格局有
股文人氣息﹐沒有一代武宗般的氣勢。獨孤愁平時練功練至黃昏
之時﹐便會泡壺清茶﹐坐在這小廳之中﹐細細品味閒居之樂。
 
 
LONG);
        set("exits", ([
	"out":__DIR__"ducu_live1",
	"west":__DIR__"ducu_live3",
        ]) );
	set("light_up",1);
        setup();
}
