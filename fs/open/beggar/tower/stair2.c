inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY + "不死鳥ソ塔最上部" + NOR);
        set ("long", @LONG 
再往上走去就是塔頂了，強風在上頭呼嘯著，灼熱
的高溫更是越發駭人，好不容易來到這裡，記得千萬要
運起十成功力護身，免得功敗垂成。
LONG);

        set("light", 1);
        set("no_auc", 1);
        set("no_scale",1);
        set("no_chome", 1);
        set("no_transmit",1);
        set("exits", ([ /* sizeof() == 1 */
                       "up" : __DIR__"top.c",
          ]));
        setup();
}
