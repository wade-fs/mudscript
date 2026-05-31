//暫時開放二刀流給金刀玩 目前quest還沒完成 by blazakira 2013/1/1
//並將 這二刀流 作quest判定mark「quests/secondary_blade」 沒解 就會刪除該技能 by blazakira 2013/1/1

#include <ansi.h>
inherit EQUIP;

string color;

void create()
{
  set_name(HIW"自由之翼"NOR,({"free_wing","fw"}));
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","由片片符彔組成，每ㄧ道符彔，就如蔚藍的天空，深邃的大海，約有數十萬的符彔組成這一\n"
      "對翅膀，每ㄧ片符彔之中，都是ㄧ個小小的世界，其中龐大的力量奔騰著，隨意扇動之間，\n"
      "上面就出現無數追求自由的身影，ㄧ個個的身影，前仆後繼，殺生成仁，為自由消遙，捨生\n"
      "忘死。\n\n傳聞中得到這一對翅膀，就可以不受任何規則羈絆！(help free wing)\n"NOR);
    set("unit","對");
    set("value",3000);
    set("material","crimsonsteel");
    set("armor_type","neck");
    set("armor_prop/armor", 3);
    set("armor_prop/dodge", 3);
    set("armor_prop/parry", 3);
    set("armor_prop/force", 3);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg",HIW"輕觸胸前的項鍊將能量灌注其中，光芒閃耀！"HIY"$N"HIW"的背後閃現出一對寬大的翅膀，\n"
      "翅膀出現的剎那，"HIY"$N"HIW"似乎已經感受不到任何的羈絆，擁有了真正的自由。\n"NOR);
    set("unequip_msg",HIW"背後的翅膀化為無數光點消失，"HIY"$N"HIW"似乎又回到了人世間感受到了滾滾紅塵。\n"NOR);
  }
  setup();
}

int query_autoload()
{
  return 1;
}

int wear()
{
  object me;
  int ret = ::wear(),k;
  if( query("equipped"))
  {
    me=environment();
    k=me->query("weapon/fwing/level"); //雖然是防具 不過統合在一起 為強化級別的設定
    if(!me->query_temp("fwing_basic_skill")) {
      me->add_temp("apply/force",k);
      if(me->query("class")=="blademan")  me->add_temp("apply/blade",3+k);
      if(me->query("family/family_name")=="金刀門")  me->add_temp("apply/secondary_blade",(3+k)*2);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",3+k);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",3+k);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",3+k);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",3+k);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery",3+k);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",3+k);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",3+k);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",3+k);
      if(me->query("class")=="killer") {
                                          me->add_temp("apply/throwing",3+k);
                                          me->add_temp("apply/dagger",3+k);
      }
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber",3+k);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",3+k);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",3+k);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",3+k);
      me->set_temp("fwing_basic_skill",1);
    }
  }
  return ret;
}

int unequip()
{
  object me = environment();
  int ret = ::unequip(),k;
  k=me->query("weapon/fwing/level");
  if( !query("equipped") )
  {
    if(me->query_temp("fwing_basic_skill")==1) {
      me->add_temp("apply/force",-k);
      if(me->query("class")=="blademan")  me->add_temp("apply/blade",-3-k);

      if(me->query("family/family_name")=="金刀門")  me->add_temp("apply/secondary_blade",-(3+k)*2);
      //如果沒解過 或 不是wiz 就刪除這雙刀流 by blazakira 2013/1/1
      if( !me->query("quests/secondary_blade") && !wizardp(me) )  me->delete_skill("secondary_blade");

      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",-3-k);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",-3-k);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",-3-k);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",-3-k);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery",-3-k);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",-3-k);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",-3-k);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",-3-k);
      if(me->query("class")=="killer") {
                                          me->add_temp("apply/throwing",-3-k);
                                          me->add_temp("apply/dagger",-3-k);
      }
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber",-3-k);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",-3-k);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",-3-k);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",-3-k);
      me->delete_temp("fwing_basic_skill");
    }
  }
  return ret;
}

void init()
{
  object me=environment();
  int k=me->query("weapon/fwing/level");
  if( me == this_player() ) {
    add_action("do_wingset", "wingset");
    add_action("do_wingshow", "wingshow");
    add_action("do_waveto", "wingto");
    add_action("do_gmove", "gmove");
    add_action("do_help", "help");
    this_object()->color_change();
    if( k && color ) set("name",color+"( "+chinese_number(k*2)+"翼 )"NOR+HIW"自由之翼"NOR);
  }
}

