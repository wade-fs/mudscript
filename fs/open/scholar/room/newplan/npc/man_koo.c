//by sueplan
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_ans1();
string do_ans2();
string do_ans3();
string do_ans4();
string do_boot1();


void create() {
        set_name("黃石公",({"old-man koo","koo","old-man"}));
        set("class","scholar");
        set("nickname","$HIC$策謀宗師$NOR$");
        set("title","奇略");
        set("long",
"黃石公為當代著名之兵法家, 著有六韜一書, 
影響後世甚深, 不過看他好像有點煩心事喔。
");
        set("inquiry", ([
        "六韜"       : (: do_ans1 :),
        "不過"       : (: do_ans2 :),
        "太公望"     : (: do_ans3 :),
        "雲山"       : (: do_ans4 :),
      "煩心事"     : (: do_boot1 :),
]));
        set("str",40);
        set("cor",25);
        set("gender","男性");
        set("attitude","heroism");
        set("family/family_name","儒門");
        set("max_gin",5000);
        set("max_kee",8000);
        set("max_sen",8000);
        set("max_force",8000);
        set("force",2000);
        set("force_faxtor",20);
        set("combat_exp",5000000);
        set_skill("stabber",120);
        set_skill("dodge",120);
        set_skill("move",120);
        set_skill("parry",120);
        set_skill("stabber",200);
        set_skill("knowpen",100);
        set_skill("god-plan",100);
        set_skill("plan",120);
        set_skill("force",200);
        set_skill("poetforce",150);
        set_skill("winter-steps",100);
        map_skill("plan","god-plan");
        map_skill("dodge","winter-steps");
        map_skill("move","winter-steps");
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
        setup();
       carry_object("/open/scholar/obj/silver-pen")->wield();
       add_money("gold",50);
 }
string do_boot1()
{
        object me=this_player();
        if(me->query("family/family_name")=="儒門")
          {
	     if( me->query_temp("get_boots")==3)
                {
                 return("ㄟ..沒事情啦!!");
         }
               if( me->query_temp("get_boots")==1)
	        {
                 return("能在幫我拿一次鞋嗎??在同一個地方");
	        }
             if( me->query_temp("get_boots")==2)
	        {
                 return("能在幫我拿第三次鞋嗎??在同一個地方");
	        }
             if( !me->query_temp("get_boots"))
		{
          me->set_temp("ask_thing_ok",1);
	        return("你能幫我拿我的鞋子嗎?我的鞋子掉了!!");
		}
        }
        else
          return("ㄟ??你不是儒門的吧??");
}
string do_ans1()
{
        object me=this_player();
        if(me->query("combat_exp")<5000000)
        {
        return "你的經驗值要到五百萬才能知道有關六韜的事情";
        }
        if( me->query("family/family_name")=="儒門" && me->query_temp("get_boots")==3)
        {
          me->set_temp("six_ask",1);
        return("
          六韜乃是我收集春秋戰國各大戰策奇謀
          裡面記著不少的重要兵法, 不過....。");
}
else
        return("連六韜都不知道??別在和我說話啦....");
}
string do_ans2()
{
        object me=this_player();
        if(me->query_temp("six_ask")==1)
        {
          me->set_temp("six_ask",2);
          return("
          這本書現在不在我這邊, 我把他贈送於
          足智多謀的軍師姜子牙 - 太公望了。
          ");
        }
        else
          return("這事和你無關吧??");
}          
string do_ans3()
{
        object me=this_player();
        if( me->query_temp("six_ask")==2)
        {
          me->set_temp("six_ask",3);
          return("
          他是我所看中的天才策謀家, 能力更在
          我之上哩, 我的六韜交給他之後, 它不
          但將所有的策謀看過後並加以改良, 比
          比我所著之六韜更為有用, 他幫周王朝
          平定江山後, 就隱居於雲山中。");
        }
        else
          return("汪汪??是狗嗎???");
}
string do_ans4()
{
        object me=this_player();
        if( me->query_temp("six_ask")==3)
        {
          me->set_temp("six_ask",4);
          return("
          年輕人, 你不知道雲山在那嗎? 好吧!!
          雲山是在長沙城附近的地方, 你去找找
          吧。");
        }
        else
          return("看日出??。");
}
int accept_object(object me, object obj)
{
        if( obj->query("id") == "small boots" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 幫我撿了鞋子, 謝了。");
        if( me->query("family/family_name") == "儒門" || me->query_temp("get_boots")<3)
          {
            command("say 呵呵, 真的感謝你囉, 以後請你多多幫我撿鞋子。");
            write(this_object()->query("name")+"看著鞋子緩緩穿上。\n\n"+
            "不過臉上卻出現了有點惡作劇的表情。\n\n");
            me->add_temp("get_boots",1);
          }
          else
          {
          command("say 我可不要那麼多鞋子喔!!");
          }
          destruct(obj);
        }
        else
        {
        command("say 幹嘛??");
        }
        return 1;
}
void init()
{
                object ob;
        ::init();
if(interactive(ob =this_player()) && !is_fighting() ) {
//             remove_call_out("greeting");
//             call_out("greeting",2,ob);
        }
add_action("do_nod","nod");
}
int do_nod()
{
        object ob = this_object() , me = this_player();
        if( me->query_temp("get_boots")==3) return 0;
        if( me->query("family/family_name")!="儒門") return 0;
        if(!me->query_temp("ask_thing_ok")) return 0;
        if(me->query_temp("get_boots")==3) return 0;
        command("say 我的鞋子掉在西南方的橋下, 請你幫我撿回來。");
         me->set_temp("can_get",1);
        message_vision("$N對$n微微笑著。\n",ob,me);
        return 1;
}
void greeting(object ob)
{
  if(ob->query_temp("get_boots")==3)
  {
        command("hmm");
        command("say 年輕人, 你真的很有耐性!!");
        command("say 你要問我什麼事呢??");
  }
}
