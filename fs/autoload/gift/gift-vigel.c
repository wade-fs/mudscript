//2003-03-18  網聚gift for vigel by frequency
inherit ITEM;
inherit F_GUILDCMDS;
inherit F_AUTOLOAD;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
object me = this_player();
object horse = new("/autoload/gift/blood-horse");
void create()
{
  set_name(HIY"御"HIW"用"HIB"韁繩"NOR,({"blood-horse-halter"}));
  set("long",HIC"駕馭汗血寶馬需的器具。\n"NOR);
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
 add_action("do_summonhorse","summon_horse");
 add_action("do_gmove", "gmove");
 add_action("do_fanset", "fanset");
 add_action("do_fanshow", "fanshow");
 add_action("do_waveto", "waveto");
 return;
}

int do_summonhorse()
{
    if(!horse)
    {
    horse = new("/autoload/gift/blood-horse");
    message_vision(RED"$N撮唇一聲清嘯，"HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIM"如一道紅光般閃現。\n"NOR,me);
    message_vision(HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIG"四蹄一振，朝著主人所在的方位飛奔而去。\n"NOR,horse);
    horse->move(environment(me));
    horse->set_leader(me);
    horse->set("family/family_name",me->query("family/family_name"));
    horse->set_temp("my_boss",(string)me->query("id"));
    me->set_temp("horse",(string)horse->query("id"));
    me->set_temp("have_horse", 1);
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
    message_vision(HIM"$N撮唇一聲清嘯，"HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIM"如一道紅光般閃現。\n"NOR,me);
    message_vision(HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIG"四蹄一振，朝著主人所在的方位飛奔而去。\n"NOR,horse);
    horse->move(environment(me));
    horse->set_heart_beat(1);
    return 1;
    }
    else if(!me->query_temp("have_horse"))
    {
    message_vision(RED"$N撮唇一聲清嘯，"HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIM"如一道紅光般閃現。\n"NOR,me);
    message_vision(HIW"〒"HIY"神駒"HIW"〒"HIR"汗血寶馬"HIG"四蹄一振，朝著主人所在的方位飛奔而去。\n"NOR,horse);
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
    message_vision("$N已經有一匹馬了。\n"NOR,me);
    return 1;
    }
    return 1;
}

int do_gmove(string arg)
{ 

   if( me->query("class") == "officer"||me->query("class") == "blademan" || wizardp(me))
   {
   switch(arg)
   {
     case "on":
           me->set_temp("gmove",1);

           write("群體移動模式 開起(on)!!!\n");
           break;
     case "off":
           me->delete_temp("gmove");
           write("群體移動模式 關閉(off)!!!\n");
           break;
     default:
           write("群體移動: gmove <on|off>\n");
   }
  return 1;
   }
      write("此命令限 官員(officer)和刀客(blademan)使用.\n");
      return 1;
}

int do_fanset(string arg)
{
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
        write(  "傳送點 0 是" + me->query_temp( "fan_s/0" ) +
              "\n傳送點 7 是" + me->query_temp( "fan_s/7" ) +
              "\n傳送點 8 是" + me->query_temp( "fan_s/8" ) +
              "\n傳送點 9 是" + me->query_temp( "fan_s/9" ) + "\n" );
        return 1;
}

int do_waveto(string arg)
{
        string room="";
        object *count;
        int i;
        if(environment(me) != environment(horse))
                return notify_fail("神駒目前不在身邊。\n");
        if(!me->query_temp("is_riding"))
                return notify_fail("請先騎上神駒。\n");
        if( me->query_temp("unconcious") )
                return notify_fail("試問昏倒的人如何駕馭神駒!?");
        if( me->is_fighting() )
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
                        if( !room = me->query_temp( "fan/"+ arg ) )
                                return notify_fail("抱歉, 沒有你所要去的地方的資料。\n");
                        break;
                case "gs":
                        room = "/open/wiz/gs.c";               break;
                default:
                        return notify_fail("抱歉, 沒有你所要去的地點。\n");
        }
        message_vision( HIW+"神駒展翅一振，載著$N朝天邊飛去。\n"+NOR ,me);

        if( me->query_temp("gmove") )
        {
                count = all_inventory( environment(me) );
                i = sizeof( count );

                if( !me->move(room) )
                        return notify_fail("目的地無法到達。\n");

                while(i--)
                {
                        if( count[i]->is_character() &&
                            !userp(count[i]) &&
                            !count[i]->is_fighting() &&
                        ( count[i]->query_temp("id") == me->query("id")
                        || count[i]->query_leader() == me ) )
                        count[i]->move(room);
                }

                message_vision(HIR+"一道亮眼紅光閃過,$N帶領眾人從疾奔而來.\n"+NOR,me);
                horse->move(room);
                horse->set_heart_beat(1);
                return 1;
        }

        if( room && !me->move(room) )
                return notify_fail("目的地無法到達。\n");

        message_vision(HIM+"紅光閃過,汗血寶馬"HIM"載著$N疾奔而來。\n"+NOR,me);
        horse->move(room);
        horse->set_heart_beat(1);
        return 1;
}

int query_autoload()
{
      return 1;
}
