#include <ansi.h>
//inherit F_GUILDCMDS;
inherit NPC;

object ghost= this_object();

void do_meeting( object me)
{
  string str;
  object where;
  if( !me->query_temp("ghost") && me->query("class") == "killer" && !ghost->query_temp("followed"))
  {
    message_vision("只見眼前白光一閃，一道煙霧似慢實快的鑽進了$N體內。\n", me);
    command("say 帶我去找綠雲組長周八伯申冤吧...");
    command("follow "+ me->query("id"));
    ghost->set_temp("followed", me);
    me->set_temp("ghost", 1);
  }
  // 假如有 follow 但是那個人又不在的話...
  else if( ghost->query_temp("followed") && !present( (ghost->query_temp("followed"))->query("id"), environment(ghost)))
  {
    where= environment( ghost->query_temp("followed"));
    str=file_name(where);
    ghost->move(str);
  }
  return;
}

void call_find_eight(object user,object eight)
{
  delete_temp("invis");
  command("say 小女子生前是一名殺手，到墓園逛逛時被某人由背後偷襲...");
  command("say 後來那個豬狗不如的東西竟然.....");
  command("cry "+ user->getuid());
  command("say 請"+(user->query("gender")=="男性" ? "壯士" : "姑娘")+"替小女子報仇，據小女子所知，那人正在黑風組總部作客。");
  command("say 如能替小女子報得大仇，小女子願以身相許\...。");
  message_vision(HIW"任盈盈講完這些話時，又化成一陣煙消失了。\n\n"NOR, user);
  eight->call_find_ljen(user,this_object());
  destruct(this_object());
}

void create()
{
  object ob;
  set_name("任盈盈",({"ljen"}));
  set("long","一位退隱江湖的殺手，現在則成了一位美麗的女鬼。\n");
  set("gender","女性");
  set("combat_exp",300000);
  set("attitude","heroism");
  set("age",18);
  set("str", 30);
  set("cor", 30);
  set("cps", 30);
  set("per", 30);
  set("spi", 30);
  set("int", 30);
  set("force", 2000);
  set("max_force", 2000);
//  set("kee", 1000);
  set("max_kee", 1000);
  set("force_factor",10);
  set_skill("move",60);
  set_skill("force",70);
  set_skill("dodge",80);
  set_skill("parry",60);
  set_skill("throwing",70);
  set_skill("blackforce",60);
  set_skill("ghost-steps",70);
  set_skill("rain-throwing",70);
  map_skill("force","blackforce");
  map_skill("dodge","ghost-steps");
  map_skill("throwing", "rain-throwing");
  set_temp("invis",1);
  set("chat_chance", 8);
  set("chat_msg", ({
    "任盈盈說道:「我死的好慘ㄚ....」\n",
    "任盈盈說道:「只有周八伯才能替我申冤。」\n",
    "任盈盈說道:「誰能幫我報仇...」\n",
    "任盈盈說道:「難道說人長的美麗也是一種錯誤嗎?」\n",
    "任盈盈說道:「誰能幫我報得大仇的，我願意以身相許\...」\n",
  }));
  setup();
  ob=carry_object("/open/killer/obj/hate_knife");
  ob->set_amount(200);
  ob->wield();
}

void init ()
{
  object me= this_player();
  if( !me->query_temp("ghost"))
    call_out("do_meeting",1,me);
  add_action("do_waveto", "waveto");
  add_action("do_waveto", "wa");
  add_action("do_waveto", "wav");
}

int do_waveto(string arg)
{
  mixed count;
  int money,i,gmove;
  object me,roomm;
  object ghost;
  string room="";
  me = this_player();
  ghost= this_object();
  if( me->query_temp("unconcious") ) return 0;
  if( me->is_fighting() )
    return notify_fail("戰鬥中無法使用喚雲扇。\n");
  if( me->query_temp("搶劫中") )
    return notify_fail("搶劫中無法使用喚雲扇。\n");
  if( environment(me)->query("no_transmit") )
  {
    write("突然一陣能量從地底發出，擊散了你招來的雲朵，\n");
    write("似乎這裡的大神不願此地可以傳送...\n");
    return 1;
  }  
  money = me->query("bank/coin");
  if( money < 500)
  {
    write("喚雲扇說：你的存款不足，無法支付費用。\n");
    return 1;
  }
  message_vision( HIB+"只見天上降下一朵雲籠罩著$N。\n"+NOR ,me);   
  switch(arg)
  {
    case "1":
      room="/open/capital/room/r70";         break;
    case "2":
      room="/open/gsword/room/su3";          break;
    case "3":
      room="/open/ping/room/road4";          break;
    case "4":
      room="/open/center/room/inn";          break;
    case "5":
      room="/open/start/room/s5";            break;
    case "10":
      room="/open/port/room/r3-1";           break;   
    case "6":
      room = me->query("startroom");         break;
    case "7":
      room = me->query_temp("fan/7");        break;
    case "8":
      room = me->query_temp("fan/8");        break;
    case "9":
      room = me->query_temp("fan/9");        break;
    default:
  }
  gmove = me->query_temp("gmove");
  if( gmove )
  {
    roomm = environment(this_player());
  }
  // 檢查 room 是否存在，gmove on|off 都得用,故放此
  if( !me->move(room) )
  {
    write("目的地無法到達。\n");
    return 1;
  }
  else
    ghost->move( room);
     
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

/*  no_transmit 一定無法 fanset,故一定無法傳送,此處多餘 ...ccat...9_12.96 
  if( environment(me)->query("no_transmit") ) {
    message_vision(HIB+"突然一陣能量從地底發出,將$N的雲朵彈走。\n"+NOR,me);
    me->move("/open/common/room/inn");
  }
  else
 */    
  if( gmove )
  {
    message_vision(HIB+"一陣清風過後，$N"HIB"帶領大家從天而降。\n"+NOR);
  } else
    message_vision(HIB+"一陣清風過後，$N"HIB"從天而降。\n"+NOR,me);
  me->set("bank/coin",money-500);
  return 1;
}
