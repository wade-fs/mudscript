//這一版本，只是加入霸雨式之謎，所需的回話與接受東西時的反應
//其他並沒有修改任何數值

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string do_ep9();
string do_fb5();
string do_givewhip();
string do_givebook();
string do_rain();
string poison();
string ask_lee();

int accept_object(object me,object ob,object who)
{
  object ob2;
  if (me->query_temp("rain_2") != 1)
  {
    command ("say 神經病，你給我這個幹嘛！\n");
    destruct(ob);
    return 0;
  }
  if(ob->query("id") == "rou_letter" && me->query_temp("gived") != 1) 
  {
    destruct(ob);
    message_vision(" 莊靜柔將信收下來，將信拆開，仔細閱\讀。\n",me);
    message_vision(" 一開始還面帶怒容，但逐漸的笑容漸開……\n",me);
    message_vision(" 看完信後，莊靜柔很開心。\n",me);
    command("say 小朋友，你真好，你將這一封信帶給柴榮他。\n");
    ob2=new("/open/killer/obj/low_let.c");
    ob2->move(me);
    me->set_temp("gived",1);  //防止重複拿取
    me->set_temp("rain_3",1);
    return 1;
  }
  if(me->query_temp("god") == 1 && ob->query("id") == "god dagger")
  {
    destruct(ob);
    message_vision(" 莊靜柔將滅神匕首收下來，仔細觀看著匕首，似乎在想著什麼。\n",me);
    message_vision(" 忽然臉頰留下兩行清淚\，莊靜柔回過身去……\n",me);
    message_vision(" 過了一會兒，回過身面對著$N。\n",me);
    command("say 當時真不好意思，打傷了你，這是天魔解體大法，拿去還給柴榮吧！");
    ob2=new("/open/killer/obj/evilgod.c");
    ob2->move(me);
  }
  return 0;
}

void create()
{
  set_name("莊靜柔",({"master low","low"}));
  set("long","她就是武林中令人聞風喪膽的冥蠱魔教教主「莊靜柔」，別看她一張秀麗的臉蛋，其為人可是十分陰毒。\n");
  set("gender","女性");
  set("class","poisoner");
  set("nickname", HIR + "九陰仙子" + NOR);
  set("combat_exp",3000000);
  set("attitude","heroism");
  set("age",26);
  set("str", 44);
  set("cor", 24);
  set("cps", 18);
  set("per", 24);
  set("int", 48);
  set("force",10000);
  set("max_kee",10000);
//  set("kee", 10000);
  set("max_gin",10000);
//  set("gin",10000);
//  set("sen",10000);
  set("max_sen",10000);
  set("bellicosity",1500);
  set("chat_chance_combat",80);
  set("chat_msg_combat",({
    (: poison :),
    (: perform_action("poison.five") :),
    (: perform_action("poison.firefinger") :),
  }));
  set("functions/firefinger/level",100);
  set("functions/five/level",100);
  set("poison",1000000);
  set_skill("literate",30);
  set("max_force",10000);
  set("env/cure_poison","dark");
  set_skill("move",120);
  set_skill("force",60);
  set_skill("dodge",120);
  set_skill("parry",50);
  set_skill("poison",120);
  set_skill("whip",100);
  set_skill("poisonforce",100);
  map_skill("force","poisonforce");
  set("force_factor",20);
  set_skill("coldpoison",100);
  set_skill("nine-steps",120);
  map_skill("dodge","nine-steps");
  map_skill("move","nine-steps");
  map_skill("poison","coldpoison");
  set_skill("ming-snake",100);
  map_skill("whip","ming-snake");
  map_skill("parry","ming-snake");

  set("inquiry",([
    "月石"         : "那是本教眾寶之一，平日收藏於左護法那，近來『遭竊』了。",
    "遭竊"         : "我想可能是本教『叛徒』所為。",
    "叛徒"         : "目前不清楚，但我想外面的訪客可能有問題。",
    "basewhip"     : (: do_givewhip :),
    "天魔解體大法" : (: do_rain :),
    "basebook"     : (: do_givebook :),
    "赤火令"       : "你以為你是誰呀! 膽敢跟我要令牌。",
    "李秋凡"       : (: ask_lee :),
    "秘籍"         : "早就不在我這邊了，不是已經被搶回去了？！",
    "衝穴"         : "還好我在秘籍奪來時，就偷偷的習得，並且融入我的內功\之中了。",
    "銀針門"       : "口亨，哪個口口聲聲要用醫術救人的門派，為了練功\還不是一直在殺人。",
    "前任教主"     : (: do_ep9() :),
    "小水池"       : "不就是殺手總壇裡的小水池嗎。",
    "教主義女"     : (: do_fb5() :),
    "武林盟主"     : "問我座下的玉女吧，這小事不要來打擾我。",
  ]));
  setup();
  create_family("冥蠱魔教",3,"教主");
  carry_object("open/poison/obj/circle.c")->wear();
  carry_object(POISON_OBJ"bleed_whip")->wield();
  carry_object("open/poison/obj/godcloth.c")->wear();
  carry_object("open/poison/obj/cape.c")->wear();
  carry_object("open/poison/obj/feather.c")->wear();
  carry_object("/obj/poison/rose_poison")->set_amount(80);
  carry_object("/obj/poison/five_poison")->set_amount(80);
  carry_object("/obj/poison/dark_poison")->set_amount(80);
  carry_object("/obj/poison/faint_poison")->set_amount(80);
  carry_object("/obj/poison/scorpion_poison")->set_amount(80);
}

