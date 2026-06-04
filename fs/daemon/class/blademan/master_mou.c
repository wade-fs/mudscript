//增加恢復title的功能 by blazakira 2011/2/26

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
string do_mdragon();
string do_mblade();
string ask_title();

void create()
{
  set_name("莫無愁",({"master mou","mou","master"}));
  set("long","神秘老人的愛兒，二十餘年來忍辱偷生，為的是找尋獨孤愁，報其父債，其狂龍刀法以快
達到其父的水準，又因鑑於當初父親所犯下的錯誤，改良【狂龍怒斬】研發出【魔龍訣】
雖威力不及父親，但確有其隱藏的後勁，且立誓與獨孤愁後代傳人勢不兩立。\n");
  set("gender","男性");
  set("attitude","heroism");
  set("age",35);
  set("class","blademan");
  set("nickname",HIR + "復仇魔刀" + NOR);
  set("title","魔刀門第二代掌門");
  create_family("魔刀門",2,"掌門");
  set("score",100000);
  set("force",4000);
  set("max_force",4000);
  set("env/魔性六斬","YES");
  set("max_kee",30000);
  set("force_factor",25);
  set("mpower",1);
  set("cor", 35);
  set("str", 35);
  set("per", 20);
  set("int", 25);
  set("functions/mdragon-dest/level",100);
  set("cps", 35);
  set("con", 35);
  set("spi", 25);
  set("kar", 35);
  set("combat_exp", 1000000);
  set("bellicosity", 3000);
  set_skill("riding",80);
  set_skill("force", 90);
  set_skill("parry", 90);
  set_skill("move", 60);
  set_skill("dodge", 60);
  set_skill("cure", 50);
  set_skill("dragon-blade",105);
  set_skill("powerforce", 90);
  set_skill("blade", 100);
  set_skill("literate", 40);
  set_skill("unarmed", 20);
  set_skill("spells", 20);
  set_skill("magic", 20);
  map_skill("parry","dragon-blade");
  map_skill("blade","dragon-blade");
  map_skill("force","powerforce");
  set("chat_chance",40);
  set("chat_msg",({
    HIW + "唉！都找不到我父親～魔刀莫測…\n" + NOR,
    HIW + "我的狂龍刀法已達上限，但和父親比起來又差了一截。\n" + NOR,
    HIY + "聽說我父親有一把鎮教之寶，不過詳情也只有我父親知道。\n" + NOR,
  }));
  set("inquiry",([
    "魔龍訣"  : (: do_mdragon :),
    "魔刀莫測":"聽說我父親被關在雪蒼後山裡，但我一直找不到，摸不著頭緒。",
    "狂龍怒斬":"那是我父親研究出來的，比我的魔龍訣強上數倍。",
    "狂龍刀法":"那是我父親當年所自豪的刀法，聽說還有失傳奧義和狂龍怒斬及三斬歸元。",
    "失傳奧義":"我不太清楚，傳到我時已沒那招了，那招式只有我父親才會。",
    "三斬歸元": (: do_mblade :),
    "稱號"    : (: ask_title :),
    "title"   : (: ask_title :),
  ]));
  set("chat_chance_combat",100);
  set("chat_msg_combat",({
  (: perform_action, "blade.mdragon-dest" :),
  }));
  set_temp("apply/armor",65);
  set_temp("apply/damage",65);
  setup();
  carry_object("/daemon/class/blademan/obj/ublade.c")->wield();
  carry_object("/daemon/class/blademan/obj/shield.c")->wear();
  carry_object("/daemon/class/blademan/obj/six-neck.c");
  add_money("gold",10);
}

// by acky 找出作弊者
void greeting(object ob)
{
  if(!ob) return ;
  if( ob->query("get-evil-mblade")==1 ) {
    if( ob->query("family/family_name")!="魔刀門" && ob->query("family/family_name")!="魔刀莫測" && !wizardp(ob)) {
      command( "chat "+ob->query("name")+"("+ob->query("id")+")你這個作弊的無恥之徒, 給我去死吧!" );
      kill_ob(ob);
      log_file( "BUG/妖刀", sprintf("%s %s(%s)非魔刀門人, 卻持有妖刀\n"
        ,ctime(time())[0..15], ob->query("name"), ob->query("id") ) );
      return;
    }
    if( !present( "evil-mblade", ob ) ) {
      new("/autoload/blademan/evil-mblade.c")->move(ob);
      command( "say 你竟然把我門的鎮教之寶給弄丟了!" );
      command( "waggle "+ob->query("id") );
      command( "say 要是下回再弄丟, 可就不管你!" );
      message_vision( HIY + "莫無愁從身旁拿出妖刀交到$N手中!\n" + NOR, ob );
      command( "say 請好好保管好吧!" );
    }
  }
}

void attempt_apprentice(object obj)
{
  command("l "+obj->query("id"));
  if(obj->query("title") == HIR + "殺手全力追殺的人頭" + NOR)
  {
    command(" say 死小孩....又想來作弊！！");
    return ;
  }
  if(obj->query_kar(1)<25||obj->query("have_officer",1)==1||obj->query("family/family_name")=="金刀門")
  {
    command("sigh "+obj->query("id"));
    command("say 莫某與你無緣，你走吧。\n");
    command("shake");
    return;
  }
  command(":)");
  command("say 好小子，果然有無比的膽量。");
  command("say 好，我收"+this_player()->name()+"為我門徒。");
  obj->delete("family");
  command("recruit "+obj->query("id"));
  if(this_player()->query("m_blade")==1) {
    this_player()->set("title","[1;31m魔刀[1;37m『三斬歸元』[1;35m傳人[0m");
  }
  message("system",HIW + "莫無愁縱聲長笑:
\n哈哈哈哈～～魔刀復仇將至。" + NOR,users());
  message("system",HIR + "\n\n今後"+this_player()->name()+"將會替我血洗獨孤老賊。\n" + NOR,users());
  this_player()->set("no_recruit", 1);
  return ;
}

void init()
{
  object ob;
  ::init();
  if(interactive(ob =this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    if(ob)
      call_out("greeting",1,ob);
  }
  add_action("do_verify","verify");
}

int do_verify(string arg)
{
  object me,ob;
  me=this_player();
  ob=new("/autoload/blademan/mblade");
  if(arg!="blade")
  {
    write("你要拿什麼啊？\n");
    return 1;
  }
  if((me->query("family/family_name")!="魔刀門")&&me->query("family/family_name")!="魔刀莫測")
  {
    write("只有魔刀門徒才會有喔。\n");
    return 1;
  }
  if(arg=="blade")
  {
    if(present("mblade",me))
    {
      write("你有刀了還要。\n");
      return 1;
    }
    write("啊？你把刀子丟啦，我再給你好了。\n");
    ob->move(me);
    return 1;
  } 
}

string do_mdragon()
{
  object who;
  who=this_player();
  if(who->query("family/family_name")!="魔刀門"&&who->query("family/family_name")!="魔刀莫測")
  {
    command("say 你怎會知到魔龍訣，難道是獨孤老賊派你來的。");
    command("say 既然如此，我就不能讓你活著回去，嘿嘿嘿。");
    command("kill "+who->query("id"));
    return "殺死你，可惡的間碟。";
  }
  command("say 這是為師畢生所研究出來的，這就傳授給你了。");
  command("say 用法(perform blade.mdragon-dest)，但要狂龍刀法『105』才能用。");
  return "希望你能好好用之。";
}

string do_mblade()
{
  object me;
  me=this_player();
  if( me->query_skill("dragon-blade",1) < 90 ) {
    command("say 你狂龍刀法需要再加強些，不要胡思亂想");
    return "去加強你的刀法吧"; }
  if( me->query("combat_exp") < 3000000 ) {
    command("say 你實戰經驗不足。");
    return "去加強你的實戰經驗吧"; }
  if( me->query("snow-head",1) < 700 ) {
    command("say 你殺的雪蒼弟子還不夠，等夠了再說吧");
    return "去多殺點雪蒼弟子吧"; }
  command("say 那是魔刀至陰至毒的招式，我父親傳我心法之後，也才習得一式");
  command("say 除非，你能拿獨孤嵊的人頭來，那樣你才有資格能習得此心法");
  command("say 獨孤嵊是魔刀的世仇，被關在魔刀門內，但是一直有人想去解救他");
  command("say 且獨孤嵊的弟子佔據魔龍塔多年，等待獨孤嵊的歸來，想一舉消滅我門");
  return "所以，只要你能消滅獨孤嵊我就傳你心法";
}

int accept_object(object who, object ob)
{
  object mid;
  if(ob->query("id") == "sa-head")
  {
    destruct(ob);
    say("莫無愁看了看獨孤嵊的頭說道 : 這是『武天至聖』獨孤嵊的頭。\n");
    if(who->query("family/family_name")=="魔刀門"||who->query("family/family_name")=="魔刀莫測")
    {
      if(!who->query("m_blade",1))
      {
        if(who->query("combat_exp") < 3000000 ) {
        say("你實戰經驗不足，再去多修練吧！\n");
        return 1;
      }
      if(!who->query_temp("ko_sa")) {
        say("他又不是你殺的，別想矇騙過關！\n");
        return 1;
      }
      if(who->query("snow-head",1)<700)
      {
        say("你還不夠邪惡，再去多殺一些人吧！\n");
      }
      else
      {
        say("沒想到你竟能殺的了他，好吧，算你對本派有所貢獻。\n"
            "我將魔刀的『三斬歸元』心法傳授給你吧。\n"
            "至於如何運用，自己去體會吧，哈哈哈！\n");
        message("system",HIC + "莫無愁詭異笑道：\n" + HIW + "
                魔刀『三斬歸元』" + HIC + "終於後繼有人了\n
                看來剷平雪蒼之日不遠呀！\n" + HIR + "
        哈！哈！哈！"+this_player()->name()+"魔刀復仇全靠你了！\n" + NOR,users());
        who->set("m_blade",1);
        who->set("title","[1;31m魔刀[1;37m『三斬歸元』[1;35m傳人[0m");
        log_file("mblade/m_blade",sprintf("%s解到魔刀後三\n",who->short()));
      }
    }
/*
    else if(who->query("t_standby")<who->query("max_standby"))
    {
      say("你心法已經會了，但魔刀人要有邪惡之氣為輔住！！\n"
          "那我就送你一個保命金身吧，危險時能保你邪惡之氣！！\n");
      log_file("mblade/standby",sprintf("%s換了一個替身\n",who->short()));
      who->add("standby",1);
      who->add("t_standby",1);
    }
    else message_vision( HIW + "\n小雪球說道：你曾經擁有的替身總數已達上限，無法再增加，我無法幫助你。\n\n" + NOR, who );
*/
  }
  else
  {
    if(!who->query("get_atman",1))
    {
      say("沒想到我魔刀門的宿敵，竟會被你所殺，看來天意難違。\n"
          "好！既然人是你殺，我就傳我部份靈力和法力給你吧。\n");
      message_vision(HIC + "莫無愁將手指向$N眉心，瞬時靈氣貫頂，$N身上散發出陰靈之氣。\n" + NOR,who);
      who->add("max_atman",200);
      who->add("max_mana",200);
      who->add("atman",200);
      who->add("mana",200);
      who->set("get_atman",1);
    }
/*
    else if(who->query("t_standby")<who->query("max_standby"))
    {
      say("嘿嘿！你已得我靈力與法力，但人心險惡那我再送你\n"
          "一個保命金身好了！小心邪惡之人呀！哈哈哈！\n");
      log_file("mblade/standby",sprintf("%s換了一個替身\n",who->short()));
      who->add("standby",1);
      who->add("t_standby",1);
    }
    else message_vision( HIW + "\n小雪球說道：你曾經擁有的替身總數已達上限，無法再增加，我無法幫助你。\n\n" + NOR, who );
*/
    }
  }
}

void heart_beat()
{
  object env,mob,*enemy,target;
  int i;
  mob = this_object();
  env = environment(mob);
  if( random(100) > 70)
  {
    enemy=mob->query_enemy();
    if( i = sizeof(enemy) ) {
      target=offensive_target(mob);
      if(target)
      if( env == environment(target) )
      {
        message_vision(HIY + "
莫無愁施展出魔刀『三斬歸元～魚龍嗜元』\n"+
"．．．『魚龍毒鴆～～煌嵐叢滅』．．．\n"+
"$N閃避不及，被打中要害，血流滿地\n" + NOR,target);
        target->receive_damage("kee",600,mob);
        COMBAT_D->report_status(target,1);
      }
    }
 }
  ::heart_beat();
}

int accept_kill(object who)
{
//  who=this_player();
  command("wear all");
  command("kill "+who->query("id"));
  command("perform blade.mdragon-dest");
  return 1;
}

int accept_fight(object who)
{
//  who=this_player();
  command("wear all");
  command("kill "+who->query("id"));
  command("perform blade.mdragon-dest");
  return 1;
}

string ask_title()
{
  object who=this_player();
  if(random(2)==0) {
    if(who->query("m_blade")==0)
      return "似乎你還沒拿到魔刀吧？";
    who->set("title","[1;31m魔刀[1;37m『三斬歸元』[1;35m傳人[0m");
  }
  else {
    if(who->query("get-evil-mblade")==0)
      return "似乎你還沒拿到妖刀吧？";
    who->set("title","[1;32m妖[1;37m刀[1;32m傳[1;37m人[0m");
  }
  return ("想要恢復稱號呀…");
}

void die()
{
  object winner = query_temp("last_damage_from");
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }

  if (winner && userp(winner)) {
    tell_object(users(),HIR + "\n\n莫無愁仰天怒吼：\n\n\t可恨的"+winner->name()+HIR + "竟阻礙我復仇大業！
\n\t老子會再回來報仇的！等著吧！\n\n" + NOR);
  }
  if (winner && winner->query("assassin")) {
    tell_object(users(),HIR + "\n\n莫無愁仰天怒吼：\n\n\t可恨的"+winner->name()+HIR + "竟阻礙我復仇大業！
\n\t老子會再回來報仇的！等著吧！\n\n" + NOR);
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj11/orange-crystal")->move(environment(winner));
        message_vision(HIM + "\n從莫無愁的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj11/orange_crystal",sprintf("%s(%s) 讓莫無愁掉下了橙色光晶於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj11/orange-crystal")->move(environment(winner));
        message_vision(HIM + "\n從莫無愁的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj11/orange_crystal",sprintf("%s(%s) 讓莫無愁掉下了橙色光晶於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  :: die();
}
