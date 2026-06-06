// officer1.c by konn
// pkla 從三分鐘改成一分鐘
// 2002-12-29 修改替身上限為100個,pkla贏50場可換替身,潛能5萬可以換替身
//增加交換指令的線索 與修正訊息之疏漏 by blazakira 2011/3/11
//增加玩家是否離線的判斷 by blazakira 2011/9/23

#include <ansi.h>
inherit CHINESE_D;
inherit NPC;

object pker_master,pker_fighter;

void create()
{
  set("title","比武擂台主持人");
  set_name("蔡總管",({"pkla officer","officer"}));
  set("long","\n他是比武擂台的主持人。\n\n"+HIY+
    "  你可以輸入以下相關指令：        \n"+
    "    encourage-pkla\n    encourage-pot\n    encourage-stone1\n    encourage-stone10\n    do_change\n" + HIG+
    "相關help，請 help 狂想原石，help ch-stdby，help pkla，help 替身\n\n" + NOR);

  set("race","人類");
  set("gender","男性");
  set("attitude","friendly");

  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("parry",100);
  set("no_kill",1);

  pker_master=0;
  pker_fighter=0;
  setup();
 }

void init()
{
  add_action("doing_encourage_pkla","encourage-pkla");
  add_action("doing_encourage_pot","encourage-pot");
  add_action("doing_encourage_sto1","encourage-stone1");
  add_action("doing_encourage_sto10","encourage-stone10");
  add_action("doing_change","do_change");
}

void shout(string msg)
{
  CHANNEL_D->do_channel(this_object(),"mud:pkla",msg);
}

int doing_encourage_pkla()
{
  object me = this_player();
//2002-12-29 pkla 50場即可喚替身 --by kalin
  if( me->query("pk_convert") >= (me->query("pk_win")/50) ) {
    tell_object(me,HIY + "蔡總管說道：你的獲勝次數還不到獎勵的標準。\n" + NOR);
    return 1;
  }
/*  if( !me->query("max_standby"))
  {
    me->set("max_standby",100);
  }
  if( me->query("max_standby")<100)
  {
    me->set("max_standby",100);
  }
*/
//  if(me->query("standby_dead_time"))
//    if(me->query("standby_dead_time")+86400 > time())
//      return notify_fail("你的替身才剛死不久，我不能發替身給你，你晚點再來吧!!\n");
  if(me->query("standby"))
    return notify_fail("你不是已經有一個了???\n");

  if(me->query("t_standby")<me->query("max_standby"))
  {
    me->add("t_standby",1);
    me->add("pk_convert",1);
    me->add("standby",1);
    tell_object(me,HIY + "蔡總管說道：恭喜你在擂台賽中勝負累積達到標準可獲得替身一個，在緊要關頭他會"+
      "代替你到地府走一趟的。\n" + NOR);
    log_file("pkstdby",sprintf("%s 用pkla換到一個替身 on %s\n",me->query("id"),ctime(time()) ));
  }
  else {
    tell_object(me,HIY + "蔡總管說道：你曾經擁有的替身總數已達上限，無法再增加。\n" + NOR);
  }
  return 1;
}