int accept_kill(object me) 
{
  command("cmd throw poison 1 to "+me->query("id"));
  command("cmd throw poison 2 to "+me->query("id"));
  command("cmd throw poison 3 to "+me->query("id"));
  command("cmd throw poison 4 to "+me->query("id"));
  command("cmd throw poison 5 to "+me->query("id"));
  return 1;
}

int accept_fight(object me)
{
  command("cmd throw poison 1 to "+me->query("id"));
  command("cmd throw poison 2 to "+me->query("id"));
  command("cmd throw poison 3 to "+me->query("id"));
  command("cmd throw poison 4 to "+me->query("id"));
  command("cmd throw poison 5 to "+me->query("id"));
  return 1;
}

string ask_lee()
{
  object me = this_player();
  if(me->query_temp("quests/acup") < 3)
  {
    return "嗯...這人...我不認識。\n";
  }
  if(me->query_temp("quests/acup") == 3)
    me->set_temp("quests/acup",4);
  return "口亨，當年他搶回去秘籍時，我那知道他跑去哪了。\n"+
         "有啦，有聽說啦，是在京城附近的山上，有沒有我就不知道了。\n";
}

string poison()
{
  command("perform poison.faint");
  return "\n";
}

void init()
{
  add_action("do_join","join");
  add_action("do_say","swear");
}

int do_join()
{
  object me=this_player();
  if(!me->query_temp("poison_pass2")){
    command("say 你還沒通過入教儀式呢？");
    command("say 等你通過再來吧。");
    return 1;
  }
  else {
    command("smile");
    command("say 很好，既然你已求得兩位長老的同意。");
    command("say 那你就在此宣誓(swear)入教。");
    me->set_temp("master_temp",1);
    say(HIC + "金童說道﹕請施主宣誓『盡忠魔教』以完成儀式。\n" + NOR);
    return 1;
  }
}

int do_say(string str)
{
  object me = this_player();
  object book = new("/open/poison/obj/pbasebook");
  if(me->query_temp("master_temp")){
    if(str == "盡忠魔教"){
      me->set("poison_low",1);
      if(!((me->query("class")=="poisoner")&&(!(me->query("family/family_name"))||(me->query("family/family_name")=="冥蠱魔教"))))
      {
        command("shout $HIR$又有人投靠我教，效忠於我了。");
      }
      else {
        command("shout $HIR$我冥蠱魔教又有新教徒$HIG$"+me->query("name")+"$HIR$。\n");
        command("shout $HIR$看來是我魔教復出武林的時候了。\n");
//        command("poisoner $HIG$讓我們一起歡迎我們的新教徒$HIR$"+me->query("name")+"$HIG$吧。\n");
        command("gt $HIG$讓我們一起歡迎我們的新教徒$HIR$"+me->query("name")+"$HIG$吧。\n");
      }
      say(HIC + "玉女說道﹕歡迎加入魔教，將來要遵從教令哦。\n" + NOR);
      command("say 這是本教入門書籍，你好好研讀吧。");
      book->move(me);
      me->delete_temp("master_temp");
      return 1;
    }
    else {
      message_vision(sprintf(HIC + "$N發誓說道﹕"+str+"\n" + NOR),me);
      command("say 你說什麼呀，沒誠意就滾回去。");
      me->delete_temp("master_temp");
      return 1;
    }
    message_vision(sprintf(HIC + "$N發誓說道﹕"+str+"\n"),me);
    command("say 我有同意讓你發誓嗎？");
    return 1;
  }
}

