#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "瀑布");
        set("long", @LONG
        
        
一下船,眼前景色如畫,清溪潺潺,水流平穩之極,兩旁滿是隨風飄逸的垂柳
,其中還夾植著無數桃樹,一陣清風拂來挾著清新的花香,令你精神為之一振
,這兒跟外面的世界決然不同,簡直就是世外桃源!!



LONG
        );

        set("exits", ([
                "north": __DIR__"road4",
                "down":__DIR__"road1",
        ]) );
        
setup();

}
