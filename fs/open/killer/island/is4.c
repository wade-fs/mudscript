inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "船隻擱淺處");
  set ("long", @LONG
前往東瀛的船隻就擱淺在這裡, 幾位船員正在忙碌的修補船底, 而其他的船
員也在此地搭起營帳 (tent). 此地大約位在小島的東南方,東邊是沙岸, 海岸的
景色十分優美, 北邊也是沙灘, 除了一兩棵乾枯的樹幹, 其他空曠礦的沒有什麼
東西.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "tent" : "
隨行人員所搭建的,從他們的手法來看應該是相當豐富. 船員們正開始分
工合作,有些做飯有些修船,有些將船上貴重物品搬運下來,十分的有效率.

",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is7.c",
  "east" : __DIR__"is5.c",
  "west" : __DIR__"is3",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/son.c" : 1,
  __DIR__"npc/shipm.c" : 1,
]));
  set("outdoors", "/u/u");
  setup();
}
void init()
{
object me=this_player();
add_action("report_ok", "report");
if (me->query_temp("can_back",1))
{
tell_object(me,HIY + "\n魯尋突然匆匆忙忙跑過來說: 船隻修好了!!\n魯尋說道: 等你準備好要返行時回報(report)我一聲就行了.\n" + NOR);
return ;
}
return ;
}
int report_ok()
{
object me;
me=this_player();
if (me->query_temp("can_back")==1)
{
tell_object(me,HIY + "你說道: 我準備好了, 可以出發了!!\n" + NOR);
call_out("b1",2,me);
me->delete_temp("can_back",1);
return 1;
}
else
{
return 0;
}
}
int b1(object me)
{
tell_object(me,HIC + "\n當一切準備就緒, 我和船員們搭上商船離開這座島嶼. \n" + NOR);
me->move(__DIR__"ship");
call_out("b2",4,me);
return 1;
}
int b2(object me)
{
tell_object(me,HIC + "船隻在海上緩緩航行, 那座小島在眼中也漸漸變小 ...\n" + NOR);
call_out("b3",6,me);
return 1;
}
int b3(object me)
{
tell_object(me,HIC + "回程上風平浪淨並沒有發生什麼意外, 過了幾天我們終於回到楓林港. \n" + NOR);
call_out("b4",3,me);
return 1;
}
int b4(object me)
{
tell_object(me,HIY + "魯尋說道: 我們回到楓林港了, 該去跟我父親回報(report)這次出行發生的事了 !\n" + NOR);
me->move("/open/port/room/r5-3");
return 1;
}