int doing_encourage_pot()
{
  object me = this_player();
  int pots = 25000+25000*(me->query("standby") +1);
  if( (int)me->query("potential") - (int)me->query("learned_points") < pots ) {
    tell_object(me,HIY + "蔡總管說道：你的潛能值不夠換替身，而下個替身需要"+pots+"點。\n" + NOR);
    return 1;
  }
  if( !me->query("max_standby"))
  {
    me->set("max_standby",100);
  }
/*
  if( me->query("max_standby")<100)
  {
    me->set("max_standby",100);
  }
*/
//  if(me->query("standby_dead_time"))
//    if(me->query("standby_dead_time")+86400 > time())
//      return notify_fail("你的替身才剛死不久，我不能發替身給你，你晚點再來吧!!\n");
/*
  if(me->query("standby"))
    return notify_fail("你不是已經有一個了???\n");
*/
  if(me->query("t_standby")<me->query("max_standby"))
  {
    me->add("t_standby",1);
    me->add("potential",-pots);
    me->add("standby",1);
    tell_object(me,HIY + "蔡總管說道：恭喜你用"+pots+"點潛能換得替身一個，在緊要關頭他會"+
      "代替你到地府走一趟的。\n" + NOR);
    log_file("potstdby",sprintf("%s 用pot換到一個替身 on %s\n",me->query("id"),ctime(time()) ));
  }
  else {
    tell_object(me,HIY + "蔡總管說道：你曾經擁有的替身總數已達上限，無法再增加。\n" + NOR);
  }
  return 1;
}
//新增換替身的方式1顆狂想原石換替身一隻。
//by Neverend 2003/05/08
int doing_encourage_sto1()
{
  object me = this_player();
  object stone = present("original stone",me);

  if( !stone )
  {
    tell_object(me,HIY + "蔡總管說道：你身上並沒有這樣東西呀!!\n" + NOR);
    return 1;
  }
  if( !stone->query("stone_id") )
  {
    tell_object(me,HIY + "蔡總管說道：你這東西並不是我所想要的唷!!\n" + NOR);
    return 1;
  }

  if( !me->query("max_standby"))
  {
    me->set("max_standby",100);
  }
/*
  if( me->query("max_standby")<100)
  {
    me->set("max_standby",100);
  }
*/
  if(me->query("standby"))
    return notify_fail("你不是已經有一個了???\n");

  if(me->query("t_standby")<me->query("max_standby"))
  {
    me->add("t_standby",1);
    me->add("standby",1);
    stone->add_amount(-1);
    tell_object(me,HIY + "蔡總管說道：恭喜你獲得替身一個，在緊要關頭他會"+
      "代替你到地府走一趟的。\n" + NOR);
    log_file("potstdby",sprintf("%s 用stone換到一個替身 on %s\n",me->query("id"),ctime(time()) ));
  } else {
    tell_object(me,HIY + "蔡總管說道：你曾經擁有的替身總數已達上限，無法再增加。\n" + NOR);
  }
  return 1;
}
//新增換替身的方式10顆狂想原石換替身一隻，且不增加替身上限。
int doing_encourage_sto10()
{
  object me = this_player();
  object stone = present("original stone",me);
  int i;

  if(me->query("standby")>1)
    return notify_fail("你的替身已經夠多了!!\n");
  if( !stone )
  {
    tell_object(me,HIY + "蔡總管說道：你身上並沒有這樣東西呀!!\n" + NOR);
    return 1;
  }
  i = stone->query_amount();

  if( i < 10 )
  {
    tell_object(me,HIY + "蔡總管說道：你身上的狂想原石不夠換喔!!\n" + NOR);
    return 1;
  }
  if( !stone->query("stone_id") )
  {
    tell_object(me,HIY + "蔡總管說道：你這東西並不是我所想要的唷!!\n" + NOR);
    return 1;
  }

  if( !me->query("max_standby"))
  {
    me->set("max_standby",100);
  }
  if( me->query("max_standby")<100)
  {
    me->set("max_standby",100);
  }

  me->add("standby",1);
  stone->add_amount(-10);
  tell_object(me,HIY + "蔡總管說道：恭喜你獲得替身一個，在緊要關頭他會"+
    "代替你到地府走一趟的。\n" + NOR);
  log_file("potstdby",sprintf("%s 用10stone換到一個替身 on %s\n",me->query("id"),ctime(time()) ));
  return 1;
}

