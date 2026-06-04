#include <ansi.h>
inherit ITEM;
inherit F_GUILDCMDS;
void create()
{
        set_name(HIW + "神羽翼" + NOR,({ "swy-wing","wing" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");
      set("long",@LONG

這是漂漂玟玟的羽翼，能傳送玟玟到想去的地方
使用格式：waveto <number>

現今提供的各傳點：
1. 京城市中   2. 蜀中市中   3. 平南市中
4. 中央驛站   5. 陵雲村     6. 您的遊戲進入點
7. <set by u> 8. <set by u> 9. <set by u>
10. 楓林港

現今提供的各門派傳點：
  sa=惡人谷  teng=仙劍派  yua=舞者  jen=任正晴
duan=段家     sue=儒門     lu=天道  liu=雪蒼
 yar=殺手     low=魔教    lee=射手 chen=官員
 lin=聖火   bonze=少林 doctor=醫生

查詢格式：fanshow
可以查詢你的傳送點所在

群體移動：gmove <on or off>
群體傳送模式開或關，若群體傳送模式開，則 waveto 將傳送
你所帶的兵及 follow 你的人

LONG);
set("value", 1000);
        }
}
void init()
{
        if( environment() == this_player() ){
        add_action("do_fanset", "fanset");
        add_action("do_fanshow", "fanshow");
        add_action("do_waveto", "waveto");
        add_action("do_gmove", "gmove");
	}
}

int query_autoload()
{
if(this_player()->query("swy")==1)
return 1;
}
int do_gmove(string arg)
{
   object me;
   me = this_player();
   switch(arg)
   {
     case "on": 
           me->set_temp("gmove",1);
           write("群體移動模式 開起(on)\n");   
           break;
     case "off":
           me->delete_temp("gmove");
           write("群體移動模式 關閉(off)\n");       
           break;
     default:
           write("群體移動：gmove <on or off>\n");      
   }
  return 1;
}

int do_fanset(string arg)
{
    int no_transmit;
    string str,str_s;
    object me,where;
    if( (arg != "7") && (arg != "8") && (arg != "9") )
    {
      write("你只能設定傳送點 7,8,9...\n");
      return 1;
    }  
    me = this_player();
    where = environment(me);
    no_transmit = where->query("no_transmit",1);
    str_s = where->query("short");
    str=file_name(where);
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
    object me;
    string str_s;
    me = this_player();
    str_s = me->query_temp("fan_s/7");
    printf("傳送點 7 是%s.\n",str_s);
    str_s = me->query_temp("fan_s/8");
    printf("傳送點 8 是%s.\n",str_s);
    str_s = me->query_temp("fan_s/9");
    printf("傳送點 9 是%s.\n",str_s);
    return 1;
}         
int do_waveto(string arg)
{ 
    mixed count;
    int money,i,gmove;
    object me,roomm,env;

    string room="";
    me = this_player();
    if( me->query_temp("unconcious") )          return 0;
    if( me->is_fighting() )
        return notify_fail("戰鬥中無法使用喚雲扇。\n");
    if( me->query_temp("搶劫中") )
        return notify_fail("搶劫中無法使用喚雲扇。\n");
    message_vision(HIW+"只見天上降下一道聖光，$N"+HIW+"消失在聖光中\n"+NOR,me);
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";		break;
       case "2":
         room="/open/gsword/room/su3";		break;
       case "3":
         room="/open/ping/room/road4";		break;
       case "4":
         room="/open/center/room/inn";		break;
       case "5":
         room="/open/start/room/s5";		break;
       case "10":
         room="/open/port/room/r3-1";		break;   
       case "6":
	 room = me->query("startroom");		break;
       case "7":
         room = me->query_temp("fan/7");	break;
       case "8":
         room = me->query_temp("fan/8");	break;
       case "9":
         room = me->query_temp("fan/9");	break;
       case "sa":
         room = "/open/badman/room/g1";         break;
       case "teng":
         room = "/open/gsword/room/g5-1";       break;
       case "yua":
         room = "/open/dancer/room/start";      break;
       case "jen":
         room = "/open/wu/room/luroom18";       break;
       case "duan":
         room = "/open/ping/room/p1";           break;
       case "sue":
         room = "/open/scholar/room/r17";       break;
       case "lu":
         room = "/open/tendo/room/start";       break;
       case "liu":
         room = "/open/snow/room/room2";        break;
       case "yar":
         room = "/open/killer/room/masterm";    break;
       case "low":
         room = "/open/poison/room/room1";      break;
       case "lee":
         room = "/open/marksman/room/room1-31"; break;
       case "chen":
         room = "/open/capital/room/chen_home"; break;
       case "lin":
         room = "/open/prayer/room/punch1"; break;
       case "bonze":
         room = "/open/bonze/room/big";  break;
       case "doctor":
         room = "/open/doctor/room/2";   break;
       default:
       write("請 look wing 吧。\n");
     }
     gmove = me->query_temp("gmove");
     if( gmove )
     {
       roomm = environment(this_player());
     }

     // 檢查 room 是否存在, gmove on|off 都得用,故放此
     env = environment(me);
     if( !me->move(room) ){
	write("無此地點\n");
	return 1;
     }
     
   if( gmove )
   {
     count = all_inventory( roomm );
     for( i=0;i < sizeof( count ) ;i++)
     {
       if( count[i]->is_character() &&
       ( count[i]->query_temp("id") == me->query("id")
          || count[i]->query_leader() == me ) )
             count[i]->move(room);
     }
   }

// 用來減少room 所佔用太多記憶體, 請不要把這裡刪除
   if( !sizeof(all_inventory(env)) && ( !env->query("objects")
    || !sizeof(env->query("objects")) ) ) destruct(env);
     
     if( gmove )
     {
message_vision(HIB+"一道聖光散去，$N"+HIB+"帶領大眾已達目地\n"+NOR,me);
     }else
message_vision(HIC+"蒼天劃過一道聖光，$N"+HIC+"悠然地出現於此\n"+NOR,me);
     return 1;
}
