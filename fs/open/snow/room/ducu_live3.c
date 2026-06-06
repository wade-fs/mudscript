#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤居書房");
	set("long",@LONG
這裡是獨孤愁平時遊讀詩書﹐觀看百家經點的書房﹐房間雖小﹐卻擺滿了
諸子百家的經典﹐獨孤愁不枉為一才子﹐裡頭的每本書﹐他至少看過百遍以上
﹐而且倒背如流﹐由此可見﹐獨孤愁不只喜好武藝﹐也十分重視文學。
 
 
LONG);
        set("exits", ([
	"east":__DIR__"ducu_live2",
	"north":__DIR__"ducu_live4",
        ]) );
	set("light_up",1);
        setup();
}
