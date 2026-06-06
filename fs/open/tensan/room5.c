inherit ROOM;
#include <ansi.h>
void create () {
        set ("short","登山步道");
        set ("long",@LONG
此處兩旁長滿了茫草，路邊一塊石頭上面刻著天山兩字，你恍然大悟
，原來這裡就是江湖傳聞中的聖地天山，你不知不覺的加快腳步想早日尋
得奇人異事來增加你的人生經驗。
LONG);
           
        set("exits", ([ /* sizeof() == 1 */
        "westup" : __DIR__"room6",
        "eastdown" :  __DIR__"room4",       
        ]));

       
        setup();
}
