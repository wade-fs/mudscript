inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + HIG + " 同 心 橋 " + NOR);
	set("long",@LONG
腳下踏著厚實的石板道，你扶著橋上的圍欄，四處望去，只覺得
視野相當的寬闊，陣陣微風吹拂～夾帶著豐富的水氣，你只覺得一陣
清涼，自我打氣提了下精神，又繼續了你的旅程～
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-23",
"south":__DIR__"a-25",
]));
	setup();
}

 
