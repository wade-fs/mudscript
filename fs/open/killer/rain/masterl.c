//這一版本，只是加入霸雨式之謎，所需的回話與接受東西時的反應
//其他並沒有修改任何數值
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string do_givewhip();
string do_givebook();
string do_rain();

int accept_object (object me,object ob)
{
  object ob2;

  if (me->query_temp("rain_2") != 1)
  {
    command ("say 神經病，你給我這個幹嘛！\n");
    return 0;
  }
  if(ob->query("id") != "rou_letter" || me->query_temp("gived") == 1) 
    return 0;
  message_vision(" 莊靜柔將信收下來，將信拆開，仔細閱讀\n",me);
  message_vision(" 一開始還面帶怒容，但逐漸的笑容漸開。。。\n",me);
  message_vision(" 看完信後，莊靜柔很開心：\n",me);
  command("say 小朋友，你真好，你將這一封信帶給柴榮他\n");
  ob2=new("/open/killer/obj/low_let.c");
  ob2->move(me);
  me->set_temp("gived",1);  //防止重複拿取
  me->set_temp("rain_3",1);
  return 1;
}

void create()
{
        set_name("莊靜柔",({"master low","low"}));
        set("long","她就是武林中令人聞風喪膽的冥蠱魔教教主「莊靜柔」﹐別看她一張秀麗的臉蛋﹐其為人可是十分陰毒。\n");
        set("gender","女性");
        set("class","poisoner");
        set("nickname", HIR "九陰仙子" NOR);
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",26);
        set("str", 44);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 48);
        set("force",800);
set("functions/firefinger/level",30);
        set_skill("literate",80);
        set("max_force",800);
        set_skill("move",100);
set_skill("force",50);
        set_skill("dodge",100);
        set_skill("parry",60);
        set_skill("poison",100);
        set_skill("unarmed",40);
        set_skill("whip",60);
        set_skill("poisonforce",60);
        map_skill("force","poisonforce");
        set("force_factor",10);
        set_skill("coldpoison",100);
        set_skill("nine-steps",120);
        map_skill("dodge","nine-steps");
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
(: perform_action,"poison.five" :),
(: perform_action,"poison.firefinger" :),
(: perform_action,"poison.faint" :),
        }));
        map_skill("move","nine-steps");
        map_skill("poison","coldpoison");
        set_skill("ming-snake",80);
        map_skill("whip","ming-snake");
        set("inquiry",([
        "basewhip" : (: do_givewhip :),
        "天魔解體大法" : (: do_rain :),
        "basebook" : (: do_givebook :),
        "赤火令"   : "你以為你是誰呀! 膽敢跟我要令牌。",
        ]));
        setup();
        create_family("冥蠱魔教",3,"教主");
carry_object("open/poison/obj/circle.c")->wear();
        carry_object(POISON_OBJ"bleed_whip")->wield();
carry_object("open/poison/obj/godcloth.c")->wear();
carry_object("open/poison/obj/cape.c")->wear();
carry_object("open/poison/obj/feather.c")->wear();
        carry_object("/obj/poison/rose_poison")->set_amount(30);
        carry_object("/obj/poison/five_poison")->set_amount(30);
        carry_object("/obj/poison/dark_poison")->set_amount(30);
carry_object("/obj/poison/faint_poison")->set_amount(30);
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
                command("say 你還沒通過入會儀式呢？");
                command("say 等你通過再來吧。");
                return 1;
               }
        else {
                command("smile");
                command("say 很好，既然你已求得兩位長老的同意。");
                command("say 那你就在此宣誓(swear)入教。");
                me->set_temp("master_temp",1);
                say(HIC"金童說道﹕請施主宣誓『盡忠魔教』以完成儀式。\n"NOR);
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
                command("shout $HIR$我冥蠱魔教又有新教徒$HIG$"+me->query("name")+"\n");
                command("shout $HIR$看來是我魔教復出武林的時後了。\n");
                command("poisoner $HIG$讓我們一起歡迎我們的新教徒$HIR$"+me->query("name")+"$HIG$吧。\n");
                }
                say(HIC"玉女說道﹕歡迎加入魔教，將來要遵從教令哦。\n"NOR);
                command("say 這是本教入門書籍，你好好研讀吧。");
                book->move(me);
                me->delete_temp("master_temp");
                return 1;
              }
          else {
            message_vision(sprintf(HIC"$N發誓說道﹕"+str+"\n"NOR),me);
            command("say 你說什麼呀，沒誠意就滾回去。");
            me->delete_temp("master_temp");
            return 1;
           }
    message_vision(sprintf(HIC"$N發誓說道﹕"+str+"\n"),me);
    command("say 我有同意讓你發誓嗎？");
    return 1;
}
}
  void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="poisoner")
        {
                command("say 你不是我們魔教的人﹐你走吧 !\n");
                return;
        }
        if(!this_player()->query("poison_low"))
        {
                command("say 雖然你是魔族一員，但你未入我教。\n");
                command("say 所以我也不便傳你任何技能，你請回吧。\n");
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
  return "你並未入我冥蠱魔教，還想要書呀，滾!\n";
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
   return "沒入教的別想要鞭子，走吧!\n";
}

string do_rain()
{
  object me = this_player();

   if(me->query_temp("rain_0") == 1)
   {
        command("sm");
        me->set_temp("rain_1",1);
        return "你想挨鞭子嗎？滾回去！我不想談那個躲在地下水道的爛人的事情\n";
   }
   command("sm "+me->query("id"));
   return "哼！不知道\n";
}
