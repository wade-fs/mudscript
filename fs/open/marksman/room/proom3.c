// Room: /open/marksman/room/proom3.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "小墓園");
  set ("long", @LONG
你眼前的是一個小墓園, 墓園四周重滿了花草, 只不過
看起來似乎沒有人整理了。墓碑上好像有寫幾個大字, 你要不要
讀看看(read stone)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"proom2",
]));
  set("outdoors", "/open/marksman");

  setup();
}
void init()
{
add_action("do_read","read");
add_action("do_pray","pray");
}

int do_read(string str)
{
object me =this_player();
if(!str || str != "stone")
{
  tell_object(me,"你要念什麼??\n");
 return 1;
}
if(me->query_temp("findbook")!=5)
{
  tell_object(me,"墓碑上的字跡你現在似乎看不清楚\n");
  return 1;
}
me->set_temp("can_say",1);
tell_object(me,
HIC"魔教義女 - 莊靜香之墓

"HIW"你看到了這九的大字嚇了一跳
沒想到伍元魂牽夢掛的愛人居然死了
虧伍元為了她等了那麼久....

你不如對她祈禱<pray>一下吧, 說不定伍元
的話真的可以帶到她的耳邊...\n"NOR);
  return 1;
}

int do_pray(string str)
{
object me=this_player();
if(!str || str!= "嫦娥應悔偷靈藥") 
{ tell_object(me,"你要說什麼\n");
  return 1;
}
if(me->query_temp("findbook")==5 && me->query_temp("can_say")==1 && me->query("class")=="poisoner" && me->query_temp("go_oldman_report")!=1)
{
  tell_object(me,HIW"你默默的唸了這段字後, 突然吹起一陣微風
風聲中帶著一道聲音 : "HIC"碧海青天夜夜深"HIW"
似乎是要你回去帶回給伍元<report>......\n"NOR);
me->set_temp("go_oldman_report",1);
return 1;
}
tell_object(me,"沒什麼事發生");
return 1;
}