int doing_change(string str)
{
  object me,powder,suipian,jiao,stone,ob1,ob2,ob3,ob4;
  me = this_player();
  powder = present("original powder",me);
  suipian = present("original suipian",me);
  jiao = present("original jiao",me);
  stone = present("original stone",me);
  ob1 = new("/obj/stone/powder");
  ob2 = new("/obj/stone/suipian");
  ob3 = new("/obj/stone/jiao");
  ob4 = new("/obj/stone/stone");

  if( !str )
  {
    tell_object(me,HIC + "蔡總管說道：請選擇 suipian, jiao, stone 三種你想兌換的種類唷!!\n" + NOR);
    return 1;
  }

  switch(str)
  {
    case "suipian":
      if( !powder ) return notify_fail("你身上沒這樣東西唷!!\n");
      if( !powder->query("stone_id") ) return notify_fail("這東西非是狂想原石真品唷!!\n");
      if( powder->query_amount() >= 10 )
      {
        tell_object(me,HIY + "你將身上的十粒狂想原石粉末換成一粒狂想原石碎片。\n" + NOR);
        powder->add_amount(-10);
        ob2->move(me);
        log_file("/stone/suipian",sprintf("%s 用10粒狂想原石粉末換到一粒狂想原石碎片於 %s\n",me->query("id"),ctime(time())));
      } else {
        tell_object(me,HIC + "蔡總管說道：你所帶來的數量不足夠兌換唷!!\n" + NOR);
      }
      break;
    case "jiao":
      if( !suipian ) return notify_fail("你身上沒這樣東西唷!!\n");
      if( !suipian->query("stone_id") ) return notify_fail("這東西非是狂想原石真品唷!!\n");
      if( suipian->query_amount() >= 10 )
      {
        tell_object(me,HIY + "你將身上的十粒狂想原石碎片換成一粒狂想原石一角。\n" + NOR);
        suipian->add_amount(-10);
        ob3->move(me);
        log_file("/stone/jiao",sprintf("%s 用10粒狂想原石碎片換到一粒狂想原石一角於 %s\n",me->query("id"),ctime(time())));
      } else {
        tell_object(me,HIC + "蔡總管說道：你所帶來的數量不足夠兌換唷!!\n" + NOR);
      }
      break;
    case "stone":
      if( !jiao ) return notify_fail("你身上沒這樣東西唷!!\n");
      if( !jiao->query("stone_id") ) return notify_fail("這東西非是狂想原石真品唷!!\n");
      if( jiao->query_amount() >= 10 )
      {
        tell_object(me,HIY + "你將身上的十粒狂想原石一角換成一粒" + HIC + "狂想原石" + HIY + "。\n" + NOR);
        jiao->add_amount(-10);
        ob4->move(me);
        log_file("/stone/stone",sprintf("%s 用10粒狂想原石一角換到一粒狂想原石於 %s\n",me->query("id"),ctime(time())));
      } else {
        tell_object(me,HIC + "蔡總管說道：你所帶來的數量不足夠兌換唷!!\n" + NOR);
      }
      break;
    default:
      tell_object(me,HIC + "蔡總管說道：只能選擇 suipian, jiao, stone 三種兌換種類唷!!\n" + NOR);
      break;
  }
  return 1;
}

int set_master(object me)
{
  pker_master = me;
  return 1;
}

int set_fighter(object me)
{
  pker_fighter = me;
  return 1;
}

int delete_master()
{
  pker_master = 0;
  return 1;
}

int delete_fighter()
{
  pker_fighter = 0;
  return 1;
}

int pk_ing()
{
  shout(HIC + "蔡總管說道：比賽時間到，停止押注。" + NOR);
  shout(HIC + "蔡總管說道：請兩位高手到第一武道館開始比賽。" + NOR);
  shout(HIC + "蔡總管說道：比賽時間為二十分鐘。" + NOR);
  pker_master->set_temp("pk_fight",1);
  pker_fighter->set_temp("pk_fight",1);
  pker_master->set_temp("pk_room",environment(pker_master));
  pker_fighter->set_temp("pk_room",environment(pker_fighter));
  pker_master->move("/open/gblade/room/pkroom/pkr"+pker_master->query_temp("pkr")+".c");
  pker_fighter->move("/open/gblade/room/pkroom/pkr"+pker_fighter->query_temp("pkr")+".c");
  this_object()->set_temp("pking_time",1);
  return 1;
}

