inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"HIG" 同 心 橋 "NOR);
	set("long",@LONG
兩個強大的邪靈正站立於兩旁，彷彿門神般的守護著這，感覺上
裡面似乎住著十分尊貴的人物，不過卻有一種被軟禁的感覺，看來儘
管是你，也無法通過這一扇門進入此建築物內。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-25",
]));
	setup();
}

 
