inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIG + "琰 揚 居 -- " + NOR+YEL + "大 松 樹" + NOR);
	set("long",@LONG
一片晴空，你正緊緊的抓著樹幹遙望著無盡的大地，一片雲海就
踩在你腳下，偶爾可以看到經過太陽照射而產生的七彩雲，偶爾也可
以看到一些不知名的生物飛翔於雲端之上，對於能目睹這種奇景，你
有一種說不出來的感動...不過...看來你得先跟這群〔蜜蜂〕解釋著
你為何會來侵犯它們的領地，不然你可能就要倒大楣了...但是...希
望它們會了解你的來意...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/queen_bee":1,
]));
	set("exits",([
"down":__DIR__"b-45",
]));
	setup();
}