int doing_list(object me)
{
  set_heart_beat(1);
  if( !pker_master ) {
    tell_object(me,"目前擂台上沒有任何人。\n");
    return 1;
  }
  printf("\n擂台老大:\n");
  if( pker_fighter ) {
    tell_object(me,sprintf("    \n%s(%s) VS %s(%s)\n\n",
      pker_master->name(),pker_master->query("id"),
      pker_fighter->name(),pker_fighter->query("id")));
  }
  else tell_object(me,sprintf("    \n%s(%s) 接受各位的挑戰。\n\n",pker_master->name(),pker_master->query("id")));
  write ("ok.\n");
  return 1;
}

int doing_me(object me)
{
  int i;
  i=me->query("combat_exp")/10;
  if(me->query("potential")-(me->query("learned_points")) < 210)
    return notify_fail("你的潛能不夠！\n");
  if( me == pker_master ) {
    tell_object(me,"你已經下挑戰書了。\n");
    return 1;
  }
  if( me == pker_fighter ) {
    tell_object(me,"你已經接受挑戰了。\n");
    return 1;
  }
  if( pker_master ) {
    tell_object(me,"已經有人捷足先登了，你考慮考慮跟他過招吧。\n");
    return 1;
  }
  if( pker_master && pker_fighter ) {
    tell_object(me,"比賽已經開始了，等下一場吧。\n");
    return 1;
  }
  if( !me->pay_money(i) ) {
    tell_object(me,"你沒有足夠的錢付報名費，sorry 啦！ ^_^\n");
    return 1;
  }

  tell_object(me,"蔡總管說：依您的江湖名聲酌收"+cvalue(i)+"的報名費。\n");
  set_master(me);
  shout(HIC + "\n蔡總管喝道：" + HIW+me->name()+HIC + "願意接受擂台挑戰。"+
    "請各大武林好手前來切磋武藝。" + NOR);
/*  tell_object(me,HIC + "\n蔡總管喝道：" + HIW+me->name()+HIC + "願意接受擂"+
    "台挑戰。請各大武林好手前來切磋武藝。\n" + NOR);*/
  this_object()->set_temp("wait_pk",1);
  return 1;
}

int doing_accept(object me)
{
  int i;
  i=me->query("combat_exp")/10;
  if(me->query("potential")-(me->query("learned_points")) < 210)
    return notify_fail("你潛能不夠！\n");
  if( me == pker_master ) {
    tell_object(me,"你已經下挑戰書，不能再接受別人的挑戰。\n");
    return 1;
  }
  if( me == pker_fighter ) {
    tell_object(me,"你已經接受別人的挑戰。\n");
    return 1;
  }
  if( pker_master && pker_fighter ) {
    tell_object(me,"擂台已經開打了，請等待下一場。\n");
    return 1;
  }
  if( !pker_master ) {
    tell_object(me,"目前擂台沒有人，你願意挑戰別人嗎？\n");
    return 1;
  }
// 之前 2 倍太小改 4 倍 by swy
  if(!wizardp(me) && !wizardp(pker_master))
    if(4*me->query("combat_exp") < pker_master->query("combat_exp") ||
         me->query("combat_exp") > 4*pker_master->query("combat_exp")) {
      tell_object(me,"你的經驗值和對手相差太多。\n");
      return 1;
    }
  if( !me->pay_money(i) ) {
    tell_object(me,"你沒有足夠的錢付報名費，sorry 啦！ ^_^\n");
    return 1;
  }

  tell_object(me,"蔡總管說：依您的江湖名聲酌收"+cvalue(i)+"的報名費。\n");
  set_fighter(me);
  pker_master->set("break_away" ,1);
  pker_fighter->set("break_away" ,1);
  shout(HIC + "蔡總管喝道：" + HIW+pker_master->name()+HIC + "與" + HIW+
    me->name()+HIC + "將在一分鐘後開始比賽。" + NOR);
/*  tell_object(me,HIC + "蔡總管喝道：" + HIW+pker_master->name()+HIC+
    "與" + HIW+me->name()+HIC + "將在一分鐘後開始比賽。\n" + NOR);*/
  shout(HIC + "蔡總管說道：要押賭注的請儘快，逾時恕不受理。" + NOR);
//  tell_object(me,HIC + "蔡總管說道：要押賭注的請儘快，逾時恕不受理。\n" + NOR);
  this_object()->set_temp("pking",1);
  this_object()->delete_temp("wait_pk");
  this_object()->set_temp("pkla_time",1);
  return 1;
}

