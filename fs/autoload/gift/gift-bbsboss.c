//2003-03-18  網聚gift for bbsboss by frequency
inherit ITEM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
object me = this_player();
void create()
{
  set_name(GRN + "萬" + HIG + "相" + HIC + "氣" + HIB + "海" + HIM + "符" + NOR,({"bbsboss-sign"}));
  set("long",HIW + "蘊藏無限靈氣的遠古神物。\n" + NOR);
  set("unit","張");  
  set("no_auc",1);
  set("no_sell",1);
  set("no_put",1);
  set("no_give",1);
  set("no_drop",1);
  set("no_get",1);
  set("no_steal",1);
  set("no_save",1);
  setup();
}

void init() 
{
 add_action("do_turnon","turn_on");
 add_action("do_turnoff","turn_off");
 return;
}

int do_turnon()
{
    message_vision(RED + "$N誠心的將" + GRN + "萬" + HIG + "相" + HIC + "氣" + HIB + "海" + HIM + "符" + RED + "垂吊在胸前，天地靈氣源源不絕湧入氣海。\n" + NOR,me);
    set_heart_beat(1);
    return 1;
}

int do_turnoff()
{
    message_vision(RED + "$N將" + GRN + "萬" + HIG + "相" + HIC + "氣" + HIB + "海" + HIM + "符" + RED + "取下收好，天地靈氣逐漸回歸天象。\n" + NOR,me);
    set_heart_beat(0);
    me->set("force_factor",10);
    return 1;
}

void heart_beat()
{
    if(!present(this_object()))   set_heart_beat(0);
    if(me->query("force_factor")<100)
    {
      me->set("force_factor",100);
    }
    if(random(9)==1)
    message_vision(YEL + "萬相形意的奧秘不斷地在$N腦海裡衝擊既有的武學常規，使得$N對武道有更多體會。\n" + NOR,me);
}

int query_autoload()
{
      return 1;
}
