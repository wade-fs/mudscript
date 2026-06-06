//增加暗殺活動的獎懲判斷 by blazakira 2011/8/25
//暫時將收到 no_give的道具 使用rumor傳達出來 既然是no_give的道具 還特地跑道皇宮深處送給天子 不再補償 by blazakira 2011/10/13

#include <ansi.h>
inherit NPC;
inherit SSERVER;

string ask_moon();
string ask_sula();
string ask_ghost();
int accept_kill(object who);

void create()
{
  set_name(HIM + "天子" + NOR, ({ "king" }) );
  set("title","當今皇上");
  set("gender", "男性" );
  set("age",50);
  set("str",50);
  set("cor",45);
  set("cps",35);
  set("int",50);
  set("long",
    "一位高大英挺的男人，言行舉止中有著令人無法抗拒的威嚴。\n"
    "但似乎有些事困擾著他，因而顯的有點鬱鬱寡歡。\n");
  set("class","fighter");
  set("clan_kill",1);
  set("del_delay",1);
  set("no_hole",1);
  set("no_plan",1);
  set("no_plan_follow",1);
  set("disable_no_give",1);

  set("capital_king",1);
  set("combat_exp",15500000);
  set("attitude", "heroism");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
    (: exert_function, "recover" :)
  }) );
  set_skill("dodge",250);
  set_skill("unarmed",250);
  set_skill("kingfist",250);
  set_skill("parry",250);

  set_skill("force",250);
  set_skill("fireforce",250);
  set_skill("bss-parry",250);
  set_skill("bss-steps",250);
  map_skill("force","fireforce");
  map_skill("unarmed","kingfist");
  map_skill("dodge","bss-steps");
  map_skill("parry","bss-parry");
  set("force",150000);
  set("max_force",100000);
  set("force_factor",40);
  set("max_gin",30000);
//  set("gin",30000);
  set("max_kee",30000);
//  set("kee",30000);
  set("max_sen",30000);
//  set("sen",30000);
  set("chat_chance", 15);
  set("chat_msg", ({
    "天子說：朕最近心情很差。\n",
    "天子說：後宮佳麗三千，各各爭寵，叫朕怎忙得過來。\n",
    "天子說：真該去練練帝王神功\了。\n",
    "天子說：傳說中的「八色魂石」，何時我也能得到此神物呢？\n",
  }) );
  set("inquiry",([
    "月半彎"   :  (:ask_moon:),
    "sula"     :  (:ask_sula:),
    "八色魂石" :  (:ask_ghost:),
  ]));
  setup();
  carry_object("/open/capital/obj/king-belt")->wear();
  carry_object("/open/capital/obj/secret_book");
  carry_object("/open/capital/obj/king-boots")->wear();
  carry_object("/open/capital/obj/king-cloak")->wear();
  carry_object("/open/capital/obj/king-cloth")->wear();
  carry_object("/open/capital/obj/king-ring")->wield();
  carry_object("/open/capital/guard/gring")->wear();
  add_money("gold",1000);
}

void init()
{
  object me=this_player();
  int force,be;

  be=me->query("bellicosity");
  force=me->query("force");
  if(be > force)
  {
    kill_ob(me);
    accept_kill(me);
  }

  add_action("do_fight", "fight");
  add_action("do_fight", "kill");
  add_action("do_cmd","cmd");
}

int do_cmd(string str) {
  object who=this_player();
  if(str=="askgod king" || str=="askgod guard" || str=="askgod king guard") {
    who->start_busy(2);
    kill_ob(who);
    accept_kill(who);
  } else if(str=="bak king" || str=="bak guard" || str=="askgod king guard") {
    who->start_busy(2);
    kill_ob(who);
    accept_kill(who);
  } else if(str=="cmd throw king"  || str=="cmd throw guard"  || str=="cmd throw guard"){
    who->start_busy(2);
    kill_ob(who);
    accept_kill(who);
  }
  return 1;
}

