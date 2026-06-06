#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
這兒是巖穴的盡頭，四周一片平坦，是個練功的好地方，看了看這四面的岩壁
發現滿是密密麻麻的蠅頭小字，趨前一看，好像記錄著一些武功招式，不過你依
招演練了一下卻發現這好像只是一般的武功，另你大感失望。
LONG
        );

        set("exits", ([
"east":__DIR__"whole",
        ]) );
setup();

}
