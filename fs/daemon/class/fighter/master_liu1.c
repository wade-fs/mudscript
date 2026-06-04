// 重新設計master_liu by Chan
// 增加許多功用
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string book();
string icef();
string test();
string super_fighter();
/*
// 以前的quests後來取消了,十里追殺令!!!!
string ask_sec()
{
        if( !this_player()->query("quests/to-kill-1") )
                return "你在說些什麼 ?\n";
        this_player()->set("quests/to-kill-2",1);
        return "好吧 ! 我就告訴你好了 ! 黑仙羅漢就是李靈 !\n";
}
//好像是返老還童之quests  取消中 by chan
int do_check( object me )
{
        command("say "+(me->query("gender")=="男性" ? "壯士" : "姑娘")+" ! 你看了似乎受到了極重的內傷﹐讓我替你看看吧 ?");
}
int do_nod()
{
        object me = this_player() , ob = this_object();
        if( !me->query("quests/kill-dugur") || me->query("quests/cure-star") ) return 0;
        message_vision("$N看了看$n身上的傷痕。\n",this_object(),this_player());
        command("sign");
        command("say 老夫無能為力﹐傷你之人的根基遠在老夫之上﹐當今世上﹐恐怕只有鄭士欣有這種實力。");
        command("say 快去找他來幫你看「你的傷」並請他幫你「療傷」。");
        return 1;
}
*/
void create()
{
   set_name("劉全書",({"master liu","liu"}));
   set("long","他是雪蒼三俠之首『黑影鬼腳』劉全書，一雙鐵腳，縱橫武林。\n");
   set("gender","男性");
   set("guild_master",1);
   set("class","fighter");
   set("nickname","黑影鬼腳");
   set("combat_exp",5000000);
   set("attitude","heroism");
   set("age",47);
   set("title","雪蒼派第四代掌門人");
   set("str", 50);
   set("cor", 24);
   set("cps", 18);
   set("per", 24);
   set("int", 42);
   set("force", 7000);
   set("max_kee",15000);
   set("kee",15000);
   set("quests/read_snow",3);
      set("max_gin",3000);
      set("gin",5000);
          set("sen",5000);
          set("max_sen",5000);
   set("s_kee",600);
   set("max_s_kee",1000);
   set("sec_kee","tiger");
   set("inquiry",([
        "天邪石":   "師父臨終前曾交給我這樣寶物﹐他說此物當贈與有緣人。",
        "有緣人":   "能說出十年前武林三大高手者﹐即為有緣人。\n",
        "藏經閣":  (: book :),
        "玄天聖地":   (: super_fighter :),
        "貢獻":   (: test :),
//      "玉門關" : (: ask_sec :),
          ]));
    set_skill("literate",30);
   set("force_factor", 50);
   set("max_force",3000);
      set_skill("snow-kee",100);
   set_skill("cure",40);
          set_skill("move",50);
   set_skill("force",120);
   set_skill("magic",20);
   set_skill("dodge",50);
       set_skill("parry",50);
   set("functions/ice-fingers/level",100);
   set("functions/snow-powerup/level",50);
   set_skill("spells",20);
      set_skill("unarmed",120);
   set_skill("snowforce",100);
   map_skill("force","snowforce");
           set_skill("black-steps",100);
   set_skill("snow-martial",100);
   map_skill("unarmed","snow-martial");
   map_skill("dodge","black-steps");
   map_skill("parry","snow-kee");
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   (: icef :),
   }));
   setup();
   create_family("雪蒼派",4,"掌門人");
   carry_object(SNOW_OBJ"figring")->wield();
   carry_object("/open/snow/obj/liucloth.c")->wear();
}

void init()
{
        object ob;
/*
        object me = this_player();
        if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
                call_out("do_check",1,me);
*/
        add_action("do_say","say");
/*
        add_action("do_nod","nod");
*/
        add_action("do_join","join");
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
     ::heart_beat();
}

void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="fighter")
        {
                command("say 你不是武者﹐我不能收你。\n");
                return;
        }
      if((int)ob->query_str()<20) {
          command("say 雪蒼武學要力量大的人才能學，我看你請回吧!\n");
          return;
      }
      command("hmm");
      command("recruit "+ob->query("id"));
}

int accept_fight(object who)
{
who=this_player();
command("cmd usekee "+who->query("id"));
 command("say 果然英雄出少年。\n");
 command("perform snow-kee.snow-powerup");
command("cmd usekee "+who->query("id"));
 command("charge "+who->query("id"));
 return 1;
}

int accept_kill(object who)
{
who=this_player();
 command("say 死吧~~~~\n");
 kill_ob(who);
command("charge "+who->query("id"));
 command("perform snow-kee.snow-powerup");
command("cmd usekee "+who->query("id"));
 return 1;
}

