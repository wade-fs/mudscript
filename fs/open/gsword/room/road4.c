#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "平台");
        set("long", @LONG
   
眼前是寬約寸許的石梁，橫架在兩座山之間，雲氣籠罩,望不見盡
處奔一段躍過了七個斷崖，石梁已到了盡頭，眼前是一望無際的石階，
看來仙劍派應不遠了。

LONG
        );

        set("exits", ([
                "south":__DIR__"road1",
               "up":__DIR__"road6",
        ]) );
        set("outdoors","/open/gsword");
setup();

}
