//2003-03-18  網聚gift for Alucard by frequency
inherit ITEM;
inherit F_GUILDCMDS;
inherit F_AUTOLOAD;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
object me = this_player();
object horse = new("/autoload/gift/sky-horse");
void create()
{
  set_name(HIC"天"HIW"馬"HIB"韁繩"NOR,({"sky-horse-halter"}));
  set("long",HIC"駕馭傳說之天馬所需的器具。\n"NOR);
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
    int exp = me->query("combat_exp");
    exp = exp/5;
    if(exp > 15000000)  exp = 15000000;
    if(!horse)
    {
    horse = new("/autoload/gift/sky-horse");
    message_vision(HIB"$N撮唇一聲清嘯，"HIC"天馬"HIW"佩加薩斯"HIB"由遙遠的天際疾飛而來。\n"NOR,me);
    message_vision(HIC"天馬"HIW"佩加薩斯"HIG"雙翅一展，朝主人所在的方位疾飛而去。\n"NOR,horse);
    horse->move(environment(me));
    horse->set_leader(me);
    horse->set("family/family_name",me->query("family/family_name"));
    horse->set_temp("my_boss",(string)me->query("id"));
    horse->set_temp("rider",me);
    horse->set("combat_exp",exp);
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
    message_vision(HIY"$N撮唇一聲清嘯，"HIC"天馬"HIW"佩加薩斯"HIY"由遙遠的天際疾飛而來。\n"NOR,me);
    message_vision(HIC"天馬"HIW"佩加薩斯"HIG"雙翅一展，朝著主人所在的方位疾飛而去。\n"NOR,horse);
    horse->move(environment(me));
    horse->set_heart_beat(1);
    return 1;
    }
    else if(!me->query_temp("have_horse"))
    {
    message_vision(HIB"$N撮唇一聲清嘯，"HIC"天馬"HIW"佩加薩斯"HIB"由遙遠的天際疾飛而來。\n"NOR,me);
    message_vision(HIC"天馬"HIW"佩加薩斯"HIG"雙翅一展，朝主人所在的方位疾飛而去。\n"NOR,horse);
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
   if (no_transmit)
      return notify_fail("突然一陣能量從地底發出,擊散了你招來的雲朵,\n似乎這裡的大神不願此地可以傳送...\n");
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
                return notify_fail("天馬目前不在身邊。\n");
        if(!me->query_temp("is_riding"))
                return notify_fail("請先騎上天馬。\n");
        if( me->query_temp("unconcious") )
                return notify_fail("試問昏倒的人如何駕馭天馬!?");
        if( me->is_fighting() )
                return notify_fail("先將戰鬥結束再走吧!!\n");

  if ( environment(me)->query("no_transmit") )
    return notify_fail("小馬不願離開這裡!!\n");
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
        message_vision( HIW+"天馬展翅一振，載著$N朝天邊飛去。\n"+NOR ,me);

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

                message_vision(HIW+"一道刺眼白光閃過,$N帶領眾人從天而降.\n"+NOR,me);
                horse->move(room);
                horse->set_heart_beat(1);
                return 1;
        }

        if( room && !me->move(room) )
                return notify_fail("目的地無法到達。\n");

        message_vision(HIW+"白光閃過,"HIC"佩加薩斯"HIW"載著$N由天而降。\n"+NOR,me);
        horse->move(room);
        horse->set_heart_beat(1);
        return 1;
}

int query_autoload()
{
      return 1;
}
