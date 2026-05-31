inherit ITEM;
inherit F_GUILDCMDS;
inherit F_AUTOLOAD;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
object horse = new("/autoload/gift/sheep");
void create()
{
  set_name(HIW"心型鈴噹"NOR,({"bell"}));
  set("long","一個心型鈴噹，用來控制工具，
  　　　　　　使用方法：
              summon_sheep ： 呼叫羊兒
              fanset       ： 設定格式: fanset <number>
              fanshow      ： 可以查詢你的傳送點所在
              waveto       ： 用過喚雲扇吧？再問就賞你一巴掌！
              throw        ： 使用格式: throw gold
      "NOR);
  set("unit","條");  
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
  add_action("do_summonsheep","summon_sheep");
  add_action("do_fanset", "fanset");
  add_action("do_fanshow", "fanshow");
  add_action("do_waveto", "waveto");
  add_action("do_throw","throw");
  return;
}

int do_throw(string arg)
{
  object me,coin;
  int i = random(7);
  me = this_player();
  coin = present("gold",me);
  if (!arg || arg != "gold")
    return notify_fail("你想丟什麼？\n");
  if (me->query_temp("havethrowpositive")==1 ||
      me->query_temp("havethrownegative")==1 ||
      me->query_temp("havethrow7")==1)
    return notify_fail("你的錢幣目前忙線中，請稍後再丟！謝謝！\n");
  if (me->is_fighting())
    return notify_fail("戰鬥中不要分心！\n");
    
  message_vision(HIW"$N拿出一枚錢幣，往上一丟，結果．．\n"NOR,me);
  if (i <= 2)
  {
   message_vision(HIC"是正面！！，$N"HIC"一時高興，攻擊力上昇了許\多。\n"NOR,me);
   me->add_temp("apply/attack",100);
   call_out("delthrow",180);
   me->set_temp("havethrowpositive",1);
  }
  else if (i >2 && i <=5)
  {
   message_vision(HIR"是反面！！，$N"HIR"當場一臉大便，毫無殺意。\n"NOR,me);
   me->add_temp("apply/attack",-100);
   call_out("delthrow",180);
   me->set_temp("havethrownegative",1);
  }
  else
  {
   message_vision(HIY"哇，中樂透了，$N"HIY"抱著小綿羊跳來跳去。\n"NOR,me);
   me->add_temp("apply/attack",200);
   call_out("delthrow",180);
   me->set_temp("havethrow7",1);
  }
  coin->add_amount(-1);
  return 1;
}

void delthrow()
{
  object me = this_player();
  message_vision("$N慢慢回復正常，等待下一次的投擲！\n",me);
  if (me->query_temp("havethrowpositive"))
  {
   me->delete_temp("havethrowpositive");
   me->add_temp("apply/attack",-100);
  }
  if (me->query_temp("havethrownegative"))
  {
   me->delete_temp("havethrownegative");
   me->add_temp("apply/attack",100);
  }
  if (me->query_temp("havethrow7"))
  {
   me->delete_temp("havethrow7");
   me->add_temp("apply/attack",-200);
  }
}



int do_summonsheep()
{
  object me = this_player();
  if(!horse)
  {
   horse = new("/autoload/gift/sheep");
   message_vision("$N搖起手上鈴鐺，"HIY"天靈靈"HIW"．．"HIY"地靈靈"HIW"．．"NOR"，$n瞬間飛到主人面前。\n",me,horse);
   message_vision("$N"HIC"哞哞叫了幾聲，唱著踏雪尋梅，往主人方向飛了過去。\n"NOR,horse);
   horse->move(environment(me));
   horse->set_leader(me);
   horse->set("family/family_name",me->query("family/family_name"));
   horse->set_temp("my_boss",(string)me->query("id"));
   me->set_temp("horse",(string)horse->query("id"));
   me->set_temp("have_horse", 1);
   horse->horsekee();
   horse->set_heart_beat(1);
   return 1;
  }
  if(environment(me) == environment(horse))
  {
   message_vision("$n對著$N親熱的磨蹭了幾下。\n",me,horse);
   horse->set_heart_beat(1);
   return 1;
  }
  if(me->query_temp("have_horse") && environment(me) != environment(horse))
  {
   message_vision("$N搖起手上鈴鐺，"HIY"天靈靈"HIW"．．"HIY"地靈靈"HIW"．．"NOR"，$n瞬間飛到主人面前。\n",me,horse);
   message_vision("$N"HIC"哞哞叫了幾聲，唱著踏雪尋梅，往主人方向飛了過去。\n"NOR,horse);
   horse->move(environment(me));
   horse->set_heart_beat(1);
   return 1;
  }
  else if(!me->query_temp("have_horse"))
  {
   message_vision("$N搖起手上鈴鐺，"HIY"天靈靈"HIW"．．"HIY"地靈靈"HIW"．．"NOR"，$n瞬間飛到主人面前。\n",me,horse);
   message_vision("$N"HIC"哞哞叫了幾聲，唱著踏雪尋梅，往主人方向飛了過去。\n"NOR,horse);
   horse->move(environment(me));
   horse->set_leader(me);
   horse->set("family/family_name",me->query("family/family_name"));
   horse->set_temp("my_boss",(string)me->query("id"));
   me->set_temp("horse",(string)horse->query("id"));
   me->set_temp("have_horse", 1);
   horse->set_heart_beat(1);
   return 1;
  }
  else
  {
   tell_object(me,"你已經有一匹羊了。\n");
   return 1;
  }
  return 1;
}


int do_fanset(string arg)
{
  object me = this_player();
  int no_transmit;
  string str,str_s;
  object where;
  if( (arg != "7") && (arg != "8") && (arg != "9") && (arg != "0"))
  {
   write("你只能設定傳送點 0,7,8,9...\n");
   return 1;
  }
  where = environment(me);
  no_transmit = where->query("no_transmit",1);
  str_s = where->query("short");
  str=file_name(where);
  if (no_transmit)
    return notify_fail("羊兒無辜地望著你,眼泛淚\光說：你去吃大便,這兒我不會記路!!\n");
  if( arg == "0")
  {
   me->set_temp("fan/0",str);
   me->set_temp("fan_s/0",str_s);
  }
  if( arg == "7")
  {
   me->set_temp("fan/7",str);
   me->set_temp("fan_s/7",str_s);
  }
  if( arg == "8")
  {
   me->set_temp("fan/8",str);
   me->set_temp("fan_s/8",str_s);
  }
  if( arg == "9")
  {
   me->set_temp("fan/9",str);
   me->set_temp("fan_s/9",str_s);
  }
  write("你設定這裡為你的新傳送點.\n");
  return 1;
}

int do_fanshow(string arg)
{
  object me = this_player();
  write("傳送點 0 是" + me->query_temp( "fan_s/0" ) +
        "\n傳送點 7 是" + me->query_temp( "fan_s/7" ) +
        "\n傳送點 8 是" + me->query_temp( "fan_s/8" ) +
        "\n傳送點 9 是" + me->query_temp( "fan_s/9" ) + "\n" );
  return 1;
}

int do_waveto(string arg)
{
  string room="";
  object *count;
  object me = this_player();  
  int i;
  if (environment(me) != environment(horse))
    return notify_fail("羊兒目前不在身邊。\n");
  if (!me->query_temp("is_riding"))
    return notify_fail("請先騎上羊兒。\n");
  if ( me->query_temp("unconcious") )
    return notify_fail("試問昏倒的人如何駕馭羊兒!?");
  if ( environment(me)->query("no_transmit") )
    return notify_fail("羊兒覺得在這裡很舒服，不願離開。");
  if ( me->is_fighting() )
    return notify_fail("先將戰鬥結束再走吧!!\n");
  switch(arg)
  {
   case "1":
            room="/open/capital/room/r70";         break;
   case "2":
            room="/open/gsword/room/su3";          break;
   case "3":
            room="/open/ping/room/road4";          break;
   case "4":
            room="/open/trans/room/room4";         break;
   case "5":
            room="/open/start/room/s5";            break;
   case "10":
            room="/open/port/room/r3-1";           break;
   case "6":
            room = me->query("startroom");         break;
   case "7":
   case "8":
   case "9":
   case "0":
   if (!room = me->query_temp( "fan/"+ arg ) )
     return notify_fail("抱歉, 沒有你所要去的地方的資料。\n");
     break;
   case "gs":
             room = "/open/wiz/gs.c";               break;
   default:
           return notify_fail("抱歉, 沒有你所要去的地點。\n");
  }
  message_vision( HIW+"$N搖搖屁股，便往天邊飛去。\n"+NOR ,horse,me);
  if (room && !me->move(room) )
    return notify_fail("目的地無法到達。\n");
  message_vision(HIW+"白光閃過,"HIY"小綿羊"HIW"載著$N由天而降。\n"+NOR,me);
  horse->move(room);
  horse->set_heart_beat(1);
  return 1;
}

int query_autoload()
{
  return 1;
}