void heart_beat()
{
  object ob=this_object();
  int i;

  if( !ob->is_fighting() && ob->query_condition() )
  {
    for(i=0;i<5;i++)
    {
      switch(i)
      {
        case 0:
          if(ob->query_condition("snake_poison"))
          {
            ob->set("env/cure_poison","snake");
            command("exert depoison");
          }
          break;
        case 1:
          if(ob->query_condition("dark_poison"))
          {
            set("env/cure_poison","dark");
            command("exert depoison");
          }
          break;
        case 2:
          if(ob->query_condition("rose_poison"))
          {
            set("env/cure_poison","rose");
            command("exert depoison");
          }
          break;
        case 3:
          if(ob->query_condition("five_poison"))
          {
            set("env/cure_poison","five");
            command("exert depoison");
          }
          break;
        case 4:
          if(ob->query_condition("fire_poison"))
          {
            set("env/cure_poison","firefinger");
            command("exert depoison");
          }
          break;
      }
    }
  }
  ::heart_beat();
}

void attempt_apprentice(object ob)
{
  if(this_player()->query("class")!="poisoner")
  {
    command("say 你不是我們魔教的人，你走吧！");
    return;
  }
  else if(!this_player()->query("poison_low"))
  {
    command("say 雖然你是魔教徒一員，但你未正式拜入我教。");
    command("say 所以我也不便傳你任何技能，你請回吧。");
    return;
  }
  command("smile");
  command("recruit "+ob->query("id"));
}

string do_givebook()
{
  object me = this_player();
  object book = new("/open/poison/obj/pbasebook");
  if(me->query("poison_low")){
    book->move(me);
    command("smile");
    return "你就好好研讀這本書。\n";
  }
  return "你並未入我冥蠱魔教，還想要書呀，滾！\n";
}

string do_givewhip()
{
  object me = this_player();
  object whip = new("/open/poison/obj/mo-whip");
  if(me->query("poison_low")){
    whip->move(me);
    command("smile");
    return "這鞭子就讓你防身用，快快長大哦。\n";
  }
  return "沒入教的別想要鞭子，走吧！\n";
}

string do_ep9()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=8)
    return("往事不足言道...");
  me->set_temp("quest-e",9);
  return("你說前任教主嗎？沒想到現在還有人提到他....
          他是我的爹爹，只是數年前因為施蠱不當而喪命....
          聽說當時幫他調蠱的調蠱人在他蠱中加入一些秘藥
          使得爹爹精血逆行而亡....
          只是至今我仍然不曉得爹爹事練什麼蠱術，只知那位調蠱師
          還關在冥蠱魔教中....");
}

string do_fb5()
{
  object me =this_player();
  if(me->query_temp("findbook")!=4)
   return("沒聽過...");
  me->set_temp("findbook",5);
  return("hmm..她已經離開好久了，我想現在不知道在哪邊定居了吧....
             好像去了一個城鎮，好像在東方....");
}

string do_rain()
{
  object me = this_player();
  if(me->query_temp("rain_0") == 1)
  {
    command("sm");
    me->set_temp("rain_1",1);
    return "你想挨鞭子嗎？滾回去！我不想談那個躲在(小水池)後的地下水道的爛人的事情。\n";
  }
  command("sm "+me->query("id"));
  return "哼！不知道。\n";
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
  tell_object(users(),
"\n\t" + YEL + "冥蠱魔教的方位突然傳來一陣嘶聲裂地的怒吼聲!!
\n\t" + YEL + "好不甘心呀!!   我" + HIM + "莊靜柔" + NOR+YEL + "竟然連區區的一個" + HIY+winner->query("name")+NOR+YEL + "都打不過!!
\n\n\t" + HIR + "我魔教所有的門徒們啊!!    請盡情的去使壞吧!!
\n\t" + HIR + "讓那天空降下地獄之火焰!!    讓那大海染成鮮紅!!" + HIR + "
\n\t讓那所有生命在我們魔教面前都感到顫慄害怕!!\n\n" + NOR);
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj1/magic_emblem")->move(environment(winner));
        message_vision(HIM + "\n從莊靜柔的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj1/magic_emblem",sprintf("%s(%s) 讓莊靜柔掉下了幻之紋章於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj1/magic_emblem")->move(environment(winner));
        message_vision(HIM + "\n從莊靜柔的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj1/magic_emblem",sprintf("%s(%s) 讓莊靜柔掉下了幻之紋章於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}
