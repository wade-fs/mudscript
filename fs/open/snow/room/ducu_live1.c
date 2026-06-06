#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤居");
          set("long",@LONG
這裡是獨孤愁生前居住之地﹐雅號「獨孤居」﹐獨孤愁一生孤傲﹐
不喜言語﹐但閒來沒事便作作小詩自娛﹐也堪稱是武林中一位才子高人
﹐在獨孤居處處可以看見獨孤愁生前所留下的詩詞。在此門口可以看到
一幅對聯﹕
 
                「狂風飛雪鬼影動﹐
                            
                              浮雲秋雨騷人愁。」
                 
 
LONG);
        set("exits", ([
	"south":__DIR__"ducu_live",
	"enter":__DIR__"ducu_live2",
        ]) );
	set("light_up",1);
        setup();
}
