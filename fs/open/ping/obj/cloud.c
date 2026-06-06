// made by ccat
// 二版...加入 group move...     ccat....9_12.96
// 由於 chun 抗議,改成只傳送 officer 所帶的兵與 follow 的player.
//                                               ccat....9_15,96
// 加強一些邏輯上的判斷, 以免出現太多的 error 並改寫一下型式
//                                              Arthur (10/9/1998)
//改錯字 by blazakira 2011/7/29

#include <ansi.h>

inherit ITEM;
inherit F_GUILDCMDS;

void create()
{
  set_name("喚雲扇", ({ "cloud fan","fan" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
  set("long",@LONG
這是一把用來招換飛雲的扇子，專門提供給有錢人使用，只要你錢莊存款夠，
你就可以隨意飛翔在本大陸。（費用：飛翔一次500 coin，直接從錢莊扣。）

      使用格式：waveto <number>    ex: waveto 1,waveto 2
      現今提供的各傳點：1. 京城市中   2. 蜀中市中   3. 平南市中
                        4. 中央驛站   5. 凌雲村     6. 您的遊戲進入點
                        7. <NONE>     8. <NONE>     9. <NONE>
                       10. 楓林港

      設定格式：fanset <number>   ex: set 7,set 8 (只限 7,8,9)
      會自動把你所在位置存下來,成為新的傳送點.

      查詢格式：fanshow           ex: fanshow
      可以查詢你的傳送點所在.

      群體移動：gmove <on|off>  ex: gmove on,gmove off
      群體傳送模式開或關，若群體傳送模式打開，則 waveto 將傳送你所帶的兵。
          ........<gmove限官員、刀客跟幫派的高層使用>............
LONG
    );
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

int do_gmove(string arg)
{
  object me = this_player();
  int value=0; //加入幫派的高階級的人使用rank
  if(me->query("clan"))
    if(me->query("clan/rank") < 4)
      value=1;
  if( me->query("class") == "officer" ||
      me->query("class") == "blademan" || value)
  {
    switch(arg)
    {
      case "on":
        me->set_temp("gmove",1);
        write("群體移動模式：開起(on)!!!\n");
        return 1;
      case "off":
        me->delete_temp("gmove");
        write("群體移動模式：關閉(off)!!!\n");
        return 1;
      default:
        return notify_fail("群體移動：gmove <on|off>\n");
    }
  }
  return notify_fail("此命令限：官員(officer)和刀客(blademan)幫派高層(rank 3以上)使用。\n");
}

int do_fanset(string arg)
{
  object where, me = this_player();

#ifdef FANSET
    if(!me->query_temp("can_fanset")) return 0;
#endif
  if( (where = environment(me))->query("no_transmit") )
    return notify_fail("一陣強大的磁場從地底傳出，干擾了你的設定，\n似乎這裡的大神不願此地可以傳送...\n");

  switch( arg ) {
    case "7" :
    case "8" :
    case "9" :
      me->set_temp( "fan/" + arg, file_name(where) );
      me->set_temp( "fan_s/" + arg, where->query("short") );
      write("你設定這裡為你的新傳送點。\n");
      return 1;
    default :
      return notify_fail("你只能設定 7、8、9 。\n");
  }
}

int do_fanshow(string arg)
{
  object me = this_player();

  write(  "傳送點 7 是" + me->query_temp( "fan_s/7" ) +
    "\n傳送點 8 是" + me->query_temp( "fan_s/8" ) +
    "\n傳送點 9 是" + me->query_temp( "fan_s/9" ) + "\n" );
  return 1;
}

int do_waveto(string arg)
{
  string room="";
  object *count, me = environment();
  int i;

  if( me->query_temp("unconcious") )
    return 0;
  if( me->is_fighting() )
    return notify_fail("戰鬥中無法使用喚雲扇。\n");
  if( CLAN_D->what_clan_area(me) != "NULL" )
    return notify_fail( "無法在幫派區域內使用。\n" );
  if( me->query_temp("不准走"))
    return notify_fail("突然一陣能量從地底發出，擊散了你招來的雲朵，\n似乎這裡的大神不願此地可以傳送...\n");
  if( me->query_temp("搶劫中") )
    return notify_fail("搶劫中無法使用喚雲扇。\n");
  if( environment(me)->query("no_transmit") )
    return notify_fail("突然一陣能量從地底發出，擊散了你招來的雲朵，\n似乎這裡的大神不願此地可以傳送...\n");
  if( me->query("bank/coin") < 500 )
    return notify_fail("喚雲扇說：你的存款不足，無法支付費用。\n");
  if( me->query_temp("invis"))
    return notify_fail("你在藏匿中，喚雲扇找不到你……\n");

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
      if( !room = me->query_temp( "fan/"+ arg ) )
        return notify_fail("抱歉，沒有你所要去的地方的資料。\n");
      break;
    case "gs":
      room = "/open/wiz/gs.c";               break;
    default:
      return notify_fail("抱歉，沒有你所要去的地點。\n");
  }
  message_vision( HIB+"只見天上降下一朵雲籠罩著$N。\n"+NOR ,me);

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

    message_vision(HIB+"一陣清風過後，$N"HIB"帶領大家從天而降。\n"+NOR,me);
    me->add("bank/coin", -500);
    return 1;
  }

  if( room && !me->move(room) )
    return notify_fail("目的地無法到達。\n");

  message_vision(HIB+"一陣清風過後，$N"HIB"從天而降。\n"+NOR,me);
  me->add("bank/coin",-500);
  return 1;
}