int color_change()
{
  object me=environment();
  string color_select;
  color_select=me->query("weapon/fwing/color");
  switch(color_select) {
    case "YEL":
      color="[0;33m";
      break;
    case "CYN":
      color="[0;36m";
      break;
    case "HIK":
      color="[1;30m";
      break;
    case "HIR":
      color="[1;31m";
      break;
    case "HIY":
      color="[1;33m";
      break;
    case "HIB":
      color="[1;34m";
      break;
    case "HIC":
      color="[1;36m";
      break;
    case "HIW":
      color="[1;37m";
      break;
    default : 
      break;
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

int do_wingset(string arg)
{
  object where, me = environment();
/*
//fan為主要功能 所以取消限制的判定 改以進化系統作替代 by blazakira
#ifdef FANSET
  if(!me->query_temp("can_fanset")) return 0;
#endif
*/
  if( (where = environment(me))->query("no_transmit") )
    return notify_fail("一陣強大的磁場從地底傳出，干擾了你的設定，\n似乎這裡的大神不願此地可以傳送...\n");
  if( arg="7" && me->query("weapon/fwing/level") <1 )
    return notify_fail("一陣強大的磁場從地底傳出，干擾了你的設定，\n似乎此翅膀尚未吸收足夠的天界能量來進化。\n");
  if( arg="8" && me->query("weapon/fwing/level") <5 )
    return notify_fail("一陣強大的磁場從地底傳出，干擾了你的設定，\n似乎此翅膀尚未吸收足夠的天界能量來進化。\n");
  if( arg="9" && me->query("weapon/fwing/level") <8 )
    return notify_fail("一陣強大的磁場從地底傳出，干擾了你的設定，\n似乎此翅膀尚未吸收足夠的天界能量來進化。\n");

  switch( arg ) {
    case "7" :
    case "8" :
    case "9" :
      me->set_temp( "wing/" + arg, file_name(where) );
      me->set_temp( "wing_s/" + arg, where->query("short") );
      write("你設定這裡為你的新傳送點。\n");
      return 1;
    default :
      return notify_fail("你只能設定 7、8、9 。\n");
  }
}

int do_wingshow(string arg)
{
  object me = this_player();

  write(  "傳送點 7 是" + me->query_temp( "wing_s/7" ) +
    "\n傳送點 8 是" + me->query_temp( "wing_s/8" ) +
    "\n傳送點 9 是" + me->query_temp( "wing_s/9" ) + "\n" );
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
    return notify_fail("戰鬥中無法使用自由之翼。\n");
  if( CLAN_D->what_clan_area(me) != "NULL" )
    return notify_fail( "無法在幫派區域內使用。\n" );
  if( me->query_temp("不准走"))
    return notify_fail("突然一陣能量從地底發出，干涉了你凝聚的天界能量，\n似乎這裡的大神不願此地可以傳送...\n");
  if( me->query_temp("搶劫中") )
    return notify_fail("搶劫中無法使用自由之翼。\n");
  if( environment(me)->query("no_transmit") )
    return notify_fail("突然一陣能量從地底發出，干涉了你凝聚的天界能量，\n似乎這裡的大神不願此地可以傳送...\n");
  if( me->query("bank/coin") < 10000 )
    return notify_fail("自由之翼說：你的存款不足，無法支付費用。\n");
  if( me->query_temp("invis"))
    return notify_fail("你在藏匿中，自由之翼找不到你……\n");

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
      if( !room = me->query_temp( "wing/"+ arg ) )
        return notify_fail("抱歉，沒有你所要去的地方的資料。\n");
      break;
    case "gs":
      room = "/open/wiz/gs.c";               break;
    default:
      return notify_fail("抱歉，沒有你所要去的地點。\n");
  }
  message_vision( HIY"$N"HIW"背後的翅膀猛然ㄧ搧，瞬間穿越了無盡的時空而去。\n"NOR ,me);

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

    message_vision(HIW"前方的空間忽然出現ㄧ陣波紋，眼前一花，"HIY"$N"HIW"帶領大家突兀的降臨了。\n"+NOR,me);
    me->add("bank/coin", -10000);
    return 1;
  }

  if( room && !me->move(room) )
    return notify_fail("目的地無法到達。\n");

  message_vision(HIW"前方的空間忽然出現ㄧ陣波紋，眼前一花，"HIY"$N"HIW"突兀的降臨了。\n"+NOR,me);
  me->add("bank/coin",-10000);
  return 1;
}

int do_help(string str)
{
  if (str!="free wing") return 0;

  write(@Help

        「自由之翼」
    這是凝聚天界的能量所形成的翅膀，專門提供給超級有錢人使用，只要你
錢莊存款夠，你就可以隨意飛翔在本大陸。
（費用：飛翔一次10000 coin，直接從錢莊扣。）

      使用格式：wingto <number>    ex: wingto 1,wingto 2
      現今提供的各傳點：1. 京城市中   2. 蜀中市中   3. 平南市中
                        4. 中央驛站   5. 凌雲村     6. 您的遊戲進入點
                        7. <NONE>     8. <NONE>     9. <NONE>
                       10. 楓林港

      設定格式：wingset <number>   ex: set 7,set 8 (只限 7,8,9)
      會自動把你所在位置存下來，成為新的傳送點。

      查詢格式：wingshow           ex: wingshow
      可以查詢你的傳送點所在.

      群體移動：gmove <on|off>  ex: gmove on,gmove off
      群體傳送模式開或關，若群體傳送模式打開，則 waveto 將傳送你所帶的兵
          ........<gmove限官員、刀客使用>............

    裝備構思協助者：燁世兵權(Evilsword)。
Help); //Help結束前方不能有空白 否則會出現錯誤
  return 1;
}
