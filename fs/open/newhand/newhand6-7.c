#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空間歷史發展館"NOR);
  set( "long", "狂想空間後來就架設在中興大學管理的大神是Weiwei,同時Weiwei將狂
想的lib釋放出去,另外Weiwei開始著手改版狂想空間,早期的狂想空間
是使用MudOS v21c2的driver,但是有很多的缺點存在,例如人數限制因
driver的關系只能在四十人之下..還有存在一些蠻大的BUG,後來Weiwei
修正了一個月左右(我聽說的,可能更長)改板至MudOS v22 a16的板本，
同時間之前狂想的巫師Anmy也在雄專架起了狂想南部分站
" );

  set("exits", ([
  "north" : __DIR__"newhand6-6",
  "south" : __DIR__"newhand6-8",
               ]));
  set("light_up", 1);
  setup();
}

