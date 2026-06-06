#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "簡陋的竹屋");
        set("long", @LONG
這屋子內亂的不得了，到處是吃剩的食物殘紮，幾個人圍在中間那張大桌子
旁，專心的看著桌上那個大碗，一個人蹲在桌子上頭，大聲的吆喝著︰西八剌！！
LONG
        );

        set("exits", ([
"out":__DIR__"fair"
        ]) );
        
set("objects",([
"/u/b/bigcat/mob/tmob":1
               ]));
setup();


}
