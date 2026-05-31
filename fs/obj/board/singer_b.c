inherit BULLETIN_BOARD;
#include <ansi.h>
                                                                
void create()
{
        set_name(HIC"詠樂門菱晶碑"NOR,({"singer board", "board"}));
        set("location","/open/singer/m01");
        set("board_id","singer_b");
        set("long","
一個碩大菱形多角的寶藍水晶，藉由光線的折射，有波紋般的字流盪
其中。
\n");
        set("capacity", 30);
        setup();
}

