inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
清風吹拂～你繞著湖面走了一段時間，不自覺的停下了腳步坐在
湖泊一旁長滿著翠綠色的青草地上，看著一些人與邪獸安詳的生活在
一起，你有種說不出來的感動，回想起剛剛在外面殺戮了不少邪獸，
你不禁猜測起他們是否也想過著這種生活，漸漸地，內心產生了一種
罪惡感。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-19",
"east":__DIR__"a-17",
]));
	setup();
}

 