int doing_end(object me)
{
  if( me != pker_master && me != pker_fighter ) {
    tell_object(me,"你並沒有參加擂台賽。\n");
    return 1;
  }
  if( me == pker_fighter ) {
    tell_object(me,"你已經接受別人的挑戰無法徹回。\n");
    return 1;
  }
  if( me == pker_master && pker_fighter ) {
    tell_object(me ,"已經有人接受你的挑戰了，打敗他再說吧。\n");
    return 1;
  }

  delete_master();
  shout(HIC + "\n蔡總管喝道：" + HIW+me->name()+HIC + "退出比賽。"+
    "想稱霸為王者請速洽於我。" + NOR);
/*  tell_object(me,HIC + "\n蔡總管喝道：" + HIW+me->name()+HIC + "退出比賽。"+
    "想稱霸為王者請速洽於我。\n" + NOR);*/
  this_object()->delete_temp("wait_pk");
  return 1;
}

int doing_winner(object me)
{
  object *user;
  string desc = "";
  int i,sam = 0;

  user = users();
  desc += "        第      一      武      道      會      勝      負      表\n\n";
  for(i=0; i<sizeof(user); i++) {
    if( !wizardp(user[i]) ) {
      desc += sprintf("  %10s%12s  勝:%-3d負:%-3d",
        user[i]->name(),"("+user[i]->query("id")+")",
        user[i]->query("pk_win"),
        user[i]->query("pk_lose"));
      if( sam % 2 == 1 ) desc += "\n";
        sam += 1;
    }
  }
  desc += "\n";
  me->start_more(desc);
  return 1;
}

int doing_bet(object me,string pk,int number)
{
  if( me->query_skill("gamble",1) < 50 ) {
    tell_object(me,"賭術需五十級才可押注，請再多多加油。\n");
    return 1;
  }
  if( me == pker_master || me == pker_fighter ) {
    tell_object(me,"你在打擂台想押什麼注？\n");
    return 1;
  }
  if( !this_object()->query_temp("pkla_time") ) {
    tell_object(me,"押注時間已過，下次請把握時間。\n");
    return 1;
  }
  if( me->query_temp("bet_pker") ) {
    tell_object(me,"你已經押過賭注了，請耐心等待比賽結果。\n");
    return 1;
  }
  if( find_player(pk) != pker_master &&
      find_player(pk) != pker_fighter  ) {
    tell_object(me,"這位玩家並沒有打擂台賽。\n");
    return 1;
  }

  if( number > 300000 || number < 0 ) {
    tell_object(me,"你押的賭注不合規定，最多三十金。\n");
    return 1;
  }
  if( !me->pay_money(number) ) {
    tell_object(me,"賭本不夠還敢來賭？\n");
    return 1;
  }
  me->set_temp("bet_pker",pk);
  me->set_temp("bet_number",number);
  tell_object(me,"你付給蔡總管"+cvalue(number)+"。\n");
  return 1;
}

int full_all(object me)
{
  int gin,kee,sen;

  gin = me->query("max_gin");
  kee = me->query("max_kee");
  sen = me->query("max_sen");
  me->set("eff_gin",gin);
  me->set("eff_kee",kee);
  me->set("eff_sen",sen);
  me->set("gin",gin);
  me->set("kee",kee);
  me->set("sen",sen);
  return 1;
}

int pk_winner(object win)
{
  full_all(win);
  tell_object(win,HIY + "蔡總管說道：比賽結束！\n" + NOR);
  win->remove_all_killer();
  win->clear_condition();
  win->move(win->query_temp("pk_room"));
  win->delete_temp("pk_room");
  win->delete_temp("over");
  win->delete_temp("hand-all");
  win->delete_temp("eyes-all");
  if(pker_master && pker_fighter &&
     pker_master->query("potential")-(pker_master->query("learned_points"))>210 &&
     pker_fighter->query("potential")-(pker_fighter->query("learned_points"))>210)
  { //增加是否離線的判斷 by blazakira
    win->add("potential",100);
    win->add("pk_win",1);
  }
  win->delete("break_away");
  win->delete_temp("pk_fight");
  return 1;
}

