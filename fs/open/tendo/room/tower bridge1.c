#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "斷魂橋");
  set ("long", @LONG
兩旁岩壁陡峭，原本有一座橋，但不知為何早已遭受破壞許久，
此處臨空數百丈，俯視腳下，驚險萬狀，你注意到高空垂著一條長索
長索的另一端綁在一塊大石頭上，崖下山林飛瀑，河川奇石，崖下景
物盡收眼底。
LONG);

  set("exits", ([
  //"south" : "/open/tendo/room/g5-1.c",
  ]));
  set("light_up", 1);
  set("outdoors",1);

  setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_fly","fly");
}

int do_fly(string str){
 int exp;
 object me;
 string name;
 me = this_player();
 exp=me->query("combat_exp",1);
 name=me->query("name");
  if(!str || str != "line"){
        tell_object(me,HIC + "你還真的以為你會臨空飛渡啊!!不借力怎飛躍呢？\n" + NOR);
        return 1;
                           }
  if(exp < 1500000){
        tell_object(me,HIC + "你的武學修為還不夠，可能會飛不過去而跌死喔。\n" + NOR);
        return 0;
                  }
  tell_object(me,HIC + "只見你借力使力，一腳踏在長索上,順勢而過。\n" + NOR);
  tell_object(users(),HIW + "
                  「孤卒浴血鬥志高，千秋定論難爭峰；

                         昊日顯照星光掩，百川匯宗誰與共。」

      "+HIY+name+HIW"臨空飛渡了" + HIR + "斷魂之橋" + NOR + "，毅然地步上了鎖妖塔之途。\n" + NOR);
  me->move("/open/tendo/room/tower/tree1");
  return 1;
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,HIW + "一條破破爛爛的長索(line)，看起來搖搖欲墜，如果你膽子夠大的話，可以試著臨空飛渡而過(fly)。\n" + NOR);
 return 1;
}
