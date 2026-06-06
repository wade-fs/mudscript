#include <ansi.h>
inherit NPC;
string ask_secret();
string ask_treasure();
string ask_pkdogstaff();
void create()
{
        set_name("洪七公",({"master hung","master","hung"}));
        set("long","洪七公是個滿頭白髮的老頭﹐若不是認識他的人 你
大概猜不到眼前這個喝酒的老年人竟是丐幫的前任幫主。
                  \n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",5000000);
        set("attitude","friendly");
        set("age",40);
        set("title",HIR + "北丐" + NOR);
        set("nickname",HIG + "九指神丐" + NOR);
        set("str", 50);
        set("cor", 40);
        set("cps", 30);
        set("per", 25);
        set("spi", 20);
        set("int", 30);
        set("con", 30);
        set("kar", 30);
        set("max_gin", 5000);
        set("max_kee", 10000);
        set("max_sen", 5000);
        set("force",20000);
        set("max_force",10000);
        set_skill("staff",150);
        set_skill("pkdog-staff",120);
        map_skill("staff","pkdog-staff");
        set_skill("force",150);
        set_skill("pkdog-force",150);
        map_skill("force","pkdog-force");
        set_skill("dodge",50);
        set_skill("move",40);
        set_skill("shift-steps",50);
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        set("force_factor",12);
        set_skill("parry",40);
        set("bellicosity",3000);
        set("MKS",10000);
        set("inquiry",([
            "打狗秘招" : (: ask_secret :),
            "鎮幫之寶" : (: ask_treasure :),
            "打狗棒" : (: ask_pkdogstaff :),
            "七惡人" : "聽說這七個壞蛋現在跑路去了，好像躲在什麼..什麼塔裡的..",
            "煉爐" : "哦～哇嘛嘸災ㄋㄟ，就叫你去仙境裡找老人就對了！",
                      ]));
        setup();
}

void init()
{
  object obj;
  add_action("do_say","say");
  :: init();
  if(interactive(obj=this_player()) && !is_fighting())
   {
    remove_call_out("greeting");
    call_out("greeting",1,obj);
   }
}

string ask_secret()
{
  object me=this_player();
  if (me->query("class")!="beggar")
      return "你非我丐幫之人，無權過問此事！ \n";
  if ((int)me->query_skill("pkdog-staff",1) <120)
      return "你最基本的武學都還沒學好了，還想問什麼事？\n";
  if (me->query_temp("go_k_snake")==1)
      return "你煩不煩呀，問那麼多次！\n";
  if (me->query("beggar/got_secret")==1)
      return "你已經得我真傳了，沒得教你了！\n";
  if (me->query("combat_exp") < 3000000)
      return "你的戰鬥能力不足哦，懶得理你！\n";
  command("say 你說秘招呀！可是你有那個本事學會嗎？");
  command("stare "+me->query("id"));
  command("say 如果你想要證明你的本事，你就去宰了蛇郎君給我看看吧！");
  me->set_temp("go_k_snake",1);
  return "沒事快走開！\n";
                
}

string ask_treasure()
{
  string str;
  object me=this_player();
  if (me->query("class") != "beggar")
    return "本幫的事無須外人過問！\n";
  if (!me->query("beggar/got_secret"))
    return "你秘學都還沒學會，你問鎮幫之寶也是白問！\n";
  else {
    me->set_temp("ask_treasure",1);
    return "本幫的鎮幫之寶就是打狗棒呀，相信你看過金庸了吧！\n";
    }
}

string ask_pkdogstaff()
{
  object me=this_player();
  if(!me->query_temp("ask_treasure"))
     tell_object(me,"洪七公懶得理會你的瘋言瘋語。\n");
  else {
    command("hmm");
    command("sigh");
    command("say 在一次遊玩中我不小心丟在哪了啦！");
    command("say 只隱約記得掉在一座不曉得叫什麼的山裡面！");
    command("shrug "+me->query("id"));
    command("say 小子，你若能幫我找回打狗棒，或許\我會授與你幾招哦！");
    command("say 你要不要呀！  (say yes or no)");
    me->set_temp("wait_reply",1);
    }
}

int do_say(string arg,object me)
{
  me=this_player();
  if(!arg) return 0;
  if(me->query_temp("find_pkdogstaff")==1)
  {
   command("kok "+me->query("id"));
   command("say 小子，你問都問過了，別再囉嗦了！");
  } 
  if(me->query_temp("wait_reply") == 1)
  {
   if (arg == "yes")
   {
    command("say 太好了，小子，我就等你幫我拿回打狗棒了！\n");
    me->set_temp("find_pkdogstaff",1);}
    else
    command("say 不願意的話就離開吧，別吵我了。\n");
   }
   else return notify_fail("你不曉得在自言自語什麼。\n");
        return 1;
}
            
int accept_object(object me,object ob)
{
  string ob_id,name;
  me=this_player();
  ob_id = ob->query("id");
  name=me->query("name");
  if(ob->query("id")=="bad staff" && me->query_temp("ko_phoenix")==1)
  {
   command ("say 哎呀，想不到這杖已經失去靈性了，這必需以七惡人的極惡之靈來激出此杖的靈性。\n");
   command ("say 七惡人在很久前就沒他們的消息嚕~~");
   command ("laugh");
   return 1;
  }
  else if(ob->query("id")=="poor staff"
       && me->query("family/family_name")=="丐幫")
  {
   if(!(me->query("beggar/got_cloudstaff")) 
   && me->query_temp("got_poor_staff")==1)
   {
    command("say 小子，你能力不錯，可以把失落的寶品給尋回了！\n");
    command("say 還差最後一道開光的手續，你等我一下。\n");
    call_out("do_cloudstaff",2);}else{
    command("say 臭小子，你想來招搖撞騙呀！\n");
    command("kok "+me->query("id"));}
   }
   else if(ob_id=="master-snake-head")
   {
    if(!me->query_temp("go_k_snake") )
    {
     command("say 你拿這東西給我幹嘛？");
     destruct(ob);
     return 1;
    }
    if(!me->query_temp("beggar_ko_snake") )
    {
     command("say 這不是你自己親手拿到的哦！");
     command("kok "+me->query("id"));
     command("say 少來魚目混珠了！");
     destruct(ob);
     return 1;
    }
    if(me->query("beggar/got_secret")==1)
    {
     command("think");
     command("say 你都已經學到秘招了！無須再拿人頭向我炫耀。");
     destruct(ob);
     return 1;
    }
    if (me->query("combat_exp")<3000000)
    {
     command("say 你經驗還不足以習得打狗秘招啦！\n");
     command("slap "+me->query("id"));
     destruct(ob);
     return 1;
    }
    command("spank "+me->query("id"));
    command("say 你果然有二下子，我就把秘招三式傳授與你吧！");
    tell_object(users(),HIY + "\t洪七公縱聲大笑......\n\n\t\t"+name+"" + HIW + "我很中意你，我這就傳予你本幫不傳秘招吧！\n" + NOR);
    me->set("beggar/got_secret",1);
    destruct(ob);
    me->set("title","" + BRED + "" + HIW + "打狗謎樣再現" + NOR);
    return 1;}else{
    command ("say 先生！您哪位，不要隨給把垃圾給我！\n");
    command ("slap "+me->query("id"));
    }
    return 1;
}

void greeting(object me)
{
  me=this_player();
  if( !me || environment(me) != environment(this_object()) ) return;
  if (me->query_temp("need_cloud")==1 
      && !(present("cloud staff",me))
      && (me->query("class")=="beggar"))
  {
   command ("say 臭小子，你居然把我送你的寶物弄丟了。\n");
   command ("say 還好大好人Pana看到了撿來給我，記得謝謝他。\n");
   new("/open/beggar/obj/cloudstaff")->move(me);
   command ("say 別再弄丟了。\n");
   me->delete_temp("need_cloud");
   command ("taoyan "+me->query("id"));
  }
  if(me->query("family/family_name")=="丐幫"
     && !me->query("beggar/got_cloudstaff"))
  {
   if(me->query_temp("ko_pin")==1 &&
      me->query_temp("ko_chung")==1 &&
      me->query_temp("ko_cow")==1   &&
      me->query_temp("ko_hung")==1  &&
      me->query_temp("ko_lee")==1   &&
      me->query_temp("ko_liung")==1 &&
      me->query_temp("ko_lan")==1  )
   {
    if(me->query_temp("got_poor_staff")==1)
    {
     command ("say 你拿到了呀。\n");
     command ("say 把它給我，它尚需要一道手續呢！\n");
    }
    else
    {
     command ("say 唷！你終於打敗了七惡人呀。\n");
     command ("say 只可惜呀，我也不會激發靈氣耶，不過我知道有個老人好像會(煉爐)。\n");
     command ("say 你先去找（煉爐），問問老人吧！\n");
    }
   }
  }
}


void do_cloudstaff(object me)
{
  int lv;
  me=this_player();
  lv = me->query_skill("force",1);
  command ("say 小兄弟，我還需借助你的幾成功\力來開光！\n");
  me->set_skill("force",lv-30);
  tell_object(me,HIR + "洪七公一隻手放在你的天靈蓋\上。\n" + NOR);
  tell_object(me,HIR + "洪七公在自己手指割了一洞，將鮮血滴在杖身。\n" + NOR);
  tell_object(me,HIY + "只見此杖發出異常光芒。\n" + NOR);
  tell_object(me,HIW + "一陣刺眼後，出現眼前的即是期待已久的．．" + HIC + "流雲杖\n" + NOR);
  call_out("do_cloudstaff1",2);
}

void do_cloudstaff1(object me)
{
  object cloudstaff;
  me=this_player();
  command ("say 小伙子，這把寶物就是屬於你的啦！\n");
  cloudstaff=new("/u/p/pana/obj/cloudstaff");
  cloudstaff->move(me);
  command ("say 另外．．嘿嘿！\n");
  command ("grin");
  call_out("do_cloudstaff2",2);
}
void do_cloudstaff2(object me)
{
  me=this_player();
  message_vision(HIG + "洪七公隻手放在$N的天靈蓋\，試將$N的潛在能力激發出來！\n" + NOR,me);
  tell_object(me,HIG + "突然間整個尋寶過程在你腦海裡上演了一次。" + NOR);
  tell_object(me,HIG + "身體一陣火熱，你把與火鳳的戰鬥過程演化成自己的能力。\n" + NOR);
  command("say 小子，你如今已更上一層樓了，加油吧\n");
  command("say 想使出火鳳的能力：perform staff.phoenix \n");
  me->set("beggar/got_phoenix",1);
  me->set("beggar/got_cloudstaff",1);
  me->set("title",HIC + "丐幫" + HIW + "『" + HIY + "究極武學" + HIW + "』" + HIR + "烈焰" + HIW + "長空" + NOR);
  me->delete_temp("got_poor_staff");
  me->delete_temp("ko_pin");
  me->delete_temp("ko_chung");
  me->delete_temp("ko_cow");
  me->delete_temp("ko_hung");
  me->delete_temp("ko_lee");
  me->delete_temp("ko_liung");
  me->delete_temp("ko_lan");
}


