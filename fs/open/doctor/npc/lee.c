#include <ansi.h>
inherit NPC;
string ask_secret();

void create()
{
 set_name("李秋凡",({"lee"}));
 set("long","
    他是銀針門掌門人的得意弟子，但因為當年在爭奪衝穴秘籍中，受了重傷。

    現在正在此地修養中。
 ");
 set("gender","男性");
 set("class","doctor");
 set("combat_exp",450000);
 set("attitude","heroism");
 set("title","銀針門弟子");
 set("age",42);
 set("str",15);
 set("cor",30);
 set("cps",20);
 set("kar",25);
 set("force",2000);
 set("max_force",2000);
 set("max_kee",1500);
 set("kee",1500);
 set("no_kill",1);
 set("no_fight",1);
 set("inquiry",([
 "衝穴秘籍"    : (:ask_secret:),
 "指導" : "可以使用 practice 來學習。\n",
 ]));
 setup();
        carry_object("/open/doctor/obj/needle4.c")->wield();
        add_money("gold",5);
}
string ask_secret()
{
  object me = this_player();
  if(me->query_temp("quests/acup") != 13)   
    return "??????????????????你怎麼進來的?????";
  me->set("quests/acupuncture",1);
  me->delete_temp("quests/acup");
  tell_object(me,HIR + "\n\n恭喜你完成衝穴之迷。\n\n");
  return "關於這件事，真是太感謝你了，不過這本秘籍我已經交給師父保管了。\n"+
         "不過我還是可以略為(指導)你幾招。";
}
void init()
{
  add_action("do_practice","practice");
  ::init();
}
int do_practice(string arg)
{
  object me,ob;
  me = this_player();
  ob = this_object();
  if(!this_player()->query("quests/acupuncture") )
    return notify_fail(ob->name() + "說道：你憑什麼要我教你？\n");
  if(me->query("sen") < 10)
    return notify_fail(ob->name() + "說道：你精神不太好，還是休息一下的好。\n");
  if( (me->query("potential") - me->query("learned_points")) < 5 ) 
    return notify_fail(ob->name() + "說道：你的潛能不足了．我再教你也是沒用。\n");
  if(me->query_skill("acupuncture",1) > 99) 
    return notify_fail(ob->name() + "說道：我就教你到這裡了。\n");


  me->improve_skill( "acupuncture" , random(me->query_int())+ 5 );
   me->add("learned_points",5);
   me->receive_damage("sen",10);
  return notify_fail("你從"+ob->name()+"的指導下，練習衝穴技巧。\n");
}
void greeting(object ob)
{
        if( !ob->query("quests/acupuncture") && !ob->query_temp("quests/acup"))
        {
        command("say 對不起，我現在不想見你。");
        ob->move("/open/doctor/room/1.c");
        }
        if(ob->query_temp("quests/acup") == 13)
        {
          command("say 歡迎歡迎，還是謝謝您救了我，我代表整個銀針門謝謝您。\n");
          return ;
        }
        command("say 謝謝您來看我啊。\n");
}



