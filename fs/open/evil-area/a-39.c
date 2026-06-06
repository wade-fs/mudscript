inherit ROOM;
#include <ansi.h>
#include "damage_water.c"

void create()
{
	set("short","沙漠");
	set("long",@LONG
火熱般的大地不斷的消耗著你對於生命的看法，你漸漸地有輕生
的念頭，只想趕緊的脫離這個走不出去的大地與殺不完的邪獸，你毫
無意識的走到了這裡，四處高聳的沙丘擋住了你的去路，你無奈著低
頭，卻發現了一個奇怪的圖形，就畫在地上...
LONG);
        set("light_up",-1);
	set("no_transmit",1);
	set("evil_area",1);
	set("item_desc",([
"圖形":"
   奇形怪狀的圖案畫滿了整個地上，大略上是呈現一個圓形的圖案，
圖案中，寫著一些密密麻麻的奇異字型，感覺上，似乎踏進入(enter)
咒術陣內，就會發生什麼事情...\n",
]));
	set("exits",([
"west":__DIR__"a-32",
]));
	setup();
}
