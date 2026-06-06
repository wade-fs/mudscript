#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
這兒是巖穴的內部，潮濕的空氣讓你連呼吸都有些窒礙不通，你好想趕快離開
這個鬼地方，地上的小碎尖石刺得你渾身不舒服。不過這兒岩壁上的拳印又比
出口處要多了一些，而且更為明顯了。
LONG
        );

        set("exits", ([
"west":__DIR__"whole1",
"east":__DIR__"hole"
        ]) );
setup();

}
