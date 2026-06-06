inherit ROOM;
#include <ansi.h>
void create () {
        set ("short","天山山腳");
        set ("long",@LONG
你抬頭一望，天山山頂直聳雲霄，從山腰開始一片的雪白往上延伸。
定神一看似忽在遠處有座宏偉的建築，你的好奇心不斷的催促你加快腳步
往前走去
LONG);
           
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"room2",
        "southeast" : "/open/main/room/f3",       
        ]));

       
        setup();
}
