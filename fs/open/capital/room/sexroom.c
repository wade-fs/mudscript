#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{  set ("short","醫館");
   set ("long",@LONG
一間有點簡陋破舊的醫院,門面裝飾的亂七八糟,不過這裡的變性
手術聽說很有名喔,一進去則有一個大媽堆著滿臉肥肉歡迎你,牆上則
掛著一個大木牌還有幾張泛黃的職照,看來這裡主治醫師的來頭還不少
哩,往裡頭看去有間小小的手術室,醫師正在幫人動大手術吧.

LONG);
    set("exits", ([ /* sizeof() == 3 */
          "east"  :  __DIR__"faceroom",
           "north"  :  __DIR__"groom",
           "south"  :  __DIR__"h06",
]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/capital/npc/shyu1"       :     1,
]));
  set("no_kill", 1);
  set("no_fight", 1);
  set("no_magic", 1);
set ("light_up",1);
setup();
}
int valid_leave(object who, string dir)
{
if( dir=="north" && !who->query_temp("change") )
return notify_fail("徐大媽怒眼看著你說道 : 林老酥啦！想做什麼？\n");
if( dir=="east" && !who->query_temp("faceoff") )
return notify_fail("徐大媽怒眼看著你說道 : 機車啦！別亂闖好嗎？\n");
        return ::valid_leave(who, dir);
}