int pk_loser(object lose)
{
  full_all(lose);
  tell_object(lose,HIY + "蔡總管說道：比賽結束！\n" + NOR);
  lose->remove_all_killer();
  lose->clear_condition();
  lose->delete_temp("over");
  lose->delete_temp("hand-all");
  lose->delete_temp("eyes-all");
  lose->delete_busy();
  lose->move("/open/wiz/courthouse");
  lose->delete_temp("pk_room");
  lose->add("potential",-130);
  lose->delete("break_away");
  lose->delete_temp("pk_fight");
  lose->add("pk_lose",1);
  if(lose->query("potential")-(lose->query("learned_points")) < 0)
  {
    lose->set("potential",0);
    lose->set("learned_points",0);
    lose->add("pkla使pot至負記錄",1);
  }
  return 1;
}

int winner(object win,object lose)
{
  object *user;
  int i;

  this_object()->delete_temp("pking");
  this_object()->delete_temp("pkla_time");
  this_object()->delete_temp("pking_time");
  this_object()->delete_temp("wait_pk");
  if( !win && !lose ) {
    if( pker_master && pker_fighter ) {
    shout(HIC + "\n蔡總管喝道：雙方超過比賽時間未分出勝負，有套招"+"嫌疑，皆罰潛能一百三十點，比賽結束。" + NOR);
    pk_loser(pker_master);
    tell_object(pker_master,HIR + "蔡總管告訴你：很抱歉，你打得太久了，必須受點懲罰。\n" + NOR);
    pk_loser(pker_fighter);
    tell_object(pker_fighter,HIR + "蔡總管告訴你：很抱歉，你打得太久了，必須受點懲罰。\n" + NOR);
  }
  else shout(HIC + "\n蔡總管喝道：雙方皆棄權，因此比賽無勝負，請下一組人馬準備。\n" + NOR);
  }
  else if( !lose ) {
    shout(HIC + "蔡總管喝道：比賽勝負已分！" + HIW+win->name()+HIC + "獲得最後的勝利！" + NOR);
    pk_winner(win);
    tell_object(win,HIR + "蔡總管告訴你：pk獲勝，得到一百點潛能。"+"歡迎下次再來！\n" + NOR);
  }
  else {
    shout(HIC + "蔡總管喝道：比賽勝負已分！" + HIW+lose->name()+HIC + "慘"+"遭屠戮...，勝者" + HIW+win->name()+"！" + NOR);
    pk_winner(win);
    tell_object(win,HIR + "蔡總管告訴你：pk 獲勝，得到一百點潛能。"+"歡迎下次再來！\n" + NOR);
    pk_loser(lose);
    tell_object(lose,HIR + "蔡總管告訴你：pk 敗陣，罰你跪一個月主機板！"+"扣一百三十點潛能，希望你繼續努力，下次再來。\n" + NOR);
  }
  delete_master();
  delete_fighter();
// 判斷有押賭注的玩家輸贏
  user = users();
  for(i=0; i<sizeof(user); i++) {
    if( user[i] && user[i]->query_temp("bet_pker") ) {
      if(win) {
        if(user[i]->query_temp("bet_pker") == win->query("id")) {
          user[i]->pay_player((int) 2 * user[i]->query_temp("bet_number"));
          tell_object(user[i],
            NOR + "蔡總管背著大袋子走了過來。\n"+
            HIR + "蔡總管告訴你：恭喜你賭場大勝！歡迎下次再來。\n"+
            NOR + "蔡總管從袋子裡拿出一樣東西往你身上一丟。\n"+
            NOR + "蔡總管背著大袋子往第一武道館走了過去。\n" + NOR);
        }
        else tell_object(user[i],
            HIR + "蔡總管告訴你：很抱歉！有賭有賠，請看開點。\n"+
            NOR + "只聽到從第一武道館傳來一陣狂笑："+
            "賺翻了！賺翻了！哇哈哈哈哈～～\n" + NOR);
      }
      else tell_object(user[i],
          HIR + "蔡總管告訴你：很抱歉！雙方皆棄權了，因此分不出"+"輸贏，賭注也沒法還給你囉！\n"+
          HIY + "蔡總管無奈的聳了聳肩。\n" + NOR);
          user[i]->delete_temp("bet_pker");
          user[i]->delete_temp("bet_number");
    }
  }
  if( win && !userp(win) ) destruct(win);
  if( lose && !userp(lose) ) destruct(lose);
  return 1;
}