int accept_object(object who,object ob)
{
  string ob_id;
  object obj = this_object();

  ob_id=ob->query("id");

  if(ob_id=="yua's letter")
  {
    if(this_player()->query("quests/moon")==1)
      return notify_fail("你要給幾次啊??\n");
    if(!this_player()->query_temp("ask_moon7"))
      return notify_fail("想騙我嗎??這不是彎兒的親筆信!!\n");
    command("say 這是彎兒親筆所寫的信，謝謝你幫朕找到她。\n");
    command("say 朕總算知道她的下落，真是太好了，非常的謝謝你。\n");
    if(this_player()->query("gender")=="男性")
    { 
      message("system",HIM + "天子" + HIR + "大聲說道：" + HIY + "由於" + HIC + ""+this_player()->name()+"" + HIY + "
解開了鏡月島之謎，即日起朕允許\他進入鏡月島。\n" + NOR,users());
    }
    this_player()->set("quests/moon",1);
    new("/obj/money/diamond")->move(this_player());
    new("/obj/money/diamond")->move(this_player());
    new("/obj/money/diamond")->move(this_player());
    command("say 為了表達朕的謝意，這三顆鑽石請你收下。\n");
  }

  if( who->query_temp("quest/young") == 2 )
  {
    if( ob->query("spirit") == 1 )
    {
      switch(ob_id)
      {
        case "dark-spirit":
          if( !who->query_temp("quest/spirit_dark") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_dark",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "fire-spirit":
          if( !who->query_temp("quest/spirit_fire") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_fire",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "ground-spirit":
          if( !who->query_temp("quest/spirit_ground") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_ground",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "ice-spirit":
          if( !who->query_temp("quest/spirit_ice") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_ice",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "light-spirit":
          if( !who->query_temp("quest/spirit_light") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_light",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "thunder-spirit":
          if( !who->query_temp("quest/spirit_thunder") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_thunder",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "water-spirit":
          if( !who->query_temp("quest/spirit_water") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_water",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        case "wind-spirit":
          if( !who->query_temp("quest/spirit_wind") )
          {
            command("say 嗯！很好很好！我要的就是這個東西了！！");
            who->set_temp("quest/spirit_wind",1);
            destruct(ob);
            call_out("check",1,obj);
          } else {
            command("say 這已經給過我了，我不需要再多的了！");
          }
          break;
        default:
          command("say 別亂給我無用處的東西，否則將滿門抄斬絕不留情！！");
          break;
      }
    }
  }
  if( ob->query("no_give") ) {
    message("rumor",HIB+"【謠言】某人: 我聽宮裡的公公耳語，"+sprintf ("有人進貢%s" + HIB + "(%s" + HIB + ")給皇上呢。\n" + NOR,ob->name(),ob->query("id")),users());
    message("rumor",HIB+"【謠言】某人: 難道他不知道送到宮裡的東西恍若「劉備借荊州」的嗎？\n" + NOR,users());
    environment()->set_temp("giver/"+who->query("id"),ob->query("name")+"("+ob->query("id")+")");
    ob->set("no_get");
    ob->set("no_steal");
    if( ob->query("boss") ) ob->set("old_boss",ob->query("boss"));
    ob->delete("boss");
  }
  return 1;
}

int check(object obj)
{
  object who;
  int i,j;

  who = this_player();

  i = this_object()->query("check");
  j = 7-i;

  obj->add("check",1);

  if( j > 0 )
    command("say 再交給我"+ chinese_number(j)+"個魂石就可以完成我的心願了。");
  if( j == 0 )
  {
    command("say 太好了，終於完成我的心願了。");
    command("say 我就幫你突破返老還童的禁錮吧！讓你能更上一層樓。");
  }

  if( obj->query("check") == 8 )
  {
    message_vision(HIC + "\n只見天子手指聚出了一陣靈光，運行在$N身上。\n",who);
    command("say 試著再一次運行你之前所學的返老還童術，你就會發現不一樣的神奇地方啦！");
    command("say 如果覺得運行的太慢了，可以 「set 倍升」 就會發現速度快很多了！");
    command("say 快速倍升的代價就是會快速的消耗你的潛能值和經驗值，是否值得就看你的取決了。");
    who->set("quests/young",1);
    who->delete_temp("quest");
    tell_object(users(),HIM + "\n天子" + HIC + "昭約：世上又多了一個會終極返老還童術的人啦！\n\n" + NOR);
    log_file("open-area/young", sprintf("%s(%s) 解開進階返老還童術 on %s\n",who->query("name"),who->query("id"), ctime(time()) ));
  }
  return 1;
}

string ask_moon()
{
  object who;
  who = this_player();
  if(!this_player()->query_temp("ask_moon2"))
    return "嗯....這我可不清楚，你最好問問別人吧。";
  command("say 你知道她在哪嗎??快告訴我!!!");
  command("say 你怎麼會知道這件事？");
  this_player()->set_temp("ask_moon3",1);
  kill_ob(who);
  accept_kill(who);
}

string ask_ghost()
{   
  object who,obj;

  who = this_player();
  obj = this_object();

  if( obj->query("check") == 8 )
  {
    command("say 別再來煩我了！");
    return "";
  }

  if( who->query("quests/young") )
  {
    command("say 感謝你替我收集來八顆魂石。");
    command("say 進階的返老還童術我已經盡傳於你了！");
    return "";
  } else {
    if( who->query("functions/young/level") < 100 )
    {
      command("say 看你的的神情該是學過返老還童術了，但卻未熟練。");
      command("say 本想託付你一件任務的，我看還是等你練到一定的程度之後再來吧！");
    } else {
      command("say 你返老還童練到一定的程度了，我想這任務可以託付給你了。");
      command("say 相傳這個世界上有八種屬性的魂石，我很想要收藏這八顆魂石。");
      command("say 你可以幫我收集來這八顆魂石嗎？");
      command("say 只要你點個頭，我就當做你答應了。");
      who->set_temp("quest/young",1);
      add_action("do_nod","nod");
    }
  }
  return "";
}

int do_nod()
{
  object me = this_player();
  if(me->query_temp("quest/young") != 1)
    return 0;

  me->set_temp("quest/young",2);
  remove_call_out("greeting");
  call_out("greeting",1,me);
  return 0;
}

void greeting(object me)
{
  object ob = this_object();
  command("think");
  command("say 替我收集齊全，少不了你的好處的。");
}

//add by cgy...好玩而已
string ask_sula()
{
  object who;
  who = this_player();
  if(this_player()->query("id")!="sula")
    return "嗯....你不是 sula問那麼多幹嘛??";
  command("say 很好你終於來了!!!");
  this_player()->set("title",HIG + "狂想空間" + HIY + "永遠的" + HIW + "卒仔" + NOR);
  message("system",HIM + "天子" + HIR + "大聲說道：" + NOR + "查" + HIC + "復活邪神" + HIY + "(sula)" + NOR + "乙員，於狂想空間\n
	 打混多年，一路走來，始終如一" + HIC + "(的肉)" + NOR + "特賜予" + HIG + "狂想空間" + HIY + "永遠的" + HIW + "卒仔" + NOR + "封號以資表揚。
	 
	            " + HIM + "欽此  " + HIG + "謝恩  \n" + NOR,users());
	
}

int do_fight(string arg)
{
  object who;
  who = this_player();

  if (!arg || arg!="king")
    return notify_fail("你想攻擊誰？\n");
  else {
    kill_ob(who);
    accept_kill(who);
  }
  return 1;
}

int accept_kill(object who)
{
  object ob, guard;
  ob = this_object();

  if( !present("kill guard", environment(ob)) && query_temp("unconcious") != 1 ) {
    if (ob->query_temp("killking")!=1){
      tell_room(environment(ob),HIW + "\n突然！衝出兩位御前侍衛長！\n\n" + NOR);
      guard = new(__DIR__"fuguard");
      guard->move(environment(ob));
      guard->command("defend king");
      guard->command("follow king");
      guard->kill_ob(who);
      guard = new(__DIR__"fuguard1");
      guard->move(environment(ob));
      ob->set_temp("killking",1);      
      guard->command("follow king");
      guard->kill_ob(who);
      tell_object(users(),HIR + "御前護衛大叫：有刺客！快保護殿下！！\n" + NOR);
      command("wear all");
    }
    else {
      command("say 可惡  ...看我的帝王神功\..");
//      tell_object(this_player(),HIC + "只覺無比厚重的壓力硬往你身上壓來。\n" + NOR);
      tell_object(who,HIC + "只覺無比厚重的壓力硬往你身上壓來。\n" + NOR);
//      this_player()->add("kee",-(this_player()->query("max_kee")/2));
      who->receive_damage("kee",(int)(who->query("max_kee")/2),ob);
    }
  }
  return 1;
}

void heart_beat()
{     
  object enemy;
  object me=this_object();
  if(!me || !environment(me)) return ;
  if(me->is_fighting() && me->query_temp("unconcious") != 1 )
  {
    enemy=offensive_target(me);
    if(!enemy) return ;
    if((me->query("kee") < me->query("max_kee")/10)&&(enemy->query_temp("ask_moon3")==1))
    {
      me->remove_all_killer();
      command("say 自從她離開後我多次派人尋訪不著，也許\李逍遙知道她的下落吧。");
      command("say 如果你找到她幫我把這封信交給她。"); 
      new("/open/capital/obj/letter")->move(enemy);
      message_vision("皇上給了$N一封信。\n",enemy);
      enemy->set_temp("ask_moon4",1);
    }
    if(50 > random(100))
    {
      me->delete_busy();
      message_vision("$N舒展了一下筋骨，瞬間生龍活虎了起來!!\n",me);
    }
  }
  ::heart_beat();
}

void die()
{
  object ob;
  int i,j,k;
  object me=this_object(),*user;
  object winner;
  if(!query_temp("last_damage_from")) {
    ::die();
    return ;
  }
  else
    winner=query_temp("last_damage_from");
  if(!winner) {
    ::die();
    return ;
  }
  winner->set("secret_book",1);

  if(winner->query_temp("ask_moon3")==1)
  {
    command("say 自從她離開後我多次派人尋訪不著，也許\李逍遙知道她的下落吧。");
    command("say 如果你找到她幫我把這封信交給她。");
    new("/open/capital/obj/letter")->move(winner);
    message_vision("皇上給了$N一封信 .\n",winner);
    winner->set_temp("ask_moon4",1);
  }
  else
  {
    write("皇上說：想不到你竟敢弒君！\n"); 
  }

  tell_object(users(),HIR + "\n\n

   『啊～～～～～～ 』

    一聲慘叫從皇城中傳出，劃破了天際，震撼了每個人的心


      『皇上駕崩啦～～～～』．．．．．．

    百姓紛紛面朝皇城的方向跪地磕頭，有些人甚至哭了起來

      太后大叫道：可惡的"+((winner&&objectp(winner)==1)?winner->query("name"):"咕哩貓")+HIR + "，竟敢以下犯上，

                凡我同胞，人人得而誅之!!!!
  \n\n" + NOR);

  if( winner && winner->query_temp("assassination list") ) {
    tell_object(users(),HIG + "   "+winner->query("name")+"竊笑道：這就是天朝的天子？呔！

      鐘妃大叫道：皇上竟被人刺殺！快給我追殺兇手。

(由於當朝天子被人刺殺，你受到心神震盪(busy一回)、功\力衰弱(附加虛弱)，實戰經驗減少。) (預計推出
  \n" + NOR);
    user=users();
    j=sizeof(user);
    for( i=0 ; i < j ; i++ )
    {
      k=user[i]->query("combat_exp"); //實戰經驗少於2kw的不懲罰
//      if(!user[i] || !environment(user[i]) || k < 20000000 || user[i]->query("id") != "blazakira" ) continue; //懲罰忽略的條件
      if(!user[i] || !environment(user[i]) || user[i]->query("id") != "blazakira" ) continue; //測試中
      k=k/1000;
      tell_object(user[i],RED+BWHT + "由於當朝天子被人刺殺，你受到心神震盪(busy一回)、功\力衰弱(附加三級虛弱)、實戰經驗減少"+k+"點!!\n" + NOR);
      user[i]->start_busy(1);
      user[i]->apply_condition("power-down",3);
      user[i]->add("combat_exp",-k);
      environment()->add_temp("king/"+user[i]->query("id")+"/combat_exp/-k",k); //因為可重複扣所以用add_temp
//    environment()->set_temp("king/",);
    }
  }
  if( winner && userp(winner) && winner != 0 ) {
    log_file("KILL_KING", sprintf("%s(%s) 打敗 天子 on %s\n"
      ,winner->query("name"),winner->query("id"), ctime(time()) ));
  }
  :: die();
}