int do_say(string str,object ob)
{
     object who;
        who=this_player();
        if(who->query("get_stone")==1){
           return 0;}//記得很久之前lum就要我改成這三個ppl的名字了這些人也算是歷史
	else {	            //了...除了sula這老賊..so...再把他改成這三個..........cgy
    if (str=="陳蝶衣")  this_player()->set_temp("say_1",1);
    if (str=="黃雲")    this_player()->set_temp("say_2",1);
    if (str=="復活邪神")  this_player()->set_temp("say_3",1);
    if(this_player()->query_temp("say_1")==1&&this_player()->query_temp("say_2")==1&&this_player()->query_temp("say_3")==1)
     {
      command("smile");
      command("say 你果然是有緣人。\n");
      
        this_player()->set("get_stone",1);
		call_out("do_gs",1,ob);
      }
    return 0;
}}
int do_gs(object ob)
    {
        object stone;
     
        command("say 天邪石拿去吧 !");
        new("/open/snow/obj/stone")->move(this_player());
        
        return 1;
    }
string icef()
{       
        command("perform snow-martial.ice-fingers");
        return "\n";
}
string book()
{
   object me=this_player();
   if(me->query("allow_study")==1)
          return "嗯...不是跟你說過了嗎？\n";
   command("say 此乃本派藏書重地﹐裡面有本派重要秘笈。");
   if(me->query("family/family_name")!="雪蒼派")
          return "你不是本派的弟子﹐沒資格讀本派的書。\n";
   if(me->query("combat_exp")<150000)
          return "已你這種程度要讀藏經閣的書﹐還早的很。\n";
    return "只有為武林有重大的貢獻的雪蒼派弟子才能入藏經閣研讀!!!\n";
}

int do_join()
{
        if(this_player()->query("class"))
                return notify_fail("你已經加入其他工會了。\n");
        this_player()->set("class","fighter");
        message("system",
        HIC + "天生英才.....\n\n一代武者"+this_player()->name()+"誕生了 !!!\n" + NOR,users());
        return 1;
}
string test()
{
 object me;
 me=this_player();
 if(me->query("family/family_name") != "雪蒼派")
  {
   return "劉全書道:這是雪蒼派的事,別的門派不用過問!!!!\n";
  }
if((int)me->query_skill("snow-martial",1)<70)
{
return "你的雪蒼武學..未熟練!!!我看算了..吧..\n";
}
 say("劉全書沈吟一下!!!\n");
 say("劉全書道:最近瀧山派的掌門任正晴來函,請我協助消滅在平南城附近的獨角虎!!!\n");
 say("劉全道續道:這個任務就交給你吧....!!!\n");
 me->set("snow_test",1);
}
int accept_object(object who, object ob)
{
  if( ob->query("id") == "tiger-head")
  {
    destruct(ob);
    if((who->query("family/family_name") == "雪蒼派") && (who->query("snow_test") != 1))
     {
      say("劉全書仔細的看了看!!,說:這不是獨角虎的頭!!。\n");
    return 0;
     }
    if((who->query("family/family_name") != "雪蒼派") || who->query("read_ok"))
     {
     say("劉全書仔細的看了看!!,說道:果然是惡獸的頭!!感謝你為武林除此大害。\n");
  return 1;
     }
   say("劉全書仔細的看了看!!說道:這果然是殘害無數百姓惡獸--獨角虎--的頭。\n");
   if(!who->query("allow_study"))
   {
    who->set("allow_study",1);
say("好吧！我准你讀藏經閣內的書﹐但是雪蒼秘錄、枯葉殘星祕笈、和黑影殘風錄三本書只准讀一本﹐而且讀一次。\n");
   }
   if(who->query("allow_study")==1)
    say("嗯...不是跟你說過了嗎？\n");
return 1;
  }
}
string super_fighter()
{
 object me;
 me=this_player();
 if((me->query("class") != "fighter") || (!me->query("ask_super_fighter")) )
  {
   return "劉全書道:此地為武者傳說聖地,恕難奉告!!!!\n";
  }
 if((me->query("family/family_name") == "瀧山派") && (me->query("title") != "瀧山奧義傳人"))
  {
   return "劉全書怒道:連自己門派的秘奧義都沒有學會了,問那麼多做什麼!!!\n";
  }
 if((me->query("family/family_name") == "雪蒼派") && (me->query("title") != "雪蒼絕學傳人"))
  {
   return "劉全書怒道:連自己門派的絕學都沒有學會了,問那麼多做什麼!!!\n";
  }
 say("劉全書沈思了一下!!!\n");
 say("劉全書吟詩道:------仙~雲~護~氣~凌、身~在~聖~地~中-----\n");
 say("劉全書續道:上二句你就去問任正晴吧。!!\n");
 say("劉全書最後道:句中的涵意就自己體會吧。!!\n");
 me->set("ask_super_fighter",1);
}
void die()
{
   object winner = query_temp("last_damage_from");
   tell_object(users(),
   "\n\t[1m想我[1;36m劉全書[1;37m闖盪武林數十載,從無一敗今天竟被[33m"+winner->query("name")+"[1;37m所敗!!真是佩服!!佩服!![0m\n");
 :: die();
}