string query_player()
{
  if( this_object()->query_str() )
    return this_object()->query_str();
  return "";
}

// damage.c 裡直接呼叫這個函式
int pk_lose(object me)
{
  if( me == pker_master )
    winner(pker_fighter,pker_master);
  else winner(pker_master,pker_fighter);
  return 1;
}

int break_away(object me,string arg)
{
  int i;

  full_all(me);
  me->add("potential",-200);
  me->delete("break_away");
  me->delete_temp("pk_fight");
  me->clear_condition();
  me->apply_condition("dark_poison",0);
  me->apply_condition("five_poison",0);
  me->apply_condition("rose_poison",0);
  me->apply_condition("snake_poison",0);
  me->apply_condition("burn",0);
  me->add("pk_lose",1);
  me->move(me->query("startroom"));
  tell_object(me,HIR + "蔡總管告訴你：pk 絡跑，須罰雙倍，扣兩百"+"點潛能，希望你繼續努力，下次再來！\n" + NOR);
  if( strlen(arg) ) {
    for(i=0; i<strlen(arg); i++) {
      tell_object(me,arg[i]);
    }
  }
  add("str",me->query("id")+" "+arg+"\n");
  return 1;
}

void heart_beat()
{
  object *user;
  int i,gin,kee,sen;

  set_heart_beat(1);

// 要有玩家pk 時才做以下這些
  if( query_temp("pking") ) { //調整判斷順序 by blazakira
    if( !pker_fighter && !pker_master ) //原順序5
      winner(0,0);
    else if( !pker_master ) //原順序1
      winner(pker_fighter,0);
    else if( pker_master->query_temp("netdead") ) //原順序2
      winner(pker_fighter,pker_master);
    else if( !pker_fighter ) //原順序3
      winner(pker_master,0);
    else if( pker_fighter->query_temp("netdead") ) //原順序4
      winner(pker_master,pker_fighter);
    else if( pker_master->query_temp("netdead") && pker_fighter->query_temp("netdead") ) //原順序6
      winner(0,0);
    else if( environment(pker_master) == environment(pker_fighter) &&
        (!pker_master->is_fighting() || !pker_fighter->is_fighting()) &&
        pker_master->query_temp("pk_fight") &&
        pker_fighter->query_temp("pk_fight") ) { //增加else後 為新順序7
      pker_master->kill_ob(pker_fighter);
      pker_fighter->kill_ob(pker_master);
    }
    if( query_temp("pkla_time") ) {
      if( query_temp("pkla_time") == 24 ) { //改成一分鐘
        delete_temp("pkla_time");
        pk_ing();
      }
      else {
        if( query_temp("pkla_time") == 22 ) //一分鐘的部份
          shout(HIC + "蔡總管喝道：距比賽時間還有十秒，請"+pker_master->name()+"與"+pker_fighter->name()+"兩位預備。" + NOR);
        add_temp("pkla_time",1);
      }
    }
  }
  else {
    if(!query_temp("wait_pk")) {
      if(pker_master) delete_master();
      if(pker_fighter) delete_fighter();
    }
  }

// pk 超過20 分鐘，則雙方等於棄權，照樣懲罰
  if( query_temp("pking_time") ) {
    if( query_temp("pking_time") == 480 )
      winner(0,0);
    else add_temp("pking_time",1);
  }
}
