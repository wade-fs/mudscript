inherit ROOM;
#include <ansi.h>
void create ()
{
set("short", "沙灘");
set("long",@long
眼前是景色明亮的沙灘，海水清澈，一些螃蟹之類的水中生物都能
看的清清楚楚，遠處有幾個小孩子正在嬉戲玩水，一股平靜的氣息讓你
說不出來的受用!!
long);
set("exits",([
"north":__DIR__"beach02",
"eastdown":"/open/killer/outsea/seagate03",
]));
setup();
}
